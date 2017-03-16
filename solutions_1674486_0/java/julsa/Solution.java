
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution {
	
	
	void solve() throws IOException {
		int t = nextInt();
		for ( int k=1; k <= t; k++){
			int n = nextInt();
			int[][] a= new int[n][];
			for ( int i = 0; i < n ; i++){
				int x = nextInt();
				a[i] = new int[x+1];
				a[i][0]=x;
				for( int j = 1; j <= x; j++){
					a[i][j]=nextInt()-1;
				}
			}
			out.print("Case #"+k+": ");
			boolean bol = false;

			for ( int i = 0; i < n; i++){
				boolean[] b = new boolean[n+1];
				int[] c = new int[2*n];
				int l = 0;
				int h=1;
				c[0]=i;
				while ((h-l>0) && (!bol)){
					for ( int j = 1; j <= a[c[l]][0]; j++){
						if (b[a[c[l]][j]]){
							bol=true;
						} else {
							b[a[c[l]][j]]=true;
							c[h]=a[c[l]][j];
							h++;
						}
					}
					l++;
				}
				if (bol){
					break;
				}
			
			}
			if (bol) {
				out.println("Yes");
			} else {
				out.println("No");
			}
			
			
			
		}		

	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String s = br.readLine();
			if (s == null) {
				return "-1";
			}
			st = new StringTokenizer(s);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	void run() throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		solve();
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Solution().run();
	}
}
