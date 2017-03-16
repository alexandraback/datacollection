import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class two {
	
	static final String name = "b-small-attempt1";
	
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new File(name + ".in"));
		PrintWriter out = new PrintWriter(new File(name + ".out"));
		
		int tc = in.nextInt();
		for(int i = 1; i <= tc; i++){
			out.print("Case #" + i + ": ");
			solve(in, out);
		}
		
		in.close();
		out.close();
	}

	private static void solve(Scanner in, PrintWriter out) {
		int B = in.nextInt();
		long N = in.nextLong();
		
		if(Math.pow(2, B - 2) < N){
			out.println("IMPOSSIBLE");
			return;
		}
		out.println("POSSIBLE");
		
		boolean[][] ar = new boolean[B][B];
		for(int i = 0; i < B - 1; i++){
			if(Math.pow(2, B - i - 2) > N && Math.pow(2, B - i - 3) < N){
				String bin = reverse(Long.toBinaryString(N));
				for(int j = 0; j < bin.length(); j++){
					if(bin.charAt(j) == '1'){
						ar[i][B - j - 2] = true;
					}
				}
			}
			else if(Math.pow(2, B - i - 2) > N){
				ar[i][i + 1] = true; 
			}else{
				for(int j = i + 1; j < B; j++){
					ar[i][j] = true;
				}
			}
		}
		
		print(ar, out);
	}
	
	public static String reverse(String s){
		String t = "";
		for(int i = 0; i < s.length(); i++){
			t = s.charAt(i) + t;
		}
		return t;
	}
	
	public static void print(boolean[][] ar, PrintWriter out){
		for(int i = 0; i < ar.length; i++){
			for(int j = 0; j < ar[i].length; j++){
				out.print(ar[i][j] ? "1" : "0");
			}
			out.println();
		}
	}
	
	public static int possible(int B, int cur, boolean[][] paths){
		if(cur == B - 1){
			return 1;
		}
		int tot = 0;
		for(int i = 0; i < B; i++){
			if(paths[cur][i]){
				tot += possible(B, i, paths);
			}
		}
		return tot;
	}
	
	public static int[][] paths(int B, long N, int cur, boolean[] visited){
		int[][] ret = new int[(int)N][B + 1];
		if(cur == B - 1){
			ret[0][0] = 2;
			ret[0][1] = B - 1;
			return ret;
		}
		int c = 0;
		visited[cur] = true;
		for(int i = 0; i < B; i++){
			if(!visited[i]){
				int[][] ret1 = paths(B, N, i, visited);
				for(int j = 0; j < ret1.length && ret1[j][0] != 0; j++){
					ret1[j][ret1[j][0]] = cur;
					ret1[j][0]++;
					ret[c++] = ret1[j];
					if(c == N){
						return ret;
					}
				}
			}
		}
		return ret;
	}
}
