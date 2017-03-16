import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Consonants {
	
	private Scanner cin;
	private PrintStream cout;
	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		new Consonants().solve();
	}

	public void solve() throws Exception {
		/*
		cin = new Scanner(System.in);
		cout = System.out;
		/*/
		cin = new Scanner(new File("A-small-attempt0.in"));
		cout = new PrintStream("A-small-attempt0.out");
		//*/
		int no = cin.nextInt();
		for (int i = 1; i <= no; ++i) {
			cout.printf("Case #%d: %s\n", i, solveCase(i));
		}
	}
	
	private String solveCase(int no) throws Exception {
		String s = cin.next();
		int n = cin.nextInt();
		int result = 0;
		Pattern pattern = Pattern.compile("[b-df-hj-np-tv-z]{" + n + "}");
		for (int i = 0; i < s.length(); ++i) {
			Matcher matcher = pattern.matcher(s.substring(i));
			if (matcher.find()) {
				result += s.length() + 1 - i - matcher.end();
			}
		}
		return String.valueOf(result);
	}
}
