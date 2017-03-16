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
		int A = Integer.parseInt(lines[0]);
		int B = Integer.parseInt(lines[1]);
		int K = Integer.parseInt(lines[2]);

		int count = 0;
		for (int i = 0; i < A; i++)
			for (int j = 0; j < B; j++)
				if ((i & j) < K)
					count++;
		System.out.println("Case #" + num + ": " + count);
	}
}
