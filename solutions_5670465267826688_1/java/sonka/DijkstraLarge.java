package qual_c;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class DijkstraLarge{

	static final String inFile = "src/qual_c/C-large.in";
	static final String outFile = "src/qual_c/output-C-large.txt";
	static Scanner reader;
	static PrintWriter writer;
	
	// 0  1  2  3  4  5  6  7
	// 1  i  j  k -1 -i -j -k
	static int[][] multi = new int[][]{
			  { 0, 1, 2, 3, 4, 5, 6, 7},
			  { 1, 4, 3, 6, 5, 0, 7, 2},
			  { 2, 7, 4, 1, 6, 3, 0, 5},
			  { 3, 2, 5, 4, 7, 6, 1, 0},
			  { 4, 5, 6, 7, 0, 1, 2, 3},
			  { 5, 0, 7, 2, 1, 4, 3, 6},
			  { 6, 3, 0, 5, 2, 7, 4, 1},
			  { 7, 6, 1, 0, 3, 2, 5, 4}
			};
	
	public static void main(String[] args) throws IOException{
		reader = new Scanner(new File(inFile));
		writer = new PrintWriter(new File(outFile));
		int numberOfTests = reader.nextInt();
		for(int caseNo = 1; caseNo <= numberOfTests; caseNo++){
			solve(caseNo);
		}
		reader.close();
		writer.flush();
		writer.close();	
	}
	

	public static void solve(int caseNo) {
		int L = reader.nextInt();
		long X = reader.nextLong();
		System.out.println(caseNo + ".: L = " + L + ", X = " + X);
		boolean output = false;
		int[] word = translate(reader.next());
		
		if (L*X >= 2) {	
			int current = word[0];
			long Y = (X>12) ? (12 + (X%4)) : X;
			
			int[] check = new int[] {1, 3};
			int j = (current == 1) ? 1 : 0;
			
			for (long i = 1; i < L*Y; i++) {
				int position = (int)(i % word.length);
				int nextChar = word[position];
				current = multi[current][nextChar];
				if (j < 2 && current == check[j]) j++;
			}
			
			if (j == 2 && current == 4) {
				output = true;
			}
		}
		
		String str;
		if (output){
			str = "Case #"+caseNo+": YES";
		}
		else {
			str = "Case #"+caseNo+": NO";
		}
		
		writer.println(str);		
	}
	
	private static int[] translate(String input) {
		int[] output = new int[input.length()];
		for (int i = 0; i < input.length(); i++)
		{
			switch (input.charAt(i)) {
			case 'i': 	output[i] = 1;
						break;
			case 'j': 	output[i] = 2;
						break;
			case 'k': 	output[i] = 3;
						break;
			}
		}
		return output;
	}
}

