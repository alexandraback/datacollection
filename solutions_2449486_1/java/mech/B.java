package codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class B {
	
	private static List<Integer> checkRow(int[] row) {
		ArrayList<Integer> condition = new ArrayList<Integer>();

		int max = 0;
		
		for (int i=0; i<row.length; i++)
			if (row[i] > max) max = row[i];
		
		for (int i=0; i<row.length; i++)
			if (row[i] < max) condition.add(i);
		
		return condition;
	}
	
	private static int[] findColMax(int[][] pattern, int h, int w) {
		int[] result = new int[w]; 
		
		for (int i=0; i<w; i++) {
			int max = 0;
			for (int j=0; j<h; j++)
				if (pattern[j][i] > max) max = pattern[j][i];
			result[i] = max;
		}
		
		return result;
	}
	
	private static boolean check(int[][] pattern, int h, int w) {
		int[] colMax = findColMax(pattern, h, w);
		
		for (int i=0; i<h; i++) {
			List<Integer> conditions = checkRow(pattern[i]);
			for (Integer col: conditions) {
				if (colMax[col] != pattern[i][col])
					return false;
			}
		}
		
		return true;
	}

	public static void main(String[] args) {
		File in = new File("E:\\Dev\\CodeJam2013\\Qual\\io\\B-large.in");
		File out = new File("E:\\Dev\\CodeJam2013\\Qual\\io\\B-large.out");

		try {
			BufferedReader reader = new BufferedReader(new FileReader(in));
			PrintWriter writer = new PrintWriter(out);

			int n = Integer.parseInt(reader.readLine());

			for (int i = 1; i <= n; i++) {
				String[] sz = reader.readLine().split(" ");

				int h = Integer.parseInt(sz[0]);
				int w = Integer.parseInt(sz[1]);
				
				int[][] pattern = new int[h][];

				for (int j = 0; j < h; j++) {
					pattern[j] = new int[w];

					String[] line = reader.readLine().split(" ");
					for (int k = 0; k < w; k++)
						pattern[j][k] = Integer.parseInt(line[k]);
				}
				
				if (check(pattern, h, w))
					writer.println("Case #" + i + ": YES");
				else
					writer.println("Case #" + i + ": NO");

			}

			reader.close();
			writer.close();
		} catch (Throwable e) {
			throw new RuntimeException(e);
		}
	}
}
