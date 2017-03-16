import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class match {
	private static int ansFirst = 10000000, ansSecond = 10000000;
	private static int min = 10000000;
	private static String first, second;
	public static void main(String[] args) throws IOException {
		BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(read.readLine());
		for (int i = 0; i < t; i++) {
			String s = read.readLine();
			first = s.substring(0, s.indexOf(" "));
			second = s.substring(s.indexOf(" " ) + 1);
			int numQ = 0;
			for (int j = 0; j < first.length(); j++) {
				if (first.charAt(j) == '?') {
					numQ++;
				}
				if (second.charAt(j) == '?') {
					numQ++;
				}
			}
			int[] temp = new int[numQ];
			recurse(temp, 0);
			String a1 = Integer.toString(ansFirst), a2 = Integer.toString(ansSecond);
			while (a1.length() < first.length()) {
				a1 = "0" + a1;
			}
			while (a2.length() < second.length()) {
				a2 = "0" + a2;
			}
			System.out.println("Case #" + (i + 1) + ": " + a1 + " " + a2);
			ansFirst = 10000000;
			ansSecond = 10000000;
			min = 10000000;
		}
	}
	public static void recurse(int[] nums, int pos) {
		if (pos == nums.length) {
			int num = 0;
			String fFirst = "";
			for (int i = 0; i < first.length(); i++) {
				if (first.charAt(i) == '?') {
					fFirst += nums[num] + "";
					num++;
				} else {
					fFirst += first.charAt(i);
				}
			}
			String sSecond = "";
			for (int i = 0; i < second.length(); i++) {
				if (second.charAt(i) == '?') {
					sSecond += nums[num] + "";
					num++;
				} else {
					sSecond += second.charAt(i);
				}
			}
			if (Math.abs(Integer.parseInt(fFirst) - Integer.parseInt(sSecond)) < min) {
				min = Math.abs(Integer.parseInt(fFirst) - Integer.parseInt(sSecond));
				ansFirst = Integer.parseInt(fFirst);
				ansSecond = Integer.parseInt(sSecond);
			} else if (Math.abs(Integer.parseInt(fFirst) - Integer.parseInt(sSecond)) == min) {
				if (Integer.parseInt(fFirst) < ansFirst) {
					min = Math.abs(Integer.parseInt(fFirst) - Integer.parseInt(sSecond));
					ansFirst = Integer.parseInt(fFirst);
					ansSecond = Integer.parseInt(sSecond);
				} else if (Integer.parseInt(fFirst) == ansFirst) {
					if (Integer.parseInt(sSecond) < ansSecond) {
						min = Math.abs(Integer.parseInt(fFirst) - Integer.parseInt(sSecond));
						ansFirst = Integer.parseInt(fFirst);
						ansSecond = Integer.parseInt(sSecond);
					}
				}
			}
			return;
		}
		for (int i = 0; i < 10; i++) {
			nums[pos] = i;
			recurse(nums, pos + 1);
		}
	}
}
