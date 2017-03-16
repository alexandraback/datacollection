import java.util.*;
import java.io.*;

public class Sums {
	static int[][][] memo;
	static int[] F,V;
	static HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
	static int N,BASE = 100001*20;
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(new File("c.in"));
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int n = reader.nextInt();
			int[] v = new int[n];
			map = new HashMap<Integer, Integer>();
			for(int i = 0; i < n; i++)
				v[i] = reader.nextInt();
			Arrays.sort(v);
			
			for(int i = 0; i < n; i++)
				if(!map.containsKey(v[i]))
					map.put(v[i], map.keySet().size());
			
			N = map.keySet().size();
			F = new int[N];
			V = new int[N];
			
			for(int i = 0; i < n; i++){
				V[map.get(v[i])] = v[i];
				F[map.get(v[i])]++;
			}
			
//			System.out.println(Arrays.toString(F));
//			System.out.println(Arrays.toString(V));
			
			memo = new int[2][N+1][2*BASE+17];
			System.out.println("Case #"+t+":");
			if(f(0,BASE,1) > 0){
				trace();
			}else{
				System.out.println("Impossible");
			}
		}
	}
	
	public static void trace(){
		int n = 0;
		int m = BASE;
		int r = 1;
		
		ArrayList<Integer> set1 = new ArrayList<Integer>();
		ArrayList<Integer> set2 = new ArrayList<Integer>();
		
		while(true){
//			System.out.println(n + " " + m + " " + r + " " + f(n,m,r));
			if(f(n,m,r) < 0)
				break;
			if(n == N){
				break;
			}else{
//				int max = f(n+1, m, r);
				if(f(n+1, m, r) > 0)
					n++;
				else{
					boolean flag = false;
					for(int i = 1; i <= F[n]; i++){
						if(f(n+1, m - i*V[n], 0) > 0){
							for(int j = 0; j < i; j++)
								set1.add(V[n]);

							m -= i*V[n];
							n++;
							r = 0;
							flag = true;
							break;
						}
					}
					
					if(!flag){
						for(int i = 1; i <= F[n]; i++){
							if(f(n+1, m + i*V[n], 0) > 0){
								for(int j = 0; j < i; j++)
									set2.add(V[n]);

								m += i*V[n];
								n++;
								r = 0;
								flag = true;
								break;
							}
						}
					}
				}
			}
		}
		
		//Print sets
		for(Integer x:set1)
			System.out.print(x + " ");
		System.out.println();
		for(Integer x:set2)
			System.out.print(x + " ");
		System.out.println();
	}
	
	public static int f(int n, int m, int r){
		if(memo[r][n][m] == 0){
			if(n == N){
				memo[r][n][m] = (r < 1 && m == BASE)?1:-1;
			}else{
				int max = f(n+1, m, r);
				for(int i = 1; i <= F[n]; i++)
					max = Math.max(max, f(n+1, m - i*V[n], 0));
				for(int i = 1; i <= F[n]; i++)
					max = Math.max(max, f(n+1, m + i*V[n], 0));
				memo[r][n][m] = max;
			}
		}
		return memo[r][n][m];
	}
}
