import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;


public class C_small {
	static BufferedReader in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader(new File(
				"/Users/yfo/Downloads/c1.in")));
		out = new PrintWriter(new FileWriter(new File(
				"/Users/yfo/Downloads/c1_out.in")));

		int T = Integer.parseInt(in.readLine());
		for (int t = 0; t < T; t++) {
			System.out.print((t + 1) + ": ");
			
			String[] tok = rst();
			int C = Integer.parseInt(tok[0]);
			int D = Integer.parseInt(tok[1]);
			int V = Integer.parseInt(tok[2]);
			
			int[]a = rit();
			boolean[]can = new boolean[V+1];
			
			for (int i=1;i<(1<<D);i++) {
				int x = i, pos = 0, sum = 0;
				while(x>0) {
					if (x%2==1) {
						sum+=a[pos];
					}
					x/=2;
					pos++;
				}
				if (sum<=V) can[sum]=true;
			}
			
			int add = 0;
			List<Integer> newVal = new ArrayList<Integer>();
			for (;;) {
				int pos = 1;
				while (pos<=V && can[pos]) pos++;
				if (pos>V) break;
				add++;
				can[pos] = true;
				for (int i=1;i<=V;i++) {
					if (i!=pos && i+pos<=V && can[i]) {
						newVal.add(i+pos);
					}
				}
				for (Integer x : newVal) {
					can[x]=true;
				}
			}
			
			
			out.println("Case #" + (t + 1) + ": "+add);
			System.out.println(add);
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
