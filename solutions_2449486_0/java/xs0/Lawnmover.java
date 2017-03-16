import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.LineNumberReader;


public class Lawnmover {
	static void go(String inputFile) throws Exception {
		LineNumberReader in = new LineNumberReader(new FileReader(inputFile));
		FileWriter out = new FileWriter(inputFile + ".out");
		
		int nCases = Integer.parseInt(in.readLine());
		for (int c = 1; c <= nCases; c++) {
			int[] dims = toInts(in.readLine());
			int rows = dims[0];
			int cols = dims[1];
			int[][] pat = new int[rows][];
			for (int r = 0; r < rows; r++)
				pat[r] = toInts(in.readLine());
			
			out.write("Case #" + c + ": " + result(pat) + "\n");
		}
		out.close();
	}
	
	static int[] toInts(String s) {
		String[] tmp = s.trim().split(" ");
		int n = tmp.length;
		int[] res = new int[n];
		for (int a = 0; a < n; a++)
			res[a] = Integer.parseInt(tmp[a]);
		return res;
	}
	
	static String result(int[][] pat) {
		int rows = pat.length;
		int cols = pat[0].length;

		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				boolean maxInRow = true;
				for (int cc = 0; cc < cols; cc++) {
					if (pat[r][cc] > pat[r][c]) {
						maxInRow = false;
						break;
					}
				}
				if (maxInRow)
					continue;
				for (int rr = 0; rr < rows; rr++) {
					if (pat[rr][c] > pat[r][c]) {
						return "NO";
					}
				}
			}
		}
		return "YES";
	}
	

	public static void main(String[] args) throws Exception {
		LineNumberReader sysIn = new LineNumberReader(new InputStreamReader(System.in));
		String line;
		while ((line = sysIn.readLine()) != null) {
			go(line.trim());
		}
	}
}
