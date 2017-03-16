import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Vector;

public class Lawnmower {

	public Lawnmower(String input, String output) throws IOException {
		Scanner sc = new Scanner(new File(input));
		BufferedWriter bw = new BufferedWriter(new FileWriter(output));
		int cases = sc.nextInt();
		for (int i = 0; i < cases; i++) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			int[][] lawn = new int[N][M];

			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					lawn[n][m] = sc.nextInt();
				}
			}

			System.out.print("Case #"+(i + 1) + ": ");
			bw.write("Case #"+(i + 1) + ": ");
			if (isMowable(lawn, N, M)) {
				System.out.println("YES");
				bw.write("YES");
			} else {
				System.out.println("NO");
				bw.write("NO");
			}
			if (i != cases - 1) {
				bw.newLine();
			}
		}
		sc.close();
		bw.close();
	}


	private boolean isMowable(int[][] lawn, int N, int M) {
		for (int cut = 0; cut < 100; cut++) {
			// printArray(lawn);
			Vector<HashSet<Integer>> rows = new Vector<HashSet<Integer>>();
			Vector<HashSet<Integer>> cols = new Vector<HashSet<Integer>>();
			for (int i = 0; i < N; i++) {
				rows.add(new HashSet<Integer>());
			}
			for (int i = 0; i < M; i++) {
				cols.add(new HashSet<Integer>());
			}
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					if (lawn[n][m] == 1) {
						rows.get(n).add(m);
					}
				}
			}

			for (int m = 0; m < M; m++) {
				for (int n = 0; n < N; n++) {
					if (lawn[n][m] == 1) {
						cols.get(m).add(n);
					}
				}
			}

			for (int n = 0; n < N; n++) {
				if (rows.get(n).size() == M)
					continue;
				for (int m = 0; m < M; m++) {
					if (cols.get(m).size() == N)
						continue;
					if (rows.get(n).contains(m) && cols.get(m).contains(n)) {
						return false;
					}
				}
			}

			boolean doneChecking = false;
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					if (lawn[n][m] > 1) {
						lawn[n][m]--;
						doneChecking = true;
					}
				}
			}

			if (!doneChecking)
				break;

		}
		return true;
	}


	private void printArray(int[][] a) {
		int N = a.length;
		int M = a[0].length;
		System.out.println("-");
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				System.out.print(a[n][m] + " ");
			}
			System.out.println();
		}
		System.out.println("=");
	}


	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		Lawnmower l = new Lawnmower("B-large.in", "lawn-out-large.txt");

	}

}
