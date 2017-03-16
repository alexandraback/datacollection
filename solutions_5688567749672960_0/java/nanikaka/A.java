package gcj2015.r1b;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class A {

	final boolean DEBUG = false;
	final boolean isSmall = true;
	final String PACKAGE = "gcj2015/r1b";
	final String PROBLEM = "A";
	
	long[] dp;
	
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small-attempt0.in")));
				else System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				if(isSmall)System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out.txt")));
				else System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		long INF = 1L << 60;
		for(int CASE=1;CASE<=T;CASE++){
			long N = sc.nextLong();
			dp = new long[(int)N+1];
			Arrays.fill(dp, INF);
			dp[1] = 1;
			Queue<Integer> q = new PriorityQueue<Integer>((int)N, new Comparator<Integer>() {
				public int compare(Integer o1, Integer o2) {
					return Long.signum(dp[o1]-dp[o2]);
				};
			});
			q.add(1);
			while(!q.isEmpty()){
				int u = q.poll();
				if (u+1 <= N && dp[u]+1 < dp[u+1]){
					dp[u+1] = dp[u]+1; q.add(u+1);
				}
				StringBuilder sb = new StringBuilder(u+"");
				int rev = Integer.valueOf(sb.reverse().toString());
				if (rev <= N && dp[u]+1 < dp[rev]){
					dp[rev] = dp[u]+1; q.add(rev);
				}
			}
			
			System.out.println("Case #"+CASE+": "+dp[(int)N]);
		}
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}
