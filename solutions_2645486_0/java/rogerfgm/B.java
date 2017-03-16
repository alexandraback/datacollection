

import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class B {
	static Scanner sc = null;
	static PrintWriter out = null;
	
	int INF = Integer.MAX_VALUE / 10;
	double DF = 0.0000000001;
	
	public void solve() throws Exception{
		int E = sc.nextInt();
		int R = sc.nextInt();
		int N = sc.nextInt();
		int[] v = new int[N];
		for(int i = 0; i < N; i++){
			v[i] = sc.nextInt();
		}
		long[] dp = new long[E+1];
		for(int i = 0; i < N; i++){
			long[] ndp = new long[E+1];
			
			for(int j = 0; j <= E; j++){ // 使う量
				for(int k = j; k <= E; k++){ // 前の量
					int ne = k - j + R; // 今の量
					if(ne >= E){
						ne = E;
					}
					long gain = (long)j * v[i] + dp[k]; // 新しい値
					ndp[ne] = max(gain, ndp[ne]);
				}
			}
			dp = ndp;
		}
		long ans = 0;
		for(int i = 0; i <= E; i++){
			ans = max(ans, dp[i]);
		}
		out.println(ans);
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		File file = new File("B-small-attempt0.in");
		if(file.exists()){
			System.setIn(new BufferedInputStream(new FileInputStream(file)));
		}
		sc =  new Scanner(System.in);
		out = new PrintWriter(new FileWriter(new File("output.txt")));
		
		B b = new B();
		int T = sc.nextInt();
		int t = 1;
		while(t <= T){
			out.print("Case #" + t + ": ");
			b.solve();
			t++;
		}
		out.close();
	}
}
