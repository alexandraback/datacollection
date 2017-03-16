import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class B {
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
		public long nextLong() throws NumberFormatException, IOException{
			return Long.valueOf(next());
		}
		public double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}
	
	static int[][] visited;
	
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,1,0,-1};
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++){
			int x = sc.nextInt();
			int y = sc.nextInt();
			System.out.print("Case #"+c+": ");
			int cuenta = 0;
			if (y < 0){
				System.out.print("S");
				y++;
				cuenta++;
				y = Math.abs(y);
				cuenta += 2 * y;
				for(int i = 0; i < y; i++)
					System.out.print("NS");
			}
			else if (y >0){
				System.out.print("N");
				y--;
				cuenta++;
				cuenta += 2 * y;
				for(int i = 0; i < y; i++)
					System.out.print("SN");
			}
			if (x < 0){
				if (cuenta == 0)
					System.out.print("W");
				else
					System.out.print("EW");
				x++;
				x = Math.abs(x);
				for(int i = 0; i < x; i++)
					System.out.print("EW");
			}
			else if (x > 0){
				if (cuenta == 0)
					System.out.print("E");
				else
					System.out.print("WE");
				x--;
				for(int i = 0; i < x; i++)
					System.out.print("WE");
			}
			System.out.println();
		}
	}

}
