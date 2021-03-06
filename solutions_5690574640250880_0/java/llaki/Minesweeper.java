import java.util.*;
import java.io.*;

public class Minesweeper {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		PrintWriter pw = new PrintWriter(System.out);
		for (int test = 1; test <= T; test++) {
			R = sc.nextInt();
			C = sc.nextInt();
			M = sc.nextInt();
			if(R<=5 && C<=5) printForSmall(pw, test);
			else printAnswer(pw, test);
		}
		pw.flush();
		pw.close();
	}
	
	
	/**
	 *    c...
	 *    ....
	 *    ...*
	 *    ..**
	 * 	 */

	static void printForSmall(PrintWriter pw, int test){
		int numPoss = R*C;
		char[][] ans = new char[R][C];
		for(int i=0; i<(1<<numPoss); i++){
			int c = 0;
			for(int x=0; x<R; x++){
				for(int y=0; y<C; y++){
					int index = C*x+y;
					if((i&(1<<index))!=0){
						ans[x][y] = '*';
						c++;
					}
					else ans[x][y] = '.';
				}
			}
			if(c!=M) continue;
			for(int x=0; x<R; x++){
				for(int y=0; y<C; y++){
					if(ans[x][y]=='*') continue;
					ans[x][y] = 'c';
					if(isReallyValid(ans)){
						pw.println("Case #"+test+":");
						for(int s=0; s<R; s++){
							for(int t=0; t<C; t++){
								pw.print(ans[s][t]);
							}
							pw.println();
						}
						return;
					}
					ans[x][y] = '.';
				}
			}
		}
		pw.println("Case #"+test+":");
		pw.println("Impossible");
	}
	
	static void printAnswer1(PrintWriter pw, int test) {
		for (int a = 2; a <= R; a++) {
			for (int b = 2; b < C; b++) {
				for (int x = 2; x < a; x++) {
					for (int y = 2; b + y <= C; y++) {
						if(a*b+x*y!=M) continue;
						char[][] ans = new char[R][C];
						for(int i=0; i<R; i++) Arrays.fill(ans[i], '*');
						
						for(int i=0; i<a; i++){
							for(int j=0; j<b; j++){
								ans[i][j] = '.';
							}
						}
						for(int i=0; i<x; i++){
							for(int j=0; j<y; j++){
								ans[i][b+j] = '.';
							}
						}
						ans[0][0] = 'c';
						pw.println("Case #" + test + ":");
						for (int i = 0; i < R; i++) {
							for (int j = 0; j < C; j++) {
								pw.print(ans[i][j]);
							}
							pw.println();
						}
						pw.println(isReallyValid(ans));
						return;
					}
				}
			}
		}
		for (int a = 2; a <= C; a++) {
			for (int b = 2; b < R; b++) {
				for (int x = 2; x < a; x++) {
					for (int y = 2; b + y <= R; y++) {
						if(a*b+x*y!=M) continue;
						char[][] ans = new char[R][C];
						for(int i=0; i<R; i++) Arrays.fill(ans[i], '*');
						
						for(int i=0; i<a; i++){
							for(int j=0; j<b; j++){
								ans[j][i] = '.';
							}
						}
						for(int i=0; i<x; i++){
							for(int j=0; j<y; j++){
								ans[b+j][i] = '.';
							}
						}
						ans[0][0] = 'c';
						pw.println("Case #" + test + ":");
						for (int i = 0; i < R; i++) {
							for (int j = 0; j < C; j++) {
								pw.print(ans[i][j]);
							}
							pw.println();
						}
						pw.println(isReallyValid(ans));
						return;
					}
				}
			}
		}
		pw.println("Case #" + test + ":");
		pw.println("Impossible");
	}

	static void printAnswer(PrintWriter pw, int test) {
		if(M==R*C-1){
			char[][] ans = new char[R][C];
			for(int i=0; i<R; i++) Arrays.fill(ans[i], '*');
			ans[0][0] = 'c';
			pw.println("Case #"+test+":");
			for(int i=0; i<R; i++){
				for(int j=0; j<C; j++){
					pw.print(ans[i][j]);
				}
				pw.println();
			}
			pw.println(isReallyValid(ans));
			return;
		}
		if (R == 1 || C == 1) {
			if (M < R + C - 2) {
				pw.println("Case #" + test + ":");
				if (R == 1) {
					for (int i = 0; i < M; i++) {
						pw.print("*");
					}
					for (int i = M; i < C - 1; i++) {
						pw.print(".");
					}
					pw.println("c");
				} else {
					for (int i = 0; i < M; i++) {
						pw.println("*");
					}
					for (int i = M; i < R - 1; i++) {
						pw.println(".");
					}
					pw.println("c");
				}
				return;
			} else {
				pw.println("Case #" + test + ":");
				pw.println("Impossible");
				return;
			}
		}
		// R>1, C>1
		M = R * C - M;
		for (int a = 2; a <= R; a++) {
			int div = M / a, mod = M % a;
			if (2 <= div && ((div < C && mod != 1) || (div == C && mod == 0))) {
				// answer exists, print it and return
				char[][] ans = new char[R][C];
				for (int i = 0; i < R; i++) {
					Arrays.fill(ans[i], '*');
				}
				for (int i = 0; i < a; i++) {
					for (int j = 0; j < div; j++) {
						ans[i][j] = '.';
					}
				}
				for (int j = 0; j < mod; j++) {
					ans[j][div] = '.';
				}
				ans[0][0] = 'c';
				pw.println("Case #" + test + ":");
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						pw.print(ans[i][j]);
					}
					pw.println();
				}
				pw.println(isReallyValid(ans));
				return;
			} else {
				continue;
			}
		}
		for (int a = 2; a <= C; a++) {
			int div = M / a, mod = M % a;
			if (2 <= div && ((div < R && mod != 1) || (div == R && mod == 0))) {
				// answer exists, print it and return
				char[][] ans = new char[R][C];
				for (int i = 0; i < R; i++) {
					Arrays.fill(ans[i], '*');
				}
				for (int i = 0; i < a; i++) {
					for (int j = 0; j < div; j++) {
						ans[j][i] = '.';
					}
				}
				for (int j = 0; j < mod; j++) {
					ans[div][j] = '.';
				}
				ans[0][0] = 'c';
				pw.println("Case #" + test + ": ");
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						pw.print(ans[i][j]);
					}
					pw.println();
				}
				pw.println(isReallyValid(ans));
				return;
			} else {
				continue;
			}
		}
		printAnswer1(pw, test);
	}
	
	static boolean isReallyValid(char[][] ans){
		boolean[][] opened = new boolean[R][C];
		boolean[][] clicked = new boolean[R][C];
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if(ans[i][j]=='c') opened[i][j] = true;
			}
		}
		while(isUnopenedZero(opened, clicked, ans)){}
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if(ans[i][j]!='*' && !opened[i][j]) return false;
			}
		}
		return true;
	}
	
	static boolean isUnopenedZero(boolean[][] opened, boolean[][] clicked, char[][] ans){
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if(opened[i][j] && !clicked[i][j] && numBombs(i, j, ans)==0){
					clicked[i][j] = true;
					for(int a=-1; a<=1; a++){
						for(int b=-1; b<=1; b++){
							if(a==0 && b==0) continue;
							if(i+a>=0 && j+b>=0 && i+a<R && j+b<C){
								opened[i+a][j+b] = true;
							}
						}
					}
					return true;
				}
			}
		}
		return false;
	}

	static int numBombs(int x, int y, char[][] ans){
		int a = 0;
		for(int i=-1; i<=1; i++){
			for(int j=-1; j<=1; j++){
				if(i==0 && j==0) continue;
				if(x+i>=0 && y+j>=0 && x+i<R && y+j<C && ans[x+i][y+j]=='*') a++;
			}
		}
		return a;
	}
	
	static int R, C, M;
}
