import java.io.*;
import java.util.*;

public class Mine {
	//private DataInputStream in;
	private PrintWriter out;
	private Scanner in;
	
	Mine() throws IOException {
		out = new PrintWriter(new FileWriter("output.txt"), true);		
	
		in = new Scanner(new File("input.txt"));
	}
	
	
	public char[][] Transpose(char[][] a, boolean flag) {
		if (!flag)
			return a;
		
		int n = a.length;
		int m = a[0].length;
		char[][] b = new char[m][n];
		for(int i = 0; i < m; i ++) {
			for(int j = 0; j < n; j ++) {
				b[i][j] = a[j][i];
			}
		}
		return b;
	}	
				
	public void Output(char[][] a) {
		for(int i = 0; i < a.length; i ++) {
			for(int j = 0; j < a[0].length; j ++) {
				out.print(a[i][j]);
			}
			out.println("");
		}
	}
	
	public void run() throws IOException {
		int R = in.nextInt();
		int C = in.nextInt();
		int M = in.nextInt();
		boolean swap = (R > C);
		if (swap) {
			int temp = R;
			R = C;
			C = temp;
		}
		M = R*C - M;
		char[][] a = new char[R][C];
		for(int i = 0; i < a.length; i ++) {
			for(int j = 0; j < a[0].length; j ++) {
				a[i][j] = '*';
			}
		}
		if (M == 1) {
			a[0][0] = 'c';
			Output(Transpose(a, swap));
			return;
		}
		/*if (M == 2) {
			if (R > 1) {
				out.println("Impossible");
				return;
			}
			a[0][0] = 'c';
			a[0][1] = '.';
			
			Output(Transpose(a, swap));
			return;
		}*/
		if (R == 1) {
			a[0][0] = 'c';
			for(int i = 1; i < M; i++) {
				a[0][i] = '.';
			}
			Output(Transpose(a, swap));
			return;
		}
		
		if (M<4 || M==5 || M==7) {
			out.println("Impossible");
			return;
		}
		
		if ((R == 2) && (M%2 == 1)) {
			out.println("Impossible");
			return;
		}
		
		if (M<2*R) {
			if (M%2 == 0) {
				for(int i = 0; i < 2; i ++) {
					for(int j = 0; j < M/2; j ++) {
						a[j][i] = '.';
					}
				}
				a[0][0] = 'c';
				Output(Transpose(a, swap));
				return;
			}
			else {
				for(int i = 0; i < 2; i ++) {
					for(int j = 0; j < (M-3)/2; j ++) {
						a[i][j] = '.';
					}
				}
				a[2][0] = '.';
				a[2][1] = '.';
				a[2][2] = '.';
				a[0][0] = 'c';
				
				Output(Transpose(a, swap));
				return;
			}
		}
			
		if (M>=2*R) {
			int l = M/R;
			int d[] = new int[l+1];
			for(int i=0; i<l; i++) {
				d[i] = R;
			}
			d[l]=M%R;
			if (d[l] == 1) {
				d[l]++;
				d[l-1]--;
				if (l==2) {
					d[l]++;
					d[l-2]--;
				}
			}
			for(int i = 0; i <= l; i ++) {
				for(int j = 0; j < d[i]; j ++) {
					a[j][i] = '.';
				}
			}
			a[0][0] = 'c';
			Output(Transpose(a, swap));
			return;
		}
		out.print("MESSED UP");
		return;
	}
	
	public static void main(String[] args) throws IOException {

		Mine m = new Mine();
		/*char[][] a = new char[1][2];
		a[0][0] = 'a';
		a[0][1] = 'b';
		m.Output(a);
		m.Output(m.Transpose(a, true));
		*/
		int T = m.in.nextInt();
		for(int i=1; i<=T; i++) {
			m.out.println("Case #" + i + ": ");
			m.run();
		}
		return;
	}
}
