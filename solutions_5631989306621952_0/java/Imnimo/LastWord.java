import java.io.File;
import java.util.Scanner;


public class LastWord {
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("A-small-attempt0.in"));
		int numCases = Integer.parseInt(s.nextLine());
		for(int c = 1;c<=numCases;c++) {
			String line = s.nextLine();
			String ans = process(line);
			System.out.println("Case #" + c + ": " + ans);
		}
	}
	public static String process(String input) {
		StringBuilder ans = new StringBuilder();
		ans.append(input.charAt(0));
		for(int i = 1;i<input.length();i++) {
			char c = input.charAt(i);
			if(c >= ans.charAt(0)) {
				ans.insert(0, c);
			} else {
				ans.append(c);
			}
		}
		return ans.toString();
	}
}
