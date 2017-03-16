import java.util.*;

public class Problem1 {

	static void printSoln(int test, int soln) {
		System.out.println("Case #" + test + ": " + soln);
	}
	
	static int solve1(int r, int c, int w) {
		r = 1;
		//pick cells (w-1), (2w-1), ... c 
		if(c % w == 0)
			return c/w + w-1;
		return c/w + w;
	}

	public static void main(String... args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int i=1; i <= T; i++) {
			int ans = solve1(in.nextInt(), in.nextInt(), in.nextInt());
			printSoln(i,ans);
		}
		
		in.close();
	}


}