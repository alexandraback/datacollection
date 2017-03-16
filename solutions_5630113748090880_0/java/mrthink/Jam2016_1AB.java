import java.util.Scanner;


public class Jam2016_1AB {
	public int[] solve(int[][] d) {
		int	n = d[0].length;
		int[] h = new int[2500];
		
		for(int i=0; i<d.length; ++i) {
			for(int j=0; j<n; ++j) {
				h[d[i][j]]++;
			}
		}
		
		int idx = 0;
		int[] ret = new int[n];
		for(int i=0; i<2500; ++i) {
			int dd = h[i];
			if(dd%2 != 0)
				ret[idx++] = i;
		}
		
		return ret;
	}
	
	public static void main(String[] args) {
		Scanner	scanIn	= new Scanner(System.in);
		
		int T	= scanIn.nextInt();
		
		for(int i=0; i<T; ++i) {
			Jam2016_1AB	inst	= new Jam2016_1AB();
			int		n		= scanIn.nextInt();
			int N = 2*n-1;

			int[][]		d	= new int[N][n];
			
			for(int j=0; j<N; ++j) {
				for(int k=0; k<n; ++k) {
					d[j][k]	= scanIn.nextInt();
				}
			}
			
			int[] ret = inst.solve(d);

			System.out.print("Case #" + (i+1) + ":");
			for(int j: ret)
				System.out.print(" " + j);
			System.out.println();
		}
		
		scanIn.close();
	}

}
