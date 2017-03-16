import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class MinesweeperMaster {

	public static void main(String[] args) {
		Scanner sc = null;
		PrintWriter fout = null;

		try {
			sc = new Scanner(new File(args[0]));
			fout = new PrintWriter(new BufferedWriter(new FileWriter("result.txt")));
		} catch(Exception e) {
			System.out.println(e);
		}

		final int T = sc.nextInt();
		for( int t = 1; t <= T; t++ ) {
			final int R = sc.nextInt();
			final int C = sc.nextInt();
			final int M = sc.nextInt();
			final int N = R * C - M;
			final int r = Math.min( R, C );
			final int c = Math.max( R, C );
			int[][] state = new int[r][c];
			boolean pos = false;
			
			if( N == 1 ) {
				pos = true;
				state[0][0] = 2;
			}
			else if( r == 1 ){
				pos = true;
				for( int i = 0; i < N; i++ ) state[0][i] = 1;
				state[0][0] = 2;
			}
			else if( r == 2 ) {
				if( N % 2 == 0 && N / 2 > 1 ) {
					pos = true;
					for( int i = 0; i < N / 2; i++ ) state[0][i] = state[1][i]= 1;
					state[0][0] = 2;
				}
			}
			else if( N % 2 == 0 && N / 2 <= c && N / 2 > 1 ) {
				pos = true;
				for( int i = 0; i < N / 2; i++ ) state[0][i] = state[1][i]= 1;
				state[0][0] = 2;
			}
			else if( N <= 9 ) {
				if( N == 4 ) {
					pos = true;
					state[0][0] = state[0][1] = state[1][0] = state[1][1] = 1;
					state[0][0] = 2;
				}
				if( N == 6 ) {
					pos = true;
					for( int i = 0; i < 2; i++ ) for( int j = 0; j < 3; j++ ) state[i][j] = 1;
					state[0][0] = 2;
				}
				if( N == 8 ) {
					pos = true;
					for( int i = 0; i < 3; i++ ) for( int j = 0; j < 3; j++ ) state[i][j] = 1;
					state[0][0] = 2;
					state[2][2] = 0;
				}
				if( N == 9 ) {
					pos = true;
					for( int i = 0; i < 3; i++ ) for( int j = 0; j < 3; j++ ) state[i][j] = 1;
					state[0][0] = 2;
				}
			}
			else {
				pos = true;
				for( int rr = 3; rr <= r; rr++ ) {
					int cc = ( N + (rr-1) ) / rr;
					if( cc > c ) continue;
					
					int n = N;
					for( int i = 0; i < rr - 1 ; i++ ) {
						for( int j = 0; j < cc; j++ ) {
							state[i][j] = 1;
						}
						n -= cc;
					}
					if( n > 1 ) {
						for( int j = 0; j < n; j++ ) {
							state[rr-1][j] = 1;
						}
					}
					else {
						state[rr-1][0] = state[rr-1][1] = 1;
						state[rr-2][cc-1] = 0;
					}
					state[0][0] = 2;
					
					break;
				}
			}
			
//			System.out.println( "Case #" + t + ":" );
			fout.println( "Case #" + t + ":" );
//			fout.println( R + " " + C + " " + N );
			if( pos == true ) {
				for( int i = 0; i < R; i++ ) {
					for( int j = 0; j < C; j++ ) {
						int i2 = i, j2 = j;
						if( r != R ) {
							i2 = j;
							j2 = i;
						}
						if( state[i2][j2] == 0 ) fout.print( "*" );
						else if( state[i2][j2] == 1 ) fout.print( "." );
						else if( state[i2][j2] == 2 ) fout.print( "c" );
//						if( state[i2][j2] == 0 ) System.out.print( "*" );
//						else if( state[i2][j2] == 1 ) System.out.print( "." );
//						else if( state[i2][j2] == 2 ) System.out.print( "c" );
					}
					fout.println();
//					System.out.println();
				}
			}
			else {
				fout.println( "Impossible" );
//				System.out.println( "Impossible" );
			}
		}

		fout.close();
		sc.close();
	}

}
