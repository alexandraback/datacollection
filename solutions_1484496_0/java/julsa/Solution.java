
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
			int[] a= new int[n];
			for ( int i = 0; i < n ; i++){
				a[i]=nextInt();
			}
			out.println("Case #"+k+": ");
			int[] b = new int[2000000];
			boolean bol = false;
			for (int i = 0; i < 1048576; i++){
				int s = 0;
				for (int j=0; j<n; j++ ){
					if ((i & (1 << j)) != 0 ){
						s+=a[j];
					}
				}
				if (b[s] !=0){
					for (int j = 0; j< n; j++){
						if (((b[s] & (1 << j))!=0) && ( ((i & b[s]) & (1<<j)) == 0 )){
							out.print(a[j]+" ");
						}
					}
					out.println();
					for (int j = 0; j< n; j++){
						if (((i & (1 << j))!=0) && ( ((i & b[s]) & (1<<j)) == 0 )){
							out.print(a[j]+" ");
						}
					}
					out.println();
					bol = true;
					break;
				} else {
					b[s] = i;
				}
			}
			if (! bol){
				out.println("Impossible");
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
