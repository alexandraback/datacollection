
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
			int s = 0;
			int[] a= new int[n];
			for ( int i = 0; i < n ; i++){
				a[i]=nextInt();
				s+=a[i];
			}
			out.print("Case #"+k+": ");
			
			for (int i = 0; i < n; i++){
				double l=0;
				double r= 1;
				while (r-l>0.00000001){
					double m = (l+r)/2;
					double p = a[i]+s*m;
					double x=1-m;
					for (int j=0; j<n; j++){
						if ((j !=i) && (a[j]<p)){
							x = x - (p-a[j])/s;
						}
					}
					if ( x<=0){
						r = m;
					} else {
						l = m;
					}
				}
				out.print((1.0*((int)(r*100000000)))/1000000+" ");
			}
			out.println();
			
			
			
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
