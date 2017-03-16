import java.io.*;
import java.util.*;

public class C{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int N = Integer.parseInt(br.readLine());

		for(int p2 = 0; p2 < N; p2++) {
			String[] s = br.readLine().split(" ");

			n = Integer.parseInt(s[0]);
			int m = Integer.parseInt(s[1]);
			permAt = -1;

			String[] z = new String[n];

			for(int i = 0; i < n; i++) z[i] = br.readLine();


			boolean[][] d = new boolean[n][n];

			for(int i = 0; i < m; i++) {
				s = br.readLine().split(" ");

				int a = Integer.parseInt(s[0]);
				int b = Integer.parseInt(s[1]);

				d[a-1][b-1] = true;
				d[b-1][a-1] = true;
			}


			long nfact = 1;
			for(int i = 1; i <= n; i++) nfact *= i;


			String best = "sad";

			Loop: while(permAt + 1 < nfact) {
				int[] p = nextPerm();
				int[] v = new int[n];
				int at = 1;
				v[0] = p[0];

				Jurg: for(int i = 1; i < n; i++) {
					for(int j = at-1; j >= 0; j--) {
						if(d[v[j]][p[i]]) {
							v[j+1] = p[i];
							at = j+2;
							continue Jurg;
						}
					}
					continue Loop;
				}

				String st = "";
				for(int i = 0; i < n; i++) st = st + z[p[i]];

				if(best.equals("sad") || best.compareTo(st) > 0) best = st;
			}

			System.out.println(permAt);
			pw.println("Case #" + (p2+1) + ": " + best);
		}


		pw.flush();
		pw.close();

	}

	public static long permAt = -1;
	public static int n;

	public static int[] nextPerm() {
		permAt++;
		long a = permAt;

		int[] ret = new int[n];

		boolean[] u = new boolean[n];

	 	Dame: for(int i = n; i > 0; i--) {
			long b = a % i;
			a /= i;

			for(int j = 0; j < n; j++) {
				if(!u[j]) {
					if(b>0) b--;
					else {
						ret[i-1] = j;
						u[j] = true;
						continue Dame;
					}
				}
			}
		}

		return ret;
	}
}