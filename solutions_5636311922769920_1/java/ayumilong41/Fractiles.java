/**
 * File Name: Fractiles.java
 * Package Name: yz.google.codejam
 * Project Name: Algorithm
 * Purpose:
 * Created Time: 8:11:23 PM Apr 8, 2016
 * Author: Yaolin Zhang
 */

import java.util.*;

/**
 * @author Yaolin Zhang
 * @time 8:11:23 PM Apr 8, 2016
 */
public class Fractiles {
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int t = 1; t <= T; ++t){
			int K = scan.nextInt();
			int C = scan.nextInt();
			int S = scan.nextInt();
			int ans = (int)Math.ceil(K / (double)C);
			//System.out.println("ans: " + ans);
			if(ans > S){
				System.out.printf("Case #%d: IMPOSSIBLE\n", t);
				continue;
			}
			long[] pos = new long[ans];
			for(int i = 0; i < ans; ++i){
				int start = C * i + 1;
				int end = (i + 1) * C;
				end = end < K ? end : K;
				long cur = 0;
				long radix = 1L;
				for(int j = 0; j < C; ++j){
					cur += (end - 1) * radix;
					radix *= K;
					--end;
					end = end > start ? end : start;
				}
				pos[i] = cur + 1;
			}
			System.out.printf("Case #%d: ", t);
			for(long p : pos){
				System.out.print(p + " ");
			}
			System.out.println();
		}
		scan.close();
	}
}
