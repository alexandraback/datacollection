package qualificationC;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		outinit();
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i=0;i<t;i++) {
			int R = sc.nextInt();
			int C = sc.nextInt();
			int M = sc.nextInt();
			solve(R,C,M);
		}
		outfile();
	}
	public static void solve(int R,int C,int M) {
		boolean flip = false;
		if (R > C) {
			flip = true;
			int temp = C;
			C = R;
			R = temp;
		}
		char[][] map = new char[R][C];
		boolean impossible = false;
		if (R*C-M == 1) {
			for(int i=0;i<R;i++) {
				for(int j=0;j<C;j++) {
					map[i][j] = '*';
				}
			}			
		}else if (R<=2) {
			if (R*C-M < 2*R || M % R != 0) {
				impossible = true;
			}else{
				for(int i=0;i<R;i++) {
					for(int j=0;j<C;j++) {
						map[i][j] = (j < C-M/R) ? '.' : '*';
					}
				}
			}
		}else{
			int[] l = new int[R];
			l[0] = 1;
			int m = R*C-M-4;
			if (m<2) {
				if (m!=0) {
					impossible = true;
				}
			}else{
				l[1] = 1;
				m -= 2;
				int add0 = Math.min(C-2, m/2);
				l[0] += add0;
				m -= add0 * 2;
				if (add0 == 0 && m == 1) {
					impossible = true;
				}
				for(int i=1;i<R-1;i++) {
					if (m>=2 && i<R-2) {
						l[i+1] = 1;
						m-=2;
					}
					int add = Math.min(C-2, m);
					l[i] += add;
					m -= add;
				}
			}
			if(!impossible) {
				//System.out.println(Arrays.toString(l));
				for(int i=0;i<R;i++) {
					for(int j=0;j<C;j++) {
						boolean flag = false;
						if (i==0) {
							if (l[0]+1 <= j) {
								flag = true;
							}
						}else{
							if (l[i-1]+1 <= j || l[i-1] == 0) {
								flag = true;
							}
						}
						map[i][j] = flag ? '*' : '.';
					}
				}
			}
		}

		StringBuffer ans = new StringBuffer();
		ans.append("\n");
		if (impossible) {
			ans.append("Impossible");
		}else{
			map[0][0] = 'c';
			if (!flip) {
				for(int i=0;i<R;i++) {
					for(int j=0;j<C;j++) {
						ans.append(map[i][j]);
					}
					if (i!=R-1) {
						ans.append("\n");
					}
				}
			}else{
				for(int j=0;j<C;j++) {
					for(int i=0;i<R;i++) {
						ans.append(map[i][j]);
					}
					if (j!=C-1) {
						ans.append("\n");
					}
				}				
			}
		}
		out(ans.toString());
		//debug
		/*
		if (!flip) {
			System.out.println(R + "," + C + "," + M + " ->\n" + ans + "\n");
		}else{
			System.out.println(C + "," + R + "," + M + " ->\n" + ans + "\n");
		}
		*/
	}
	
	public static int outnum = 0;
	public static BufferedWriter bw;
	public static void outinit() {
		try {
			bw = new BufferedWriter(new FileWriter("out.txt"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static void out(Object o) {
		outnum++;
		try {
			bw.write("Case #" + outnum + ": " + o);
			bw.newLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static void outfile() {
		try {
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
