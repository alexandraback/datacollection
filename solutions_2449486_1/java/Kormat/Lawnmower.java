import java.io.File;
import java.io.IOException;
import java.util.Scanner;

import com.google.common.base.Charsets;
import com.google.common.io.Files;

/*
 * using Google Guava (http://code.google.com/p/guava-libraries/)
 */

public class Lawnmower {
	public static void main(String[] args) throws IOException {
		String content = Files.toString(new File(args[0]), Charsets.UTF_8);
		Scanner scanner = new Scanner(content);
		
		StringBuilder output = new StringBuilder();
		int testCases = scanner.nextInt();
		for(int i=1; i<=testCases; i++) {
			String solution = "Case #"+i+": "+solve(scanner)+"\n";
			System.err.print(solution);
			output.append(solution);
		}
		Files.write(output.toString(), new File("out.out"), Charsets.UTF_8);
	}
	
	private static String solve(Scanner scanner) {
		int h = scanner.nextInt();
		int w = scanner.nextInt();
		int[][] lawn = new int[h][w];
		for (int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				lawn[i][j] = scanner.nextInt();
			}
		}
		
		for (int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				if (!(maximumInTheRow(i,j,lawn) || maximumInTheCol(i,j,lawn))) return "NO";
			}
		}
		return "YES";
	}

	private static boolean maximumInTheCol(int y, int x, int[][]lawn) {
		for (int i=0; i<lawn.length; i++) {
			if (lawn[i][x] > lawn[y][x]) return false;
		}
		return true;
	}

	private static boolean maximumInTheRow(int y, int x, int[][]lawn) {
		for (int i=0; i<lawn[0].length; i++) {
			if (lawn[y][i] > lawn[y][x]) return false;
		}
		return true;
	}
}
