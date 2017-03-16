import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Jardin {
	
	static boolean check(int[][] jar, int row, int col, int n, int m){
		boolean can = true;
			
		for(int i=0; i<n; i++){
			if(jar[i][col]>jar[row][col]){
				can = false;
			}
		}
		
		if (can) return true;
		
		can = true;
		for(int i=0; i<m; i++){
			if(jar[row][i]>jar[row][col]){
				can = false;
			}
		}
		if (can) return true;		
		
		return false;
	}
	
	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);
		
		int cases = sc.nextInt();
		
		for(int c = 0; c<cases; c++){
			
			int n = sc.nextInt(), m = sc.nextInt();
			
			int[][] jar = new int[n][m];
			
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					jar[i][j] = sc.nextInt();
				}
			}
			
			boolean imp = false;
			
			for(int i=0; i<n && !imp; i++){
				for(int j=0; j<m; j++){
					if(!check(jar,i,j,n,m)){
						imp = true;
						break;
					}
				}
			}
			
			if(imp){
				System.out.printf("Case #%d: NO\n", c+1);
			} else {
				System.out.printf("Case #%d: YES\n", c+1);
			}		
		}
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
