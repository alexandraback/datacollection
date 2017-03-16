import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class A {

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

	}

	/**
	 * Solves a Test Case
	 *
	 * @param caseNum
	 * @throws java.io.IOException
	 */
	private static void solveCase(int caseNum) throws IOException {
		// Read input
		String[] tokens = io.readNextLine();
        int p = Integer.parseInt(tokens[0]);
        int q = Integer.parseInt(tokens[1]);

		// Do the work
        int n = solve(p, q, 40);

		// Print results
		io.printCase(caseNum).println(n > 0 ? n : "impossible");

	}

    private static int solve(long p, long q, int m) {
        int n=0;
        while (p < q && m > 0) {
            p <<= 1;
            n++;
            m--;
        }
        if (m <= 0) {
            return 0;
        } else if (p == q || solve(p-q, q, m) > 0) {
            return n;
        } else {
            return 0;
        }
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
			String[] tokens = line.split("/");
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
