import java.util.*;
import java.io.*;

public class C {
	public static String convert(int num) {
		char[] arr = Integer.toString(num).toCharArray();
		Arrays.sort(arr);
		return new String(arr);
	}
	
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		HashMap<String, Long> map = new HashMap<String, Long>();
		int A, B;
		long ans;
		
		for(int caseNo = 1;caseNo <= T; caseNo++) {
			A = in.nextInt();
			B = in.nextInt();
			ans = 0;
			map.clear();
			
			for(int num = A; num <= B; num++) {
				String s = convert(num);
				long curCount = 0;
				if (map.containsKey(s)) {
					curCount = map.get(s);
				}
				//System.out.println("NUM: "+num+" "+s+" count: "+curCount);
				ans += curCount;
				map.put(s, curCount + 1);
			}
			
			ans = 0;
			for(String s : map.keySet()) {
				long cnt = map.get(s);
				if (cnt > 1) ++ans;
			}
				
			System.out.println("Case #"+caseNo+": "+ans);
		}
	}
}