import java.io.*;
import java.util.*;

public class C {
	
	static int sqrt(long n){
		long left = 0;
		long right = 10000000;		
		while(left < right-1){
			long mid = (left+right)/2;
			if(mid*mid <= n){
				left = mid;
			}else{
				right = mid;
			}
		}
		return (int)left;
	}
	
	static boolean isPalindrom(String a){
		char[] chs = a.toCharArray();
		int n = chs.length;		
		for(int i = 0; i < n/2; i++){
			if(chs[i] != chs[n-1-i]) return false;
		}
		return true;
	}

	public static void main(String[] args) {
		Scanner in = null;
		PrintWriter out = null;
		try {
			in = new Scanner(new File("C-small-attempt0.in"));
			out = new PrintWriter("output.txt");
		} catch (Exception e) {
			e.printStackTrace();
		}
		long[] count = new long[10000000+1];
		for(long i = 1;  i <= 10000000; i++){
			if(isPalindrom(String.valueOf(i)) && isPalindrom(String.valueOf(i*i))){
				count[(int)i] = count[(int)i-1]+1;
			}else{
				count[(int)i] = count[(int)i-1];
			}
		}		
		int T = in.nextInt();
		for(int c = 0; c < T; c++){
			out.print("Case #" + (c+1) + ": ");
			long A = in.nextLong();
			long B = in.nextLong();
			out.println(count[(int)sqrt(B)]-count[(int)sqrt(A-1)]);
		}
		in.close();
		out.close();
	}

}

