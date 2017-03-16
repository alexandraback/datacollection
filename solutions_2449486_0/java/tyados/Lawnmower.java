import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Lawnmower {

	static int N, M, caseNum;
	
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br  = new BufferedReader(new InputStreamReader(new FileInputStream("lawnmower.in")));
		PrintWriter pw = new PrintWriter(new FileOutputStream("lawnmower.out"));
		
		caseNum = Integer.parseInt(br.readLine());
		
		
		for (int i = 1;i <= caseNum;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			int[][] arr = new int[N][M];
			int[] maxRow = new int[N];
			int[] maxCol= new int[M];
			for (int k = 0;k < N;k++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0;j < M;j++) {
					arr[k][j] = Integer.parseInt(st.nextToken());
					if (arr[k][j] > maxRow[k])
						maxRow[k] = arr[k][j];
					if (arr[k][j] > maxCol[j])
						maxCol[j] = arr[k][j];
				}
			}
			boolean work = true;
			for (int k = 0;k < N && work;k++) {
				for (int j = 0;j < M && work;j++) {
					if (arr[k][j] < maxRow[k] && arr[k][j] < maxCol[j]) {
						pw.println("Case #" + i + ": NO");
						work = false;
						break;
					}
				}
				if (!work)
					break;
			}
			if (work)
				pw.println("Case #" + i  + ": YES");
			
		}
		
		pw.close();
		br.close();
		
	}
		
}
