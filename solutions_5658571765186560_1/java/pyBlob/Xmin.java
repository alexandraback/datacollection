

import java.util.Scanner;

import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Double.parseDouble;
import static java.lang.Float.parseFloat;

public class Xmin {
	public static Scanner s = new Scanner(System.in);
	
	public static void main(String[] args) {
		/*for (int X=1 ; X<=4 ; X++) {
			for (int C=1 ; C<=4 ; C++) {
				for (int R=1 ; R<=C ; R++) {
					System.out.print("X="+X+", C="+C+", R="+R+": ");
					
					run(X, R, C);
				}
			}
			System.out.println();
		}*/
		
		int n = parseInt(s.nextLine());
		
		for (int i=1 ; i<=n ; i++) {
			System.out.print("Case #" + i + ": ");
			
			String line[] = s.nextLine().split(" ");
			
			int X = parseInt(line[0]);
			int R = parseInt(line[1]);
			int C = parseInt(line[2]);
			
			run(X, R, C);
		}
	}
	
	public static void run(int X, int R, int C) {
		// R=min, C=max
		if (C<R) {
			int t = R;
			R = C;
			C = t;
		}
		
		boolean win;
		
		if (R*C==X) {
			win = true;
		} else if (((R*C)%X) != 0 || C<X) {
			// R*C not multiple of X -> loose
			// big side C smaller than X -> loose
			win = false;
		} else {
			// always R <= C && C >= X
			// RC multiple of X
			
			if (X == 1) {
				win = true; // -> win
			} else if (X == 2) {
				win = true; // -> win
			} else if (X == 3) {
				if (R==1) {
					win = false; // choose 2x2 -> loose
				} else {
					win = true; // -> win
				}
			} else if (X == 4) {
				if (R==1) {
					win = false; // choose 2x2+ -> loose
				} else if (R == 2) {
					win = false; // choose 2x3 -> loose, because of seperated area "uneven"
				} else {
					win = true; // -> win
				}
			} else if (X == 5) {
				if (R < 3) { // choose 3x3+ -> loose
					win = false;
				} else if (R == 3) {
					win = (C >= 10); // choose W-pentomino -> loose for C<10
				} else {
					win = true; // -> win
				}
			} else if (X == 6) {
				if (R < 3) {
					win = false; // choose 3x3+ -> loose
				} else if (R == 3) {
					win = false; // choose 3x3 h/y/fish-hexomino -> loose
				} else {
					win = true; // no 4x4+ -> loose
				}
			} else {
				// choose nice loopy n-ominos with a 1-hole -> loose
				// either n-omino too big / 1-hole can't be filled
				win = false;
			}
		}
		
		//System.out.println(win ? "WIN" : "loose");
		System.out.println(win ? "GABRIEL" : "RICHARD");
	}
	
}
