import java.util.Arrays;
import java.util.Scanner;


public class Problem1 {
	
	static int[] cache = new int[1000000];
	static int[] prev = new int[cache.length];
	static {
		Arrays.fill(cache, Integer.MAX_VALUE);
		cache[1] = 1;
		for(int k=1; k < cache.length-1; k++) {
			if(cache[k+1] > cache[k]+1) {
				cache[k+1] = cache[k]+1;
				prev[k+1] = k;
			}
			int rev = (int) rev(k);
			if(rev < cache.length && cache[rev] > cache[k]+1) {
				cache[rev] = cache[k]+1;
				prev[rev] = k;
			}
		}
	}
	
	static long rev(long in) {
		String rev = new StringBuilder(Long.toString(in)).reverse().toString();
		return Long.parseLong(rev);
	}
	

	static long next(long n) {
		if(n < 1000)
			return prev[(int) n];
		long n2 = rev(n);
		int k = (int) Math.pow(10,((int)Math.log10(n)+1)/2);;
		if(n % k == 1 && n2 % k != 1) {
			return n2;
		}
		return n-1;
	}
	
	static int quickSolve(long n) {
		while(n != 1)  {
			System.out.println(n);
			n = next(n);
			assert next(n) == prev[(int) n] : next(n) + " " + prev[(int) n];
			
		}
		return 0;
	}
	
	static int quickSolve2(long n) {
		int ans = 0;
		while(n >= cache.length) {
			long n2 = rev(n);
			int k = (int) Math.pow(10,((int)Math.log10(n)+1)/2);
			if(n % k == 1 && n2 % k != 1)
				 n = n2;
			else
				n = n-1;
			ans++;
		}
		return ans + cache[(int) n];
	}
	
	static long quickSolve3(long n) {
		long ans = 0;
		while(n >= 10000) {
			long n2 = rev(n);
			int k = (int) Math.pow(10,((int)Math.log10(n)+1)/2);
			if(n % k == 1 && n2 % k != 1)
				 n = n2;
			else if((int) Math.log10(n) > (int) Math.log10(n-1))
				n = n-1;
			else if(n % k == 1 && n2 % k == 1)
				n = n-1;
			else if(n % k == 0)
				n = n-1;
			else {
				long m = n;
				n = n - n % k + 1;
				ans += (m - n - 1);
			}
			ans++;
		}
		return ans + cache[(int) n];
	}
	
	static void printPath(int N) {
		while(N != 1) {
			System.out.println(N);
			N = prev[N];
		}
		System.out.println(N);
	}
	
	static void submit() {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int i=1; i <= T; i++)
			System.out.println("Case #"+i+": " + cache[in.nextInt()]);
		in.close();
	}
	
	static void submit2() {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int i=1; i <= T; i++)
			System.out.println("Case #"+i+": " + quickSolve3(in.nextLong()));
		in.close();
	}
	

	public static void main(String[] args) {
		submit2();
	}

}