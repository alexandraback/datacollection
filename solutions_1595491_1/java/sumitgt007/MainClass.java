import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class MainClass {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("B-large.in"));
		PrintWriter out = new PrintWriter(new File("Dancing-large.out"));

		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			int ans = 0;

			int N = sc.nextInt(), S = sc.nextInt(), p = sc.nextInt();
			ArrayList<Integer> sums = new ArrayList<Integer>();
			for (int j = 0; j < N; j++) {
				sums.add(sc.nextInt());
			}
			for (int j = 0; j < N; j++) {
				int tempP = p;

				int sum = sums.get(j);
				int sumBackup = sum;
				while (tempP <= 10 && tempP <= sumBackup) {
					sum = sums.get(j);
					sum -= tempP;
					int half = sum / 2;
					int half2 = sum - half;

					if ((Math.abs(half2 - half) <= 1)
							&& (Math.abs(half2 - tempP) <= 1)
							&& (Math.abs(tempP - half) <= 1)) {
						ans++;
						int test = sums.remove(j);
						// System.out.println(test + "\t " + tempP + "\t" + half
						// + "\t" + half2);
						j--;
						N--;
						break;
					}
					tempP++;

				}

			}
			// System.out.println(S);
			outer: for (int j = 0; j < N; j++) {
				int tempP = p;

				int sum = sums.get(j);
				int sumBackup = sum;
				while (tempP <= 10 && tempP <= sumBackup) {
					sum = sums.get(j);
					sum -= tempP;
					int half = sum / 2;
					int half2 = sum - half;
					if ((Math.abs(half2 - half) <= 2)
							&& (Math.abs(half2 - tempP) <= 2)
							&& Math.abs(tempP - half) <= 2) {
						if (S != 0) {

							ans++;
							S--;

							int test = sums.remove(j);
							// System.out.println(test + "\t " + tempP + "\t"
							// + half + "\t" + half2 + "\t" + S);

							j--;
							N--;
							break;
						}
						if (S == 0) {
							// System.out.println("broke");
							break outer;
						}
					}
					tempP++;

				}

			}
			/* System.out.println(sums); */
			out.println("Case #" + (i + 1) + ": " + ans);
		}
		out.close();

	}
}
