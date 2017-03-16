
import java.io.*;
import java.util.*;

public class CodeJam2013_R1B_C {
	static int D = 521196;
	static String[] dic;
	
	public static void main(String[] args) throws Exception{
//		Scanner sc = new Scanner(new FileReader("testC.in"));
		Scanner sc = new Scanner(new FileReader("C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("C-small.out"));
		Scanner sc2 = new Scanner(new FileReader("garbled_email_dictionary.txt"));
		dic = new String[D];
		for(int i=0; i<D; i++)
			dic[i] = sc2.next();
		Arrays.sort(dic);

		CodeJam2013_R1B_C obj = new CodeJam2013_R1B_C();
		int ntest = sc.nextInt();
		for(int test=1; test<=ntest; test++) {
			String S = sc.next();
			
			int res = obj.calc(S);
			
			pw.println("Case #" + test + ": " + res);
			System.out.println("Case #" + test + ": " + res);
		}
		System.out.println("Finished.");
		sc.close();
		pw.close();
	}
	
	public int calc(String S) {
		int N = S.length();
		int[][] dp = new int[5][N+1];
		for(int i=0; i<5; i++)
			Arrays.fill(dp[i], N);
		dp[0][0] = 0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<D; j++) {
				int L = dic[j].length();
				if(i+L<=N) {
					int first=-1;
					int last=-10;
					int cnt=0;
					boolean valid = true;
					for(int k=0; k<dic[j].length(); k++) {
						if(dic[j].charAt(k)!=S.charAt(i+k)) {
							if(first==-1)
								first=k;
							if(k-last<5) {
								valid = false;
								break;
							}
							last = k;
							cnt++;
						}
					}
					if(valid) {
						if(cnt==0) {
							for(int k=0; k<5; k++) {
								dp[Math.max(0, k-L)][i+L] = Math.min(dp[Math.max(0, k-L)][i+L], dp[k][i]);
							}
						} else {
							for(int k=0; k<5; k++) {
								if(k<=first)
									dp[Math.max(0, 5-(L-last))][i+L] = Math.min(dp[Math.max(0, 5-(L-last))][i+L], dp[k][i]+cnt);
							}
						}
					}
				}
			}
		}
		
		int ans = N;
		for(int i=0; i<5; i++)
			ans = Math.min(ans, dp[i][N]);
		return ans;
	}
}
