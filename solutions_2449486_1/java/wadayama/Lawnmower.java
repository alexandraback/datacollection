import java.io.*;
import java.util.*;

public class Lawnmower {

	public static void main(String[] args) {
		Scanner sc = null;
		PrintWriter fout = null;
		int T = 0;

		try {
			sc = new Scanner(new File(args[0]));
			fout = new PrintWriter(new BufferedWriter(new FileWriter("result.txt")));
			T = sc.nextInt();
		}
		catch( Exception e ) {
			System.out.println(e);
		}

		for( int a = 1; a <= T; a++ ) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			int[][] h = new int[N][M];
			int[][] H = new int[N][M];
			
			for( int i = 0; i < N; i++ ) {
				for( int j = 0; j < M; j++ ) {
					h[i][j] = sc.nextInt();
					H[i][j] = 100;
				}
			}
			String ret = "YES";
			FORI: for( int i = 0; i < N; i++ ) {				
				for( int j = 0; j < M; j++ ) {
					int v = h[i][j];
					boolean flag = true;
					for( int k = 0; k < N; k++ ) {
						if( h[k][j] > v ) flag = false;
					}
					if( flag ) continue;
					flag = true;
					for( int k = 0; k < M; k++ ) {
						if( h[i][k] > v ) flag = false;
					}
					if( !flag ) {
						ret = "NO";
						break FORI;
					}
				}
			}
//			System.out.println("Case #" + a + ": " + ret );
			fout.println("Case #" + a + ": " + ret );
		}

		fout.close();
		sc.close();
	}

}
