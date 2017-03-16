import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class A {
	/*
	 * Author: Diego Alejandro Agudelo España.
	 */
	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens())
				tk=new StringTokenizer(br.readLine());
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}
	
	static class Pair{
		int x,y;
		public Pair(int xx,int yy){
			x = xx;
			y = yy;
		}
	}
	
	static Pair getadds(int tengo, int objetivo){
		int times = 0;
		while(true){
			if (tengo > objetivo)
				return new Pair(tengo,times);
			times++;
			tengo = tengo + tengo - 1;
		}
	}
	
	static Pair[] a;
	static int[] v;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++){
			int inicial = sc.nextInt();
			int N = sc.nextInt();
			a = new Pair[N];
			v = new int[N];
			for(int i = 0; i < N; i++)
				v[i] = sc.nextInt();
			Arrays.sort(v);
			if (inicial == 1){
				System.out.printf("Case #%d: %d\n",c,N);
				continue;
			}
			Pair actual= new Pair(inicial, 0);
			for(int i = 0; i < N; i++){
				a[i] = getadds(actual.x, v[i]);
				a[i].x += v[i];
				a[i].y += actual.y;
				actual = a[i];
			}
			int ans = N;
			for(int i = 0; i < N; i++)
				ans = Math.min(ans, a[i].y + (N - 1 - i));
			System.out.printf("Case #%d: %d\n",c,ans);
		}
	}

}
