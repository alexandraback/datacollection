import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.util.Scanner;

public class Q2 {
	public static void main(String[] args) {
		try {
			Scanner sc = new Scanner(new FileInputStream(new File("B-small-attempt0.in")));
			BufferedWriter bos = new BufferedWriter(new FileWriter(new File("B-small-attempt0.out")));
			int cNum = Integer.parseInt(sc.nextLine());
			for (int i = 0; i < cNum; i++) {
				max = 0;
				int[] cnt = new int['Z' - 'A' + 1];
				String[] nums = sc.nextLine().split(" ");
				int K = Integer.parseInt(nums[0]);
				int L = Integer.parseInt(nums[1]);
				int S = Integer.parseInt(nums[2]);
				String keyboard = sc.nextLine();
				String target = sc.nextLine();
				int len = keyboard.length();
				for (int c = 0; c < len; c++) {
					cnt[keyboard.charAt(c) - 'A']++;
				}

				int divisor = 1;
				for (int j=0; j<S; j++) {
					divisor *= len;
				}
				double optimal = -bruteForce(keyboard, S, target, 0, "")*1.0f/divisor + max;
//				System.out.println(max+" "+optimal+" "+(bruteForce(keyboard, S, target, 0, "")*1.0f/divisor)+" "+bruteForce(keyboard, S, target, 0, ""));
				bos.write(String.format("Case #%d: %f\n", i + 1, optimal));
				bos.flush();
			}
			sc.close();
			bos.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	static int max = 0;
	private static int bruteForce(String keyboard, int S, String target, int depth, String builtStr) {
		int len = keyboard.length();
		int ret = 0;
		if (depth == S) {
			int tLen = target.length();
			for (int i = 0; i < S - tLen + 1; i++) {
				boolean match = true;
				for (int j = 0; j < tLen; j++) {
					if (target.charAt(j) != builtStr.charAt(i + j)) {
						match = false;
						break;
					}
				}
				if (match)
					ret++;
//				System.out.println(builtStr+" "+ret+" "+target);
			}
			max = Math.max(max, ret);
		} else {
			for (int i = 0; i < len; i++) {
				ret += bruteForce(keyboard, S, target, depth + 1, builtStr + keyboard.charAt(i));
			}
		}
		return ret;
	}

}
