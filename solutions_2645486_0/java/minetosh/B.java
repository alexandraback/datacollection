import java.io.*;
import java.util.*;

public class B {
	public static void main(String args[]) {
		try {
			InputStreamReader isr = null;
			try {
				isr = new InputStreamReader(System.in, "UTF-8");
				BufferedReader br = null;
				try {
					br = new BufferedReader(isr);
					new B().go(br);
				} finally {
					if (br != null) br.close();
				}
			} finally {
				if (isr != null) isr.close();
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	public void go(BufferedReader br) throws Exception {
		int num = Integer.parseInt(br.readLine());
		for (int n = 1; n <= num; n++)
			solve(n, br);
	}

	public void solve(int num, BufferedReader br) throws Exception {
		String lines[] = br.readLine().split(" ");
		int E = Integer.parseInt(lines[0]);
		int R = Integer.parseInt(lines[1]);
		int N = Integer.parseInt(lines[2]);
		long v[] = new long[N];
		lines = br.readLine().split(" ");
		for (int i = 0; i < N; i++) {
			v[i] = Long.parseLong(lines[i]);
		}
		
		long table[][] = new long[N + 1][E + 1];
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= E; j++)
				table[i][j] = -1;

		long value = work(E, E, R, v, 0, table);
		System.out.println("Case #" + num + ": " + value);
	}

	public long work(int E, int e, int r, long v[], int n, long table[][]) {
		if (n == v.length)
			return 0;
		if (table[n][e] != -1)
			return table[n][e];
		else {
			long ret = 0;
//			if (n == v.length - 1)
//				ret = v[n] * e;
//			else {
				long values[] = new long[e + 1];
				int nexte;
				nexte = e + r;
				nexte = (nexte >= E)? E: nexte;
				values[0] = work(E, nexte, r, v, n + 1, table);
				for (int i = 1; i <= e; i++) {
					nexte = e - i + r;
					nexte = (nexte >= E)? E: nexte;
					values[i] = i * v[n] + work(E, nexte, r, v, n + 1, table);
				}
				Arrays.sort(values);
				ret = values[e];
//			}
			table[n][e] = ret;
			return ret;
		}
	}
}
