import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

public class Lawnmower {
	
	private static final String inputFilePath = "Input/input.txt";
	private static final int HEIGHTLIMIT = 100;
	
	private static boolean checkValid(int x, int y, boolean[][] blocked) {
		int N = blocked.length;
		int M = blocked[0].length;
		boolean flag = true;
		for (int i = 0; i < M; i ++)
			if (blocked[x][i]) {
				flag = false;
				break;
			}
		if (flag)
			return true;
		
		flag = true;
		for (int i = 0; i < N; i ++)
			if (blocked[i][y]) {
				flag = false;
				break;
			}
		return flag;
	}
	
	private static boolean solve(int[][] A) {
		int N = A.length;
		int M = A[0].length;
		boolean[] heightexist = new boolean[HEIGHTLIMIT + 1];
		Arrays.fill(heightexist, false);		
		for (int i = 0; i < N; i ++)
			for (int j = 0; j < M; j ++)
				heightexist[A[i][j]] = true;
		
		boolean[][] blocked = new boolean[N][M];
		for (int i = 0; i < N; i ++)
			Arrays.fill(blocked[i], false);
		
		for (int height = HEIGHTLIMIT; height > 0; height --)
			if (heightexist[height]) {
				for (int i = 0; i < N; i ++)
					for (int j = 0; j < M; j ++)
						if (A[i][j] == height) {
							if (!checkValid(i, j, blocked))
								return false;
						}
				for (int i = 0; i < N; i ++)
					for (int j = 0; j < M; j ++)
						if (A[i][j] == height)
							blocked[i][j] = true;
			}
		return true;
	}
	
	/**
	 * Good Luck, Wash!
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(inputFilePath)); 
		int T = Integer.parseInt(br.readLine());
		for (int caseNum = 1; caseNum <= T; caseNum ++) {
			String[] parts = br.readLine().split(" ");
			int N = Integer.parseInt(parts[0]);
			int M = Integer.parseInt(parts[1]);
			int[][] A = new int[N][M];
			for (int i = 0; i < N; i ++) {
				parts = br.readLine().split(" ");
				for (int j = 0; j < M; j ++)
					A[i][j] = Integer.parseInt(parts[j]);
			}
			
			if (solve(A))
				System.out.println(String.format("Case #%d: YES", caseNum));
			else
				System.out.println(String.format("Case #%d: NO", caseNum));
		}
		br.close();

	}

}
