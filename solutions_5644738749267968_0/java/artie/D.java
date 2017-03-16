import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class D {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		new D().run();
	}

	private void run() throws Exception {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("src\\input.txt"));
		PrintWriter pw = new PrintWriter("output.txt");
		int tc = sc.nextInt();
		double[] a = new double[1000];
		double[] b = new double[1000];
		for (int t = 1; t <= tc; t++) {
			int n = sc.nextInt();
			for (int i = 0; i < n; i++)
				a[i] = Double.parseDouble(sc.next());
			for (int i = 0; i < n; i++)
				b[i] = Double.parseDouble(sc.next());
			Arrays.sort(a, 0, n);
			Arrays.sort(b, 0, n);
			int l1 = 0;
			int r1 = n - 1;
			int l2 = 0;
			int r2 = n - 1;
			int x = 0;
			for (int i = 0; i < n; i++) {
				if (a[r1] > b[r2]) {
					r1--;
					r2--;
					x++;					
				} else {
					l1++;
					r2--;					
				}
			}
			l1 = 0;
			r1 = n - 1;
			l2 = 0;
			r2 = n - 1;
			int y = 0;
			for (int i = 0; i < n; i++) {
				if (a[r1] > b[r2]) {
					r1--;
					l2++;
					y++;					
				} else {
					r1--;
					r2--;					
				}
			}
			pw.printf("Case #%d: %d %d\n", t, x, y);
		}
		pw.close();
	}

}
