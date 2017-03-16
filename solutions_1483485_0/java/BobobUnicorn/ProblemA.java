import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) throws FileNotFoundException {
		PrintStream out = new PrintStream(new FileOutputStream(new File(
				"a-small.out")));
		Scanner in = new Scanner(new File("A-small-attempt0.in"));

		char[] convert = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u',
				'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p',
				'f', 'm', 'a', 'q'};

		int T = in.nextInt();
		in.nextLine(); // clear

		for(int i = 1; i <= T; i++){
			String line = in.nextLine();
			
			out.printf("Case #%d: ", i);
			for(char c: line.toCharArray()){
				if(c != ' ')
					out.print(convert[c-'a']);
				else
					out.print(c);
			}
			out.println();
		}
		
		in.close();
		out.close();
	}

	// public static void decode() {
	// // our language is impossible to understandthere are twenty six
	// // factorial possibilitiesso it is okay if you want to just give up
	// // ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh
	// // wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv
	// Scanner in = new Scanner(System.in);
	// char[] convert = new char[26];
	// Arrays.fill(convert, '!');
	//
	// String conv = in.nextLine();
	// String orig = in.nextLine();
	//
	// for (int i = 0; i < orig.length(); i++)
	// if (orig.charAt(i) != ' ')
	// convert[orig.charAt(i) - 'a'] = conv.charAt(i);
	//
	// for (int i = 0; i < 26; i++)
	// System.out.print("'" + convert[i] + "', ");
	// }
}
