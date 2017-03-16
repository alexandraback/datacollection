import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class Osmos {
	Osmos(){
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		for(int t = 1; t<=tests; t++){
			A = in.nextInt();
			N = in.nextInt();
			ary = new int[N];
			for(int i = 0; i<N; i++)
				ary[i] = in.nextInt();
			Arrays.sort(ary);
			MAX = ary[ary.length-1];
			memo = new int[N][MAX+1];
			for(int[] a: memo)
				Arrays.fill(a, -1);
			System.out.println("Case #"+t+": " +go(0, A));
		}
	}
	int A, N, MAX;
	int[] ary;
	int[][] memo;
	int go(int i, int s){
		if(s > MAX) return 0;
		if(i == ary.length) return 0;
		if(memo[i][s] != -1) return memo[i][s];
		if(ary[i] >= s){
			int ans = go(i+1, s)+1;
			if(s+s-1 > s) ans = Math.min(ans, go(i, s+s-1)+1);
			return memo[i][s] = ans;
		}
		return memo[i][s] = go(i+1, s+ary[i]);
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream(new File("osmos.in")));
		System.setOut(new PrintStream(new File("osmos.out")));
		new Osmos();
	}

}
