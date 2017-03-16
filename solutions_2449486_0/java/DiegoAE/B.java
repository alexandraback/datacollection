import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class B {
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
	
	static int N,M;
	static int[][] h;
	
	static boolean test(int x,int y){
		boolean flag = true;
		for(int i = 0; i < N; i++)
			if (h[i][y] > h[x][y])
				flag = false;
		if (flag)
			return true;
		flag = true;
		for(int j = 0; j < M; j++)
			if (h[x][j] > h[x][y])
				flag = false;
		if (flag)
			return true;
		return false;
	}
	
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++){
			N = sc.nextInt();
			M = sc.nextInt();
			h = new int[N][M];
			for(int i = 0; i < N; i++)
				for(int j = 0; j < M; j++)
					h[i][j] = sc.nextInt();
			boolean flag = true;
			for(int i = 0; i < N; i++)
				for(int j = 0; j < M; j++)
					if (!test(i,j)){
						flag = false;
						break;
					}
			
			System.out.print("Case #"+c+": ");
			System.out.println((flag)?"YES":"NO");
		}
	}

}
