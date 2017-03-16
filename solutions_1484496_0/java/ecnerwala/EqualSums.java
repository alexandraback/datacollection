import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

public class EqualSums {

	public static Scanner sc;
	public static PrintWriter out;
	public static int[] pow2;

	public static void main(String[] args) throws Exception{
		char problem = 'C';
		boolean smallCase = true;
		boolean practice = false;
		sc = new Scanner(new File(problem + "-" + (smallCase ? "small" : "large") + (practice ? "-practice" : "") + ".in"));
		out = new PrintWriter(new FileWriter(problem + "-" + (smallCase ? "small" : "large") + (practice ? "-practice" : "") + ".out"));
		pow2 = new int[25];
		pow2[0] = 1;
		for(int i = 1; i < pow2.length; i++) pow2[i] = 2 * pow2[i - 1];
		int t = sc.nextInt();
		for(int i = 1; i <= t; i++) {
			out.println("Case #" + i + ":");
			solve();
		}
		out.close();
		System.exit(0);
	}

	public static void solve() {
		int num = sc.nextInt();
		int[] nums = new int[num];
		for(int i = 0; i < num; i++) nums[i] = sc.nextInt();
		HashMap<Integer, Integer> sums = new HashMap<Integer, Integer>();
		for(int subset = 0; subset < pow2[num]; subset++) {
			int sum = 0;
			for(int index = 0; index < num; index++) if((pow2[index] & subset) > 0) sum += nums[index];
			if(sums.containsKey(sum)) {
				for(int index = 0; index < num; index++) if((pow2[index] & subset) > 0) out.print(nums[index] + " ");
				out.println();
				subset = sums.get(sum);
				for(int index = 0; index < num; index++) if((pow2[index] & subset) > 0) out.print(nums[index] + " ");
				out.println();
				return;
			} else sums.put(sum, subset);
		}
		out.println("Impossible");
	}

}
