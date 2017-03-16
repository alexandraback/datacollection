import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Solution {

	public static void A() throws IOException {

//		File inf = new File("/Users/guanhaipeng/Documents/InOut/input.txt");
		File inf = new File("/Users/guanhaipeng/Documents/InOut/A-large.in");
		File outf = new File("/Users/guanhaipeng/Documents/InOut/output.txt");
		Scanner scanner = new Scanner(inf);
		BufferedWriter out = new BufferedWriter(new FileWriter(outf));
		int caseNum = scanner.nextInt();
		scanner.nextLine();
		for (int i = 1; i <= caseNum; i++) {
			int ans = 0;
			// TODO
			String[] line = scanner.nextLine().split(" ");
			int Smax = new Integer(line[0]);
			int totalAudience = 0;
			for (int j = 0; j <= Smax; j++) {
				int audience = new Integer(line[1].charAt(j) - '0');

				if (totalAudience >= j) {
					totalAudience += audience;
				} else {
					ans += j - totalAudience;
					totalAudience = j + audience;
				}
			}
			// TODO
			String string = "Case #" + i + ": " + ans;
			System.out.println(string);
			out.write(string + "\n");
		}
		scanner.close();
		out.flush();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		A();
	}

}
