import java.util.Arrays;
import java.util.Scanner;


public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t=1;t<=T;t++){
			int H = sc.nextInt();
			int W = sc.nextInt();
			int[][] grid = new int[H][W];
			for(int a=0;a<H;a++){
				for(int b=0;b<W;b++){
					grid[a][b]=sc.nextInt();
				}
			}
			int[] rows = new int[H];
			int[] cols = new int[W];
			boolean OK = true;
			for(int a=0;a<H;a++){
				for(int b=0;b<W;b++){
					rows[a]=Math.max(grid[a][b],rows[a]);
					cols[b]=Math.max(grid[a][b],cols[b]);
				}
			}
			for(int a=0;a<H;a++){
				for(int b=0;b<W;b++){
					if(grid[a][b]<rows[a]&&grid[a][b]<cols[b])OK=false;
				}
			}
			System.out.printf("Case #%d: %s%n",t,OK?"YES":"NO");
		}
	}

}
