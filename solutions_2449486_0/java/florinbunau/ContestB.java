package contest;
import java.io.*;
import java.util.*;


public class ContestB {
	
	String OUTPUT_FOLDER = "input-contest/";
	String IN_NAME = "B-small-attempt0.in";
	String OUT_NAME = "B-small-attempt0.out";
	
	int T;
	int n, m;
	int board[][];
	
	class PairThatMustBeValid {
		public int line;
		public int column;
		
		PairThatMustBeValid(int i, int j) {
			line = i;
			column = j;
		}
	}
	
	class DataToCheck {
		public Set<Integer> lines = new HashSet<Integer>();
		public Set<Integer> columns = new HashSet<Integer>();
		public Set<PairThatMustBeValid> pairs = new HashSet<PairThatMustBeValid>();
	}
	
	Map<Integer, DataToCheck> heightToDataToCheck = new HashMap<Integer, DataToCheck>();
	
    public static void main(String[] args) throws IOException {
    	ContestB problem = new ContestB();
    	
		problem.readInput();
	}
    
    public void solveCase(int testCase) throws IOException  {
    	for (Integer height : heightToDataToCheck.keySet()) {
    		// check lines
    		Set<Integer> lines = heightToDataToCheck.get(height).lines;
    		Set<Integer> validLines = new HashSet<Integer>();
    		for (int i : lines) {
    			boolean invalid = false;
    			for (int j = 0; j < m; ++j) {
    				if (board[i][j] > height) {
    					invalid = true;
    				}
    			}
    			if (!invalid) {
    				validLines.add(i);
    			}
    		}
    			
    		// check column
    		Set<Integer> columns = heightToDataToCheck.get(height).columns;
    		Set<Integer> validColumns = new HashSet<Integer>();
    		for (int j : columns) {
    			boolean invalid = false;
    			for (int i = 0; i < n; ++i) {
    				if (board[i][j] > height) {
    					invalid = true;
    				}
    			}
    			if (!invalid) {
    				validColumns.add(j);
    			}
    		}
    		
    		Set<PairThatMustBeValid> pairs = heightToDataToCheck.get(height).pairs;
    		for (PairThatMustBeValid pair : pairs) {
    			boolean valid = (validLines.contains(pair.line) || validColumns.contains(pair.column));
    			if (!valid) {
    				writeOutput(testCase, "NO");
    				return;
    			}
    		}
    	}
    	writeOutput(testCase, "YES");
    }

    
    public void readInput() throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(OUTPUT_FOLDER + IN_NAME));

		String line = br.readLine();
		T = Integer.parseInt(line);
	
		try {
			for (int t = 0; t < T; ++t) {
				heightToDataToCheck = new HashMap<Integer, DataToCheck>();
				
				line = br.readLine();
				String split[] = line.split(" ");
				n = Integer.parseInt(split[0]);
				m = Integer.parseInt(split[1]);
				board = new int[n][m];
				for (int i = 0; i < n; ++i) {
					line = br.readLine();
					split = line.split(" ");
					for (int j = 0; j < m; ++j) {
						board[i][j] = Integer.parseInt(split[j]);
						DataToCheck dataToCheck = heightToDataToCheck.get(board[i][j]);
						if (dataToCheck == null) {
							dataToCheck = new DataToCheck();
							heightToDataToCheck.put(board[i][j], dataToCheck);
						}
						dataToCheck.lines.add(i);
						dataToCheck.columns.add(j);
						dataToCheck.pairs.add(new PairThatMustBeValid(i, j));
					}
				}
				solveCase(t);
			}

		} finally {
			br.close();
		}
	}
    
    public void writeOutput(int testCase, String answer) throws IOException {
    	boolean appendToFile = !(testCase == 0);
    	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(OUTPUT_FOLDER + OUT_NAME, appendToFile)));
    	out.printf("Case #%d: %s", testCase+1, answer);
    	if (testCase < T-1) {
    		out.println();
    	}
        out.close();
    }
}
