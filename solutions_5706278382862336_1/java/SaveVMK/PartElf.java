import java.io.*;
import java.util.*;

public class PartElf {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/A-large.in"))));

		String output = "";
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= t; i++) {
			String[] s = sc.nextLine().split("/");
			long p = Long.parseLong(s[0]);
			long q = Long.parseLong(s[1]);
			long gcd = gcd(p,q);
			p /= gcd;
			q /= gcd;
			for (int j = 0; ; j++) {
				if (p > q) {
					for (int k = 0; q%2==0; k++)
					{
						q /= 2;
					}
				}
				if (q % 2 == 1) {
					output += "Case #" + i + ": ";
					if (q == 1) {
						output += j + "\n";
					} else {
						output += "impossible\n";
					}
					break;
				} else {
					q /= 2;
				}
			}
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/A-large.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
	
	static long gcd(long a, long b) {
		if(a == 0 || b == 0) return a+b; // base case
		return gcd(b,a%b);
	}
}