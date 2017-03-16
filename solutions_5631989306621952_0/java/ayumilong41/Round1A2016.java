/**
 * File Name: Round1A2016.java
 * Package Name: yz.google.codejam
 * Project Name: Algorithm
 * Purpose:
 * Created Time: 7:58:30 PM Apr 15, 2016
 * Author: Yaolin Zhang
 */
import java.util.Scanner;

/**
 * @author Yaolin Zhang
 * @time 7:58:30 PM Apr 15, 2016
 */
public class Round1A2016 {
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int t = 1; t <= T; ++t){
			char[] str = scan.next().toCharArray();
			String last = str[0] + "";
			for(int i = 1; i < str.length; ++i){
				if(last.charAt(0) <= str[i]){
					last = str[i] + last;
				}else{
					last += str[i];
				}
			}
			
			System.out.printf("Case #%d: %s\n", t, last);
		}
		scan.close();
	}
}
