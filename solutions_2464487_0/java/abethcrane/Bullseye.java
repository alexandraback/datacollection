import java.util.Scanner;
import java.lang.*;

public class Bullseye {

	public int radius = 0;
	public int paint_mil = 0;
	public int max = 100001;//Long.MAX_VALUE;
			
	public Bullseye(int r, int t) {
		radius = r;
		paint_mil = t;
	}
	
	public int numRings() {
		int paintUsed = 0;
		int start = 0;
		int end = max;
		int middle = start+end/2;
		int n = middle;

		boolean found = false;
		
		//binary search from 0 up to your biggest
		// at each point substitute n into the equation
		// paint used = (n+1) * (2n + 2r + 1)
		
		// if paint used is more than paint_mil, search lower
		// if paint used is less than paint_mil, search higher
		
		// but!
		int testPaint = 0;
		
		while (start < end && !found) {
			paintUsed = (n+1) * ((2*n) + (2*radius) + 1);
			//System.out.format("Paint used: %d, n: %d, start: %d, end:%d\n", paintUsed, n, start, end);
			if (paintUsed < paint_mil) {
				// if we find one where paint used is less than paint mil, and the one above is more, then we go with it.
				n = n+1;
				testPaint = (n+1) * ((2*n) + (2*radius) + 1);
				if (testPaint > paint_mil) {
					n -= 1;
					found = true;
				} else {
					start = middle;
					middle = (start+end)/2;
					n = middle;
					//System.out.format("n: %d, start: %d, end:%d\n", n, start, end);
				}
			} else if (paintUsed > paint_mil) {
				end = middle;
				middle = (start+end)/2;
				//System.out.format("start+end:%d, start+end/2:%d\n", start+end, start+end/2);
				n = middle;
				//System.out.format("n: %d, start: %d, end:%d\n", n, start, end);
			} else {
				found = true;
			}
		}
		
		return n += 1;
	}

}
