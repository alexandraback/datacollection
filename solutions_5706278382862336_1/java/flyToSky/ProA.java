package Round1C;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class ProA {

	public static void main(String[] args) throws Exception {
		BufferedReader fin = new BufferedReader(
				new InputStreamReader(new FileInputStream("D:/A-large.in")));
		PrintWriter fout = new PrintWriter(
				new OutputStreamWriter(new FileOutputStream("D:/A-large.out")));
		String line = fin.readLine();
		int n = Integer.parseInt(line);
		for (int p = 1; p <= n; p++) {
			fout.print("Case #" + p + ": ");
			line = fin.readLine();
			int pos = line.indexOf('/');
			long u = Long.parseLong(line.substring(0, pos));
			long v = Long.parseLong(line.substring(pos+1, line.length()));
			long g = gcd(u, v);
			u /= g;
			v /= g;
			if (!check(v)) {
				fout.println("impossible");
				continue;
			}
			int cnt = 0;
			for (int i = 0; i <= 40; i++) {
				if (u >= v) {
					fout.println(cnt);
					break;
				}
				v >>= 1;
				cnt++;
			}
		}
		fout.close();
		fin.close();
	}
	static long gcd(long u, long v) {
		long w;
		while (v != 0) {
			w = v;
			v = u % v;
			u = w;
		}
		return u;
	}
	static boolean check(long v) {
		if ((v&(v-1)) == 0)
			return true;
		else
			return false;
	}
}
