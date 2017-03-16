import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


public class GoogleCodeJam2014Q3 {

	ArrayList<String> inputLines = new ArrayList<String>();
	ArrayList<String> outputLines = new ArrayList<String>();
	private static final String PATH ="/Users/koichisakumoto/Documents/GoogleCodeJam/";
	
	public static void main(String[] args) {
		GoogleCodeJam2014Q3 inst = new GoogleCodeJam2014Q3();
		inst.getLines(PATH + "Q3/C-small-attempt1.in.txt");
		//inst.getLines(PATH + "Q3/test.txt");
		inst.solveProblem();
		inst.putLines(PATH + "Q3/answer1.txt");
	}

	private static final int MINE = 0;
	private static final int CLICK = 1;
	private static final int NONE = 2;
	
	private void solveProblem(){
		int currentLine = 0;
		int totalNum = Integer.parseInt(inputLines.get(currentLine++));
		
		for (int problemNum = 1; problemNum <= totalNum; problemNum++ ) {
			
			// input problem
			String[] rcm = inputLines.get(currentLine++).split(" ");
			final int r = Integer.parseInt(rcm[0]);
			final int c = Integer.parseInt(rcm[1]);
			final int m = Integer.parseInt(rcm[2]);

			// solve problem
			int matrix[][];
			if ( (r == 1) || (c == 1) ){
				if( m == r*c-1 ){
					matrix = allButOneMineVector(r, c, m);
				} else {
					matrix = makeVector(r, c, m);
				}
			} else {
				if( m == r*c-1 ){
					matrix = allButOneMineMatrix(r, c, m);
				} else {
					matrix = makeMatrix(r, c, m);
				}
			}

			// make answer
			outputLines.add("Case #" + problemNum + ":");
			if ( matrix == null ){
				outputLines.add("Impossible");
			} else {
				for (int i = 0; i < r; i++) {
					String row = "";
					for (int j = 0; j < c; j++) {
						row = row + parseCell(matrix[i][j]);
					}
					outputLines.add(row);
				}
			}
		}
	}
	
	private String parseCell(int x){
		switch(x){
		case MINE: return "*";
		case CLICK: return "c";
		case NONE: return ".";
		}
		return null;
	}
	
	private int[][] allButOneMineVector(int r, int c, int m){
		if ( r == 1 ){
			int matrix[][] = new int[1][c];
			for (int j = 0; j < c-1; j++) {
				matrix[0][j] = MINE;
			}
			matrix[0][c-1] = CLICK;
			return matrix; 
		}
		if ( c == 1 ){
			int matrix[][] = new int[r][1];
			for (int i = 0; i < r-1; i++) {
				matrix[i][0] = MINE;
			}
			matrix[r-1][0] = CLICK;
			return matrix; 
		}
		return null;
	}
	
	private int[][] makeVector(int r, int c, int m){
		if ( r == 1 ){
			int matrix[][] = new int[1][c];
			for (int j = 0; j < c-1; j++) {
				matrix[0][j] = NONE;
			}
			matrix[0][c-1] = CLICK;
			for (int j = 0; j < c-2; j++) {
				if ( m > 0 ){
					matrix[0][j] = MINE;
					m--;
				}
			}
			if (m == 0) return matrix; 
		}
		if ( c == 1 ){
			int matrix[][] = new int[r][1];
			for (int i = 0; i < r-1; i++) {
				matrix[i][0] = NONE;
			}
			matrix[r-1][0] = CLICK;
			for (int i = 0; i < r-2; i++) {
				if ( m > 0 ){
					matrix[i][0] = MINE;
					m--;
				}
			}
			if (m == 0) return matrix; 
		}
		return null;
	}
	
	private int[][] allButOneMineMatrix(int r, int c, int m){
		int matrix[][] = new int[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				matrix[i][j] = MINE;
			}
		}
		matrix[r-1][c-1] = CLICK;
		return matrix;
	}
	
	private int[][] makeMatrix(int r, int c, int m){
		int matrix[][] = new int[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				matrix[i][j] = NONE;
			}
		}
		matrix[r-1][c-1] = CLICK;
		
		for (int i = 0; i < r-2; i++) {
			for (int j = 0; j < c-2; j++) {
				if ( m > 0 ){
					matrix[i][j] = MINE;
					m--;
				}
			}
		}
		if ( m == 0 ) return matrix;
		
		if ( m % 2 == 1 ) {
			if ( (r >= 3) && (c >= 3) ){
				matrix[r-3][c-3] = NONE;
				m++;
			} else {
				return null;
			}
			for (int i = 0; i < r-3; i++) {
				if ( m > 0 ){
					matrix[i][c-2] = MINE;
					matrix[i][c-1] = MINE;
					m -= 2;
				}
			}
			for (int j = 0; j < c-3; j++) {
				if ( m > 0 ){
					matrix[r-2][j] = MINE;
					matrix[r-1][j] = MINE;
					m -= 2;
				}
			}
		} else {
			for (int i = 0; i < r-2; i++) {
				if ( m > 0 ){
					matrix[i][c-2] = MINE;
					matrix[i][c-1] = MINE;
					m -= 2;
				}
			}
			for (int j = 0; j < c-2; j++) {
				if ( m > 0 ){
					matrix[r-2][j] = MINE;
					matrix[r-1][j] = MINE;
					m -= 2;
				}
			}
		}
		if ( m == 0 ) return matrix;
		
		return null;
	}
	
	private void getLines(String fileName){
		try {
            FileReader in = new FileReader(fileName);
            BufferedReader br = new BufferedReader(in);
            String line;
            while ((line = br.readLine()) != null) {
            	inputLines.add(line);
            }
            br.close();
            in.close();
        } catch (IOException e) {
            System.out.println(e);
        }
	}
	
	private void putLines(String fileName){
		try {
			FileWriter out = new FileWriter(fileName); // new file
			BufferedWriter bw = new BufferedWriter(out);
            for ( String line : outputLines ){
            	bw.write(line + "\r\n");
            }
            bw.close();
            out.close();
        } catch (IOException e) {
            System.out.println(e);
        }
	}
	
}
