import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class Elf {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);
		int cases = sc.nextInt();
		PrintWriter out = new PrintWriter(System.out);
		
		double[] x = new double[43];
		x[0] = 1;
		for(int i=1; i<43; i++){
			x[i] = x[i-1]/2;
		}

		for(int cas = 1; cas<=cases; cas++){
			String[] tok = sc.next().split("/");
			long p = Long.parseLong(tok[0]);
			long q = Long.parseLong(tok[1]);
			double cur =  (double)p/(double)q;
			
			int first = Integer.MAX_VALUE;
			
			for(int i=0; i<=40; i++){
				if(cur>=x[i]) {
					cur-=x[i];
					first =  Math.min(first, i);
				}
			}
			
			if(Long.bitCount(q)== 1){
			//if(Math.abs(cur-0.0)<1E-9){
				out.printf("Case #%d: %d\n",cas,first);
			} else {
				out.printf("Case #%d: impossible\n",cas);
			}
		}
		out.flush();
		out.close();
	}

	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble(){
			return Double.parseDouble(next());
		}
	}

}
