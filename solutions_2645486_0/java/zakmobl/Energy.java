import java.util.Scanner;

public class Energy {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int t = in.nextInt();
		for (int c = 0; c < t; c++) {
			int e = in.nextInt();
			int r = in.nextInt();
			int n = in.nextInt();
			
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = in.nextInt();
			int v[][] = new int[n + 1][e+1];
			for (int i = n-1 ; i >= 0; i--)
				for (int j = 0; j <= e; j++)
					for (int k = 0; k <= j; k++){
					int e_do = Math.min(e, j - k + r);
					v[i][j] = Math.max(v[i][j], v[i+1][e_do] + k * a[i]);
				}
			System.out.printf("Case #%d: %d\n",c + 1,v[0][e]);
		}
		

	}

}
