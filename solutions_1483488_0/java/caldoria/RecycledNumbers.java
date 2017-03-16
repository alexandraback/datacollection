package codejam;

import java.util.*;

public class RecycledNumbers {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for (int k = 1; k <= T; k++) {
			
			int c = 0;
			
			int A = in.nextInt();
			int B = in.nextInt();
			
			for (int cand = A; cand <= B; cand++) {
				String str = Integer.toString(cand);
				char[] cstr = str.toCharArray();
				int n = cstr.length;
				int first = cstr[0]-0x30;
				int mod = (int)Math.pow(10, n-1);
				Set<String> ms = new HashSet<String>();
				for (int i = 1; i < n; i++) {
					int d = cstr[i]-0x30;
					if (d == 0) continue;
					if (d >= first) {
							String teststr = str.substring(i) + str.substring(0, i);
							if (ms.contains(teststr)) {
								continue;
							}
							ms.add(teststr);
							int test = Integer.parseInt(teststr);
							if (test <= B && test > cand) {
								System.out.println(str + ", " + teststr + ", " + A + ", " + B);
								c++;
							}
					}
				}
			}
			
			System.out.println("Case #" + k + ": " + c);
			
		}
		
	}

}
