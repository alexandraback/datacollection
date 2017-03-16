import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class A {

	private static final String ALPHABET = "abcdefghijklmnopqrstuvwxyz";

	private static String[] GOOGLERESE = new String[] {
		"y qee",
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv"
	};
	
	private static String[] ENGLISH = new String[] {
		"a zoo",
		"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up"
	};
	
	private static Map<Character, Character> g2e;
	private static Map<Character, Character> e2g;
	
	private static CodeJamIO io = new CodeJamIO();

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		try {
			init();

			int numCases = Integer.parseInt(io.readNextLine()[0]);
			for (int i=1; i <= numCases; i++) {
				io.debug("Solving Case #" + i + "...");
				solveCase(i);
				io.debug("Case #" + i + " solved!");
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	/**
	 * Performs initial computations
	 */
	private static void init() {
		g2e = new HashMap<Character, Character>();
		e2g = new HashMap<Character, Character>();
		for (int i=0; i<GOOGLERESE.length; i++) {
			for (int j=0; j<GOOGLERESE[i].length(); j++) {
				Character g = GOOGLERESE[i].charAt(j);
				Character e = ENGLISH[i].charAt(j);
				if (g == ' ' || e == ' ') {
					continue;
				}
				g2e.put(g, e);
				e2g.put(e, g);
			}
		}
		
		Character gMissing = null;
		Character eMissing = null;
		for (Character c : ALPHABET.toCharArray()) {
			if (g2e.get(c) == null) {
				gMissing = c;
			}
			if (e2g.get(c) == null) {
				eMissing = c;
			}
		}
		
		if (gMissing != null && eMissing != null) {
			g2e.put(gMissing, eMissing);
			e2g.put(eMissing, gMissing);
		}
		
		io.debug(g2e.keySet().size() + " translations");
	}

	/**
	 * Solves a Test Case
	 * 
	 * @param caseNum
	 * @throws IOException
	 */
	private static void solveCase(int caseNum) throws IOException {
		// Read input
		String[] tokens = io.readNextLine();
		
		// Do the work
		StringBuffer translated = new StringBuffer();
		String space = "";
		for (String token : tokens) {
			translated.append(space);
			for (int i=0; i<token.length(); i++) {
				translated.append(g2e.get(token.charAt(i)));
			}
			space = " ";
		}
		
		// Print results
		io.printCase(caseNum).println(translated);

	}

	/**
	 * Input and Output CodeJam style
	 *
	 */
	private static class CodeJamIO {
		private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		private static PrintWriter out = new PrintWriter(System.out, true);
		private static PrintWriter err = new PrintWriter(System.err, true);

		public String[] readNextLine() throws IOException {
			String line = in.readLine();
			String[] tokens = line.split("\\s+");
			return tokens;
		}

		public CodeJamIO printCase(int caseNum) { return print("Case #" + caseNum + ": " ); }
		
		public CodeJamIO print(Object o) { out.print(o); return this; }

		public CodeJamIO print(Object o[]) { return print(concat(o)); }

		public CodeJamIO print(Object o[][]) { return print(concat(o)); }

		public CodeJamIO println() { out.println(); return this; }

		public CodeJamIO printlnCase(int caseNum) { return printCase(caseNum).println(); }
		
		public CodeJamIO println(Object o) { return print(o).println(); }

		public CodeJamIO println(Object o[]) { return print(o).println(); }

		public CodeJamIO println(Object o[][]) { return print(concat(o)).println(); }

		public CodeJamIO println(List<Integer[]> l) { return print(concat(l)).println(); }

		
		private String concat(Object[] o) {
			StringBuffer buf = new StringBuffer(10*o.length);
			
			String delim = "";
			for (int i=0; i < o.length; i++) {
				buf.append(delim).append(o[i]);
				delim = " ";
			}
			return buf.toString();
		}
		
		private String concat(Object[][] o) {
			StringBuffer buf = new StringBuffer(100*o.length);
			for (int i=0; i < o.length; i++) {
				buf.append(concat(o[i])).append("\n");
			}
			return buf.toString();
		}

		private String concat(List<Integer[]> list) {
			StringBuffer buf = new StringBuffer();
			String delim = "";
			for (Object[] elm : list) {
				buf.append(delim).append(concat(elm)).append("\n");
			}
			return buf.toString();
		}

		public void debug(String message) {
			err.println(Calendar.getInstance().getTime() + ": " + message);
		}

		public void debug(String message, Object[] o) {
			err.println(Calendar.getInstance().getTime() + ": " + message);
			err.println("\t" + concat(o));
		}

		public void debug(String message, Object[][] o) {
			err.println(Calendar.getInstance().getTime() + ": " + message);
			String values = concat(o);
			err.println("\t" + values.replaceAll("\n", "\n\t"));
		}

		public void debug(String message, List<Integer[]> list) {
			err.println(Calendar.getInstance().getTime() + ": " + message);
			String values = concat(list);
			err.println("\t" + values.replaceAll("\n", "\n\t"));
		}

	}

}
