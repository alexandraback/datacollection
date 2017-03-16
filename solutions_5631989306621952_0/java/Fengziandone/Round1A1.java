import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Round1A1 {

	public static void main(String... strings) {
		Scanner sc = new Scanner(System.in);
		 PrintStream ps = System.out;
		 try {
		 System.setOut(new PrintStream(new FileOutputStream("out1.txt")));
		 } catch (FileNotFoundException e) {
		 // TODO Auto-generated catch block
		 e.printStackTrace();
		 }
		 ps.close();
		int numCases = Integer.valueOf(sc.nextLine());

		for (int i = 0; i < numCases; i++) {
			String output = "";
			String s = sc.nextLine();
			int len = s.length();
			output += s.charAt(0);
			for (int j = 1; j < len; j++) {
				String temp = "";
				temp += s.charAt(j);
				if (s.charAt(j) >= output.charAt(0)) {
					output = temp.concat(output);

				} else {
					output = output.concat(temp);
				}
			}
			System.out.printf("Case #%d: %s\n", i + 1, output);
		}
	}
}
