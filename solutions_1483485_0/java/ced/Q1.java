import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;


public class Q1 {
	static HashMap<Character, Character> map = new HashMap<Character, Character>();
	static {
		map.put('y', 'a');
		map.put('n', 'b');
		map.put('f', 'c');
		map.put('i', 'd');
		map.put('c', 'e');
		map.put('w', 'f');
		map.put('l', 'g');
		map.put('b', 'h');
		map.put('k', 'i');
		map.put('u', 'j');
		map.put('o', 'k');
		map.put('m', 'l');
		map.put('x', 'm');
		map.put('s', 'n');
		map.put('e', 'o');
		map.put('v', 'p');
		map.put('z', 'q');
		map.put('p', 'r');
		map.put('d', 's');
		map.put('r', 't');
		map.put('j', 'u');
		map.put('g', 'v');
		map.put('t', 'w');
		map.put('h', 'x');
		map.put('a', 'y');
		map.put('q', 'z');
	}
	private static void run(int CASE) throws Exception {
		String line = readLine();
		char[] s = line.toCharArray();
		for (int i = 0; i < line.length(); i++) {
			Character ch = map.get(s[i]);
			if(ch!=null) s[i] = ch;
		}
		printf("Case #%d: %s\n", CASE, new String(s));
	}

	//-- Supporting --//
	static BufferedReader in;
	static PrintWriter out;
	static {
		try {
			in = new BufferedReader(new FileReader("A-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("out.txt"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) throws Exception {
		int N = Integer.parseInt(readLine());
		for (int c = 1; c <= N; c++) {
			run(c);
		}
		in.close();
		out.close();
	}

	private static String readLine() throws IOException {
		return in.readLine();
	}

	private static void printf(String str, Object... o) {
		System.out.printf(str, o);
		out.printf(str, o);
	}

}
