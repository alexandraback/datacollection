import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


public class Round1C_A_ {

	private static final String PROBLEM = "A";
	private static final String ATTEMPT = "0";
	
	private static final String INPUT_FILE  = "A-large.in";//PROBLEM + "-small-attempt" + ATTEMPT + ".in";
	private static final String OUTPUT_FILE = "A-large.out";//PROBLEM + "-small-attempt" + ATTEMPT + ".out";
	
	@SuppressWarnings("resource")
	public static void main(String[] args) throws Throwable {

		BufferedReaderWrapper br = null;
		BufferedWriterWrapper bw = null;
		
		try {
			br = new Round1C_A_.BufferedReaderWrapper(new FileReader(INPUT_FILE));
			bw = new BufferedWriterWrapper(new FileWriter(OUTPUT_FILE));

			int nCase = br.getIntLine();

			StringBuilder sb = new StringBuilder();
			for (int i=0;i<nCase;i++) {

				String[] line = br.readLine().split("/");

				double answ = Double.valueOf(line[0]) / Double.valueOf(line[1]);

				int anscestor = 0;
				// count ansector
				while (answ < 1.0 && anscestor < 41) {
					answ *= 2.0;
					anscestor ++;
				}
				
				int result = anscestor;
				// determin if possible
				while ((answ % 1.0 ) != 0.0 && anscestor < 41) {
					answ *= 2.0;
					anscestor++;
				}
				U.appendCaseResult(sb, i+1, (answ % 1.0 )== 0.0 && anscestor < 41, result, "impossible");
				
				//U.appendCaseResult(sb, i+1, result == -1, "", result);
				/*
				sb.append("Case #");
				sb.append(i+1);
				sb.append(": ");
				if (result == -1) {
					sb.append("NOT POSSIBLE");
				} else {
					sb.append(result);
				}
				sb.append("\n");
				//*/
			}
			
			bw.write(sb.toString());
		
		} catch (Throwable t) {
			throw t;
		} finally {
			br.closeQuietly();
			bw.closeQuietly();
		}
	}


	
	
	
	// Utilities
	static class U  {
		/**
		 * check if all booleans in array is true.
		 * 
		 * @param ba
		 * @return
		 */
		public static boolean isAllTrue(boolean[] ba) {
			for (int i = 0;i<ba.length;i++) {
				if (!ba[i]) return false;
			}
			return true;
		}

		/**
		 * check if all booleans in array is false
		 * 
		 * @param ba
		 * @return
		 */
		public static boolean isAllFalse(boolean[] ba) {
			for (int i = 0;i<ba.length;i++) {
				if (ba[i]) return false;
			}
			return true;
		}

		public static boolean containsTrue(boolean[] ba) {
			return !isAllFalse(ba);
		}
		
		public static boolean containsFalse(boolean[] ba) {
			return !isAllTrue(ba);
		}

		/**
		 * count the number of true in boolean array
		 * 
		 * @param ba
		 * @return
		 */
		public static int countTrue(boolean[] ba) {
			int result = 0;
			for (int i = 0;i<ba.length;i++) {
				if (ba[i]) result++;
			}
			return result;
		}

		/**
		 * count the number of false in boolean array
		 * 
		 * @param ba
		 * @return
		 */
		public static int countFalse(boolean[] ba) {
			int result = 0;
			for (int i = 0;i<ba.length;i++) {
				if (!ba[i]) result++;
			}
			return result;
		}

		/**
		 * convert String[] to List<String>.
		 * 
		 * @param array
		 * @return
		 */
		public static List<String> getListFromArray(String[] array) {
			List<String> list = new ArrayList<String>(array.length);
			for (int i=0;i<array.length;i++) {
				list.add(array[i]);
			}
			return list;
		}
		
		/**
		 * convert String[] to Set<String>.
		 * 
		 * @param array
		 * @return
		 */
		public static Set<String> getSetFromArray(String[] array) {
			Set<String> set = new HashSet<String>(array.length);
			for (int i=0;i<array.length;i++) {
				set.add(array[i]);
			}
			return set;
		}
		
		public static void appendCaseResult(StringBuilder sb, int iCase, int val) {
			sb.append("Case #");
			sb.append(iCase);
			sb.append(": ");
			sb.append(val);
			sb.append("\n");
		}

		public static void appendCaseResult(StringBuilder sb, int iCase, String val) {
			sb.append("Case #");
			sb.append(iCase);
			sb.append(": ");
			sb.append(val);
			sb.append("\n");
		}

		public static void appendCaseResult(StringBuilder sb, int iCase, boolean b, int val1, int val2) {
			sb.append("Case #");
			sb.append(iCase);
			sb.append(": ");
			if (b) {
				sb.append(val1);
			} else {
				sb.append(val2);
			}
			sb.append("\n");
		}

		public static void appendCaseResult(StringBuilder sb, int iCase, boolean b, String val1, String val2) {
			sb.append("Case #");
			sb.append(iCase);
			sb.append(": ");
			if (b) {
				sb.append(val1);
			} else {
				sb.append(val2);
			}
			sb.append("\n");
		}

		public static void appendCaseResult(StringBuilder sb, int iCase, boolean b, int val1, String val2) {
			sb.append("Case #");
			sb.append(iCase);
			sb.append(": ");
			if (b) {
				sb.append(val1);
			} else {
				sb.append(val2);
			}
			sb.append("\n");
		}

		public static void appendCaseResult(StringBuilder sb, int iCase, boolean b, String val1, int val2) {
			sb.append("Case #");
			sb.append(iCase);
			sb.append(": ");
			if (b) {
				sb.append(val1);
			} else {
				sb.append(val2);
			}
			sb.append("\n");
		}
	}

	private static class BufferedReaderWrapper extends BufferedReader {

		public BufferedReaderWrapper(Reader r) {
			super(r);
		}

		public int getIntLine() throws IOException {
			int n = Integer.parseInt(super.readLine());
			return n;
		}

		public String[] getSplittedString() throws IOException {
			String [] sa = super.readLine().split(" ");
			return sa;
		}

		public int[] getSplittedInt() throws IOException {
			String [] sa = super.readLine().split(" ");
			int[] result = new int[sa.length];
			for (int i=0;i<sa.length;i++) {
				result[i] = Integer.parseInt(sa[i]);
			}
			return result;
		}

		public double[] getSplittedDouble() throws IOException {
			String [] sa = super.readLine().split(" ");
			double[] result = new double[sa.length];
			for (int i=0;i<sa.length;i++) {
				result[i] = Double.parseDouble(sa[i]);
			}
			return result;
		}

		public String[] copyStrArray(String[] sa) {
			return Arrays.copyOf(sa, sa.length);
		}

		public int[] copyIntArray(int[] ia) {
			return Arrays.copyOf(ia, ia.length);
		}
		
		public double[] copyDoubleArray(double[] da) {
			return Arrays.copyOf(da, da.length);
		}
		
		public void swap(String[] sa, int i, int j) {
			String tmp = sa[i];
			sa[i] = sa[j];
			sa[j] = tmp;
		}
		
		public void swap(int[] sa, int i, int j) {
			int tmp = sa[i];
			sa[i] = sa[j];
			sa[j] = tmp;
		}
		
		public void swap(double[] sa, int i, int j) {
			double tmp = sa[i];
			sa[i] = sa[j];
			sa[j] = tmp;
		}
		
		public void closeQuietly() {
			try {
				if (this != null) {
					super.close();
				}
			} catch (Throwable t) {
				// nothing to do
			}
		}
	}

	private static class BufferedWriterWrapper extends BufferedWriter {

		public BufferedWriterWrapper(Writer w) {
			super(w);
		}

		public void closeQuietly() {
			try {
				if (this != null) {
					super.close();
				}
			} catch (Throwable t) {
				// nothing to do
			}
		}
	}
}

