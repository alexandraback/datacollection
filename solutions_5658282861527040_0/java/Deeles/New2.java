import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;


public class New2 {
	
	private int[] o;
		
	public void d() {
		File f = new File("kod.txt");
		try (Scanner s = new Scanner(f)) {
			
		int T = s.nextInt();
		o = new int[T];
		for (int i = 0; i < T; i++) {
			compute(s.nextInt(), s.nextInt(), s.nextInt(), i);
		}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		f = new File("out.txt");
		try (PrintWriter pw = new PrintWriter(f)) {
			for (int i = 1; i < o.length + 1; i++) {
				pw.println("Case #" + i + ": " + o[i-1]);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	private void compute (int A, int B, int K, int k) {
		int c = 0;
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				if ((int)(i & j) < K) {
					c++;
				}
			}
		}
		o[k] = c;
	}


	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		New2 n = new New2();
		n.d();
	}

}
