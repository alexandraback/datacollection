import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.BufferedOutputStream;
import java.io.FileOutputStream;


public class OminousOmino {
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		//System.setIn(new FileInputStream("D-large.in"));
		//System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream("OminousOmino_large.out")), true));
		int[][][] m = new int[5][5][5]; 
		
		for(int i=1 ; i<5 ; i++) {
			for(int j=1 ; j<5 ; j++) {
				for(int k=1; k<5; k++) {
					if( i == 1 ) {
						if( j==1 && k==1) {
							m[i][j][k] = 1;
						} else {
							m[i][j][k] = 2;
						}
					} else if( i == 2 ) {
						if( j*k <= 3 ) {
							m[i][j][k] = 1;
						} else {
							m[i][j][k] = 2;
						}
					} else if ( i == 3 ) {
						if( j == 1  || k == 1) {
							m[i][j][k] = 1;
						} else if( j == 2  && k == 2) {
							m[i][j][k] = 1;
						} else {
							m[i][j][k] = 2;
						}
					} else if ( i == 4 ) {
						m[i][j][k] = 1;
					}					
				}
			}
		}
		
		m[2][1][3] = 1;
		m[2][3][1] = 1;

		m[4][3][4] = 2;
		m[4][4][3] = 2;
		m[4][4][4] = 2;

		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int totalCaseNumber = Integer.parseInt( reader.readLine() );
		for(int caseNo=1 ; caseNo<=totalCaseNumber ; caseNo++ ) {
			String line = reader.readLine();
			String[] part = line.split(" ");
			int x = Integer.parseInt(part[0]);
			int r = Integer.parseInt(part[1]);
			int c = Integer.parseInt(part[2]);
			
			
			boolean res = true;

					    if (x >= 7 ) {
					        res = false;
					    } else if (x > r && x > c ) {
					        res = false;
					    } else if( r * c % x != 0 ) {
					        res = false;
					    } else if( (x + 1) / 2 > Math.min(r, c) ) {
					        res = false; 
					    } else if (x <=  3) {
					        res = true;
					    } else if (x == 4) {
					        res = Math.min(r, c) > 2;
					    } else if (x == 5) {
					        res = !(Math.min(r, c) == 3 && Math.max(r, c) == 5);
					    } else if ( x == 6 ) {
					        res = Math.min(r, c) > 3;
					    }
					    System.out.println("Case #" + caseNo + ": " + (!res ? "RICHARD" : "GABRIEL"));
			//int val = m[x][r][c];
			//System.out.println("Case #" + caseNo + ": " + (val == 1 ? "RICHARD" : "GABRIEL"));
		}
		reader.close();
	}
}
