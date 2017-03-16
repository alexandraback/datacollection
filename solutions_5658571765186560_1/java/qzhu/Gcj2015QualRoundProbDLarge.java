/* 
 * Google Code Jam - 2015 - Qualification Round - Problem D "Ominous Omino"
 * Solution for large input by Qiyu Zhu
 */

import java.util.Scanner;


public class Gcj2015QualRoundProbDLarge {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++) {
			int omino = in.nextInt();
			int rows = in.nextInt();
			int cols = in.nextInt();
			System.out.printf("Case #%d: %s%n", i + 1, handleCase(omino, rows, cols) ? "GABRIEL" : "RICHARD");
		}
	}
	
	
	/* 
	 * Here is my mathematical justification that covers all the possible cases.
	 * 
	 * Note that R and C can be swapped without changing the result of the game, because all
	 * tiles can be rotated and flipped. We will make use of this fact silently in the proof.
	 * 
	 * Basic condition: If the number of grid cells is not a multiple
	 * of the omino size, then no tiling exists and Richard wins.
	 * 
	 * Case arguments based on the omino size (assuming that the basic condition holds):
	 * 
	 * - X = 1: (monomino)
	 *   Gabriel wins because obviously any grid can be tiled with single squares.
	 * 
	 * - X = 2: (domino)
	 *   Gabriel wins if and only if the basic condition holds. Domino tilings are easy.
	 * 
	 * - X = 3: (tromino)
	 *   Because 3 is prime, at least one of R or C must be a multiple of 3. Assume (R,C) = (3r, C).
	 *   - If C = 1, then no tiling is possible (Richard wins)
	 *     because Richard can give the L-shaped tromino.
	 *   - If C = 2, we can show by hand that the 2 possible trominoes can be tiled in a
	 *     3-by-2 rectangle. Then we replicate this rectangle r times to get the desired output.
	 *   - If C >= 3, we create a 3-by-2 tiling containing Richard's tromino and pad it
	 *     with linear pieces up to the desired size, then replicate the rectangle r times.
	 *   Thus Gabriel wins iff C >= 2.
	 * 
	 * - X = 4: (tetromino)
	 *   If R or C (or both) is 2, no tiling is possible because Richard can give the
	 *   T-shaped tetromino, which produces a space that has an odd number of cells
	 *   (which can't be tiled with 4-ominoes). Thus both R and C must be at least 3.
	 *   +-----
	 *   |.O...
	 *   |OOO..
	 *   +-----
	 *   
	 *   Since 4 is a composite number, the basic condition can be satisfied in two ways:
	 *   - If R or C (or both) is a multiple of 4, then assume that (R,C) = (4r, C).
	 *     - If C = 1 or 2, it is not tileable regardless of r, so Richard wins.
	 *     - If C = 3, we can show by hand that the 5 possible tetrominoes can be tiled in a
	 *       4-by-3 rectangle. Then we replicate this rectangle r times to get the desired output.
	 *     - If C >= 4, we create a 4-by-3 tiling containing Richard's tetromino and pad it
	 *       with linear pieces to up to the desired size, then replicate the rectangle r times.
	 *     Thus in this case, Gabriel wins iff C >= 3.
	 *   - If R and C are both multiples of 2, then assume than (R,C) = (2r, 2c).
	 *     - Due to the reasoning in the introduction of the X = 4 case, (r,c) >= (2,2) so (R,C) >= (4,4).
	 *     - Due to the "multiple of 4" case above, a 4-by-4 rectangle is tileable for any given tetromino,
	 *       so we can pad it with 2-by-2 pieces to get the desired size of (2r, 2c).
	 *     Thus in this case, Gabriel wins iff (R,C) >= (4,4).
	 * 
	 * - X = 5: (pentomino)
	 *   Because 5 is prime, at least one of R or C must be a multiple of 5. Assume (R,C) = (5r, C).
	 *   - If C = 1 or 2, no tiling is possible since there Richard can give the
	 *     3-by-3 L-shaped pentomino that will not fit within the grid at all.
	 *   - If C = 3, then the result depends on r (or R):
	 *     - If r = 1 (i.e. (R,C) = (5,3)), no tiling is possible because the
	 *       W-shaped pentomino always (in any position or orientation) produces
	 *       two spaces that have a non-multiple-of-5 number of cells:
	 *       +-----+
	 *       |...O.|
	 *       |..OO.|
	 *       |.OO..|
	 *       +-----+
	 *       However, note that the other 10 possible pentominoes can be tiled
	 *       in a 5-by-3 rectangle. (We will use this fact in subsequent cases.)
	 *     - If r = 2, we can show that the W-shaped pentomino can produce a tiling.
	 *       Furthermore, all other pentominoes can be tiled in 5-by-3,
	 *       so it can be padded with linear pieces up to a 10-by-3 tiling.
	 *     - If r >= 3, we apply the r = 2 case to Richard's given pentomino
	 *       and pad with linear 5-by-1 pieces up to the desired size.
	 *   - If C = 4: If the given pentomino is not the W-tile, then we make a 5-by-3 tiling and
	 *     pad it up to 5-by-4. Otherwise if it's the W-tile, then we can show that it can be
	 *     tiled nonetheless. Finally we replicate this 5-by-4 rectangle r times to get the output.
	 *   - If C >= 5: We apply the C = 4 case, pad with linear pieces to reach our C value,
	 *     then replicate this intermediate result r times to get the final resulting rectangle.
	 *   Thus Gabriel wins iff (C = 3 and r >= 2) or C >= 4.
	 * 
	 * - X = 6: (hexomino)
	 *   Both R and C must be greater than 2 because there is an L-shaped hexomino that won't fit.
	 *   Moreover, R and C must be greater than 3 because if the minimum dimension is 3, there is
	 *   a T-shaped hexomino that creates spaces that have a non-multiple-of-6 number of cells:
	 *   +------
	 *   |..O...
	 *   |..O...
	 *   |OOOO..
	 *   +------
	 *   Hence we established that R and C >= 4. We can painstakingly work out by hand
	 *   that all 35 possible free hexominoes can be tiled in a 6-by-4 rectangle.
	 *   
	 *   Since 6 is composite, the basic condition can hold in two ways:
	 *   - If R or C (or both) is a multiple of 6, then assume that (R,C) = (6r, C).
	 *     - If 1 <= C <= 3, we already know that this is too narrow to support
	 *       certain tiles, as argued above in the introduction of the X = 6 case.
	 *     - If C >= 4, we can generate a 6-by-4 tiling rectangle, pad it with
	 *       linear pieces to get a 6-by-C rectangle, then replicate it r times.
	 *     Thus in this case, Gabriel wins iff C >= 4.
	 *   - If R is a multiple of 3 and C is a multiple of 2 (without
	 *     loss of generality), then assume that (R,C) = (3r, 2c).
	 *     If r = 1, then R = 3 and we know this is not tileable; hence r >= 2.
	 *     If c = 1, then C = 2 and we know this is not tileable; hence c >= 2.
	 *     Overall we require that (R,C) >= (6,4). We can generate a 6-by-4 tiling from Richard's
	 *     given hexomino, then pad with 3-by-2 rectangle pieces to reach the desired output size.
	 *     Thus in this case, Gabriel wins iff (R,C) >= (6,4).
	 * 
	 * - X >= 7: Richard wins because he can always give an X-omino that contains
	 *   a 1-cell hole, which makes it impossible to tile with X-ominoes.
	 */
	private static boolean handleCase(int omino, int rows, int cols) {
		if (rows * cols % omino != 0)
			return false;
		switch (omino) {
			case  1:  return true;
			case  2:  return true;
			case  3:  return Math.min(rows, cols) >= 2;
			case  4:  return Math.min(rows, cols) >= 3;
			case  5:  return (rows % 5 == 0 && (cols == 3 && rows >= 10 || cols >= 4)) || (cols % 5 == 0 && (rows == 3 && cols >= 10 || rows >= 4));
			case  6:  return (rows >= 6 && cols >= 4) || (rows >= 4 && cols >= 6);
			default:  return false;
		}
	}
	
}
