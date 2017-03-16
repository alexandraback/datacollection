package gcj2015.r1c;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	final boolean DEBUG = false;
	final boolean isSmall = true;
	final String PACKAGE = "gcj2015/r1c";
	final String PROBLEM = "B";
	
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small-attempt4.in")));
				else System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				if(isSmall)System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out-4.txt")));
				else System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int CASE=1;CASE<=T;CASE++){
			int K = sc.nextInt(), L = sc.nextInt(), S = sc.nextInt();
			int[] key = new int[128];
			for(char c:sc.next().toCharArray())key[c]++;
			char[] str = sc.next().toCharArray();
			double[] p = new double[L];
			String strr = new String(str);
			int maxsuffix = 0;
			for(int i=1;i<L;i++){
				String sub = strr.substring(0, i);
				if (strr.endsWith(sub)){
					maxsuffix = Math.max(maxsuffix, i);
				}
			}
			for(int i=0;i<L;i++)p[i]=(key[str[i]]+0.0)/K;
			if (p[L-1] == 0) {
				System.out.printf("Case #%d: %.12f\n", CASE, 0.0); continue;
			}
			double[][][] dp = new double[S+1][128][L];
			int max = 0;
			dp[0][0][0] = 1.0;
			double E = 0;
			for(int i=0;i<S;i++)for(int j=0;j<=S;j++)for(int k=0;k<L;k++)if(0 < dp[i][j][k]){
				dp[i+1][j][0] += dp[i][j][k] * (1-p[k]); // reset to 0
//				if (i+1 == S)E+=j*dp[i+1][j][0];
				if (k+1 == L){
					dp[i+1][j+1][maxsuffix] += dp[i][j][k] * p[k]; // typed!
					if (0 < p[k]) max = Math.max(max, j+1);
//					if (i+1 == S)E+=(j+1)*dp[i+1][j+1][maxsuffix];
				} else {
					dp[i+1][j][k+1] += dp[i][j][k] * p[k];
//					if (i+1 == S)E+=j*dp[i+1][j][k+1];
				}
			}
			for(int j=0;j<=S;j++)for(int k=0;k<L;k++)if(0 < dp[S][j][k])E += j*dp[S][j][k];
//			System.out.println(max+" "+maxsuffix+" "+E);
			System.out.printf("Case #%d: %.12f\n", CASE, Math.max(0, max-E));
		}
	}
	
	void debug(Object...o){
		System.out.println(Arrays.deepToString(o));
	}
	
	public static void main(String[] args) {
		new B().run();
	}
}
