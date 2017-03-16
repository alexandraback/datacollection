import java.io.*;


public class B {
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("B-small-attempt2.in.txt"));
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("B-small-attempt2.out.txt")));
			int T = Integer.parseInt(br.readLine());
			for (int t = 1; t <= T; t++) {
				String nm = br.readLine();
				int N = Integer.parseInt(nm.split(" ")[0]);
				int M = Integer.parseInt(nm.split(" ")[1]);
				int[][] board = new int[N][M];
				for (int i = 0; i < N; i++) {
					String line = br.readLine();
					String[] lengths = line.split(" ");
					for (int j = 0; j < M; j++)
						board[i][j] = Integer.parseInt(lengths[j]);
				}
				check(board, pw, t, N, M);
			}
			br.close();
			pw.close();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public static void check(int[][] board, PrintWriter pw, int t, int N, int M) {
		boolean ans = true;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				boolean col = true;
				for (int k1 = 0; k1 < N; k1++)
					if (board[i][j] < board[k1][j])
						col = false;
				boolean row = true;
				for (int k2 = 0; k2 < M; k2++)
					if (board[i][j] < board[i][k2])
						row = false;
				if (!row && !col)
					ans = false;
			}
		if (ans)
			pw.println("Case #" + t + ": YES");
		else
			pw.println("Case #" + t + ": NO");
	}
}
