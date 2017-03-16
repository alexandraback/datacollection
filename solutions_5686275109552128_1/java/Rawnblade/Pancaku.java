import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class Pancaku{
	public static long[][] memo = new long[1001][1001];
	
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new File("b.out"));
		
		for(long[] m:memo)Arrays.fill(m,-1);
		
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int n = reader.nextInt();
			
			int[] f = new int[1001]; //Number of diners with this many pancakus
			for(int i = 0; i < n; i++)
				f[reader.nextInt()]++;
			
//			int low = 1;
//			int high = 1001;
//			while(low < high){
//				int mid = (low + high)/2;
//				boolean good = f(mid, f);
//				if(good)
//					high = mid;
//				else
//					low = mid+1;
//			}
			
			int min = 1001;
			for(int i = 1; i <= 1000; i++){
				int cost = i;
				for(int j = i+1; j <= 1000; j++)
					cost += f[j] * g(j,i);
				min = Math.min(min, cost);
			}
			
			out.println("Case #"+t+": "+min);
			System.out.println("Case #"+t+": "+min);
		}
		
		out.close();
	}
	
	public static boolean f(int time, int[] f){
		for(int i = 1000; i >= 1; i--){
			if(f[i] == 0) continue;
			if(i <= time) break;
			time -= f[i] * g(i, time);
			if(time < 0) return false;
		}
		return true;
	}
	
	//Min cuts to get n below m
	public static long g(int n, int m){
		if(memo[n][m] == -1){
			if(n <= m)
				memo[n][m] = 0;
			else if(m == 0){
				memo[n][m] = 1000000;
			}else{
				long min = n;
				for(int i = 1; i <= n / 2; i++)
					min = Math.min(min, 1 + g(i,m) + g(n-i,m));
				memo[n][m] = min;
			}
		}
		return memo[n][m];
	}
}
