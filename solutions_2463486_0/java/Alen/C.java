package cn.zhoushuyan.codejam._2013.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class C {
	
	public static void main(String[] args) throws Exception {
		// TODO input file path
		String filePath = "/Users/Alen/Documents/CodeJam/2013/Qualification/C-Small.in";

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
			int a = Integer.valueOf(strs[0]);
			int b = Integer.valueOf(strs[1]);
			
			int[] palindromeSquarePalindromes = new int[]{1, 4, 9, 121, 484};
			
			int total = 0;
			
			for (int j : palindromeSquarePalindromes) {
				if (j >= a && j <=b) {
					total++;
				}
			}
			
			
			// TODO output
			bw.write(String.format("Case #%d: %d\r\n", i + 1, total));
		}

		bw.flush();
		bw.close();
		br.close();

	}

}
