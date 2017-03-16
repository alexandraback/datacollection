package cn.zhoushuyan.codejam._2013.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class B {
	public static void main(String[] args) throws Exception {
		// TODO input file path
		String filePath = "/Users/Alen/Documents/CodeJam/2013/Qualification/B-Large.in";

		BufferedReader br = new BufferedReader(new FileReader(filePath));
		String outFile = filePath.substring(0, filePath.lastIndexOf('.'))
				+ ".out";
		BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
		
		String line = br.readLine();
		int t = Integer.valueOf(line);
		for (int i = 0; i < t; i++) {
			// TODO main logical
			// ...
			line = br.readLine();
			String[] strs = line.split(" ");
			int n = Integer.valueOf(strs[0]);
			int m = Integer.valueOf(strs[1]);
			int height[][] = new int[n][m];
			for (int j = 0; j < n; j++) {
				line = br.readLine();
				strs = line.split(" ");
				for (int j2 = 0; j2 < m; j2++) {
					height[j][j2] = Integer.valueOf(strs[j2]);
				}
			}
			
			int rowHighest[] = new int[n];
			for (int j = 0; j < rowHighest.length; j++) {
				rowHighest[j] = 0;
			}
			int columnHighest[] = new int[m];
			for (int j = 0; j < columnHighest.length; j++) {
				columnHighest[j] = 0;
			}
			
			for (int j = 0; j < height.length; j++) {
				for (int j2 = 0; j2 < height[j].length; j2++) {
					if (rowHighest[j] < height[j][j2])
						rowHighest[j] = height[j][j2];
					if (columnHighest[j2] < height[j][j2])
						columnHighest[j2] = height[j][j2];
				}
			}
			
			boolean possible = true;
			
j:			for (int j = 0; j < height.length; j++) {
				for (int j2 = 0; j2 < height[j].length; j2++) {
					if (height[j][j2] != rowHighest[j] && height[j][j2] != columnHighest[j2]) {
						possible = false;
						break j;
					}
				}
			}
			
			// TODO output
			bw.write(String.format("Case #%d: %s\r\n", i + 1, possible ? "YES" : "NO"));
		}

		bw.flush();
		bw.close();
		br.close();

	}
}
