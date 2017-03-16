import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		File in = new File("A-small-attempt0.in");
		File out = new File("file.out");
		Scanner scanner = null;
		PrintStream ps = null;
		try {
			scanner = new Scanner(in);
			ps = new PrintStream(out);
			int num = scanner.nextInt();
			scanner.nextLine();
			for(int i = 1; i <= num; i++) {
				String word = scanner.nextLine();
				ps.printf("Case #" + i + ": ");
				ps.println(fun(word));
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} finally {
			if(scanner != null) {
				scanner.close();
			}
			if(ps != null) {
				ps.close();
			}
		}
	}
	
	public static String fun(String word) {
		StringBuffer sb = new StringBuffer();
		char max = word.charAt(0);
		for(char c : word.toCharArray()) {
			if(c >= max) {
				sb.insert(0, c);
				max = c;
			} else {
				sb.append(c);
			}
		}
		return sb.toString();
	}
	
}
