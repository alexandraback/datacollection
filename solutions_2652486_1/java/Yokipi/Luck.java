package roundonea2013;

import java.io.*;
import java.util.*;


public class Luck {
	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(new File(
				"src/roundonea2013/Luck.in")));
		FileWriter out = new FileWriter(new File("src/roundonea2013/Luck.out"));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int R = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());

			int[] attempt = new int[M-1];
			Random rand = new Random();
			
			out.write("Case #" + t + ":\n");
			for (int r = 1; r <= R; r++) {
				st = new StringTokenizer(in.readLine());
				ArrayList<Integer> given = new ArrayList<Integer>();
				for (int i = 0; i < K; i++) {
					given.add(Integer.parseInt(st.nextToken()));
				}
				
				for (int i = 0; i < M-1; i++) {
					attempt[i] = 0;
				}
				
				/*
				while (true) {
					for (int i = 0; i < M-1; i++) {
						attempt[i] = 0;
					}
					for (int i = 0; i < N; i++) {
						attempt[rand.nextInt(M-1)]++;
					}
					
					boolean shortcut = false;
					int maximum = 1;
					for (int j = 0; j < M-1; j++) {
						for (int k = 0; k < attempt[j]; k++) {
							maximum *= (j+2);
						}
					}
					for (int g : given) {
						if (maximum % g != 0) {
							shortcut = true;
							break;
						}
					}
					
					if (!shortcut) {
						ArrayList<Integer> generated = new ArrayList<Integer>();
						for (int i = 0; i < K*K; i++) {
							int product = 1;
							for (int j = 0; j < M-1; j++) {
								for (int k = 0; k < attempt[j]; k++) {
									if (rand.nextBoolean()) product *= (j+2);
								}
							}
							generated.add(product);
						}
						
						if (generated.contains(given)) break;
					}
				}*/
				
				// Strategy 2
				int product = 1;
				for (int g : given) {
					product *= g;
				}
				product *= product;
				for (int i = 0; i < M-1; i++) {
					if (product % (i+2) == 0) {
						product /= (i+2);
						attempt[i]++;
					}
				}
				
				for (int i = 0; i < M-1; i++) {
					double k = K;
					attempt[i] = (int) Math.ceil(attempt[i]/k);
				}
				
				while (true) {
					int sum = 0;
					for (int i = 0; i < M-1; i++) {
						sum += attempt[i];
					}
					
					if (sum == N) {
						/*
						boolean possible = true;
						int broken = 0;
						int maximum = 1;
						for (int i = 0; i < M-1; i++) {
							for (int j = 0; j < attempt[i]; j++) {
								maximum *= (i+2);
							}
						}
						for (int g : given) {
							if (maximum % g != 0) {
								possible = false;
								broken = g;
								break;
							}
						}
						if (possible) break;
						else {
							for (int i = 0; i < M-1; i++) {
								if (broken % (i+2) == 0) {
									attempt[i]++;
								}
							}
						}*/
						break;
					}
					else if (sum > N) {
						int chosen = rand.nextInt(M-1);
						if (attempt[chosen] > 0) attempt[chosen]--;
					}
					else {
						int chosen = rand.nextInt(M-1);
						attempt[chosen]++;
					}
				}
				
				String digits = "";
				for (int i = 0; i < M-1; i++) {
					for (int j = 0; j < attempt[i]; j++) {
						digits += (i+2);
					}
				}
				
				out.write(digits + "\n");
			}
			


		}

		in.close();
		out.close();
	}
}
