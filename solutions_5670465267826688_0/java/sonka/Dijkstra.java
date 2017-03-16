package qual_c;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Dijkstra {

	static final String inFile = "/Users/Sonicka/Desktop/C-small-attempt0.in";
	static final String outFile = "/Users/Sonicka/Desktop/output.txt";
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
		int X = reader.nextInt();
		boolean output = false;
		int[] word = translate(reader.next());
		
		if (L*X >= 2) {
			int[] sentence = repeat(L, X, word);
			
			int[] check = new int[] {1, 3};
			int j = (sentence[0] == 1) ? 1 : 0;

			for (int i = 1; i < sentence.length; i++) {
				sentence[i] = multi[sentence[i-1]][sentence[i]];
				if (j < 2 && sentence[i] == check[j]) j++;
			}

			if (j == 2 && sentence[sentence.length-1] == 4) {
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

	private static int[] repeat(int L, int X, int[] word) {
		int[] repeated = new int[L*X];
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < X; j++)
			{
				repeated[j*L+i] = word[i];
			}
		}
		return repeated;
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

