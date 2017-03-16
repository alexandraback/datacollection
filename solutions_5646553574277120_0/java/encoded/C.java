import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {

	//private static final String STAGE = "C-test";
	//private static final String STAGE = "C-small-attempt0";
	//private static final String STAGE = "C-small-attempt1";
	//private static final String STAGE = "C-small-attempt2";
	//private static final String STAGE = "C-small-attempt3";
	//private static final String STAGE = "C-small-attempt4";
	private static final String STAGE = "C-small-attempt5";
	// private static final String STAGE = "C-large";

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = null;
		PrintStream out = null;
		try {
			in = new Scanner(new File(STAGE + ".in"));
			out = new PrintStream(new File(STAGE + ".out"));
			int t = in.nextInt();
			int caseNumber = 1;
			while (caseNumber <= t) {
				int c = in.nextInt();
				int d = in.nextInt();
				int v = in.nextInt();
				List<Integer> ds = new ArrayList<Integer>();
				for (int i = 0; i < d; i++) {
					ds.add(in.nextInt());
				}
				out.println("Case #" + caseNumber++ + ": " + solve(ds, c, v));
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			if (in != null) {
				in.close();
			}
			if (out != null) {
				out.close();
			}
		}
	}
	
	private static void fillDp(List<Integer> ds, int[] dp, int v) {
		for (int mask = 1; mask < (1 << ds.size()); mask++) {
			String s = Integer.toBinaryString(mask);
			int sum = 0;
			for (int i = s.length() - 1; i >= 0; i--) {
				if (s.charAt(i) == '1') {
					sum += ds.get(s.length() - 1 - i);
				}
			}
			if (sum <= v) {
				dp[sum] = 1;
			}
		}
	}
	
	public static int solve(List<Integer> ds, int c, int v) {
		int[] dp = new int[v + 1];
		fillDp(ds, dp, v);
		int result = 0;
		for (int i = 1; i < dp.length; i++) {
			if (dp[i] == 0) {
				int maxNumber = -1;
				int maxCount = -1;
				for (int number = 1; number <= v; number++) {
					if (ds.contains(number)) {
						continue;
					}
					int count = 0;
					if (dp[number] == 0) {
						count++;
					}
					for (int value = 1; value < dp.length; value++) {
						if (dp[value] == 0) {
							if (number < value && dp[value - number] == 1) {
								count++;
							}
						}
					}
					if (count > maxCount) {
						maxNumber = number;
						maxCount = count;
					}
				}
				result++;
				ds.add(maxNumber);
				fillDp(ds, dp, v);
				i = 0;
			}
		}
		
		return result;
	}
}