import java.io.*;
import java.util.*;

public class P1 {
	public static void main (String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner (System.in);
//		PrintStream op = System.out;
		Scanner sc = new Scanner (new FileInputStream ("D:\\Internet\\A-large.in"));
		PrintStream op = new PrintStream ("output.txt");
		int T = sc.nextInt();
		sc.nextLine();
		for (int t = 1; t <= T; t++) {
			String[] toks = sc.nextLine().split("/");
			long p = Long.parseLong(toks[0]);
			long q = Long.parseLong(toks[1]);
			op.print("Case #" + t + ": ");
			if (p > q) {
				op.println("impossible");
				continue;
			}
			for (long i = 2; i <= Math.sqrt(p); i++) {
				while (p % i == 0 && q % i == 0) {
					p /= i;
					q /= i;
				}
			}
			if (q % p == 0) {
				q /= p;
				p = 1;
			}
			long temp = q, count = 0;
			while (temp > 0) {
				count += temp & 1;
				temp = temp >> 1;
			}
			if (count != 1) {
				op.println("impossible");
				continue;
			}
			temp = p;
			int ans = 0;
			while (temp < q) {
				temp = temp << 1;
				ans++;
			}
			op.println(ans);
		}
	}
}