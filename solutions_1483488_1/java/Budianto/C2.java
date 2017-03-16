import java.util.*;
import java.io.*;

public class C2 {
	public static String convert(int num) {
		char[] arr = Integer.toString(num).toCharArray();
		Arrays.sort(arr);
		return new String(arr);
	}
	
	// count lower than A
	public static long countRecycle(int A, int num) {
		//long ans = 0;
		
		StringBuffer s = new StringBuffer(Integer.toString(num));
		HashSet<Integer> set = new HashSet<Integer>();
		for(int i=0;i<s.length(); i++) {
			char c = s.charAt(0);
			s = s.deleteCharAt(0);
			s = s.append(c);
			
			int anotherNum = Integer.parseInt(s.toString());
			if (anotherNum >= A && anotherNum < num){ 
				//System.out.println("RECYCLED: "+num+" "+anotherNum);
				//++ans;
				set.add(anotherNum);
			}
		}
		
		return set.size();
	}
	
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		int A, B;
		long ans;
		
		for(int caseNo = 1;caseNo <= T; caseNo++) {
			A = in.nextInt();
			B = in.nextInt();
			ans = 0;
			
			for(int num = A; num <= B; num++) {
				ans += countRecycle(A, num);
			}
				
			System.out.println("Case #"+caseNo+": "+ans);
		}
	}
}