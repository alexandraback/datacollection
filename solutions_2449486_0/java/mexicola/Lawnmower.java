package Qualification2013;


import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.TreeSet;



public class Lawnmower {

	private static final int SIZE_MATRIX = 4;
	private static int[][] matrix;
	private static int h, w;
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		String inFile = "in"+File.separator+"B-small-attempt0.in.txt";
		String outFile = "out"+File.separator+"B-small-attempt0.out";
		
//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader in = new BufferedReader(new FileReader(inFile));
		PrintWriter out = new PrintWriter(new FileWriter(outFile));

		String s = "";
		String[] sArray = null;
		
		// num examples
		s = in.readLine();
		int t = Integer.parseInt(s);
		
		int element;
		TreeSet<Integer> elements;
		boolean valid;
		for (int i = 0; i < t; i++) {
			s = in.readLine();
			sArray = s.split("\\s+");
			h = Integer.parseInt(sArray[0]);
			w = Integer.parseInt(sArray[1]);
			
			matrix = new int[h][w];
			elements = new TreeSet<Integer>();
			for (int j = 0; j < h; j++) {
				s = in.readLine();
				sArray = s.split("\\s+");
				
				for (int k = 0; k < w; k++) {
					element = Integer.parseInt(sArray[k]);
					matrix[j][k] = element;
					elements.add(element);
				}
			}
			
			// check lines
			valid = true;
			for (int e: elements) {
				if (!checkElement(e)) {
					valid = false;
					break;
				}
			}
			
			if (valid)
				out.println("Case #"+(i+1)+": YES");
			else
				out.println("Case #"+(i+1)+": NO");

			

		}
		
		


		in.close();
		out.close();
	}


	private static boolean checkElement(int e) {
		boolean colValid, lineValid;
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				if (matrix[j][k] == e) {
					colValid = lineValid = true;
					for (int p = 0; p < h; p++) {
						if (matrix[p][k] > e)
							colValid = false;
					}
					for (int q = 0; q < w; q++) {
						if (matrix[j][q] > e)
							lineValid = false;
					}
					if (!colValid && !lineValid)
						return false;
				}
			}
		}
		return true;
		
	}
	
	

}
