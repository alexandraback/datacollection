

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
		
		if (((R*C)%X) != 0 || C<X) {
			// R*C not multiple of X -> loose
			// big side C smaller than X -> loose
			win = false;
		} else {
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
			} else {//if (X == 4) {
				if (R==1) {
					win = false; // choose 2x2+ -> loose
				} else if (R == 2) {
					win = false; // choose 2x3 -> loose, because of seperated area "uneven"
				} else {
					win = true; // -> win
				}
			}
		}
		
		//System.out.println(win ? "WIN" : "loose");
		System.out.println(win ? "GABRIEL" : "RICHARD");
	}
	
}
