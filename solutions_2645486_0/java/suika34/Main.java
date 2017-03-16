import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Main {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String line = br.readLine();
			int T = Integer.parseInt(line);
			
			for (int i=1; i<=T; i++) {
				line = br.readLine();
				String[] a = line.split(" ");
				int E = Integer.parseInt(a[0]);
				int R = Integer.parseInt(a[1]);
				int N = Integer.parseInt(a[2]);
				int[] v = new int[N];
				line = br.readLine();
				a = line.split(" ");
				for (int j=0; j<N; j++) {
					v[j] = Integer.parseInt(a[j]);
				}
				Main main = new Main();
				long sol = main.solve(E, R, N, v);
				System.out.println("Case #"+i+": "+sol);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public long solve(int E, int R, int N, int[] v) {
		long[][] table = new long[N+1][E+1];
		
		for (int i=0; i<=N; i++) {
			for (int j=R; j<=E; j++) {
				if (i == 0) {
					table[i][j] = 0;
				} else {
					long max = 0;
//					for (int e=0; e<=E; e++) {
//						if (0<= j+e-R && j+e-R<=E) {
//							long t = table[i-1][j+e-R] + e * v[i-1];
//							if (t > max) {
//								max = t;
//							}
//						} else if (j+e-R < 0) {
//							System.out.println("negative");
//						} else if (E < j+e-R) {
//							long t = table[i-1][E] + e * v[i-1];
//							if (t > max) {
//								max = t;
//							}
//						}
//					}
					for (int k=j-R; k<=E; k++) {
						long t = table[i-1][k] + (k-j+R) * v[i-1];
						if (t > max) {
							max = t;
						}
					}
					table[i][j] = max;
				}
			}
		}
		
//		for (int i=0; i<=N; i++) {
//			for (int j=0; j<=E; j++) {
//				System.out.print(table[i][j]+" ");
//			}
//			System.out.println();
//		}
		
		long max = 0;
		for (int i=0; i<=E; i++) {
			if (table[N][i] > max) {
				max = table[N][i];
			}
		}
		return max;
	}

}
