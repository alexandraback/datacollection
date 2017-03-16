import java.util.Scanner;


public class B {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		CAS: for(int cas=1; cas<=T; cas++) {
			int R = in.nextInt();
			int C = in.nextInt();
			int[][] G = new int[R][C];
			for(int r=0; r<R; r++)
				for(int c=0; c<C; c++)
					G[r][c] = in.nextInt();
			
			for(int r=0; r<R; r++)
				for(int c=0; c<C; c++) {
					boolean down = true;
					for(int rr=0; rr<R; rr++)
						if(G[rr][c] > G[r][c]) down = false;
					
					boolean across = true;
					for(int cc=0; cc<C; cc++)
						if(G[r][cc] > G[r][c]) across = false;
					if(!down && !across) {
						System.out.printf("Case #%d: NO\n", cas);
						continue CAS;
					}
				}
			System.out.printf("Case #%d: YES\n", cas);
		}
	}
}
