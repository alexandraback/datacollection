import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class C {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		new C().run();
	}
	
	int r, c, m;
	char b[][];
	int col[][], num[][], qi[], qj[];
	boolean found;
	
	private void run() throws Exception {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("src\\input.txt"));
		PrintWriter pw = new PrintWriter("output.txt");
		int tc = sc.nextInt();
		b = new char[50][50];
		col = new int[50][50];
		num = new int[50][50];
		qi = new int[50 * 50];
		qj = new int[50 * 50];
		for (int t = 1; t <= tc; t++) {
			r = sc.nextInt();
			c = sc.nextInt();
			m = sc.nextInt();
			found = false;
			dumb(0, 0, 0);
			/*boolean flag = clever();
			if (flag != found)
				System.out.println("wrong");
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++)
					System.out.print(col[i][j]);
				System.out.println();
			}*/
			pw.printf("Case #%d:\n", t);
			if (!found)
				pw.println("Impossible");
			else {
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++)
						pw.print(b[i][j]);
					pw.println();
				}
			}
		}
		pw.close();
	}

	private boolean clever() {
		// TODO Auto-generated method stub
		for (int i = 0; i < r; i++)
			Arrays.fill(b[i], '.');
		int ci = r - 1;
		int cj = c - 1;
		int it = 0;
		for (int set = 0; set < m; ) {
			if (ci >= 0 && cj >= 0 && b[ci][cj] == '.') {
				b[ci][cj] = '*';
				ci--;
				cj++;
				set++;
				if (cj == c || ci == -1) {
					it++;
					ci = r - 1;
					cj = c - 1 - it;					
				}				
			} else {
				ci--;
				cj = 0;
			}
		}
//		for (int i = 0; i < r; i++)
//			Arrays.fill(b[i], '*');
//		for (int i = 0; i < 2; i++)
//			for (int j = 0; j < 5; j++)
//				b[i][j] = '.';
//		for (int j = 0; j < 4; j++)
//			b[2][j] = '.';
//		for (int i = 3; i < 5; i++)
//			for (int j = 0; j < 2; j++)
//				b[i][j] = '.';		
//		b[4][1] = '.';
//		b[2][3] = '*';
		for (int i = 0; i < r; i++)
			System.out.println(new String(b[i], 0, c));
		fillNum();
		b[0][0] = 'c';
		return bfs(0, 0);
	}

	private void dumb(int i, int j, int set) {
		// TODO Auto-generated method stub
		if (set > m)
			return;
		if (j == c) {
			i++;
			j = 0;
		}
		if (i == r) {
			if (set == m) {
				check();
			}
			return;
		}
		b[i][j] = '*';
		dumb(i, j + 1, set + 1);
		if (found)
			return;
		b[i][j] = '.';
		dumb(i, j + 1, set);
		if (found)
			return;
	}
	
	private boolean bfs(int fi, int fj) {
		for (int i = 0; i < r; i++)
			Arrays.fill(col[i], 0);
		int tail = -1;
		int head = -1;
		qi[++head] = fi;
		qj[head] = fj;
		col[fi][fj] = 1;
		while (tail < head) {
			int ci = qi[++tail];
			int cj = qj[tail];
			if (num[ci][cj] == 0) {
				for (int dx = -1; dx <= 1; dx++)
					for (int dy = -1; dy <= 1; dy++)
						if ((dx != 0 || dy != 0) && ci + dx >= 0 && ci + dx < r && cj + dy >= 0 && cj + dy < c && col[ci + dx][cj + dy] == 0) {
							col[ci + dx][cj + dy] = 1;
							qi[++head] = ci + dx;
							qj[head] = cj + dy;
						}					
			}
		}
		boolean flag = true;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (num[i][j] != -1 && col[i][j] == 0)
					flag = false;
		return flag;
	}

	private void check() {
		// TODO Auto-generated method stub
		fillNum();
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (b[i][j] == '.') {
					if (bfs(i, j)) {
						b[i][j] = 'c';
						found = true;
						return;
					}
				}
	}

	private void fillNum() {
		// TODO Auto-generated method stub
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				if (b[i][j] == '*') {
					num[i][j] = -1;
					continue;
				}
				num[i][j] = 0;
				for (int dx = -1; dx <= 1; dx++)
					for (int dy = -1; dy <= 1; dy++)
						if ((dx != 0 || dy != 0) && i + dx >= 0 && i + dx < r && j + dy >= 0 && j + dy < c) {
							num[i][j] += b[i + dx][j + dy] == '*' ? 1 : 0;
						}
			}
	}

}
