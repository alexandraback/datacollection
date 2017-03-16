package CodeJam2015;

import java.util.Scanner;

public class D {
	static boolean can(int X, int R, int C) { //can gabriel win?
		if (X >= 7) //make a hole-shaped figure
			return false;
		if (X == 1)
			return true;
		if (((R * C) % X) != 0)
			return false;
		if (X == 2)
			return true; //the area determines this
		if (X == 3) {
			// either [][][] or [][]
			//                    []
			if (R == 1 || C == 1) return false; //richard chooses L-shape
			//at least one of R and C is a multiple of 3
			//richard will sure lose if he chooses the long shaped one
			//gabriel can put two L-shaped ones side by side to form a 2 by 3
			//along with long shaped ones, he can make any n by 3
			//and hence any n by 3m
			return true;
		}
		if (X == 4) {
			if (R == 1 || C == 1) return false; //richard chooses L-shape
			if (R == 2 || C == 2) return false; //richard chooses T-shape
			  //for either side, there is x to fill in on the long side
			  //and x+1 on the short side
			// either at least one of R and C is a multiple of 4,
			// or both are even
			// ==> either 3 by 4k, or 4+2k by 4+2l
			// any 3 by 4 can be filled in with any of the 4-ominos
			// so 3 by 4k is doable
			// and 4 by 4 can be made with another long sided one
			// so 4+2k by 4+2l can be done by putting 2 by 2 blocks.
			return true;
		}
		if (X == 5 || X == 6)
			throw new RuntimeException("Haven't handled yet");
		return false;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int cases = 1; cases <= T; cases++) {
			int X = sc.nextInt();
			int R = sc.nextInt();
			int C = sc.nextInt();
			
			if (can(X, R, C))
				System.out.println("Case #" + cases + ": GABRIEL");
			else
				System.out.println("Case #" + cases + ": RICHARD");
		}
		sc.close();
	}

}
/*
4
2 2 2
2 1 3
4 4 1
3 2 3
*/