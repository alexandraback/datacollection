/*  
    Author: Gaurav Gupta
    Date:   14 Apr 2012
 */
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Dancing {

	/**
	 * TODO Put here a description of what this method does.
	 * 
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub.

		FileWriter fw = new FileWriter("Output2.txt");
		PrintWriter pw = new PrintWriter(fw);

		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		int N, S, p, t;
		for (int i = 0; i < T; i++) {
			N = sc.nextInt();
			S = sc.nextInt();
			p = sc.nextInt();

			int avg = 3 * p;
			int sum = 0;

			for (int j = 0; j < N; j++) {
				t = sc.nextInt();

				if (t >= (avg - 4)) {
					if (t < (avg - 2)) {
						if (S > 0 && t >= p) {
							sum++;
							S--;

						}
					} else {
						sum++;
					}
				}
				// System.out.print(t + ", ");
			}

			pw.println("Case #" + (i + 1) + ": " + sum);
			System.out.println("Case #" + (i + 1) + ": " + sum);
		}

		pw.close();

	}

	public static boolean isBest(int t, int p) {
		return true;
	}

}
