package codejam2016.round1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class GettingTheDigits {	
	public void run() throws IOException {
		BufferedReader fin = new BufferedReader(new FileReader(new File("in.txt")));
		PrintWriter fout = new PrintWriter(new File("out.txt"));
		int numCases = Integer.parseInt(fin.readLine());
		for (int cases = 0; cases < numCases; cases++) {
//			String[] line = fin.readLine().split(" ");
//			int n = Integer.parseInt(line[0]);
			int[] frequencies = new int[500];
			int[] numbers = new int[10];
			for (char ch : fin.readLine().toCharArray()) {
				frequencies[ch]++;
				switch(ch) {
				case 'Z' : numbers[0]++; break;
				case 'U' : numbers[4]++; break;
				case 'X' : numbers[6]++; break;
				case 'G' : numbers[8]++; break;
				}
			}
			numbers[5] = frequencies['F'] - numbers[4];
			numbers[7] = frequencies['V'] - numbers[5];
			numbers[3] = frequencies['H'] - numbers[8];
			numbers[2] = frequencies['T'] - frequencies['H'];
			numbers[1] = frequencies['O'] - numbers[2] - numbers[4] - numbers[0];
			numbers[9] = frequencies['I'] - numbers[5] - numbers[6] - numbers[8];

			System.out.format("Case #%d: ", cases+1);
			fout.format("Case #%d: ", cases+1);
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < numbers[i]; j++) {
					fout.print(i);
					System.out.print(i);
				}
			}
			System.out.println();
			fout.println();
		}
		fin.close();
		fout.close();
	}

	public static void main(String[] args) throws IOException {
		GettingTheDigits test = new GettingTheDigits();
		test.run();
	}
}
