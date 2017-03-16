import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class Googlerese {

	public static void main(String args[]) throws FileNotFoundException {

		Scanner inFile = new Scanner(new File("A-small-attempt0.in"));
		PrintStream outFile = new PrintStream(new File("A-small0-out.txt"));

		int numCases = inFile.nextInt();
		inFile.nextLine(); // Gets rid of newline char

		for (int i = 1; i <= numCases; i++) {

			String inLine = inFile.nextLine();
			Scanner tokenizer = new Scanner(inLine);
			String newStr = "";

			while (tokenizer.hasNext()) {
				String nextToken = tokenizer.next();
				newStr += translate(nextToken) + " ";
			}

			newStr = newStr.trim();
			printCase(outFile, i, newStr);

		}

	}
	
	
	private static void printCase(PrintStream outStream, int i, String str) {
		outStream.println("Case #" + i +": " + str);
	}

	private static String translate(String word) {
		String translated = "";
		for (int i = 0; i < word.length(); i++) {
			translated += flipLetter(word.charAt(i));
		}
		return translated;
	}

	private static char flipLetter(char ch) {

		char flipped = '\n';

		switch (ch) {
		case 'a':
			flipped = 'y';
			break;
		case 'b':
			flipped = 'h';
			break;
		case 'c':
			flipped = 'e';
			break;
		case 'd':
			flipped = 's';
			break;
		case 'e':
			flipped = 'o';
			break;
		case 'f':
			flipped = 'c';
			break;
		case 'g':
			flipped = 'v';
			break;
		case 'h':
			flipped = 'x';
			break;
		case 'i':
			flipped = 'd';
			break;
		case 'j':
			flipped = 'u';
			break;
		case 'k':
			flipped = 'i';
			break;
		case 'l':
			flipped = 'g';
			break;
		case 'm':
			flipped = 'l';
			break;
		case 'n':
			flipped = 'b';
			break;
		case 'o':
			flipped = 'k';
			break;
		case 'p':
			flipped = 'r';
			break;
		case 'q':
			flipped = 'z';
			break;
		case 'r':
			flipped = 't';
			break;
		case 's':
			flipped = 'n';
			break;
		case 't':
			flipped = 'w';
			break;
		case 'u':
			flipped = 'j';
			break;
		case 'v':
			flipped = 'p';
			break;
		case 'w':
			flipped = 'f';
			break;
		case 'x':
			flipped = 'm';
			break;
		case 'y':
			flipped = 'a';
			break;
		case 'z':
			flipped = 'q';
			break;
		}
		return flipped;
	}
	
}
