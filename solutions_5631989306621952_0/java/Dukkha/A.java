import java.io.*;

public class A {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			char[] cc = br.readLine().toCharArray();
			int n = cc.length;
			char[] max = new char[n];
			max[0] = cc[0];
			for (int i = 1; i < n; i++)
				max[i] = max[i - 1] > cc[i] ? max[i - 1] : cc[i];
			int p = 0, q = n - 1;
			char[] aa = new char[n];
			for (int i = n - 1; i >= 0; i--)
				if (cc[i] == max[i])
					aa[p++] = cc[i];
				else
					aa[q--] = cc[i];
			pw.println("Case #" + t + ": " + new String(aa));
		}
		pw.close();
	}
}
