import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Solution {


	public static final String G_STRING = "GABRIEL";
	public static final String R_STRING = "RICHARD";

	public static String winner(int X, int R, int C) {
		if (R > C) { // ensure R <= C
			return winner(X, C, R);
		}
		if (R * C % X != 0) {
			return R_STRING;
		} else if (X == 1 || X == 2) {
			return G_STRING;
		} else if (R * C == X) {
			return R_STRING;
		} else if (X == 3) {
			return (R == 1) ? R_STRING : G_STRING;
		} else if (X == 4) {
			return (R <= 2) ? R_STRING : G_STRING;
		} else if (X >= 7) {
			return R_STRING;
		}
		return null;
	}

	public static void D() throws IOException{
		File inf = new File("/Users/guanhaipeng/Documents/workspace/CodeJam/src/D-small-attempt0.in");
		File outf = new File("/Users/guanhaipeng/Documents/workspace/CodeJam/src/output.txt");

//		BufferedReader in = new BufferedReader(new FileReader(inf));
		Scanner scanner = new Scanner(inf);
		BufferedWriter out = new BufferedWriter(new FileWriter(outf));


		int caseNum = scanner.nextInt();

		for (int i = 1; i <= caseNum; i++) {
			//TODO
			int X = scanner.nextInt();
			int R = scanner.nextInt();
			int C = scanner.nextInt();
			//TODO
			String string = "Case #" + i + ": " + winner(X, R, C);
			System.out.println(string);
			out.write(string + "\n");
		}
		scanner.close();
		out.flush();
//		in.close();
		out.close();
	}
	public static void main(String[] args) throws IOException {
		D();
	}

}
