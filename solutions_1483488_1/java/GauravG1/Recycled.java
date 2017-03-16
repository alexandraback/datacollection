/*  
    Author: Gaurav Gupta
    Date:   14 Apr 2012
 */
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Recycled {

	/**
	 * TODO Put here a description of what this method does.
	 * 
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub.

		FileWriter fw = new FileWriter("Output3.txt");
		PrintWriter pw = new PrintWriter(fw);

		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		int sum = 0;
		int A, B;
		for (int i = 0; i < T; i++) {
			A = sc.nextInt();
			B = sc.nextInt();
			sum = 0;
			for (int j = A; j <= B; j++) {
				int n = j;
				int m;
				String ns = String.valueOf(n);
				String ms;
				int count = 0;
				int found = 0;
				int rep[] = new int[ns.length()];
				for (int k = 0; k < ns.length(); k++) {
					ms = ns.substring(k, ns.length()) + ns.substring(0, k);

					m = Integer.parseInt(ms);

					if (m > n && m >= A && m <= B) {

						found = 0;

						for (int l = 0; l < count; l++)
							if (rep[l] == m) {
								found = 1;
							}

						if (found == 0) {
							rep[count] = m;
							count++;
							sum++;
							// System.out.println(n + "  " + m);
						}

					}

				}

			}

			pw.println("Case #" + (i + 1) + ": " + sum);
			System.out.println("Case #" + (i + 1) + ": " + sum);
		}

		pw.close();

	}

}
