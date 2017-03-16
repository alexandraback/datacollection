import java.util.*;
import java.io.*;

public class C{
	public static boolean isPalindrome(long val) {
		String s = Long.toString(val);
		for(int i=0;i<s.length()/2;i++) {
			if (s.charAt(i) != s.charAt(s.length()-i-1)) return false;
		}
		return true;
	}
	
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for(int caseNo=1;caseNo<=T;caseNo++){
			long A = in.nextLong();
			long B = in.nextLong();
			
			long cnt = 0;
			for(int i=1;i<=10000000;i++) {
				long num = i;
				long sq = num * num;
				if (sq >= A && sq <= B) {
					if (isPalindrome(num) && isPalindrome(sq)){
						//System.out.println(num);
						++cnt;
					}
				}
			}
			
			System.out.println("Case #"+caseNo+": "+cnt);
		}
	}
}