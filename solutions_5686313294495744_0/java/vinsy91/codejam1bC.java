import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;


public class codejam1bC {
	public static void main(String[] args) {
		int T = in.nextInt();
		for(int t = 0; t < T; t++) {
			List<String> l1 = new ArrayList<>();
			List<String> l2 = new ArrayList<>();
			int ans = 0;
			int n = in.nextInt();
			for(int i = 0; i < n; i++) {
				String s1 = in.next();
				String s2 = in.next();	
				l1.add(s1);
				l2.add(s2);
			}
			for(int i = 0; i < n; i++) {
				boolean flagFirst = false;
				boolean flagSecond = false;
				for(int j = 0; j < n; j++) {
					if(j != i && (!l1.get(i).equals(l1.get(j)))) {
						flagFirst = true;
					}
				}
				for(int j = 0; j < n; j++) {
					if(j != i && (!l2.get(i).equals(l2.get(j)))) {
						flagSecond = true;
					}
				}
				if(flagFirst && flagSecond == true) {
					ans++;
				}
			}
		
			
			System.out.println("Case #"+(t+1)+": "+ans);
		
		
	}
	}
	
	

	//------------ fast input/ouput--------//
	
	public static Object returnFirst(Object x, Object y) {
		return x;
	}

	public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	public static FastScanner in = new FastScanner();

	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	} //--fast i/o ends here----//
	

}
