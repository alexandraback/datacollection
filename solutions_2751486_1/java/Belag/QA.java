import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class QA {

	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		sc.nextLine();
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			String name = sc.nextLine();
			String[] arg = name.split(" ");
			name = arg[0];
			int n = Integer.parseInt(arg[1]);

			int index = 0;
			int previousCons = 0;
			long result = 0;
			int length = name.length();
			for (int i = 0; i < length; i++) {
				if (name.charAt(i) == 'a' || name.charAt(i) == 'e'
						|| name.charAt(i) == 'i' || name.charAt(i) == 'o'
						|| name.charAt(i) == 'u') {
					previousCons = 0;
				} else {
					if(previousCons != n) {
						previousCons++;
					}
					if (previousCons == n) {
						result += (i-n-index + 2)*(length-i);
						index = i -n + 2;
					}
				}
			}
			pw.println("Case #" + caseNum + ": " + result);
		}

		pw.flush();
		pw.close();
		sc.close();
	}
	
	
	
	
}
