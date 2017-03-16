import java.util.*;
import java.io.*;
import java.lang.*;

class Energy { 
	int E, R, N;
	int[] v;
	long[][][] dp;
	long[][] memo;
	
  public static void main(String[] args) {
  	Energy t = new Energy();
  	t.run();
  }
  
  public void run() {
    Scanner sc = new Scanner(System.in);
    int T = Integer.parseInt(sc.nextLine());
    
    for (int i=0; i<T; i++) {
    	String[] sp = sc.nextLine().split(" ");
  		E = Integer.parseInt(sp[0]);
  		R = Integer.parseInt(sp[1]);
  		N = Integer.parseInt(sp[2]);
  		sp = sc.nextLine().split(" ");
  		v = new int[N];
  		for (int j=0; j<N; j++) v[j] = Integer.parseInt(sp[j]);
			dp = new long[N][2][N];
  		for (int j=0; j<N; j++) for (int k=0; k<2; k++) Arrays.fill(dp[j][k], -1);
  		memo = new long[N][6];
  		for (int j=0; j<N; j++) Arrays.fill(memo[j], -1);
			long res = doit(0, E);
  		
    	System.out.println("Case #" + (i+1) + ": " + res);
    }
  }
  
  /*public long doit(int pos, int full, int recover) {
  	if (pos == N) return 0;
  	if (dp[pos][full][recover]!=-1) return dp[pos][full][recover];
  	
  	long max = 0;
  	// use all energy
  	if (full == 1) max = Math.max(max, v[pos] * E + doit(pos+1, 0, 1));
  	if (recover > 0) max = Math.max(max, v[pos] * R * recover + doit(pos+1, full, 0));
  	
  	// not doing anything
  	if (full == 0) {
  		if ((recover+1) * R >= E) max = Math.max(max, doit(pos+1, 1, 0));
  		else max = Math.max(max, doit(pos+1, full, recover+1));
  	}
  	
  	// use only recovery energy
  	max = Math.max(max, v[pos] * R + doit(pos+1, full, recover));
  	
  	return (dp[pos][full][recover]=max);
  }*/
  
  public long doit(int pos, int energy) {
  	if (pos == N) return 0;
  	if (memo[pos][energy]!=-1) return memo[pos][energy];
  	long max = 0;
  	
  	for (int i=0; i<=energy; i++) {
  		max = Math.max(max, v[pos] * i + doit(pos+1, (energy-i+R>E?E:energy-i+R)));	
  	}
  	
  	return (memo[pos][energy] = max);
  }
}

