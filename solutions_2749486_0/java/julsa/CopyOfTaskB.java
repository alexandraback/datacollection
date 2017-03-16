import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class CopyOfTaskB {

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	void run() throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		String s1 = br.readLine();
		st = new StringTokenizer(s1);
		int t = Integer.parseInt(st.nextToken());
		BigInteger[] f = new BigInteger[5001];
		f[0] = BigInteger.ONE;
		f[1] = BigInteger.ONE;
		for (int i = 2; i <= 5000; i++) {
			f[i] = new BigInteger(i + "");
			f[i] = f[i].multiply(f[i - 1]);
		}
		for (int i1 = 1; i1 <= t; i1++) {
			out.print("Case #" + i1 + ": ");
			s1 = br.readLine();
			st = new StringTokenizer(s1);
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			if (x > 0) {
				for (int i = 0; i < x; i++) {
					out.print("WE");
				}
			} else {
				for (int i = 0; i < -x; i++) {
					out.print("EW");
				}
			}
			if (y > 0) {
				for (int i = 0; i < y; i++) {
					out.print("SN");
				}
			} else {
				for (int i = 0; i < -y; i++) {
					out.print("NS");
				}
			}
			out.println();
		}

		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new CopyOfTaskB().run();
	}

}