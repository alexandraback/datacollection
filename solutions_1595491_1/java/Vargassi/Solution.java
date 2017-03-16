package gjc.googledancer;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Solution {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("B-large.txt"));
		int nTestCases = Integer.parseInt(br.readLine());
		for (int i=0; i<nTestCases; i++) {
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line);
			int nDancer = Integer.parseInt(st.nextToken());
			int nSurprise = Integer.parseInt(st.nextToken());
			int threshold = Integer.parseInt(st.nextToken());

			int result = 0;
			for (int j=0; j<nDancer; j++) {
				int totalValue = Integer.parseInt(st.nextToken());
				int stdValue = 0, surpriseValue = 0;
				if (totalValue%3==0) {
					stdValue = totalValue/3;
					if (totalValue==0 || totalValue==30) {
						surpriseValue = stdValue;
					} else {
						surpriseValue = totalValue/3 + 1;
					}
				} else if (totalValue%3==1) {
					stdValue = totalValue/3 + 1;
					surpriseValue = totalValue/3 + 1;
				} else if (totalValue%3==2) {
					stdValue = totalValue/3+1;
					if (totalValue==29) {
						surpriseValue = stdValue;
					} else {
						surpriseValue = totalValue/3 + 2;
					}
				}
				
				if (stdValue>=threshold) {
					result++;
				} else if (surpriseValue>=threshold && nSurprise>0) {
					result++;
					nSurprise--;
				}
			}
			
			// Display the results.
			bw.write("Case #"+(i+1)+": ");
			bw.write(result+"\n");
		}
		bw.close();
	}

}
