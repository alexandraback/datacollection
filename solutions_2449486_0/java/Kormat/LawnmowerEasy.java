import java.io.File;
import java.io.IOException;
import java.util.Scanner;

import com.google.common.base.Charsets;
import com.google.common.io.Files;

/*
 * using Google Guava (http://code.google.com/p/guava-libraries/)
 */

public class LawnmowerEasy {
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
		
		boolean[] allOnesRows = new boolean[h];
		for (int i=0; i<h; i++) {
			boolean allOnes = true;
			for(int j=0; j<w; j++) {
				if (lawn[i][j] == 2) allOnes=false;
			}
			allOnesRows[i] = allOnes;
		}
		boolean[] allOnesCols = new boolean[w];
		for (int j=0; j<w; j++) {
			boolean allOnes = true;
			for(int i=0; i<h; i++) {
				if (lawn[i][j] == 2) allOnes=false;
			}
			allOnesCols[j] = allOnes;
		}
		
		for (int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				if (lawn[i][j] == 1 && !(allOnesRows[i] || allOnesCols[j])) return "NO";
			}
		}
		return "YES";
	}
}
