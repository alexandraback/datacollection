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


public class Round1C_C {

	private static final String PROBLEM = "C";
	private static final String ATTEMPT = "7";
	
	private static final String INPUT_FILE  = PROBLEM + "-small-attempt" + ATTEMPT + ".in";
	private static final String OUTPUT_FILE = PROBLEM + "-small-attempt" + ATTEMPT + ".out";
	
	@SuppressWarnings("resource")
	public static void main(String[] args) throws Throwable {

		BufferedReaderWrapper br = null;
		BufferedWriterWrapper bw = null;
		
		try {
			br = new Round1C_C.BufferedReaderWrapper(new FileReader(INPUT_FILE));
			bw = new BufferedWriterWrapper(new FileWriter(OUTPUT_FILE));

			int nCase = br.getIntLine();

			StringBuilder sb = new StringBuilder();
			for (int i=0;i<nCase;i++) {

				int[] oneLine = br.getSplittedInt();
				
				int N, M, K;
				if (oneLine[0] < oneLine[1]) {
					N = oneLine[0];
					M = oneLine[1];
				} else {
					N = oneLine[1];
					M = oneLine[0];
				}
				K = oneLine[2];

				if (K == 1) {
					U.appendCaseResult(sb, i+1, 1);
					continue;
				}
				if (N==1) {
					U.appendCaseResult(sb, i+1, K);
					continue;
				}
				if (K <= N || K <= M) {
					U.appendCaseResult(sb, i+1, K);
					continue;
				}
				
				
				double result = Double.MAX_VALUE;
				double result1 = Double.MAX_VALUE;
				double result2 = Double.MAX_VALUE;
				double result3 = Double.MAX_VALUE;
				double result4 = Double.MAX_VALUE;
				while (result == Double.MAX_VALUE) {
//					while (result == Double.MAX_VALUE && result1 == Double.MAX_VALUE 
//							&& result2 == Double.MAX_VALUE && result3 == Double.MAX_VALUE && result4 == Double.MAX_VALUE ) {
					int K1 = K - 1;
					int K2 = K - 2;
					int K3 = K - 3;
					int K4 = K - 4;

					for (int x = 0;x<=N;x++) {
						double y = (double)(K-2*x)/(double)(x+2);
						double y1 = (double)(K1-2*x)/(double)(x+2);
						double y2 = (double)(K2-2*x)/(double)(x+2);
						double y3 = (double)(K3-2*x)/(double)(x+2);
						double y4 = (double)(K4-2*x)/(double)(x+2);
						if (!(y < 0.0 || y > (double)M) && y % 1.0 == 0.0) {
							result = Math.min(result, K - x*y);
						}
						if (!(y1 < 0.0 || y1 > (double)M) && y1 % 1.0 == 0.0) {
							result1 = Math.min(result1, K - x*y1);
						}
						if (!(y2 < 0.0 || y2 > (double)M) && y2 % 1.0 == 0.0) {
							result2 = Math.min(result2, K - x*y2);
						}
						if (!(y3 < 0.0 || y3 > (double)M) && y3 % 1.0 == 0.0) {
							result3 = Math.min(result3, K - x*y3);
						}
						if (!(y4 < 0.0 || y4 > (double)M) && y4 % 1.0 == 0.0) {
							result4 = Math.min(result4, K - x*y4);
						}
					}
					K++;
				}

				if (result != Double.MAX_VALUE) { 
				U.appendCaseResult(sb, i+1, (int)result);
				continue;
				}
				int finalAns = Math.min(Math.min(Math.min((int)result, ((int)result1)+1), Math.min(((int)result2)+2, ((int)result3)+3)), ((int)result4)+4);
				U.appendCaseResult(sb, i+1, finalAns);
//				if (result != Double.MAX_VALUE) { 
//					U.appendCaseResult(sb, i+1, (int)result);
//				}
//				else if (result1 != Double.MAX_VALUE) { 
//					U.appendCaseResult(sb, i+1, ((int)result1)+1);
//				}
//				else if (result2 != Double.MAX_VALUE) { 
//					U.appendCaseResult(sb, i+1, ((int)result2)+2);
//				}
//				else if (result3 != Double.MAX_VALUE) { 
//					U.appendCaseResult(sb, i+1, ((int)result3)+3);
//				}
//				else { 
//					U.appendCaseResult(sb, i+1, ((int)result4)+4);
//				}
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

