package qualification2013;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

@SuppressWarnings("unused")
class B {

	private boolean log = true;
	
	private static final String FILE_PATH 	= "src//qualification2013//";
	private static final String FILE_NAME 	= "B-large";
	
	private static final File INPUT_FILE 	= new File(FILE_PATH + FILE_NAME + ".in");
	private static final File OUTPUT_FILE 	= new File(FILE_PATH + FILE_NAME + ".out");
	
	private Scanner sc;
	private PrintWriter pw;
	
	private B() throws IOException {
		sc = new Scanner(INPUT_FILE);
		pw = new PrintWriter(OUTPUT_FILE);
				
		final int C = sc.nextInt();
		
		for (int i = 1; i <= C; i++) {
			write(String.format("Case #%d: ", i));
			solve();
			write("\n");
		}
		
		pw.flush();
		pw.close();
		sc.close();
		System.out.println("Done!");
	}
	
	private void solve() {
		final int N = sc.nextInt();
		final int M = sc.nextInt();
		
		int[][] lawn = new int[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				lawn[i][j] = sc.nextInt();
			}
		}
		if (N == 1 || M == 1) { write("YES"); return;}
		
		
		int[] rowMax = new int[N];
		for (int i = 0; i < N; i++) {
			rowMax[i] = max(lawn[i]);
		}
		
		int[] columnMax = new int[M]; 
		for (int i = 0; i < M; i++) {
			int[] tmp = new int[N];
			for (int j = 0; j < N; j++) {
				tmp[j] = lawn[j][i];
			}
			columnMax[i] = max(tmp);
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (lawn[i][j] < columnMax[j] && lawn[i][j] < rowMax[i]) {
					write("NO");
					return;
				}
			}
		}
		
		write("YES");
	}
	
	private int max(int... num) {
		int max = Integer.MIN_VALUE;
		for (int i : num) {
			if (i > max) max = i;
		}
		return max;
	}
	
	private void write(String s) {
		pw.write(s);
		if(log) System.out.print(s);
	}
	
	private void write(int i) 	{ write(Integer.toString(i)); }
	private void write(long i)  { write(Long.toString(i)); }
	
	public static void main(String[] args) {
		try {
			new B();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
