import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Problem1 {
	public static void main(String[] args) throws FileNotFoundException {
		String map = "yhesocvxduiglbkrztnwjpfmaq";
		Scanner s = new Scanner(System.in);
		PrintStream ps = new PrintStream(new FileOutputStream(
				"d:\\output\\pro1.txt"));
		int num = s.nextInt();
		s.nextLine();
		for (int i = 1; i <= num; i++) {
			String line = s.nextLine();
			String prefix = "Case #" + i + ": ";
			StringBuilder output = new StringBuilder(prefix);
			for (int j = 0; j < line.length(); j++) {
				char c = line.charAt(j);
				if (c == ' '){
					output.append(c);
				}else{
					output.append(map.charAt(c - 'a'));
				}
			}
			System.out.println(output);
			ps.println(output);
		}
	}
}
