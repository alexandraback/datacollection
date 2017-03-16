import java.util.*;

public class Recycled {
	static int CAP = 2000000;
	static long[] f;
	static int[] pow = new int[]{1,10,100,1000,10000,100000,1000000};
	public static void main(String[] args){
		Scanner reader = new Scanner(System.in);
		
		int times = reader.nextInt();
		for(int k = 1; k <= times; k++){
			int n = reader.nextInt();
			int m = reader.nextInt();
			
			fill(n,m);
			
			long sum = 0;
			for(int i = n; i <= m; i++)
				sum += (f[i]*(f[i]-1))/2l;
			System.out.println("Case #"+k+": "+sum);
		}
	}
	
	public static int getRoot(int n){
		int p = -1;
		for(int i = 0; i <= 6; i++)
			if(n/pow[i] > 0)
				p = i;
		
		int x = n;
		int min = n;
		for(int i = 0; i <= p; i++){
			x = ((x%pow[p]) * 10) + x/pow[p];
			if(x/pow[p] > 0)
				min = Math.min(min, x);
		}
		
		return min;
	}
	
	public static int getRoot(int n, int low){
		int p = -1;
		for(int i = 0; i <= 6; i++)
			if(n/pow[i] > 0)
				p = i;
		
		int x = n;
		int min = n;
		for(int i = 0; i <= p; i++){
			x = ((x%pow[p]) * 10) + x/pow[p];
			if(x/pow[p] > 0 && x >= low)
				min = Math.min(min, x);
		}
		
		return min;
	}
	
	public static void fill(int n, int m){
		f = new long[2000001];
		
		for(int i = n; i <= m; i++)
			f[getRoot(i, n)]++;
	}
	
	public static void fill(){
		f = new long[2000001];
		
		for(int i = 0; i <= CAP; i++)
			f[getRoot(i)]++;
	}
}
