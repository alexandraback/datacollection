package gjc.recyclednumber;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class Solution {

	List<Integer> list = new LinkedList<Integer>();
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("C-small-attempt0.txt"));
		int nTestCases = Integer.parseInt(br.readLine());
		for (int i=0; i<nTestCases; i++) {
			Set<String> resultSet = new HashSet<String>();
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line);
			int bottom = Integer.parseInt(st.nextToken());
			int top= Integer.parseInt(st.nextToken());
			for (int j=bottom; j<=top; j++) {
				String str = j+"";
				// Rotate and check if existing number exists.
				String temp = str;
				for (int k=0; k<str.length()-1; k++) {
					temp = temp.substring(1) + temp.charAt(0);
					if (!temp.startsWith("0")) {
						int number = Integer.parseInt(temp);
						if (number<j && number>=bottom) {
							resultSet.add(number+","+j);
						}
					}
				}
			}
			
			// Display the results.
			bw.write("Case #"+(i+1)+": ");
			bw.write(resultSet.size()+"\n");
		}
		bw.close();
	}

}
