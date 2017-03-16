package toshico.gcj_2016.round_1a;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class A_TheLastWord {

	private String lastWord;

	public A_TheLastWord(final String S) {
		super();
		StringBuilder lastWordBuilder = new StringBuilder();
		for(char c : S.toCharArray()) {
			if(lastWordBuilder.length()==0 || c>=lastWordBuilder.charAt(0)) {
				lastWordBuilder.insert(0, c);
			} else {
				lastWordBuilder.append(c);
			}
		}
		this.lastWord = lastWordBuilder.toString();
	}

	public String getLastWord() {
		return this.lastWord;
	}

	public static void main(final String[] args) {
		try (final Scanner sc = new Scanner(args.length > 0 ? new FileInputStream(args[0]) : System.in);
				final PrintStream pr = args.length > 1 ? new PrintStream(args[1]) : System.out;) {
			final int nb_test = sc.nextInt();
			for (int i = 1; i <= nb_test; i++) {
				A_TheLastWord test = new A_TheLastWord(sc.next());
				StringBuilder output = new StringBuilder(String.format("Case #%d: ", i));
				output.append(String.format("%s", test.getLastWord()));
				System.out.println(output.toString());
			}
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

}
