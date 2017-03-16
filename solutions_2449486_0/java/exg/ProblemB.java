import java.io.*;

public class ProblemB {

    public static String checkPattern(int[][] pattern)
    {
	final int M = pattern.length;
	final int N = pattern[0].length;
	int[] maxLines = new int[M];
	int[] maxColumns = new int[N];
	for (int i = 0; i < M; ++i) {
	    for (int j = 0; j < N; ++j) {
		maxLines[i] = Math.max(maxLines[i], pattern[i][j]);
		maxColumns[j] = Math.max(maxColumns[j], pattern[i][j]);
	    }
	}
	for (int i = 0; i < M; ++i) {
	    for (int j = 0; j < N; ++j) {
		if (pattern[i][j] < maxLines[i] &&
		    pattern[i][j] < maxColumns[j]) {
		    return "NO";
		}
	    }
	}
	return "YES";
    }

    public static void main(String[] args)
	throws IOException
    {
	BufferedReader fin = new BufferedReader(new FileReader(args[0]));
	int T = Integer.parseInt(fin.readLine());

	for (int t = 1; t <= T; ++t) {
	    String[] line = fin.readLine().split(" ");
	    int M = Integer.parseInt(line[0]);
	    int N = Integer.parseInt(line[1]);
	    int[][] pattern = new int[M][N];

	    for (int i = 0; i < M; ++i) {
		line = fin.readLine().split(" ");
		for (int j = 0; j < N; ++j) {
		    pattern[i][j] = Integer.parseInt(line[j]);
		}
	    }

	    System.out.print("Case #" + t + ": ");
	    System.out.println(checkPattern(pattern));
	}
    }

}