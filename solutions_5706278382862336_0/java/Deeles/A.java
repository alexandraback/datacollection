import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;


public class A {
	
	int[] st;
	
	public void d() {
		File f = new File("kod.txt");
		try (Scanner s = new Scanner(f)) {
			
			int T = s.nextInt();
			st = new int[T];
			for (int i = 0; i < T; i++) {
				String st = s.next();
				int P = Integer.parseInt(st.substring(0, st.indexOf('/')));
				int Q = Integer.parseInt(st.substring(st.indexOf('/') + 1, st.length()));
				compute(P, Q, i);
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		f = new File("out.txt");
		try (PrintWriter pw = new PrintWriter(f)) {
			
			for (int i = 1; i < st.length + 1; i++) {
				if (st[i-1] == -1) {
					pw.println("Case #" + i + ": " + "impossible");
					continue;
				} 
				pw.println("Case #" + i + ": " + st[i-1]);
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}	
	}
	
	private void compute(int P, int Q, int i) {
		/*int PP = P;
		*/int QQ = Q;/*
		while ((PP) == ((PP / 2) * 2)) {
			PP = PP / 2;
		}*/
		while ((QQ) == ((QQ / 2) * 2)) {
			QQ = QQ / 2;
		}
		
		if (QQ != 1) {
			st[i] = -1;
			return;
		}
		
		int c = 0;
		while (P < Q) {
			c++;
			P = P * 2;
		}
		st[i] = c;
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		A a = new A();
		a.d();
	}

}
