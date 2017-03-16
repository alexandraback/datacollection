import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Kindergarten {

	Scanner in;

	public static void main(String[] args) {
		Kindergarten myClass = new Kindergarten();
		myClass.solve();
	}

	FileWriter writer;

	private void solve() {
		try {

			in = new Scanner(new BufferedReader(new FileReader("C-small-attempt5.in")));
			 //in = new Scanner(System.in);

			writer = new FileWriter("the-file-name.txt");
			int T = in.nextInt();

			for (int i = 1; i <= T; i++) {

				int N = in.nextInt();

				System.out.println(N);

				HashMap<Integer, Integer> kidGraph = new HashMap<Integer, Integer>();

				for (int k = 1; k <= N; k++) {
					int h = in.nextInt();
					kidGraph.put(k, h);
				}

				HashMap<Integer, ArrayList<Integer>> kidSeatingGraph = new HashMap<Integer, ArrayList<Integer>>();

				// 0 if not
				// 1 if one-way
				// 2 if two-way
				HashMap<Integer, Integer> appendableSeating = new HashMap<Integer, Integer>();

				for (int s = 1; s <= N; s++) {

					ArrayList<Integer> finalSeating = new ArrayList<Integer>();

					boolean[] visited = new boolean[N + 1];

					for (int x = 0; x < visited.length; x++) {
						visited[x] = false;
					}

					Queue<Integer> q = new LinkedList<Integer>();
					q.add(s);
					int pop = -1;
					int coun = 0;
					while (q.size() != 0) {
						pop = q.poll();

						visited[pop] = true;
						finalSeating.add(pop);
						if (!visited[kidGraph.get(pop)]) {
							q.add(kidGraph.get(pop));
						}
						if (coun > 250) {
							System.out.println("ERROR");
						}
					}
					int lastGuy = finalSeating.get(finalSeating.size() - 1);
					int guyBeforeLast = finalSeating.get(finalSeating.size() - 2);

					if (kidGraph.get(lastGuy) == guyBeforeLast) {
						kidSeatingGraph.put(s, finalSeating);
						appendableSeating.put(s, 1);
					} else {
						if (kidGraph.get(lastGuy) == s) {

							// might wanna rewrite this
							if (finalSeating.size() == 2) {
								kidSeatingGraph.put(s, finalSeating);
								appendableSeating.put(s, 2);
							} else {
								kidSeatingGraph.put(s, finalSeating);
								appendableSeating.put(s, 0);
							}

						} else {

							kidSeatingGraph.put(s, finalSeating);
							appendableSeating.put(s, 4);

						}

					}

				}

				int maxPossibleSingleSeating = 0;
				int idS = 0;

				int maxPossibleOneWaySeating = 0;
				HashSet<Integer> possibleIDPs = new HashSet<Integer>();

				for (int e = 1; e <= N; e++) {
					if (appendableSeating.containsKey(e)) {
						if (appendableSeating.get(e) == 0) {
							if (kidSeatingGraph.get(e).size() > maxPossibleSingleSeating) {
								idS = e;
								maxPossibleSingleSeating = kidSeatingGraph.get(e).size();
							}
						}

						if (appendableSeating.get(e) == 1) {
							if (kidSeatingGraph.get(e).size() > maxPossibleOneWaySeating) {
								maxPossibleOneWaySeating = kidSeatingGraph.get(e).size();
								possibleIDPs = new HashSet<Integer>();
								possibleIDPs.add(e);

							} else if (kidSeatingGraph.get(e).size() == maxPossibleOneWaySeating) {
								possibleIDPs.add(e);
							}
						}

					}
				}

				int totalMax = 0;
				
				int maxIQ = 0;
				System.out.println(possibleIDPs);

				for (Integer iq : possibleIDPs) {
System.out.println(kidSeatingGraph.get(iq));
					int maxToAppend = 0;
					int maxPossibleOneWaySeatingType1 = 0;

					
					
					
					// HashSet<Integer> elementsOfOptSeat = new
					// HashSet<Integer>(kidSeatingGraph.get(idP));

				
					maxToAppend = 0;

					//System.out.println(kidSeatingGraph.get(4));

					for (Integer e : kidSeatingGraph.keySet()) {

						if (!kidSeatingGraph.get(iq).contains(e)) {

							if (kidSeatingGraph.get(e).get(kidSeatingGraph.get(e).size() - 2) == kidSeatingGraph.get(iq)
									.get(kidSeatingGraph.get(iq).size() - 1)) {

								if (maxToAppend < (kidSeatingGraph.get(e).size() - 2)) {
									//System.out.println("magic e is:");
									//System.out.println(kidSeatingGraph.get(e));
									boolean intersects = false;
									for(int y = 0; y < kidSeatingGraph.get(e).size()-2; y++){
										if(kidSeatingGraph.get(iq).contains(kidSeatingGraph.get(e).get(y))){
											intersects = true;
										}
									}
									
									if(!intersects){
									maxToAppend = kidSeatingGraph.get(e).size() - 2;
									}
									
									
									
								}
							}

						}
					}

					if (totalMax < Math.max(maxToAppend + maxPossibleOneWaySeating, maxPossibleOneWaySeatingType1)) {
						totalMax = Math.max(maxToAppend + maxPossibleOneWaySeating, maxPossibleOneWaySeatingType1);
						maxIQ = iq;
					}

				}

				
			for (Integer e : kidSeatingGraph.keySet()) {

				if (appendableSeating.get(e) == 2 && !kidSeatingGraph.get(maxIQ).contains(e)) {
					//System.out.println(appendableSeating.get(e));
					totalMax = totalMax + 1;
				}
			}
				
				
				
				int ans = Math.max(totalMax, maxPossibleSingleSeating);

				StringBuilder s = new StringBuilder();

				s.append("Case #");
				s.append(i);
				s.append(": ");

				s.append(ans + "");
				System.out.println("myans " + ans);
				s.append("\n");

				writer.write(s.toString());

			}
			writer.close();
		} catch (IOException e) {
		}

	}

}
