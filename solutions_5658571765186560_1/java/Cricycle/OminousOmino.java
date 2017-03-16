import java.util.*;

public class OminousOmino
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int tt = 1; tt <= t; ++tt)
		{
			int x = in.nextInt();
			int r = in.nextInt();
			int c = in.nextInt();
			
			boolean gabeWin = solve(x, r, c);
			String result = gabeWin ? "GABRIEL" : "RICHARD";
			
			System.out.printf("Case #%d: %s\n", tt, result);
		}
	}
	
	public static boolean solve(int xomino, int r, int c)
	{
		int temp = Math.max(r, c);
		r = Math.min(r, c);
		c = temp;
		
		// gabe cannot win if xominoes can't evenly divide the space
		if ( (r*c) % xomino != 0)
			return false;
		
		// gabe cannot win if xominoe has a hole in it
		if (xomino >= 7)
			return false;
		
		// gabe cannot win if richard can choose a piece which won't fit in the board
		// L piece --> e.g., if r = 1, then if x = 3, we can choose L and it won't fit
		if (xomino > 2*r)
			return false;
		
		// gabe cannot win if richard can choose a piece which won't fit in the board
		// straight piece --> 1 by X, r <= c, and c < x, this piece won't fit.
		if (xomino > c)
			return false;
		
		switch(r)
		{
			case 2:
				if (xomino <= 3)
					return true;
				return false; // xomino for 4: _|-
			case 3:
				if (xomino <= 5)
					return true;
				return false; // xomino for 6: -|--
			default:
				return true;
		}
	}
}