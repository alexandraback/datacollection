import java.util.*;
import java.io.*;

public class B {
	
	private static String rush(final int N, int L1[], int L2[]) {
		int done[] = new int[N];
		int cnt = 0;
		int stars = 0;
		int left = N;
		for(;;) {
			for(boolean l2 = true; l2; ) {
				l2 = false;
				for(int i = 0; i < N; i++)
					if(done[i] < 2 && L2[i] <= stars) {
						stars += 2 - done[i];
						done[i] = 2;
						l2 = true;
						cnt++;
						if(--left == 0)
							return Integer.toString(cnt);
					}
			}
			int j = -1, m2 = -1;
			for(int i = 0; i < N; i++)
				if(done[i] == 0 && L1[i] <= stars)
					if(L2[i] > m2) {
						m2 = L2[i];
						j = i;
					}
			if(j < 0)
				return "Too Bad";
			stars += done[j] = 1;
			cnt++;
		}
	}
	
	public static void main(String args[]) throws Exception {
		//String fileName = "B.in";
		//String fileName = "B-small-attempt0.in";
		String fileName = "B-large.in";
		BufferedReader in = new BufferedReader(new FileReader(fileName));
		PrintStream out = new PrintStream(fileName.substring(0, fileName.lastIndexOf('.')) + ".out");
		int T = Integer.parseInt(in.readLine());
		for(int i = 1; i <= T; i++) {
			out.print("Case #" + i + ": ");
			final int N = Integer.parseInt(in.readLine());
			final int L1[] = new int[N], L2[] = new int[N];
			for(int n = 0; n < N; n++) {
				StringTokenizer st = new StringTokenizer(in.readLine());
				L1[n] = Integer.parseInt(st.nextToken());
				L2[n] = Integer.parseInt(st.nextToken());
			}
			out.println(rush(N, L1, L2));
		}
		out.close();
		in.close();
	}
}