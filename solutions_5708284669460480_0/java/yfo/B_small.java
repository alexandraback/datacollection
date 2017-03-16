import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class B_small {
	static BufferedReader in;
	static PrintWriter out;
	public static int cnt[]; 
	static int K, L, S;
	static String alphabet;
	static String target;
	
	public static void solve(String pref) {
		int total=0;
		int len = pref.length();
		if (len==S) {
			for (int i=0;i<=len-L;i++) {
				boolean found = true;
				for (int j=0;j<L;j++) {
					if (pref.charAt(i+j)!=target.charAt(j)) {
						found = false;
						break;
					}
				}
				if (found) total++;
			}
			cnt[total]++;
		} else {
			for (int i=0;i<alphabet.length();i++) {
				solve(pref+alphabet.charAt(i));
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader(new File(
				"/Users/yfo/Downloads/b1.in")));
		out = new PrintWriter(new FileWriter(new File(
				"/Users/yfo/Downloads/b1_out.in")));

		int T = Integer.parseInt(in.readLine());
		for (int t = 0; t < T; t++) {
			System.out.print((t + 1) + ": ");
			
			String[] tok = rst();
			K = Integer.parseInt(tok[0]);
			L = Integer.parseInt(tok[1]);
			S = Integer.parseInt(tok[2]);
			
			alphabet = in.readLine();
			target = in.readLine();

			cnt = new int[8];
			solve("");
			int all = (int)Math.pow(K, S);
			int max = 0;
			for (int i=1;i<8;i++) {
				if (cnt[i]>0) max = i;
			}
			
			double ans = 0.0D;
			if (max > 0) {
				double exp = 0.0D;
				for (int i=1;i<8;i++) {
					exp+=((double)cnt[i]/(double)all)*i;
				}
				ans = max-exp;
			}
			
			out.println("Case #" + (t + 1) + ": "+ans);
			System.out.println(ans);
		}

		in.close();
		out.close();
	}

	static int ri() throws IOException {
		return Integer.parseInt(in.readLine());
	}

	static long rl() throws IOException {
		return Long.parseLong(in.readLine());
	}

	static String[] rst() throws IOException {
		return in.readLine().split(" ");
	}

	public static int[] rit() throws IOException {
		String[] tok = in.readLine().split(" ");
		int[] res = new int[tok.length];
		for (int i = 0; i < tok.length; i++) {
			res[i] = Integer.parseInt(tok[i]);
		}
		return res;
	}

	public static long[] rlt() throws IOException {
		String[] tok = in.readLine().split(" ");
		long[] res = new long[tok.length];
		for (int i = 0; i < tok.length; i++) {
			res[i] = Long.parseLong(tok[i]);
		}
		return res;
	}
}
