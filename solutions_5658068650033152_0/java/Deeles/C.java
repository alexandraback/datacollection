import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;


public class C {
	
	int[] st;
	int[][] f = new int[21][21];
	
	public void d() {
		File f = new File("kod.txt");
		try (Scanner s = new Scanner(f)) {
			
			int T = s.nextInt();
			st = new int[T];
			for (int j = 0; j < 21; j++) {
				for (int k = 0; k < 21; k++) {
					this.f[j][k] = j*k + 2*j + 2*k;
				}
			}
			for (int i = 0; i < T; i++) {
				compute(s.nextInt(), s.nextInt(), s.nextInt(), i);
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		f = new File("out.txt");
		try (PrintWriter pw = new PrintWriter(f)) {
			
			for (int i = 1; i < st.length + 1; i++) {
				pw.println("Case #" + i + ": " + st[i-1]);
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}	
	}
	
	private void compute(int N, int M, int K, int i) {		
		int min = Integer.MAX_VALUE;
		int x = 0;
		int y = 0;
		for (int l = 0; l < N; l++) {
			for (int k = 0; k < M; k++) {
				if (K <= f[l][k]) {
					if (min > 2*l + 2*k) {
						min = 2*l + 2*k;
					}
				}
			}
		}
		st[i] = min;
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		C c = new C();
		c.d();
	}

}
