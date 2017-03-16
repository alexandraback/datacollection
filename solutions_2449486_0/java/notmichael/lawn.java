import java.util.*;

public class lawn {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int a=0; a<cases; a++) {
			int n = in.nextInt();
			int m = in.nextInt();
			in.nextLine();
			int[][] law = new int[n][m];
			for (int i=0; i<n; i++) {
				String[] line = in.nextLine().split(" ");
				for (int j=0; j<m; j++) {
					law[i][j] = Integer.parseInt(line[j]);
				}
			}
			int[] binary = new int[n+m];
			for (int i=0; i<(n+m); i++) {
				binary[i] = 1;
			}
			int max = power(n+m);
			boolean possible = false;
			for (int i=0; i<max; i++) {
				for (int j=0; j<n; j++) {
					boolean broke = false;
					for (int k=0; k<m; k++) {
						if (law[j][k] != min(binary[k],binary[m+j])) {
							broke = true;
							break;
						}
					}
					if (broke) {
						if (i!= max-1) {
							binary = increment(binary, 0);
						}
						break;
					}
					else if (j==n-1) {
						possible = true;
					}
				}
				if (possible) {
					break;
				}
			}
			if (possible) {
				System.out.println("Case #" + (a+1) + ": YES");
			}
			else {
				System.out.println("Case #" + (a+1) + ": NO");
			}
		}
	}
	private static int power(int x) {
		int r = 1;
		for (int i=0; i<x; i++) {
			r = r*2;
		}
		return r;
	}
	private static int[] increment(int[] binary, int place) {
		if (binary[place]==1) {
			binary[place] = 2;
		}
		else {
			binary[place] = 1;
			increment(binary, place+1);
		}
		return binary;
	}
	private static int min(int a, int b) {
		if (a<b) {
			return a;
		}
		else {
			return b;
		}
	}

}
