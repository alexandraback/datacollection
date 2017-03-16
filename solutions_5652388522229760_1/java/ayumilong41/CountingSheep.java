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
			long N = scan.nextLong();
			long r = count(N);
			System.out.printf("Case #%d: %s\n", t, r == - 1 ? "INSOMNIA" : Long.toString(r));
		}
		
		scan.close();
	}
	
	public static long count(long n){
		if(n == 0){
			return -1;
		}
		int digits = 0;
		long num = n;
		while(digits != ((1 << 10) - 1)){
			long cur = num;
			while(cur > 0){
				long curDig = cur % 10;
				digits |= (1 << curDig);
				cur = cur / 10;
			}
			num += n;
		}
		
		return num - n;
	}
}
