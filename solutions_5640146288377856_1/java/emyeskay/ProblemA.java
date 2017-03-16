import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


public class ProblemA {
	
	/*
	 * 	
	 * 	Input 
 		
		3
		1 4 2
		1 7 7
		2 5 1
		
		Output
		
		Case #1: 3
		Case #2: 7
		Case #3: 10

	 * */

	public static void main(String[] args) throws IOException {
		
		long time = System.currentTimeMillis();
		//System.out.println("START: " + time);

		Scanner input = new Scanner(new File("src/A-large.in"));
		int numCases = Integer.parseInt(input.nextLine());
		for (int n = 0; n < numCases; n++) {
			
			int r = input.nextInt();
			int c = input.nextInt();
			int w = input.nextInt();
			
			if( w == 1 ) {
				System.out.println("Case #" + (n + 1) + ": " + (r * c));
				continue;
			}
			
			int res = solve(1, c, w);
			
			if( r > 1 ) {
				res = res + ( (r-1) * (c/w) );
			}
			
			System.out.println("Case #" + (n + 1) + ": " + res);
			
		}

	}
	
	public static int solve(int r, int c, int w) {
		
		int n = 0;
		
		if( r == 1 && (w == c || w == c-1) ) return c;
		
		n = n + 1;
		
		if( c-w < w ) {
			c = w;
		} else {
			c = c-w;
		}
		
		n += solve(r, c, w);
		
		return n;
	}

}
