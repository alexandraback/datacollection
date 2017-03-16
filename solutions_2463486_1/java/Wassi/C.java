package qualification;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long max=10000000;
		HashSet<Long> fands = new HashSet<Long>();
		long n=1;
		while(true){
			if(isPalindrom(n) && isPalindrom(n*n)){
				fands.add(n*n);
			}
			long tmp=makePalindrom(n, 1);
			if(tmp>max) break;
			if(isPalindrom(tmp*tmp)){
				fands.add(tmp*tmp);
			}
			tmp=makePalindrom(n, 0);
			if(tmp<=max){
				if(isPalindrom(tmp*tmp)){
					fands.add(tmp*tmp);
				}
			}
			n++;
		}
		Long[] nums = new Long[fands.size()];
		nums = fands.toArray(nums);
		Arrays.sort(nums);
		
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for(int t=1;t<=T;t++){
			long A= s.nextLong();
			long B = s.nextLong();
			
			int cnt = 0;
			for(int i=0;i<nums.length;i++){
				if(nums[i]>=A && nums[i]<=B) cnt++;
			}
			
			System.out.println("Case #" + t + ": " + cnt);
		}
		
	}
	
	public static boolean isPalindrom(long n){
		char[] p=(n+"").toCharArray();
		for(int i=0;i<p.length/2;i++){
			if(p[i]!=p[p.length-1-i]) return false;
		}
		return true;
	}
	public static long makePalindrom(long n, int start){
		char[] nt = (n+"").toCharArray();
		char[] ntt = new char[2*nt.length-start];
		for(int i=0;i<nt.length;i++){
			ntt[i]=nt[i];
		}
		int pos=nt.length;
		for(int i=nt.length-1-start;i>=0;i--){
			ntt[pos++] = nt[i];
		}
		return Long.parseLong(String.valueOf(ntt));
	}

}
