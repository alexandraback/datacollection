

/**
 * 
 * @author RasPat
 *Problem can be found here:
 * https://code.google.com/codejam/contest/189252/dashboard#s=p1
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Prob2 {
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		String pathRoot = "C:\\Users\\RasPat\\workspace\\2013_1C\\";
		String relRoot = "B-small-attempt2.in";
//		relRoot = "testB.in";
		String in = pathRoot + relRoot;
		// Length of the file extension
		int extLength = 2;
		String out = in.substring(0, in.length() - extLength) + "out";

		BufferedReader r = null;
		BufferedWriter w = null;
		try {
			r = new BufferedReader(new FileReader(in));
			w = new BufferedWriter(new FileWriter(out));
			String[] line;
			// First line of Input is the # of test cases
			int testCases = Integer.parseInt(r.readLine());
			int caseCount = 0;

			while (caseCount < testCases) {
				caseCount++;
				line = r.readLine().split(" ");
				
				int X = Integer.parseInt(line[0]);
				int Y = Integer.parseInt(line[1]);
				int curX = 0;
				int curY = 0;
				String result = "";
				
				for(int i = 1; i <= 500; i++) {
					int dX = Math.abs(X - curX);
					int dY = Math.abs(Y - curY);
					
					if (curX < X) {
						if (i <= dX) {
							curX += i;
							result += 'E';
						} else {
							curX -= i;
							result += 'W';
						}
					} else if (curX > X) {
						if (i <= dX) {
							curX -= i;
							result += 'W';
						} else {
							curX += i;
							result += 'E';
						}
					} else if (curY < Y) {
						if (i <= dY) {
							curY += i;
							result += 'N';
						} else {
							curY -= i;
							result += 'S';
						}
					} else if (curY > Y) {
						if (i <= dY) {
							curY -= i;
							result += 'S';
						} else {
							curY += i;
							result += 'N';
						}
					} else
						break;
				}
//				System.out.println(curX + ", " +  curY);
				if(curX != X || curY != Y) {
					System.out.println("didn't finish in 500 moves");
				} else
					System.out.println("moves: " + result.length());
//				System.out.println(result);
/**
 * Pseudo Code
 * To move one unit N move S the N etc
 * -100 < X,Y < 100
 * max 500 moves
 * Try brute force?
 * For any X,Y find a way to add/subtract the numbers 1, .. n where n < 500 
 * X = 1 +   - 3     + 5     = 3
 * Y =     2     - 4 	 + 6 = 4	 
 * (3,4)
 * X+Y=1 + 2 - 3 - 4 + 5 + 6 = 7
 * 200 * 200 = 40000
 * any number can be in either X or Y and either positive or negative
 * 500 * 4 = 2000 possibilities
 * array of form 0 to 499.
 * each value has an X or Y value and a positive and negative value
 * array of X,Y coordinates
 * 
 * take the perfect numbers formed by the numbers 1 - 500
 * see if the X+Y value can be made by subtracting soem value form the perfect numbers
 * 
 * Just keep moving towards the goal until you're there
 * if the x value is greater than add towards it if less than move away form it
 * same with Y
 * 
 */
				
				

				w.write("Case #" + caseCount + ": " + result);
				

//				w.write(" " + String.format("%.6f", d));
				w.newLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				r.close();
				if (w != null) {
					w.flush();
					w.close();
				}
				System.out.println("Time elapsed: "+ (System.currentTimeMillis() - start));
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
