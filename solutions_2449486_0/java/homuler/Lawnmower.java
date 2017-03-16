package gcj_2014_pr;
import java.util.*;
import java.io.*;

public class Lawnmower {
	public boolean judge(int[][] map){
		int n = map.length;
		int m = map[0].length;
		boolean[][] cut = new boolean[n][m];
		for(int i = 0; i < n*m; i++){
			int a = 0;
			int b = 0;
			int max = -1;
			for(int j = 0; j < n; j++){
				for(int k = 0; k < m; k++){
					if( !cut[j][k] && map[j][k] > max ){
						a = j;
						b = k;
						max = map[a][b];
					}
				}
			}
	//		writer.println(a + ", " + b + ", max = " + map[a][b]);
			boolean flag = true;
			for(int j = 0; j < m; j++){
				if( cut[a][j] && map[a][j] > map[a][b] ){
					flag = false;
				}
			}
			if( !flag ){
				for(int j = 0; j < n; j++){
					if( cut[j][b] && map[j][b] > map[a][b] ){
						return false;
					}
				}
			}
			cut[a][b] = true;
		}
		return true;
	}
	public void solve() throws IOException {
		int t = nextInt();
		for(int i = 0; i < t; i++){
			int n = nextInt();
			int m = nextInt();
			int[][] map = new int[n][m];
			for(int j = 0; j < n; j++){
				for(int k = 0; k < m; k++){
					map[j][k] = nextInt();
				}
			}
			if( judge(map) ){
				writer.println("Case #" + (i+1) + ": YES");
			} else {
				writer.println("Case #" + (i+1) + ": NO");
			}
		}
	}

	public static void main(String[] args) throws IOException {
		new Lawnmower().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() throws IOException {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			writer = new PrintWriter(System.out);
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
}
