package contest;
import java.io.*;
import java.util.*;


public class ContestA {
	
	String OUTPUT_FOLDER = "input-contest/";
	String IN_NAME = "A-large.in";
	String OUT_NAME = "A-large.out";
	
	int N;
	
	String board[] = new String[4];
	
	
    public static void main(String[] args) throws IOException {
    	ContestA problem = new ContestA();
    	
		problem.readInput();
	}
    
    public void solveCase(int testCase) throws IOException  {
    	int n = 4;
    	boolean Xwon = false;
    	boolean Owon = false;
    	int empty = 0;
    	for (int i = 0; i < n; ++i) {
    		int Xcnt = 0;
    		int Ocnt = 0;
    		int Tcnt = 0;
    		for (int j = 0; j < n; ++j) {
    			if (board[i].charAt(j) == 'X') {
    				Xcnt++;
    			}
    			if (board[i].charAt(j) == 'O') {
    				Ocnt++;
    			}
    			if (board[i].charAt(j) == 'T') {
    				Tcnt++;
    			}
    			if (board[i].charAt(j) == '.') {
    				empty++;
    			}
    		}
    		if ((Xcnt == 3 && Tcnt == 1) || Xcnt == 4) {
    			Xwon = true;
    		}
    		if ((Ocnt == 3 && Tcnt == 1) || Ocnt == 4) {
    			Owon = true;
    		}
    	}
    	
    	for (int i = 0; i < n; ++i) {
    		int Xcnt = 0;
    		int Ocnt = 0;
    		int Tcnt = 0;
    		for (int j = 0; j < n; ++j) {
    			if (board[j].charAt(i) == 'X') {
    				Xcnt++;
    			}
    			if (board[j].charAt(i) == 'O') {
    				Ocnt++;
    			}
    			if (board[j].charAt(i) == 'T') {
    				Tcnt++;
    			}
    		}
    		if ((Xcnt == 3 && Tcnt == 1) || Xcnt == 4) {
    			Xwon = true;
    		}
    		if ((Ocnt == 3 && Tcnt == 1) || Ocnt == 4) {
    			Owon = true;
    		}
    	}
    	
		int Xcnt = 0;
		int Ocnt = 0;
		int Tcnt = 0;
    	for (int i = 0; i < n; ++i) {
    		if (board[i].charAt(i) == 'X') {
				Xcnt++;
			}
			if (board[i].charAt(i) == 'O') {
				Ocnt++;
			}
			if (board[i].charAt(i) == 'T') {
				Tcnt++;
			}
			if ((Xcnt == 3 && Tcnt == 1) || Xcnt == 4) {
    			Xwon = true;
    		}
    		if ((Ocnt == 3 && Tcnt == 1) || Ocnt == 4) {
    			Owon = true;
    		}
    	}
    	
		Xcnt = 0;
		Ocnt = 0;
		Tcnt = 0;
    	for (int i = 0; i < n; ++i) {
    		int j = n-1-i;
    		if (board[i].charAt(j) == 'X') {
				Xcnt++;
			}
			if (board[i].charAt(j) == 'O') {
				Ocnt++;
			}
			if (board[i].charAt(j) == 'T') {
				Tcnt++;
			}
			if ((Xcnt == 3 && Tcnt == 1) || Xcnt == 4) {
    			Xwon = true;
    		}
    		if ((Ocnt == 3 && Tcnt == 1) || Ocnt == 4) {
    			Owon = true;
    		}
    	}
    	if (Xwon == false && Owon == false && empty > 0) {
    		writeOutput(testCase, "Game has not completed");
    	}
    	if (Xwon == false && Owon == false && empty == 0) {
    		writeOutput(testCase, "Draw");
    	}
    	if (Xwon == true) {
    		writeOutput(testCase, "X won");
    	}
    	if (Owon == true) {
    		writeOutput(testCase, "O won");
    	}
    }

    
    public void readInput() throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(OUTPUT_FOLDER + IN_NAME));

		String line = br.readLine();
		N = Integer.parseInt(line);
	
		try {
			for (int i = 0; i < N; ++i) {
			    for (int j = 0; j < 4; ++j) {
			    	line = br.readLine();
			    	board[j] = line;
			    }
			    line = br.readLine();
				solveCase(i);
			}

		} finally {
			br.close();
		}
	}
    
    public void writeOutput(int testCase, String answer) throws IOException {
    	boolean appendToFile = !(testCase == 0);
    	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(OUTPUT_FOLDER + OUT_NAME, appendToFile)));
    	out.printf("Case #%d: %s", testCase+1, answer);
    	if (testCase < N-1) {
    		out.println();
    	}
        out.close();
    }
}
