package j2016.r1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Scanner;

@SuppressWarnings("all")
public class C {

	private static final String FILE_NAME = "C-small-attempt0";	
	
	private static final String RELATIVE_PATH;
	static {
		String p = C.class.getPackage().getName();
		p = p.replace('.', '\\');
		RELATIVE_PATH = "src\\" + p + "\\" + FILE_NAME;
	}
	
	private Scanner in;
	private PrintStream out;
	
	public C () throws FileNotFoundException {
		in = new Scanner(new File(RELATIVE_PATH + ".in"));	
		out = new PrintStream(RELATIVE_PATH + ".out"); 
			
		int cases = nextInt();	
		for (int i = 1; i <= cases; i++) {
			print("Case #" + i + ": ");
			solve();
			println();
		}	

		out.close();
		System.out.println("\nDONE!");
	}
	
	private void solve() {
		HashMap<String, Integer> fc = new HashMap<>();
		HashMap<String, Integer> sc = new HashMap<>();
		int N = nextInt();
		String[][] s = new String[N][2];
		for (int n = 0; n < N; n++) {
			String[] words = {next(), next()};
			if (!fc.containsKey(words[0])) {
				fc.put(words[0], 1);
			} else {
				int i = fc.get(words[0]);
				fc.put(words[0], i+1);
			}
			if (!sc.containsKey(words[1])) {
				sc.put(words[1], 1);
			} else {
				int i = sc.get(words[1]);
				sc.put(words[1], i+1);
			}
			s[n] = words;
		}
		
		int m = max(fc, sc, s, 0, 0);
		print(m);
	}
	
	int max(HashMap<String, Integer> fc, HashMap<String, Integer> sc, String[][] ss, int i, int c) {
		if (i > ss.length) return c;
		
		int m = 0;
		for (int x = i; x < ss.length; x++) {
			String[] s = ss[x];
			int f1 = fc.get(s[0]);
			int f2 = sc.get(s[1]);
			if (f1 > 1 && f2 > 1) {
				m = Math.max(max(clone(fc), clone(sc), ss, x+1, c), m);
				c++;
				fc.put(s[0], f1-1);
				sc.put(s[1], f2-1);
			}
		}
		
		return Math.max(m, c);
	}
	
	HashMap<String, Integer> clone(HashMap<String, Integer> m) {
		HashMap<String, Integer> clone = new HashMap<>();
		for (Entry<String, Integer> e : m.entrySet()) {
			clone.put(new String(e.getKey()), new Integer(e.getValue()));
		}
		return clone;
	}
	
	
	
	/*
	 * Manage input
	 */
	private String next() {
		return in.next();
	}
	private int nextInt() {
		return in.nextInt();
	}
	private long nextLong() {
		return in.nextLong();
	}

	/*
	 * Manage output
	 */
	private void print(String s) { 
		System.out.print(s);
		out.print(s); 
	}	
	private void print(int i) { 
		System.out.print(i);
		out.print(i); 
	}	
	private void print(Object o) {
		System.out.print(o);
		print(o);
	}
	private void println() { 
		System.out.println();
		out.println(); 
	}
	
	public static void main(String[] args) {
		try {
			new C();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
