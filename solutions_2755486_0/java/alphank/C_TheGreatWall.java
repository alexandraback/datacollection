package round1C2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class C_TheGreatWall {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("aSample.txt"));
			BufferedWriter bw = new BufferedWriter(new FileWriter("aOutput.txt"));

			Scanner in = new Scanner(br);

			int T = in.nextInt();
			for (int t = 0; t < T; t++) {
				int N = in.nextInt();

				int[] d = new int[N];
				int[] n = new int[N];
				int[] w = new int[N];
				int[] e = new int[N];
				int[] s = new int[N];
				int[] delta_d = new int[N];
				int[] delta_p = new int[N];
				int[] delta_s = new int[N];

				for (int i = 0; i < N; i++) {
					d[i] = in.nextInt();
					n[i] = in.nextInt();
					w[i] = in.nextInt() + 1000;
					e[i] = in.nextInt() + 1000;
					s[i] = in.nextInt();
					delta_d[i] = in.nextInt();
					delta_p[i] = in.nextInt();
					delta_s[i] = in.nextInt();
				}

				int[] wall = new int[2000];		/* 0 is 1000 */

				int day = 0;
				int numOfSuccess = 0;
				boolean[] isTribeFinished = new boolean[N];
				boolean allTribesFinished = false;

				while(!allTribesFinished) {
					for (int i = 0; i < N; i++) {
						if(d[i] == day) {
							if(processAttack(wall, w[i], e[i], s[i])) {
								numOfSuccess++;
							}
						}
					}

					for (int i = 0; i < N; i++) {
						if(d[i] == day) {
							updateWall(wall, w[i], e[i], s[i]);
							n[i]--;
							if(n[i] == 0) {
								d[i] = -1;
								isTribeFinished[i] = true;
								int j;
								for (j = 0; j < N; j++) {
									if(isTribeFinished[j] == false) {
										break;
									}
								}
								if(j == N) {
									allTribesFinished = true;
								}
							}
							else {
								d[i] += delta_d[i];
								w[i] += delta_p[i];
								e[i] += delta_p[i];
								s[i] += delta_s[i];

							}
						}
					}
					day++;
				}

				bw.write("Case #" + (t + 1) + ": " + numOfSuccess + "\n");
				System.out.println("Case #" + t + ": " + numOfSuccess);
			}
			in.close();
			br.close();
			bw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void updateWall(int[] wall, int w, int e, int s) {
		for (int i = w; i < e; i++) {
			if(wall[i] < s) {
				wall[i] = s;
			}
		}
	}

	private static boolean processAttack(int[] wall, int w, int e, int s) {

		for (int i = w; i < e; i++) {
			if(wall[i] < s) {
				return true;
			}
		}
		return false;
	}

}
