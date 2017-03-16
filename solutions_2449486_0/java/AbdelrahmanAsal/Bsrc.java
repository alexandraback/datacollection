import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class B {

	void run() throws Exception {
		BufferedReader bfd = new BufferedReader(
				new InputStreamReader(System.in));
		int tc = Integer.parseInt(bfd.readLine());
		StringTokenizer tk;
		for(int t = 1; t <= tc; ++t) {
			System.out.print("Case #"+ t +": ");
			tk = new StringTokenizer(bfd.readLine());
			int n = Integer.parseInt(tk.nextToken());
			int m = Integer.parseInt(tk.nextToken());
			int arr[][] = new int[n][m];
			for (int i = 0; i < n; ++i) {
				tk = new StringTokenizer(bfd.readLine());
				for(int j = 0; j < m; ++j) {
					arr[i][j] = Integer.parseInt(tk.nextToken()); 
				}
			}
			boolean ok = true;
			int mxRow[] = new int[n];
			for(int i = 0; i < n; ++i) {
				int mx = 0;
				for(int j = 0; j < m; ++j) {
					mx = Math.max(mx, arr[i][j]);
				}
				mxRow[i] = mx;
			}
			int mxCol[] = new int[m];
			for(int i = 0; i < m; ++i) {
				int mx = 0;
				for(int j = 0; j < n; ++j) {
					mx = Math.max(mx, arr[j][i]);
				}
				mxCol[i] = mx;
			}
			L: for(int i = 0; i < n; ++i) {
				for(int j = 0; j < m; ++j) {
					if(arr[i][j] >= mxRow[i] || arr[i][j] >= mxCol[j]);
					else {
						ok = false;
						break L;
					}
				}
			}
			if(ok) System.out.println("YES");
			else System.out.println("NO");
		}

	}
	
	public static void main(String[] args) throws Exception {
		new B().run();
	}

}


