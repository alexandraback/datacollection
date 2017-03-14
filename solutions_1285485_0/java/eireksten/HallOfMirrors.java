import java.io.*;
import java.text.*;
import java.util.*;

public class HallOfMirrors {
	
	static BufferedReader stdin;
	static StringTokenizer st;

	static String LINE() throws Exception { return stdin.readLine(); }
	static String TOKEN() throws Exception {
		while (st == null || !st.hasMoreTokens())st = new StringTokenizer(LINE());
		return st.nextToken();
	}
	static int INT() throws Exception {return Integer.parseInt(TOKEN());}
	static long LONG() throws Exception {return Long.parseLong(TOKEN());}
	static double DOUBLE() throws Exception {return Double.parseDouble(TOKEN());}

	
	static DecimalFormat DF = new DecimalFormat("0.000",new DecimalFormatSymbols(Locale.ENGLISH));
	
	
	public static void main(String[] args) throws Exception {
		String input = "D-small-attempt0.in";
		String output = "D-small.out";
//		String input = "A-large.in";
//		String output = "A-large.out";
//		String input = "testa.in";
//		String output = "testa.out";
		stdin = new BufferedReader(new FileReader(new File(input)));
		FileWriter frw = new FileWriter(output);
		
		int cases = INT();
		int cc = 1;
		while(cases-->0) {
			System.out.println(cc);
			int H = INT(), W = INT(), D = INT();
			char[][] map = new char[H-2][];
			LINE();
			for(int i = 0; i< H-2; i++) {
				String row = LINE();
				map[i] = new char[W-2];
				for(int j = 1;j<row.length()-1;j++) {
					map[i][j-1] = row.charAt(j);
				}
			}
			LINE();
			
			int solution = new HallOfMirrors().solve(map, D);
			
			frw.write("Case #"+(cc++)+": ");
			frw.write(""+solution);
			frw.write("\n");
//			break;
		}
		frw.flush();
		frw.close();
		
		
		
	}
	
	public int solve(char[][] source, int D) {
		int N = source.length;
		int M = source[0].length;
		
		int NN = (D+N-1)/N;
		int NM = (D+M-1)/M;
		char[][] ss = new char[(2*NN+1)*N][(2*NM+1)*M];
		
		for(int i = 0;i<=NN;i++) {
			for(int j = 0;j<=NM;j++) {
				fill(ss, source, (NN+i)*N, (NM+j)*M, i%2!=0, j%2!=0);
				fill(ss, source, (NN+i)*N, (NM-j)*M, i%2!=0, j%2!=0);
				fill(ss, source, (NN-i)*N, (NM+j)*M, i%2!=0, j%2!=0);
				fill(ss, source, (NN-i)*N, (NM-j)*M, i%2!=0, j%2!=0);
			}
		}
		
//		for(char[] line : source)
//			System.out.println(String.valueOf(line));
//		System.out.println();
		int goalx = NN*N, goaly = NM*M;
out:	for(int i = 0;i<N;i++) {
			for(int j = 0;j<M;j++) {
				if(source[i][j]=='X') {
					goalx += i;
					goaly += j;
//					System.out.println("ok"+i+" "+j);
					break out;
				}
			}
		}
//		System.out.println(goalx+" "+goaly+" --> ");
		int count = 0;
		long d2 = D*D;
		for(int i = 0;i<ss.length;i++) {
			for(int j = 0;j<ss[i].length;j++) {
				if(i == goalx && j == goaly)continue;
				if(ss[i][j] == 'X') {
					
					// 1.Verify that path does not cross an X
					if(checkPath(ss, i, j, goalx, goaly, d2)) {
						count++;
//						System.out.println(i+" "+j);

					}
				}
			}
		}
		
//		System.out.println();

		
		return count;
		
	}
	
	private boolean checkPath(char[][] ss, int sx, int sy, int ex, int ey, long d2) {
//		System.out.println(sx+" "+sy+" -> "+ex+" "+ey);
		int dx = Math.abs(sx-ex);
		int dy = Math.abs(sy-ey);
		
		int gcd = GCD(Math.max(dx, dy), Math.min(dx, dy));
		
		int ddx = dx / gcd;
		int ddy = dy / gcd;
		if(ex < sx) ddx *= -1;
		if(ey < sy) ddy *= -1;
		
		int x = sx+ddx;
		int y = sy+ddy;
		
		while(x != ex || y != ey) {
//			System.out.println(x+);
			if(ss[x][y] == 'X') {
				return false;
			}
			
			x += ddx;
			y += ddy;
		}
		
		long sqdist = dx*dx + dy*dy;
		return sqdist <= d2;
	}
	
	public static int GCD(int a, int b) {
		   if (b==0) return a;
		   return GCD(b,a%b);
		}
	
	
	private static void fill(char[][] ss, char[][] source, int x, int y, boolean flipx, boolean flipy) {
		for(int i = 0;i<source.length;i++) {
			for(int j = 0;j<source[i].length;j++) {
				int xx = flipx?(source.length-1-i):i;
				int yy = flipy?(source[i].length-1-j):j;
				ss[x+i][y+j] = source[xx][yy];			
			}
		}
	}

}
