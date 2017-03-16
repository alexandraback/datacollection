import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class c {

	public static void main(String[] args) throws Exception {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt4.in"));
		PrintWriter pw = new PrintWriter("C-small.out", "UTF-8");
		
		int t = Integer.parseInt(br.readLine());
		
		for (int test = 1; test <= t; test++) {
			String[] line = br.readLine().split(" ");
			
			int n = Integer.parseInt(line[0]);
			int m = Integer.parseInt(line[1]);
			int k = Integer.parseInt(line[2]);
			
			if (k < 5 || m < 3 || n < 3) {
				pw.printf("Case #%d: %d%n", test, k);
			} else if (m * n - 4 <= k) {
				pw.printf("Case #%d: %d%n", test, 2 * (m - 2) + 2 * (n - 2) + (k - (m * n - 4)));
			} else {
				int a = 3;
				int b = 3;
				boolean done = false;
				while (a * b - 4 < k) {
					if (a > b) {
						if (b < m) {
							b++;
						} else {
							a++;
						}
					} else {
						if (a < n) {
							a++;
						} else {
							b++;
						}
					}
					if (a * b - 6 >= k) {
						pw.printf("Case #%d: %d%n", test, 2 * (a - 2) + 2 * (b - 2) - 1);
						done = true;
						break;
					}
					if (a * b - 3 == k) {
						pw.printf("Case #%d: %d%n", test, 2 * (a - 2) + 2 * (b - 2) + 1);
						done = true;
						break;
					}
				}
				if (!done) {
					pw.printf("Case #%d: %d%n", test, 2 * (a - 2) + 2 * (b - 2));
				}
			}
		}
		
		br.close();
		pw.close();
	}
}