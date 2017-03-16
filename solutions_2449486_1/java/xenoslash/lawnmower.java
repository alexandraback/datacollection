package qual;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class lawnmower {
	private static BufferedReader f;
	private static PrintWriter out;
	public static void main(String[] args) throws IOException{	
		//f = new BufferedReader(new InputStreamReader(System.in));
		//out = new PrintWriter(System.out);
	   
		f = new BufferedReader(new FileReader("B-large.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("B-large.out")));
		int N = Integer.parseInt(f.readLine());
		for(int i=1; i<=N;i++){
			out.write("Case #" + i+": ");
			solve();
		}
		out.close();
	}
	
	public static void solve() throws IOException{
		String[] toks = f.readLine().split(" ");
		int N = Integer.parseInt(toks[0]);
		int M = Integer.parseInt(toks[1]);
		
		int[][] arr = new int[N][M];
		for(int row=0;row<N;row++){
			String[] nums = f.readLine().split(" ");
			for(int col=0;col<M;col++){
				arr[row][col] = Integer.parseInt(nums[col]);
			}
		}
		
		for(int row=0;row<N;row++){
			for(int col=0;col<M;col++){
				boolean isRowCut = true;
				boolean isColCut = true;
				for(int r=0; r<N;r++){
					if(arr[r][col] > arr[row][col]){
						isRowCut = false;
						break;
					}
				}
				for(int c=0;c<M;c++){
					if(arr[row][c] > arr[row][col]){
						isColCut = false;
						break;
					}
				}
				if(!isRowCut && !isColCut){
					out.write("NO\n");
					return;
				}
			}
		}
		
		out.write("YES\n");
	}
	
	

public static class FastScanner {
	BufferedReader br;
	StringTokenizer st;

	public FastScanner(String s) {
		try {
			br = new BufferedReader(new FileReader(s));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public FastScanner() {
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	String nextToken() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}

}
