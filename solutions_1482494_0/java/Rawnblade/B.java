import java.util.*;
import java.io.*;

public class B {
	static int[][] memo;
	static int[] pow;
	static Pair[] p;
	static int N,M;
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(new File("b.in"));
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int n = reader.nextInt(); N = n;
			p = new Pair[n];
			
			for(int i = 0; i < n; i++)
				p[i] = new Pair(reader.nextInt(), reader.nextInt());
			
			pow = new int[n+1];
			pow[0] = 1;
			for(int i = 1; i <= n; i++)
				pow[i] = pow[i-1]*3;

			memo = new int[pow[n]][2*n+1];
			for(int[] m:memo)Arrays.fill(m,-1);
			
			int sol = f(0,0);
			
			System.out.print("Case #"+t+": ");
			if(sol > (int)1e8){
				System.out.println("Too Bad");
			}else{
				System.out.println(sol);
			}
		}
	}
	
	public static int f(int m, int k){
		if(memo[m][k] == -1){
			if(k == 2*N){
				memo[m][k] = 0;
			}else{
				int min = (int)1e9;
				for(int i = 0; i < N; i++){
					int c = getDigit(m, i);
					if((c == 0 && k >= p[i].a) || (c == 1 && k >= p[i].b))
						min = Math.min(min, 1 + f(m+pow[i], k+1));
					if(c == 0 && k >= p[i].b)
						min = Math.min(min, 1 + f(m+2*pow[i], k+2));
				}
				memo[m][k] = min;
			}
		}
		return memo[m][k];
	}
	
	public static int getDigit(int x, int i){
		return (x/pow[i])%3;
	}
	
	public static class Pair implements Comparable<Pair>{
		int a,b;
		public Pair(int _a, int _b){
			a = _a;
			b = _b;
		}
		public int min(){
			return Math.min(a,b);
		}
		public int compareTo(Pair p){
			if(b <= p.min())
				return -1;
			if(p.b <= min())
				return 1;
			if(a <= p.min())
				return -1;
			if(p.a <= min())
				return 1;
			return 0;
		}
		public String toString(){
			return "("+a+", "+b+")";
		}
	}
}
