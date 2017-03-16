import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;

public class Lawn {

	public static void main(String[] args) throws Exception {
		Lawn object = new Lawn();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase()
				+ ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		st.nextToken();
		int testCases = (int) st.nval;

		for (int tc = 1; tc <= testCases; tc++) {
			st.nextToken();
			int n = (int) st.nval;
			
			st.nextToken();
			int m = (int) st.nval;
			
			int mat[][] = new int[n][m];
			
			for (int i=0; i<n; i++)
				for (int j=0; j<m; j++) {
					st.nextToken();
					mat[i][j] = (int) st.nval;
				}

			String output = object.solve(mat);
			wr.write("Case #" + tc + ": " + output + "\r\n");
		}

		wr.close();
	}

	private String solve(int[][] mat) {
		ArrayList<Integer> arr = new ArrayList<Integer>();
		HashSet<Integer> hs = new HashSet<Integer>();
		
		HashMap<Integer, ArrayList<Integer>> where = new HashMap<Integer, ArrayList<Integer>>();
		
		for (int i=0; i<mat.length; i++)
			for (int j=0; j<mat[i].length; j++) {
				if (!hs.contains(mat[i][j])) {
					hs.add(mat[i][j]);
					arr.add(mat[i][j]);
					
					where.put(mat[i][j], new ArrayList<Integer>());
				}
				
				where.get(mat[i][j]).add(i*1001 + j);
				
			}
		
		Collections.sort(arr);
		Collections.reverse(arr);
		
		for (int i=1; i<arr.size(); i++) {
			
			ArrayList<Integer> find = where.get(arr.get(i));
			
			for (int next : find) {
				int row = next / 1001;
				int col = next % 1001;
				
				//try by row
				boolean okRow = true;
				for (int cc=0; cc<mat[0].length; cc++)
					if (mat[row][cc] > arr.get(i))
						okRow = false;
				
				boolean okCol = true;
				for (int rr=0; rr<mat.length; rr++)
					if (mat[rr][col] > arr.get(i))
						okCol = false;
				
				if (!okRow && !okCol)
					return "NO";					
			}
			
		}
				
		return "YES";
	}
}
