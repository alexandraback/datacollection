import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class GoodLuck {

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
			int R = sc.nextInt();
			int N = sc.nextInt();
			int M = sc.nextInt();
			int K = sc.nextInt();

//			System.out.println("Case #" + a + ":" );
			fout.println("Case #" + a + ":");

			for( int r = 0; r < R; r++ ) {
				int[] mul = new int[K];
				for( int i = 0; i < K; i++ ) mul[i] = sc.nextInt();
				
				int[][][] score = new int[M+1][M+1][M+1];

				for( int n = 0; n < K; n++ ) {
					for( int i = 2; i <= M; i++ ) {
						for( int j = i; j <= M; j++ ) {
							for( int k = j; k <= M; k++ ) {
								if( mul[n] == i * j * k ) {
									if( i == j && j == k ) score[i][j][k]++;
									else if( i == j || j == k || k == i ) score[i][j][k] += 3;
									else score[i][j][k] += 6;
								}
							}
						}
					}
				}

				int ms = 0;
				int mi = 2, mj = 2, mk = 2;
				
				for( int i = 2; i <= M; i++ ) {
					for( int j = i; j <= M; j++ ) {
						for( int k = j; k <= M; k++ ) {
							if( score[i][j][k] > ms ) {
								ms = score[i][j][k];
								mi = i;
								mj = j;
								mk = k;
							}
						}
					}
				}
				
//				System.out.println( "" + mi + mj + mk );
				fout.println( "" + mi + mj + mk );
			}
		}

		fout.close();
		sc.close();
	}
}
