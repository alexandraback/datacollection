import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Diamond implements Runnable {
	int[] M = new int[1005];
	int[][] father = new int[1005][12];
	int[][] nWay = new int[1005][1005];
	boolean stopflag;
	int test;
	
	private void solve() throws IOException {
		int ntest = nextInt();
		for (test = 1; test <= ntest; test++){
			int N = nextInt();
			for (int i = 1; i <= N; i++){
				M[i] = nextInt();
				for (int j = 1; j <= M[i]; j++)
					father[i][j] = nextInt();
			}
			
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					nWay[i][j] = -1;
			stopflag = false;
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					Cal(i, j);
			
			if (!stopflag) writer.println("Case #" + test + ": " + "No");
		}
	}
	
	private int Cal(int x, int y){
		if (stopflag) return 0;
		
		if (nWay[x][y] == -1){
			nWay[x][y] = 0;
			if (x == y) nWay[x][y] = 1;
			else{
				for (int i = 1; i <= M[x]; i++)
					nWay[x][y] += Cal(father[x][i], y);
				if (nWay[x][y] >= 2 && !stopflag){
					stopflag = true; 
					writer.println("Case #" + test + ": " + "Yes");
				}
			}
		}
		
		return nWay[x][y];
	}

	public static void main(String[] args) {
		new Diamond().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(
					new FileInputStream(
							"D:\\workspace\\Code Jam 2012\\Al.in")));
			tokenizer = null;
			writer = new PrintWriter(new File("output.txt"));
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}
