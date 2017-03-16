import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class QuestionD {

	public static void doPuzzle() {
		try {
			
			File questionfile = new File("D.in");
			BufferedReader questionreader = new BufferedReader(new FileReader(questionfile));
	
			File answerfile = new File("D.out");
			PrintWriter answerwriter = new PrintWriter(new BufferedWriter(new FileWriter(answerfile)));

			String[] params = null;
			String question = questionreader.readLine();
			int T = Integer.parseInt(question);
			int[] A = new int[T];
			int[] B = new int[T];
			
			for (int i = 0; i < T; i++) {
				question = questionreader.readLine();
				params = question.split(" ");
				int H = Integer.parseInt(params[0]);
				int W = Integer.parseInt(params[1]);
				int D = Integer.parseInt(params[2]);
				String[] M = new String[H];
				for (int j = 0; j < H; j++) M[j] = questionreader.readLine(); 
				answerwriter.println("Case #" + (i+1) + ": " + analyze(H, W, D, M));
			}

			answerwriter.close();
			questionreader.close();
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		} catch (IOException e) {
			e.printStackTrace();
			return;
		}
	}
	
	private static int analyze(int H, int W, int D, String[] M) {
		int CX = 0;
		int CY = 0;
		char[][] realMap = new char[H][W];
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				char c = M[i].charAt(j);
				realMap[i][j] = c;
				if (c == 'X') {
					CX = i;
					CY = j;
				}
			}
		}

		boolean[][] virtualMap = new boolean[D*2+1][D*2+1];
		
		int answer = 0;
		
		for (int i = 0; i < D; i++) {
			for (int j = 0; j <= D*2; j++) {
				if (checkMirror(H, W, D, CX, CY, realMap, virtualMap, i, j)) answer++;
			}
		}
		{
			int i = D;
			for (int j = 0; j < D; j++) {
				if (checkMirror(H, W, D, CX, CY, realMap, virtualMap, i, j)) answer++;
			}
			for (int j = D*2; j > D; j--) {
				if (checkMirror(H, W, D, CX, CY, realMap, virtualMap, i, j)) answer++;
			}
		}
		for (int i = D*2; i > D; i--) {
			for (int j = 0; j <= D*2; j++) {
				if (checkMirror(H, W, D, CX, CY, realMap, virtualMap, i, j)) answer++;
			}
		}

		return answer;
	}

	private static int[] delta = { 1, -1 };
	private static int[] reverse = { 1, 0 };
	private static boolean checkMirror(int H, int W, int D, int CX, int CY, char[][] realMap, boolean[][] virtualMap, int PX, int PY) {
		if (virtualMap[PX][PY]) return false;
		
		int dx = Math.abs(PX - D);
		int dy = Math.abs(PY - D);
		if ((D * D) < (dx * dx + dy * dy)) return false;

		dx *= 2;
		dy *= 2;
		int rx = CX;
		int ry = CY;
		int drx = (PX > D) ? 0 : 1;
		int dry = (PY > D) ? 0 : 1;
		int dpx = drx;
		int dpy = dry;
		
		if (dx > dy) {
			for (int x = 1, oy = 0; x <= dx; x++) {
				int y = (dy * x) / dx;
				if ((((dy * x) % dx) == 0) && ((x % 2) == 0) && ((y % 2) == 0)) {
						//到達フラグ
						if (virtualMap[D+(x/2)*delta[dpx]][D+(y/2)*delta[dpy]]) return false;
						virtualMap[D+(x/2)*delta[dpx]][D+(y/2)*delta[dpy]] = true;
						//像判定
						if (realMap[rx][ry] == 'X') return true;
						oy = y;
						continue;
				} else if (y > oy) {
					oy = y;
					if (((dy * x) % dx) == 0) {
						if (((x % 2) == 1) && ((y % 2) == 1)) {
							//角反射
							if (realMap[rx+delta[drx]][ry+delta[dry]] != '#') {
								rx += delta[drx];
								ry += delta[dry];
							} else {
								if (realMap[rx+delta[drx]][ry] != '#') rx += delta[drx];
								else drx = reverse[drx];
								if (realMap[rx][ry+delta[dry]] != '#') ry += delta[dry];
								else dry = reverse[dry];
							}
							continue;
						}
					}
					if ((y % 2) == 1) {
						//y反射
						if (realMap[rx][ry+delta[dry]] != '#') ry += delta[dry];
						else dry = reverse[dry];
					}
				}
				if ((x % 2) == 1) {
					//x反射
					if (realMap[rx+delta[drx]][ry] != '#') rx += delta[drx];
					else drx = reverse[drx];
				}
			}
		} else {
			for (int y = 1, ox = 0; y <= dy; y++) {
				int x = (dx * y) / dy;
				if ((((dx * y) % dy) == 0) && ((x % 2) == 0) && ((y % 2) == 0)) {
						//到達フラグ
						if (virtualMap[D+(x/2)*delta[dpx]][D+(y/2)*delta[dpy]]) return false;
						virtualMap[D+(x/2)*delta[dpx]][D+(y/2)*delta[dpy]] = true;
						//像判定
						if (realMap[rx][ry] == 'X') return true;
						ox = x;
						continue;
				} else if (x > ox) {
					ox = x;
					if (((dx * y) % dy) == 0) {
						if (((x % 2) == 1) && ((y % 2) == 1)) {
							//角反射
							if (realMap[rx+delta[drx]][ry+delta[dry]] != '#') {
								rx += delta[drx];
								ry += delta[dry];
							} else {
								if (realMap[rx+delta[drx]][ry] != '#') rx += delta[drx];
								else drx = reverse[drx];
								if (realMap[rx][ry+delta[dry]] != '#') ry += delta[dry];
								else dry = reverse[dry];
							}
							continue;
						}
					}
					if ((x % 2) == 1) {
						//x反射
						if (realMap[rx+delta[drx]][ry] != '#') rx += delta[drx];
						else drx = reverse[drx];
					}
				}
				if ((y % 2) == 1) {
					//y反射
					if (realMap[rx][ry+delta[dry]] != '#') ry += delta[dry];
					else dry = reverse[dry];
				}
			}
		}
		
		return false;
	}

}

