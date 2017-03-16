import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class A {

	private static final String PROBLEM = "A";
	private static final String ATTEMPT = "4";

	//private static final String PREFIX = PROBLEM;
	private static final String PREFIX = PROBLEM + "-small-attempt" + ATTEMPT;
	//private static final String PREFIX = PROBLEM + "-large.";
	private static final String INPUT_FILE  = PREFIX + ".in";
	private static final String OUTPUT_FILE = PREFIX + ".out";
	
	public static void solve(int iCase, BufferedReaderWrapper br) throws Throwable {
		String n=br.getStringLine();
		int num = Integer.valueOf(n);
		int digit = n.length();
		char head = n.charAt(0);
		char tail = n.charAt(n.length()-1);
		String rev = new StringBuilder(n).reverse().toString();
		
		long result = sol(n, num, digit, head, tail, rev);
//		result = min(result, sol(rev, num, digit, head, tail, n));
		
		U.appendCaseResult(sb, iCase+1, result);
	}

	private static long sol(String n, int num, int digit, char head, char tail,
			String rev) {
		long result = 0;
		if (n.equals("1")) {
			result = 1;
		} else if (head=='1') {
			if (tail != '1') {
				result = dig[digit-1] + Integer.valueOf(n.substring(1, n.length()));
			} else {
				result = min(dig[digit-1] + Integer.valueOf(n.substring(1, n.length())), 
						1+dig[digit-1] + Integer.valueOf(rev.substring(1, n.length())));
			}
		} else if (tail=='0') {
			int add = head-'0'-1;
			for (int i=0;i<digit-1;i++) {
				add *= 10;
			}
			add += 1;
			add = num-add;
			result = dig[digit-1] + (head-'0'-1)+1+add;
		} else {
			int add = head-'0';
			for (int i=0;i<digit-1;i++) {
				add *= 10;
			}
			add += 1;
			add = num-add;
			result = dig[digit-1] + (head-'0') + 1 + add;
			
			int add2 = head-'0';
			int aaa=0;
			for (int i=digit/2;i<digit;i++) {
				aaa=aaa*10+(n.charAt(i)-'0');
			}
			int bbb=0;
			for (int i=1;i<digit/2;i++) {
				bbb=bbb*10+(n.charAt(i)-'0');
			}
			result = min(result, 
					dig[digit-1] + (head-'0') + 1 + (aaa-1)+1+(num-bbb));
			
		}
		return result;
	}
	
	// StringBuilder to write result
	static StringBuilder sb = new StringBuilder();

	static long[] dig = new long[15];
	
	@SuppressWarnings("resource")
	public static void main(String[] args) throws Throwable {
		BufferedReaderWrapper br = null;BufferedWriterWrapper bw = null;
		try {
			br = new A.BufferedReaderWrapper(new FileReader(INPUT_FILE));
			bw = new BufferedWriterWrapper(new FileWriter(OUTPUT_FILE));
			
			dig[0] = 1;
			dig[1] = 10;
			for (int i=2;i<dig.length;i++) {
				int nine = 9;
				for (int j=0;j<i-2;j++) {
					nine = nine*10+9;
				}
				dig[i] = dig[i-1]+9+1+nine;
//				System.out.println(dig[i]);
			}
			
			int nCase = br.getIntLine();
			for (int iCase=0;iCase<nCase;iCase++) {
				solve(iCase, br);
			}
			bw.write(sb.toString());
		} catch (Throwable t) {
			throw t;
		} finally {
			br.closeQuietly(); bw.closeQuietly();
		}
	}

	// Utilities
	static class U  {
		/** check if all booleans in array is true. */
		public static boolean isAllTrue(boolean[] ba) {
			for (int i = 0;i<ba.length;i++) {
				if (!ba[i]) return false;
			}
			return true;
		}

		/** check if all booleans in array is false */
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

		/** count the number of true in boolean array */
		public static int countTrue(boolean[] ba) {
			int result = 0;
			for (int i = 0;i<ba.length;i++) {
				if (ba[i]) result++;
			}
			return result;
		}

		/** count the number of false in boolean array */
		public static int countFalse(boolean[] ba) {
			int result = 0;
			for (int i = 0;i<ba.length;i++) {
				if (!ba[i]) result++;
			}
			return result;
		}

		/** convert String[] to List<String>. */
		public static List<String> getListFromArray(String[] array) {
			List<String> list = new ArrayList<String>(array.length);
			for (int i=0;i<array.length;i++) {
				list.add(array[i]);
			}
			return list;
		}
		
		public static List<Integer> getListFromArray(Integer[] array) {
			List<Integer> list = new ArrayList<Integer>(array.length);
			for (int i=0;i<array.length;i++) {
				list.add(array[i]);
			}
			return list;
		}
		
		public static List<Integer> getListFromArray(int[] array) {
			List<Integer> list = new ArrayList<Integer>(array.length);
			for (int i=0;i<array.length;i++) {
				list.add(array[i]);
			}
			return list;
		}
		
		public static List<Long> getListFromArray(Long[] array) {
			List<Long> list = new ArrayList<Long>(array.length);
			for (int i=0;i<array.length;i++) {
				list.add(array[i]);
			}
			return list;
		}
		
		public static List<Long> getListFromArray(long[] array) {
			List<Long> list = new ArrayList<Long>(array.length);
			for (int i=0;i<array.length;i++) {
				list.add(array[i]);
			}
			return list;
		}
		
		public static List<Double> getListFromArray(Double[] array) {
			List<Double> list = new ArrayList<Double>(array.length);
			for (int i=0;i<array.length;i++) {
				list.add(array[i]);
			}
			return list;
		}

		public static List<Double> getListFromArray(double[] array) {
			List<Double> list = new ArrayList<Double>(array.length);
			for (int i=0;i<array.length;i++) {
				list.add(array[i]);
			}
			return list;
		}

		/** convert String[] to Set<String>. */
		public static Set<String> getSetFromArray(String[] array) {
			Set<String> set = new HashSet<String>(array.length);
			for (int i=0;i<array.length;i++) {
				set.add(array[i]);
			}
			return set;
		}
		
		public static Set<Integer> getSetFromArray(Integer[] array) {
			Set<Integer> set = new HashSet<Integer>(array.length);
			for (int i=0;i<array.length;i++) {
				set.add(array[i]);
			}
			return set;
		}
		
		public static Set<Integer> getSetFromArray(int[] array) {
			Set<Integer> set = new HashSet<Integer>(array.length);
			for (int i=0;i<array.length;i++) {
				set.add(array[i]);
			}
			return set;
		}
		
		public static Set<Long> getSetFromArray(Long[] array) {
			Set<Long> set = new HashSet<Long>(array.length);
			for (int i=0;i<array.length;i++) {
				set.add(array[i]);
			}
			return set;
		}
		
		public static Set<Long> getSetFromArray(long[] array) {
			Set<Long> set = new HashSet<Long>(array.length);
			for (int i=0;i<array.length;i++) {
				set.add(array[i]);
			}
			return set;
		}
		
		public static Set<Double> getSetFromArray(double[] array) {
			Set<Double> set = new HashSet<Double>(array.length);
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

		public static void appendCaseResult(StringBuilder sb, int iCase, long val) {
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

		public static String[] copyStrArray(String[] sa) {
			return Arrays.copyOf(sa, sa.length);
		}

		public static int[] copyIntArray(int[] ia) {
			return Arrays.copyOf(ia, ia.length);
		}
		
		public static double[] copyDoubleArray(double[] da) {
			return Arrays.copyOf(da, da.length);
		}
		
		public static boolean[] copyBooleanArray(boolean[] ba) {
			return Arrays.copyOf(ba, ba.length);
		}
		
		public static void swap(String[] sa, int i, int j) {
			String tmp = sa[i];
			sa[i] = sa[j];
			sa[j] = tmp;
		}
		
		public static void swap(int[] sa, int i, int j) {
			int tmp = sa[i];
			sa[i] = sa[j];
			sa[j] = tmp;
		}
		
		public static void swap(double[] sa, int i, int j) {
			double tmp = sa[i];
			sa[i] = sa[j];
			sa[j] = tmp;
		}
		
		public static int bit2int(String bit) {
			int ans = 0;
			for (int i=0;i<bit.length();i++) {
				ans = (ans<<1) + (bit.charAt(i) - '0');
			}
			return ans;
		}

		public static long bit2long(String bit) {
			long ans = 0;
			for (int i=0;i<bit.length();i++) {
				ans = (ans<<1) + bit.charAt(i) - '0';
			}
			return ans;
		}
		
		public static String int2bit(int input) {
			StringBuilder sb = new StringBuilder();
			while (input != 0) {
				sb.append(input&1);
				input = input>>1;
			}
			return sb.reverse().toString();
		}

		public static String long2bit(long input) {
			StringBuilder sb = new StringBuilder();
			while (input != 0) {
				sb.append(input&1);
				input = input>>1;
			}
			return sb.reverse().toString();
		}

		public static int countBits(int input) {
			int result = 0;
			while (input != 0) {
				result += input&1;
				input = input>>1;
			}
			return result;
		}

		public static int countBits(long input) {
			int result = 0;
			while (input != 0) {
				result += input&1;
				input = input>>1;
			}
			return result;
		}
	}

	private static class BufferedReaderWrapper extends BufferedReader {
		public BufferedReaderWrapper(Reader r) {
			super(r);
		}

		public int getIntLine() throws IOException {
			return Integer.parseInt(super.readLine());
		}

		public String getStringLine() throws IOException {
			return super.readLine();
		}

		public String[] getSplittedString() throws IOException {
			return super.readLine().split(" ");
		}

		public int[] getSplittedInt() throws IOException {
			String [] sa = super.readLine().split(" ");
			int[] result = new int[sa.length];
			for (int i=0;i<sa.length;i++) result[i] = Integer.parseInt(sa[i]);
			return result;
		}

		public Integer[] getSplittedObjInt() throws IOException {
			String [] sa = super.readLine().split(" ");
			Integer[] result = new Integer[sa.length];
			for (int i=0;i<sa.length;i++) result[i] = Integer.parseInt(sa[i]);
			return result;
		}

		public long[] getSplittedLong() throws IOException {
			String [] sa = super.readLine().split(" ");
			long[] result = new long[sa.length];
			for (int i=0;i<sa.length;i++) result[i] = Long.parseLong(sa[i]);
			return result;
		}

		public Long[] getSplittedObjLong() throws IOException {
			String [] sa = super.readLine().split(" ");
			Long[] result = new Long[sa.length];
			for (int i=0;i<sa.length;i++) result[i] = Long.parseLong(sa[i]);
			return result;
		}

		public double[] getSplittedDouble() throws IOException {
			String [] sa = super.readLine().split(" ");
			double[] result = new double[sa.length];
			for (int i=0;i<sa.length;i++) result[i] = Double.parseDouble(sa[i]);
			return result;
		}

		public Double[] getSplittedObjDouble() throws IOException {
			String [] sa = super.readLine().split(" ");
			Double[] result = new Double[sa.length];
			for (int i=0;i<sa.length;i++) result[i] = Double.parseDouble(sa[i]);
			return result;
		}

		public void closeQuietly() {
			try {
				if (this != null) super.close();
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
				if (this != null) super.close();
			} catch (Throwable t) {
				// nothing to do
			}
		}
	}
	
	private static class DescComparatorI implements Comparator<Integer> {
		public int compare(Integer i0, Integer i1) {
			if (i1.equals(i0)) return 0;
			return i1 > i0 ? 1 : -1;
		}
	}
	
	private static class DescComparatorL implements Comparator<Long> {
		public int compare(Long l0, Long l1) {
			if (l1.equals(l0)) return 0;
			return l1 > l0 ? 1 : -1;
		}
	}
	
	private static class DescComparatorD implements Comparator<Double> {
		public int compare(Double d0, Double d1) {
			if (d1.equals(d0)) return 0;
			return d1 > d0 ? 1 : -1;
		}
	}
}

