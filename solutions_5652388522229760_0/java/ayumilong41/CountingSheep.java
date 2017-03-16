/**
 * File Name: CountingSheep.java
 * Package Name: yz.google.codejam
 * Project Name: Algorithm
 * Purpose:
 * Created Time: 6:00:41 PM Apr 8, 2016
 * Author: Yaolin Zhang
 */

import java.util.*;

/**
 * @author Yaolin Zhang
 * @time 6:00:41 PM Apr 8, 2016
 */
public class CountingSheep {
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int t = 1; t <= T; ++t){
			int N = scan.nextInt();
			int r = count(N);
			System.out.printf("Case #%d: %s\n", t, r == - 1 ? "INSOMNIA" : Integer.toString(r));
		}
		
		scan.close();
	}
	
	public static int count(int n){
		if(n == 0){
			return -1;
		}
		int digits = 0;
		int oldN = n;
		while(digits != ((1 << 10) - 1)){
			int cur = n;
			while(cur > 0){
				int curDig = cur % 10;
				digits |= (1 << curDig);
				cur = cur / 10;
			}
			n += oldN;
		}
		
		return n - oldN;
	}
}
