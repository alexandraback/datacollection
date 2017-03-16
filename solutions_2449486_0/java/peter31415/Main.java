import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;


public class Main {
	static String file = "B-small-attempt0";
	
	public static void main(String[] args) throws IOException {	
	
		FileInputStream fis = new FileInputStream(file+ ".in");
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);

		FileOutputStream fos = new FileOutputStream(file + ".out");
		OutputStreamWriter isw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(isw);

		String line = null;
		List<String> lines = new ArrayList<String>();
		while ((line = br.readLine()) != null) {
			lines.add(line);
		}

		int problemCount = Integer.parseInt(lines.get(0));
		int currentIndex = 0;
		for (int i = 0; i < problemCount; i++) {
			String[] v = lines.get(++currentIndex).split(" ");
			int rows = Integer.parseInt(v[0]);
			int cols = Integer.parseInt(v[1]);
			int[][] d = new int[rows][cols];
			
			for (int j = 0; j < d.length; j++) {
				v = lines.get(++currentIndex).split(" ");
				for (int j2 = 0; j2 < v.length; j2++) {
					d[j][j2] = Integer.parseInt(v[j2]);
				}
			}
			
			boolean solution = getSolution(d);
			String r = "Case #" + (i+1) + ": ";
			
			if (solution)
				r+="YES";
			else
				r+="NO";
			
			System.out.println(r);
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();
	
	}
	
	public static boolean getSolution(int[][] d)
	{
		int[] largestInRow = new int[d.length];
		int[] largestInCol = new int[d[0].length];
		
		for (int i = 0; i < d.length; i++) {			
			for (int j = 0; j < d[0].length; j++) {
				largestInRow[i]=Math.max(largestInRow[i], d[i][j]);
				largestInCol[j]=Math.max(largestInCol[j], d[i][j]);
			}
		}
		
		for (int i = 0; i < d.length; i++) {			
			for (int j = 0; j < d[0].length; j++) {
				if (d[i][j] < largestInRow[i] && d[i][j] < largestInCol[j])
					return false;
			}
		}
		
		return true;
	}
}
