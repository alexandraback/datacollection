import java.util.Arrays;
import java.util.Scanner;


public class Problem1 {
	
	static int[] cache = new int[2000000];
	static {
		Arrays.fill(cache, Integer.MAX_VALUE);
		cache[1] = 1;
		for(int k=1; k < cache.length-1; k++) {
			cache[k+1] = Math.min(cache[k]+1,cache[k+1]);
			int rev = rev(k);
			if(rev < cache.length)
				cache[rev] = Math.min(cache[k]+1,cache[rev]);
		}
	}
	
	static int rev(int in) {
		String rev = new StringBuilder(Integer.toString(in)).reverse().toString();
		return Integer.parseInt(rev);
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int i=1; i <= T; i++)
			System.out.println("Case #"+i+": " + cache[in.nextInt()]);
		in.close();
	}

}