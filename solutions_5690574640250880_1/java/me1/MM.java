import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class MM {

	public static void main(String[] args) throws FileNotFoundException {
		 PrintStream out = new PrintStream("output.txt");
//		PrintStream out = System.out;

		Scanner scanner = new Scanner(new File("C-large.in"));

		int cases = scanner.nextInt();
		for (int casen = 1; casen <= cases; casen++) {
			out.print("Case #" + casen + ":\n");

			int r, c, m;
			r = scanner.nextInt();
			c = scanner.nextInt();
			m = scanner.nextInt();
			char[][] A = new char[r][c];
			char[][] B = new char[r][c];
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					A[i][j] = B[i][j] = '.';

			int posAi = 0, posAj = 0;
			int posBi = 0, posBj = 0;
			for (int i = 0; i < m; i++) {
				A[posAi][posAj] = '*';
				B[posBi][posBj] = '*';
				posAj++;
				if (posAj == c) {
					posAj = 0;
					posAi++;
				}
				posBi++;
				if (posBi == r) {
					posBi = 0;
					posBj++;
				}
			}

			if (r*c-1==m) {
				myprint(A, out);
				continue;
			}
			int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
			int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };

			int ni, nj;
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++) {
					if (A[i][j] != '.' && B[i][j] != '.')
						continue;
					for (int k = 0; k < 8; k++) {
						ni = i + dx[k];
						nj = j + dy[k];
						if (ni < 0 || ni >= r || nj < 0 || nj >= c)
							continue;
						if (A[i][j] == '.' && A[ni][nj] == '*')
							A[i][j] = 'x';
						if (B[i][j] == '.' && B[ni][nj] == '*')
							B[i][j] = 'x';
					}
				}

			boolean visible;
			boolean failA = false, failB = false;
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					if (A[i][j] == 'x') {
						visible = false;
						for (int k = 0; k < 8; k++) {
							ni = i + dx[k];
							nj = j + dy[k];
							if (ni < 0 || ni >= r || nj < 0 || nj >= c)
								continue;
							if (A[ni][nj] == '.')
								visible = true;
						}
						if (!visible)
							failA = true;
					}
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					if (B[i][j] == 'x') {
						visible = false;
						for (int k = 0; k < 8; k++) {
							ni = i + dx[k];
							nj = j + dy[k];
							if (ni < 0 || ni >= r || nj < 0 || nj >= c)
								continue;
							if (B[ni][nj] == '.')
								visible = true;
						}
						if (!visible)
							failB = true;
					}

			if (!failA)
				myprint(A, out);
			else if (!failB)
				myprint(B, out);
			else {
				int t = r * c - m;
				boolean madeit = false;
//				for (int i = 2; i <= r; i++)
//					for (int j = 2; j <= c; j++)
//						if (!madeit)
//							if (i * j == t) {
//								solvePrint(i, j, r, c, m, out);
//								madeit = true;
//							}
				
//				if (!madeit && m <= (r-2)*(c-2)) {
//					for (int i=0;i<r;i++)
//						for (int j=0;j<c;j++)
//							A[i][j]='.';
//					int count=m;
//					for (int i=0;i<r-2;i++)
//						for (int j=0;j<c-2;j++)
//							if (count-- > 0)
//								A[i][j]='*';
//					
//					myprint(A, out);
//					out.println("////////////////////////////////////////////////////////");
//					madeit=true;
//				}

				for (int i=2;i<=r;i++)
					for (int j=2;j<=c;j++)
						if (!madeit && r*c-(2*i+2*j-4) >= m && r*c-(i*j) <= m) {
							solvePrint2(r,c,m,i,j,out);
							madeit=true;
						}

				
				if (!madeit) {
					out.println("Impossible");
					System.err.println(r+" "+c+" "+m+" "+t);
					myprint(A, System.err);
				}
			}

		}
		scanner.close();
	}

	private static void solvePrint2(int r, int c, int m, int ii, int jj,
			PrintStream out) {
//		out.println(r+" "+c+" "+m+" "+"########################################################");
		char[][] A = new char[r][c];
		int t = r * c - m;
		
		for (int i=0;i<r;i++)
			for (int j=0;j<c;j++)
				A[i][j]='*';
		
//		for (int i = 0; i < r; i++) {
//			for (int j = 0; j < c; j++)
//				out.print(A[i][j]);
//			out.println();
//		}
//		out.println("########################################################");

		t+=4;
		for (int i=0;i<ii;i++) {
			A[i][0]= A[i][1] = '.';
			t-=2;
		}

//		for (int i = 0; i < r; i++) {
//			for (int j = 0; j < c; j++)
//				out.print(A[i][j]);
//			out.println();
//		}
//		out.println("########################################################");

		
		for (int j=0;j<jj;j++) {
			A[0][j]= A[1][j] = '.';
			t-=2;
		}
		
//		for (int i = 0; i < r; i++) {
//			for (int j = 0; j < c; j++)
//				out.print(A[i][j]);
//			out.println();
//		}
//		out.println("########################################################");

		
		for (int i=2;i<ii;i++)
			for (int j=2;j<jj;j++)
				if (t>0) {
					A[i][j]='.';
					t--;
				}
		A[0][0]='c';
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				out.print(A[i][j]);
			out.println();
		}
//		out.println("########################################################");
	}
//
//	private static void solvePrint(int ii, int jj, int r, int c, int m,
//			PrintStream out) {
//
//		out.println("***************************************************");
//		for (int i = 0; i < r; i++) {
//			for (int j = 0; j < c; j++) {
//				if (i == 0 && j == 0)
//					out.print("c");
//				else if (i < ii && j < jj)
//					out.print(".");
//				else
//					out.print("*");
//			}
//			out.println();
//		}
//	}

	private static void myprint(char[][] a, PrintStream out) {
		a[a.length - 1][a[0].length - 1] = 'c';
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				if (a[i][j] == 'x')
					a[i][j] = '.';
				out.print(a[i][j]);
			}
			out.println();
		}
	}
}