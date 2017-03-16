import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 *
 * @author Chadi
 */

class TestCase {
	String sentence;
	Map<Character, Character> m;;
	
	
	public TestCase() {
		m = new HashMap<Character, Character>();
		m.put('a', 'y');
		m.put('b', 'h');
		m.put('c', 'e');
		m.put('d', 's');
		m.put('e', 'o');
		m.put('f', 'c');
		m.put('g', 'v');
		m.put('h', 'x');
		m.put('i', 'd');
		m.put('j', 'u');
		m.put('k', 'i');
		m.put('l', 'g');
		m.put('m', 'l');
		m.put('n', 'b');
		m.put('o', 'k');
		m.put('p', 'r');
		m.put('q', 'z');
		m.put('r', 't');
		m.put('s', 'n');
		m.put('t', 'w');
		m.put('u', 'j');
		m.put('v', 'p');
		m.put('w', 'f');
		m.put('x', 'm');
		m.put('y', 'a');
		m.put('z', 'q');
	}
	
	public String solve() {
		String result = "";
		for (int i = 0; i < sentence.length(); i++) {
			if (sentence.charAt(i) == ' ') {
				result += sentence.charAt(i);
			}
			else {
				result += m.get(sentence.charAt(i));
			}
		}
		return result;
	}

}

public class A {
    public static void main(String[] args) throws FileNotFoundException, IOException {
		/* READ INPUT + DATA STRUCTURES */
		//String input = "C-small-attempt0.in";
		String input = "A-small-attempt0.in";
		String output = input.replace(".in", ".out");
		File f = new File(input);
		Scanner sc = new Scanner(f);

		int T = Integer.parseInt(sc.nextLine());
		TestCase[] cases = new TestCase[T];
		for (int i = 0; i < T; i++) {
			cases[i] = new TestCase();

			/* Add inputs to this case */
			
			cases[i].sentence = sc.nextLine();

			
		}
		/* END READ INPUT + DATA STRUCTURES */

		File out = new File(output);
		if (out.exists()) {
			out.delete();
		}
		PrintWriter pw = new PrintWriter(new FileOutputStream(out, true));

		for (int i = 0; i < T; i++) {
			System.out.println("Solving case: " + "#" + (i+1));
			String result = "Case #" + (i+1) + ": " + cases[i].solve();
			if (i <= T-2) { pw.println(result); }
			else { pw.print(result); }
		}
		pw.close();
    }
}