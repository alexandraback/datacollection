package blah;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class QB {
	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("B-small-attempt1.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));

		int caseCnt = sc.nextInt();
		sc.nextLine();

		// Case number
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			pw.write("Case #" + caseNum + ": ");
			System.out.println("Case #" + caseNum + ": ");
			int N = sc.nextInt();
			LinkedList<String> trains = new LinkedList<String>();
			System.out.println(N);
			for (int i = 0; i < N; i++) {
				trains.add(sc.next());
			}
			long possible = 0;

			boolean isPossible = true;
			
			for(int t = 0;t<trains.size();t++) {
				String train = trains.get(t);
				System.out.println(train);
				boolean decrease = false;
				
				// Debut
				{
					char c = train.charAt(0);
					int numIdentic = 0;
					for (int i = t; i < trains.size(); i++) {
						String s = trains.get(i);
						boolean identical = true;
						for (int j = 0; j < s.length(); j++) {
							if (s.charAt(j) != c)
								identical = false;
						}

						if (identical) {
							numIdentic++;
							String result = train;
							if (i != t) {
								trains.remove(i);
								i--;
								if(i<t) {
									t--;
								}
								result = s + train;
								trains.remove(t);
								trains.add(t,result);
								decrease = true;
								train = result;
							}
						}

					}
					possible += factoriel(numIdentic);
					
					boolean done = false;
					for (int i = t; i < trains.size(); i++) {
						String s = trains.get(i);
						if(s != train) {
							if(s.charAt(s.length() - 1) == c) {
								if(done) {
									isPossible = false;
								} else {
									done = true;
									trains.remove(i);
									if(i<t) {
										t--;
									}
									trains.remove(t);
									String result = s + train;
									trains.add(t,result);
									decrease = true;
									train = result;
									
								}
							}
						}
					}
				}

				// Fin
				{
					char c = train.charAt(train.length()-1);
					int numIdentic = 0;
					for (int i = t; i < trains.size(); i++) {

						String s = trains.get(i);
						boolean identical = true;
						for (int j = 0; j < s.length(); j++) {
							if (s.charAt(j) != c)
								identical = false;
						}

						if (identical) {
							numIdentic++;
							String result = train;
							if (i != t) {
								trains.remove(i);
								i--;
								result = train + s;
								if(i<t) {
									t--;
								}
								trains.remove(t);
								trains.add(t,result);
								decrease = true;
								train = result;
							}
						}

					}
					possible += factoriel(numIdentic);
					
					boolean done = false;
					for (int i = t; i < trains.size(); i++) {
						String s = trains.get(i);
						if(s != train) {
							if(s.charAt(0) == c) {
								if(done) {
									isPossible = false;
								} else {
									done = true;
									trains.remove(i);
									if(i<t) {
										t--;
									}
									trains.remove(t);
									String result = train + s;
									trains.add(t,result);
									decrease = true;
									train = result;
								}
							}
						}
					}
				}
				
				if (decrease)
					t--;
			}
			
			for(String train1 : trains) {
				for(String train2 : trains) {
					if(train1 != train2) {
						for(int i = 0;i<train1.length();i++) {
							char c = train1.charAt(i);
							if(train2.indexOf(c) != -1)
								isPossible = false;
						}
					}
				}
			}
			
			possible += factoriel(trains.size());
			if(possible == 0)
				possible = 1;
			if(!isPossible) {
				System.out.println(0);
				pw.print(0);
			} else {
				System.out.println(possible);
				pw.print(possible);
			}
			pw.print("\n");
			
		}

		pw.flush();
		pw.close();
		sc.close();
	}

	private static long factoriel(int numIdentic) {
		long result = 1;
		for (int i = 2; i <= numIdentic; i++) {
			result = result * i;
		}
		if(result == 1)
			return 0;
		return result;
	}

}
