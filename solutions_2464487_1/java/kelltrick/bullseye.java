import java.io.*;
import java.util.*;

public class bullseye {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 1; i <= n; i++){
			long r = sc.nextLong();
			long t = sc.nextLong();
			long ans = getAns(r,t);
			System.out.printf("Case #%d: %d\n",i,ans);
		}
	}

	private static long getAns(long r, long t) {
		long max = 1;

		while(f(r,max) < f(r,max+1) && f(r,max) <= t){
			max<<=1;
		}
		
		long low = 0;
		long high = max;
		long mid = (low+high)/2;

		while(f(r,mid) > t || (f(r,mid) < t && f(r,mid+1) <= t))
		{
			if(f(r,mid) > t)
				high = mid;
			else if(f(r,mid) < t)
				low = mid;
			else 
				return mid;

			mid = (low+high)/2;
		}

		return mid;
	}
	
	private static long f(long r, long n){
		n--;
		long ret = 0;
		ret += 2*n*n;
		ret += 2*n*r;
		ret += 3*n;
		ret += 2*r;
		ret += 1;
		return ret;
	}

}
