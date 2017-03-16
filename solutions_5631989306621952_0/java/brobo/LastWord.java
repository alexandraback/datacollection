import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class LastWord {
	public static void main(String[] args) throws Exception {
		 Scanner input = new Scanner(new File("input/a_small.in"));
		 PrintWriter output = new PrintWriter(new File("output/a_small.out"));
//		Scanner input = new Scanner(System.in);
//		PrintWriter output = new PrintWriter(System.out);

		int testCases = input.nextInt();
		input.nextLine();
		primary: for (int casen = 1; casen <= testCases; casen++) {
			output.printf("Case #%d: ", casen);
			
			char[] letters = input.nextLine().toCharArray();
			String res = "" + letters[0];
			for (int i = 1; i < letters.length; i++) {
				if (letters[i] >= res.charAt(0)) {
					res = letters[i] + res;
				} else {
					res = res + letters[i];
				}
			}
			output.println(res);
			output.flush();
		}
		output.close();
	}
}