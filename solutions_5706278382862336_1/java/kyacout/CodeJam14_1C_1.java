import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class CodeJam14_1C_1 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new File("output2"));
		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			String[] line = br.readLine().split("/");
			long p = Long.parseLong(line[0]);
			long q = Long.parseLong(line[1]);
			long g = gcd(p, q);
			p /= g;
			q /= g;
			
			int counter = 1;
			while (p * 2 < q) {
				p *= 2;
				g = gcd(p, q);
				p /= g;
				q /= g;
				counter++;
			}
			
			p = (p * 2) - q;
			g = gcd(p, q);
			p /= g;
			q /= g;
			
			int counter2 = counter;
			boolean f = false;
			while (counter2 < 40) {
				if ((p == 1 && q == 2) || p == 0) {
					f = true;
					break;
				} else if (p * 2 < q) {
					p *= 2;
					g = gcd(p, q);
					p /= g;
					q /= g;
				} else {
					p = (p * 2) - q;
					g = gcd(p, q);
					p /= g;
					q /= g;
				}
				counter2++;
			}
			
			out.print("Case #" + tc + ": ");
			out.println(f ? counter : "impossible");
		}
		out.close();
	}

	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}
}
