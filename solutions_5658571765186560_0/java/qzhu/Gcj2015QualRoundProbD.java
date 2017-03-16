/* 
 * Google Code Jam - 2015 - Qualification Round - Problem D "Ominous Omino"
 * Solution for large input by Qiyu Zhu
 */

import java.util.Scanner;


public class Gcj2015QualRoundProbD {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++)
			System.out.printf("Case #%d: %s%n", i + 1, handleCase(in) ? "GABRIEL" : "RICHARD");
	}
	
	
	/* 
	 * Mathematical intuition (does not cover all cases):
	 * - Without loss of generality, assume R >= C.
	 * - If the number of grid cells is not a multiple of the omino size, then Richard wins.
	 * - It is easy to show that 1-ominoes and 2-ominoes can always tile (provided the grid is divisible).
	 * - If the size of the omino is at least 7, then it is possible to create a
	 *   hole of size 1 which is impossible to fill with an X-omino (where X >= 7).
	 * - If X >= R + C, then there is an L-shaped X-omino that cannot fit in the grid.
	 *   Similarly if X >= 2 * min(R, C) + 1 there is a non-fitting L-shaped X-omino.
	 * - If R or C (or both) is 2, then the T-shaped 4-omino will create an odd space that can't
	 *   be filled with 4-ominoes, and there are 5- and 6-ominos that create 1-cell islands:
	 *     +--+  +--+  +--+
	 *     |O.|  |OO|  |OO|
	 *     |OO|  |O.|  |O.|
	 *     |O.|  |OO|  |OO|
	 *     |..|  |..|  |O.|
	 * - If X = 6 and R or C (or both) is 3, then there is a T-shaped 6-omino that
	 *   forces the creation of spaces that have {1, 2, 4, 5} mod 6 cells:
	 *     +---+
	 *     |O..|
	 *     |OOO|
	 *     |O..|
	 *     |O..|
	 *     |...|
	 * - We can hand-check that these cases are tileable for all possible X-ominoes:
	 *   - X = 3 for (R,C) in {(3,2), (3,3), (4,3)}.
	 *   - X = 4 for (R,C) in {(4,3), (4,4)}.
	 */
	private static boolean handleCase(Scanner in) {
		// Read input and swap dimensions
		int omino = in.nextInt();
		int rows = in.nextInt();
		int cols = in.nextInt();
		if (rows < cols) {
			int temp = rows;
			rows = cols;
			cols = temp;
		}
		
		// Handle cases
		if (rows * cols % omino != 0)
			return false;
		if (omino == 1 || omino == 2)
			return true;
		if (omino >= 7)
			return false;
		if (omino >= rows + cols || omino >= cols * 2 + 1)
			return false;
		if ((rows == 2 || cols == 2) && omino >= 4)
			return false;
		if ((rows == 3 || cols == 3) && omino == 6)
			return false;
		if (omino == 3 && (rows == 3 && cols == 2 || rows == 3 && cols == 3 || rows == 4 && cols == 3 || rows == 4 && cols == 4))
			return true;
		if (omino == 4 && (rows == 4 && cols == 3 || rows == 4 && cols == 4))
			return true;
		
		throw new AssertionError("Undetermined");
	}
	
}
