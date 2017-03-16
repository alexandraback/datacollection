import java.io.*;
import java.util.*;

public class B extends CodeJammer {

		public static Integer[][] a;

		public void process() throws IOException {
			int n = reader.readInt();
			//System.out.println(n);
			a = new Integer[n][2];
			for (int i=0; i<n; i++) {
					int[] arr = reader.readArray();
					Integer[] arr2 = new Integer[2];
					arr2[0] = arr[0];
					arr2[1] = arr[1];		
					a[i] = arr2;
			}
			C c = new C();
			Arrays.sort(a,c);
			
			int stars = 0;
			int punts = 0; //number done for one star so far
			//int started = 0; //levels started
			//int completed = 0; //levels completed (for two stars)
			//these PQueue's store the num. stars needed to complete.
			//PriorityQueue<Integer> startedLevels = new PriorityQueue<Integer>();
			//PriorityQueue<Integer> freshLevels = new PriorityQueue<Integer>();
			
			HashSet<Integer> fresh = new HashSet<Integer>();
			HashSet<Integer> started = new HashSet<Integer>();
			HashSet<Integer> finished = new HashSet<Integer>();
			for (int i=0; i<n; i++) fresh.add(i);

			PriorityQueue<Integer> toFinish = new PriorityQueue<Integer>(n,new finComp());
			PriorityQueue<Integer> toStart = new PriorityQueue<Integer>(n,new stComp());
			for (int i=0; i<n; i++) toFinish.add(i);
			
			
			//for (int i=0; i<n; i++) freshLevels.add(a[i][1]);
			int poss = 0; //number of levels possible to complete on some difficulty
			while (poss<n && stars >= a[poss][0]) {
					toStart.add(poss);
					poss++;
			}
			
			boolean working = true;
			while (working) {
				boolean acted = false;
				/*while (freshLevels.peek() != null && freshLevels.peek() <= stars) {
					int cost = freshLevels.poll();
					stars += 2;
					completed++;
					acted = true;
					System.out.println("Acing with " + cost);
				}
				while (startedLevels.peek() != null && startedLevels.peek() <= stars) {
					int cost = startedLevels.poll();
					stars++;
					completed++;
					started--;
					acted=true;
					System.out.println("Finishing with " + cost);
				}*/

				while (toFinish.peek() != null && a[toFinish.peek()][1] <= stars) {
						int i = toFinish.poll();
						if (fresh.contains(i)) {
								fresh.remove(i);
								finished.add(i);
								stars +=2;
								//System.out.println("Aced " + i);
						} else {
								started.remove(i);
								finished.add(i);
								stars++;
								//System.out.println("Finished " + i);
						}
						acted = true;
				}

				if (!acted) {
					//Try to play for a single star
					while (poss<n && stars >= a[poss][0]) {
							toStart.add(poss);
							poss++;
					}
					if (poss-started.size()-finished.size() > 0) {
							//startedLevels.add(freshLevels.poll());
							int i = toStart.poll();
							while (!fresh.contains(i)) i = toStart.poll();
							//started++;
							punts++;
							stars++;
							fresh.remove(i);
							started.add(i);
							//System.out.println(i + " started");
							//System.out.println("Starting with " + a[started+completed][0]);
					} else {
							working = false;
					}
				}
			}

			if (stars == 2*n) {
					output(punts+n);
			} else {
					output("Too Bad");
			}
		}
		
		public static class C implements Comparator<Integer[]> {
			public int compare (Integer[] a, Integer[] b) {
				return a[0] - b[0];
			}
		}

		public static class finComp implements Comparator<Integer> {
				public int compare (Integer i, Integer j) {
						return a[i][1] - a[j][1];
				}
		}

		public static class stComp implements Comparator<Integer> {
				public int compare (Integer i, Integer j) {
						return a[j][1] - a[i][1];
				}
		}

		public static void main(String[] args) {
				B b = new B();
				b.run(args);
		}

}
