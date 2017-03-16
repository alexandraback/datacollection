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
			System.out.printf("Case #%d: ", t);
			for(int i = 1; i<= S; ++i){
				System.out.print(i + " ");
			}
			System.out.println("\n");
		}
		
		scan.close();
	}
}
