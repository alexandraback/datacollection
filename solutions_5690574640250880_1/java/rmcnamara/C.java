import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;


public class C {

	public static void main( String[] args ) throws Exception{
		System.setIn(new FileInputStream("clarge.in"));
		System.setOut(new PrintStream(new File("clarge.out")));
		
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for ( int casenum = 1; casenum <= T; casenum++ ){
			int r = in.nextInt();
			int c = in.nextInt();
			int m = r * c - in.nextInt();
			
			System.out.print("Case #" + casenum + ": ");
			char[][] ret = new char[r][c];
			for ( int i = 0; i < r; i++ ){
				Arrays.fill(ret[i], '*');
			}
			int open = 0;
			
			boolean fail = false;
			if ( m > r * c ){
				fail = true;
			}
			else{
				if ( r == 1 || c == 1 ){
					for ( int i = 0; open != m && i < r; i++ ){
						for ( int j = 0; open != m && j < c; j++ ){
							ret[i][j] = '.';
							open++;
						}
					}
				}
				else
				{
					if ( r == 2 || c == 2 ){
						if ( m % 2 == 1 && m > 1 ){
							fail = true;
						}
					}
					
					if ( m % 2 == 1 && m > 1 && m < 9 ){
						fail = true;
					}
					else if ( m == 2 ){
						fail = true;
					}
					else if ( m > 1 &&  !fail ){
						// create the r
						for ( int i = 0; m >= 2 && i < Math.max(r, c);i++){
							if ( i < r ){
								// horiz
								ret[i][0] = '.';
								ret[i][1] = '.';
								m-=2;
							}
							if ( i < 2 || m < 2 ) continue;
							if ( i < c ){
								// vert
								ret[0][i] = '.';
								ret[1][i] = '.';
								m-=2;
							}
						}
						// fill in
						for ( int i = 2; m > 0 && i < r; i++ ){
							for ( int j = 2; m > 0 && j < c; j++){
								ret[i][j] = '.';
								m--;
							}
						}
					}
				}
			}
			ret[0][0] = 'c';
			System.out.println();
			if ( fail ){
				System.out.println("Impossible");
			}
			else{
				for ( int i = 0; i < r; i++ ){
					System.out.println(new String(ret[i]));
				}
			}
		}
	}
}
