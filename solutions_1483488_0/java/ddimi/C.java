import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Calendar;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class C {

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
	 * @throws IOException
	 */
	private static void solveCase(int caseNum) throws IOException {
		// Read input
		String[] tokens = io.readNextLine();
		int a = Integer.parseInt(tokens[0]);
		int b = Integer.parseInt(tokens[1]);
		
		// Do the work
		Set<String> recycled = new HashSet<String>();
		for (int n=a; n<=b; n++) {
			String nstr = Integer.toString(n);
			int firstDigit = Integer.parseInt(nstr.substring(0, 1));
			for (int i=1; i<nstr.length(); i++) {
				if (Integer.parseInt(nstr.substring(i, i+1)) < firstDigit) {
					continue;
				} else {
					int m = Integer.parseInt(nstr.substring(i) + nstr.substring(0, i));
					if (m > n && m >= a && m <= b) {
						recycled.add(Integer.toString(n) + Integer.toString(m));
					}
				}
			}
		}

		// Print results
		io.printCase(caseNum).println(recycled.size());

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
