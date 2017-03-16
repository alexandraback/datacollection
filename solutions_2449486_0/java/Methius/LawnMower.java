package LawnMower;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

import common.Key;
import common.Primitives;

public class LawnMower {

	public static final String YES = "YES", NO = "NO";
	public static final String FORMAT = "Case #%d: %s\n";	
	
	public static boolean isValidField(int[][] field){

		int m = field.length,
				n = field[0].length;
		
		// Construct place holders for Max valuess
		int[] maxCol = new int[m],
				maxRow = new int[n];
		
		// Find max of columns
		for (int i = 0; i < m; i++) {
			maxCol[i] = Primitives.max(field[i]);
		}
		
		// Find max of rows
		for (int i = 0; i < n; i++) {
			int[] row = new int[m];
			for (int j = 0; j < m; j++) {
				row[j] = field[j][i];
			}
			
			maxRow[i] = Primitives.max(row);
		}
		
		// Go through matrix and check if the found value per cell is a row or column max
		for (int i = 0; i < m; i++) 
			for (int j = 0; j < n; j++) 
				if(field[i][j] != maxCol[i] && field[i][j] != maxRow[j])
					return false;
		
		return true;
		
	}
	
	public static int[][][] getFields(String file){
		
		BufferedReader br = null;
		int[][][] fields = null;
		
	    try {
			br = new BufferedReader(new FileReader(file));
	    	int t = Integer.parseInt(br.readLine());
	    	
	    	fields = new int[t][][];
	    	
			for (int i = 0; i < t; i++) {
		    	String[] fieldSS = br.readLine().split(" ");
		    	
		    	int n = Integer.parseInt(fieldSS[0]);
		    	int m = Integer.parseInt(fieldSS[1]);
		    	
		    	fields[i] = new int[n][m];
		    	
				for (int j = 0; j < n; j++) {
					String[] values = br.readLine().split(" ");
					for (int k = 0; k < m; k++) {
						fields[i][j][k] = Integer.parseInt(values[k]);
					}
				}
			}
	    } catch (NumberFormatException | IOException e) {
			e.printStackTrace();
		} finally {
	        try {
				br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
	    }
	    
	    return fields;
	}
	
	public static void main(String[] args){
		String id = "small-attempt0";
		int[][][] fields = getFields("input/lawnmower/B-"+id+".in");
		
		StringBuffer buf = new StringBuffer();
		for (int i = 0; i < fields.length; i++) {
			
			String outcome = isValidField(fields[i]) ? YES : NO;
			String result = String.format(FORMAT, i+1, outcome);
			
			buf.append(result);
			System.out.print(result);			
		}
		
		try {
			PrintWriter out = new PrintWriter("output/lawnmower/output-"+id+".txt");
			out.print(buf.toString());
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
}
