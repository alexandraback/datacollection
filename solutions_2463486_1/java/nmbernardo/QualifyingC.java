import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;


public class QualifyingC {
	
	
	static TreeSet<Long> mapper = new TreeSet<Long>();
	
	
	public static boolean ispalindrome(Long num) {
		
		char s[] = Long.toString(num).toCharArray();
		
		
		for(int i = 0; i < s.length ; i++) {
			if(s[i] != s[s.length - i - 1]) {
				return false;
			}
		}
		
		return true;
	}
	

	
	public static void main(String[] args) throws Exception{
		
		System.setIn(new FileInputStream("test.in"));
		System.setOut(new PrintStream(new FileOutputStream("C.out")));
		Scanner sc = new Scanner(System.in);
		
		
		
//		
//		HashSet<Long> s = allPalindromic(100000000L);
//		
//		System.out.println(s);
		
		
		mapper.add(1L);
		mapper.add(0L);
		
				
		for(long i = 2L; i <=  20000000;i++) {
				boolean first = true;
				
			//	System.out.println(i);
				
				Long val = i;
				
				while(ispalindrome(val)) {
					if(first)
						first = false;
					else
						mapper.add(val);
					
					if(val >= Math.floor((Math.sqrt(Long.MAX_VALUE))))
						break;
					
					val *= val;
				}
		}
		
		
//		System.out.println(mapper.size());
		
		Iterator<Long> it = mapper.iterator();
		
		
		int ind = 0;

		long arr[] = new long[mapper.size()];
		
		while(it.hasNext()) {
			long val = it.next();
			
			arr[ind++] = val;
		}
		
		
		
		Arrays.sort(arr);
		
		
		
//		for(int i = 0; i < arr.length; i++) {
//			System.out.println(arr[i]);
//		}
		
		
		
		int T = sc.nextInt();
		
		for(int t=1; t <= T; t++) {
			long A = sc.nextLong();
			long B = sc.nextLong();
			
			
			if(B < A) {
				long tmp = A;
				A = B;
				B = tmp;
			}
			
			
			int B_ind = -1;
			int A_ind= -1;
			
			for(int i = 0; i < arr.length; i++) {
				if(arr[i] >  B) {
					B_ind = i - 1;
					break;
				}
			}
			
			for(int i = 0; i < arr.length; i++) {
				if(arr[i] >= A) {
					A_ind = i - 1;
					break;
				}
			}
			
			System.out.printf("Case #%d: %d",t,B_ind - A_ind);
			System.out.println();
			
			
		}
	
		
		
		
		
	}
}
