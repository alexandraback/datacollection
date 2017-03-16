package round1B;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class B {

	String solve(Scanner in) throws IOException {
		int n = in.nextInt(), x = in.nextInt(), y = in.nextInt();
		
		int s = 1;
		while((s+3)*(s+2)/2 <= n)
			s += 2;

		if(inside(x,y,s))
			return "1";
		if(!inside(x,y,s+2))
			return "0";
		
		int remain = n - (s+1)*s/2;
		double ans = 0;
		
		double[][] dp = new double[s+2][s+2];
		dp[0][0] = 1;
		for(int sum = 1; sum <= 2*s+4; sum++)
			for(int i = 0; i <= s+1; i++) {
				int j = sum - i;
				if(j < 0 || j > s+1)
					continue;
				
				dp[i][j] = 0;
				if(i > 0)
					dp[i][j] += dp[i-1][j] * (j == s+1 ? 1 : 0.5);
				if(j > 0)
					dp[i][j] += dp[i][j-1] * (i == s+1 ? 1 : 0.5);
				
				if(sum == remain && i >= y+1)
					ans += dp[i][j];
			}
		/*
		for(int i = 0; i <= s+1; i++) {
			for(int j = 0; j <= s+1; j++)
				System.out.print(dp[i][j] + " ");
			System.out.println();
		}System.out.println();
		*/
		return ""+ans;
	}
	
	boolean inside(int x, int y, int s) {
		int half = s-1;
		return y <= x+half && y <= -x+half;
	}
	
	
/*************************************************************************************************/
	
	public static void main(String[] args) throws IOException {
		for(File f : new File(".").listFiles())
			if(f.isFile() && f.getName().startsWith(B.class.getSimpleName() + "-")
					      && f.getName().endsWith(".in")) {
				
				Scanner in = new Scanner(new FileReader(f));
				PrintWriter out = new PrintWriter(new FileWriter(f.getName() + ".out"));
				
				long start = System.currentTimeMillis();
				int cases = in.nextInt(); in.nextLine();
				for(int caseno = 1; caseno <= cases; caseno++)
					out.printf("Case #%d: %s%n", caseno, new B().solve(in));
				System.out.printf("%s: %d ms%n", f.getName(), System.currentTimeMillis()-start);
				out.close();
			}
	}
}
