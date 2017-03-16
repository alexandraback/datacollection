import java.io.*;
import java.util.*;

public class HallOfMirrors {

	public static void main(String[] args) {
		Scanner sc = null;
		PrintWriter fout = null;
		int t = 0;

		try {
			sc = new Scanner(new File(args[0]));
			fout = new PrintWriter(new BufferedWriter(new FileWriter("result.txt")));
			t = sc.nextInt();
		} catch(Exception e) {
			System.out.println(e);
		}
		
		for( int i = 0; i < t; i++ ) {
			int h = sc.nextInt();
			int w = sc.nextInt();
			int d = sc.nextInt();
			sc.nextLine();
			
			int[][] room = new int[h][w];
			int x0 = 0, y0 = 0;
			for( int y = 0; y < h; y++ ) {
				String tmp = sc.nextLine();
				for( int x = 0; x < w; x++ ) {
					switch( tmp.charAt(x) ) {
					case '#':
						room[y][x] = 1;
						break;
					case 'X':
						room[y][x] = 2;
						x0 = x;
						y0 = y;
						break;
					}
				}
			}
			
			int right = 2 * ( w - x0 - 1 ) - 1;
			int left = 2 * x0 - 1;
			int bottom = 2 * ( h - y0 - 1 ) - 1;
			int top = 2 * y0 - 1;
			int[][] tmp = new int[2*d+1][2*d+1];

			for( int y = 0; y <= d; y++ ) {
				for( int x = 0; x <= d; x++ ) {
					boolean bok = false, tok = false, lok = false, rok = false;
					int ytmp = y % ( bottom + top );
					int xtmp = x % ( left + right );
					
					if( ytmp == bottom || ytmp == 0 ) bok = true;
					if( ytmp == top || ytmp == 0 ) tok = true;
					if( xtmp == right || xtmp == 0 ) rok = true;
					if( xtmp == left || xtmp == 0 ) lok = true;
					
					if( bok && rok ) tmp[d+y][d+x] = 1;
					if( bok && lok ) tmp[d+y][d-x] = 1;
					if( tok && rok ) tmp[d-y][d+x] = 1;
					if( tok && lok ) tmp[d-y][d-x] = 1;
				}
			}
			
			int ret = 0;
			for( int y = 0; y <= d; y++ ) {
				if( y * y > d * d ) continue;
				for( int x = 0; x <= d; x++ ) {
					if( x == 0 && y == 0 ) continue;
					if( x * x + y * y > d * d ) continue;
					
					int gcdtmp = gcd( x, y );
					int xm = x / gcdtmp, ym = y / gcdtmp;
					
					if( tmp[d+y][d+x] == 1 ) {
						ret++;
						for( int ratio = 1; ratio * Math.max( xm, ym ) <= d; ratio++ ) {
							tmp[d+ratio*ym][d+ratio*xm] = 4;
						}
						tmp[d+y][d+x] = 3;
					}
					if( tmp[d+y][d-x] == 1 ) {
						ret++;
						for( int ratio = 1; ratio * Math.max( xm, ym ) <= d; ratio++ ) {
							tmp[d+ratio*ym][d-ratio*xm] = 4;
						}
						tmp[d+y][d-x] = 3;
					}
					if( tmp[d-y][d+x] == 1 ) {
						ret++;
						for( int ratio = 1; ratio * Math.max( xm, ym ) <= d; ratio++ ) {
							tmp[d-ratio*ym][d+ratio*xm] = 4;
						}
						tmp[d-y][d+x] = 3;
					}
					if( tmp[d-y][d-x] == 1 ) {
						ret++;
						for( int ratio = 1; ratio * Math.max( xm, ym ) <= d; ratio++ ) {
							tmp[d-ratio*ym][d-ratio*xm] = 4;
						}
						tmp[d-y][d-x] = 3;
					}
				}
			}
			tmp[d][d] = 2;
			for( int y = 0; y < tmp.length; y++ ) {
				for( int x = 0; x < tmp.length; x++ ) {
					//System.out.print(tmp[y][x]);
				}
				//System.out.println();
			}
			
//			System.out.println("Case #" + (i+1) + ": " + ret);
			fout.println("Case #" + (i+1) + ": " + ret);
		}

		fout.close();
		sc.close();
	}

	static private int gcd( int a, int b ) {
		if( b == 0 ) return a;
		return gcd( b, a % b );
	}
}
