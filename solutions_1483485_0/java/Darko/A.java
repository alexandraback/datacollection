import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	private void work() throws IOException {
		Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("A-small.out"));
		String abc = " ";
		for (char c = 'a'; c <= 'z'; c++) {
			abc += c;
		}
		char[] replace = " yhesocvxduiglbkrztnwjpfmaq".toCharArray();
		int nc = sc.nextInt();
		sc.nextLine();
		for (int tc = 1; tc <= nc; tc++) {
			pw.printf("Case #%d: ", tc);
			char[] line = sc.nextLine().toCharArray();
			for (int i = 0; i < line.length; i++) {
				pw.write(replace[abc.indexOf(line[i])]);
			}
			pw.println();
		}
		pw.close();
	}

	public static void main(String[] args) throws IOException {
		new A().work();
	}
}
