import java.io.*;
import java.util.*;

public class B {

	public static void main(String[] args) {
		Scanner in = null;
		PrintWriter out = null;
		try {
			in = new Scanner(new File("B-small-attempt0.in"));
			out = new PrintWriter("output.txt");
		} catch (Exception e) {
			e.printStackTrace();
		}
		int T = in.nextInt();
		for(int c = 0; c < T; c++){
			out.print("Case #" + (c+1) + ": ");
			int N = in.nextInt();
			int M = in.nextInt();
			int[][] lawn = new int[N][M];
			int[] x = new int[N];
			for(int i = 0; i < N; i++){
				x[i] = 0;
				for(int j = 0; j < M; j++){
					lawn[i][j] = in.nextInt();
					x[i] = Math.max(x[i], lawn[i][j]);
				}
			}			
			int[] y = new int[M];
			for(int j = 0; j < M; j++){
				y[j] = 0;
				for(int i = 0; i < N; i++){
					y[j] = Math.max(y[j], lawn[i][j]);
				}
			}
			boolean ok = true;
			for(int i = 0; i < N; i++){
				for(int j = 0; j < M; j++){
					if(lawn[i][j] != Math.min(x[i], y[j])) ok = false;
				}
			}
			if(ok) out.println("YES");
			else out.println("NO");
		}
		in.close();
		out.close();
	}

}

