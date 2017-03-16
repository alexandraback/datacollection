/**
 * File Name: RevengeOfThePancakes.java
 * Package Name: yz.google.codejam
 * Project Name: Algorithm
 * Purpose:
 * Created Time: 6:43:02 PM Apr 8, 2016
 * Author: Yaolin Zhang
 */

import java.util.*;

/**
 * @author Yaolin Zhang
 * @time 6:43:02 PM Apr 8, 2016
 */
public class RevengeOfThePancakes {
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int t = 1; t <= T; ++t){
			String s = scan.next();
			int count = change(s);
			System.out.printf("Case #%d: %d\n", t, count);
		}
		
		scan.close();
	}
	
	public static int change(String s){
		int lastMinus = s.length() - 1;
		while(lastMinus >= 0 && s.charAt(lastMinus) == '+'){
			--lastMinus;
		}
		if(lastMinus == -1){//All '+'
			return 0;
		}
		char pre = s.charAt(0);
		int count = 0;
		for(int i = 1; i <= lastMinus; ++i){
			if(s.charAt(i) == pre){
				continue;
			}else{
				++count;
				pre = s.charAt(i);
			}
		}
		return (pre == '-') ? count + 1 : count;
	}
}
