import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class C {
	private static PrintStream outfile;
	private static HashSet<Integer> impossibleSizes = new HashSet<Integer>();

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(System.in);
		outfile = new PrintStream("C-small.out.txt");

		impossibleSizes.add(0);
		impossibleSizes.add(2);
		impossibleSizes.add(3);
		impossibleSizes.add(5);
		impossibleSizes.add(7);

		int cases = scan.nextInt();
		int m, rows, cols, empty;
		for (int c = 1; c <= cases; c++) {
			rows = scan.nextInt();
			cols = scan.nextInt();
			m = scan.nextInt();
			empty = rows * cols - m;
			println("Case #" + c + ":");
			if (isImpossible(rows, cols, m))
				println("Impossible");
			else {
				char[][] field = new char[rows][cols];
				for (char[] row : field)
					Arrays.fill(row, '*');
				
				if (empty > 1) {
					if (empty > (cols << 1)) {
						int bottomRow = empty/cols;
						for (int i = 0; i < bottomRow; i++)
							Arrays.fill(field[i], '.');
						for (int i = 0; i < empty%cols; i++)
							field[bottomRow][i] = '.';
						if ((empty % cols) == 1) {
							field[bottomRow][1] = '.';
							field[bottomRow-1][cols-1] = '*';
							if (bottomRow == 2) {
								field[2][2] = '.';
								field[0][cols-1] = '*';
							}
						}
					} else if (rows == 1) {
						for (int i = 0; i < empty; i++)
							field[0][i] = '.';
					} else {
						if ((empty & 1) == 1) {
							field[2][0] = '.';
							field[2][1] = '.';
							field[2][2] = '.';
							empty -= 3;
						}
						for (int i = 0; i < (empty >> 1); i++) {
							field[0][i] = '.';
							field[1][i] = '.';
						}
					}
				}
				
				field[0][0] = 'c';
				for (char[] row : field)
					println(new String(row));
			}
		}
		outfile.close();
	}
	
	private static void println(String str) {
		outfile.println(str);
		System.out.println(str);
	}
	
	private static boolean isImpossible(int rows, int cols, int m) {
		int empty = rows * cols - m;
		if (empty == 0)
			return true;
		else if (empty == 1 || rows == 1 || cols == 1)
			return false;
		else if (impossibleSizes.contains(empty))
			return true;
		else if (rows == 2 || cols == 2)
			return ((empty & 1) == 1); // Odd numbers
		else
			return false;
	}
}
