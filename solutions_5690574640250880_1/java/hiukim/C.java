import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class C {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    boolean DEBUG = false;
    
    public void task() throws IOException {
    	out.println();
    	
    	int R = nextInt();
    	int C = nextInt();
    	int BOMB = nextInt();
    	int M = R * C - BOMB;
    	boolean isRotated = false;
    	if (R > C) {
    		int tmp = R; R = C; C = tmp;
    		isRotated = true;
    	}
    	
    	if (M < 4 && R > 1 && M > 1) {
    		if (DEBUG) System.out.println(R + ", " + C + ", " + BOMB + ", " + (R*C - BOMB));
    		out.println("Impossible");
    		return;
    	}
    	
    	char[][] board = new char[R][C];
    	for (int r = 0; r < R; r++) {
    		Arrays.fill(board[r], '*');
    	}
    	
    	if (M == 1) {
    		board[0][0] = '.';
    	} else if (R == 1) {
    		for (int c = 0; c < M; c++) {
    			board[0][c] = '.';
    		}
    	} else if (R == 2) {
    		if (M % 2 == 1) {
    			if (DEBUG) System.out.println(R + ", " + C + ", " + BOMB + ", " + (R*C - BOMB));
    			out.println("Impossible");
        		return;
    		}
    		
    		for (int c = 0; c < M/2; c++) {
    			board[0][c] = '.';
    			board[1][c] = '.';
    		}
    	} else {
    		if (M == 4) {
    			board[0][0] = '.';
    			board[0][1] = '.';
    			board[1][0] = '.';
    			board[1][1] = '.';    			
    		} else if (M == 7 || M == 5) {
    			if (DEBUG) System.out.println(R + ", " + C + ", " + BOMB + ", " + (R*C - BOMB));
    			out.println("Impossible");
        		return;    			
    		} else if (M < 3 * C){
    			for (int r = 0; r < 3; r++) 
    				for (int c = 0; c < 2; c++) 
    					board[r][c] = '.';
    			M -= 6;
    			int c = 2;
    			while (M >= 2 && c < C) {
    				board[0][c] = '.';
    				board[1][c] = '.';
    				M -= 2;
    				c += 1;
    			}
    			c = 2;
    			while (M >= 1) {
    				board[2][c++] = '.';
    				M--;
    			}
    		} else {
    			for (int r = 0; r < 3; r++) 
    				for (int c = 0; c < C; c++) 
    					board[r][c] = '.';
    			M -= 3 * C;
    			int r = 3; int c = 0;
    			while (M > 0) {
    				board[r][c++] = '.';
    				M--;
    				if (c == C) {
    					r++;
    					c = 0;
    				}
    			}
    			if (c == 1) {
    				board[r][c] = '.';
    				board[r-c][C-1] = '*';
    			}
    		}    		
    	}
    	
    	for (int r = 0; r < R; r++) {
    		for (int c = 0; c < C; c++) {
    			if (board[r][c] == '*') BOMB--;
    		}
    	}
    	if (BOMB != 0) {
    		throw new RuntimeException();
    	}
    	if (!verify(board)) {
    		throw new RuntimeException();
    	}
    	
    	board[0][0] = 'c';
    	if (isRotated) {
    		for (int c = 0; c < C; c++) {
	    		for (int r = 0; r < R; r++) {
	    			out.print(board[r][c]);
	    		}
	    		out.println();
	    	}
    	} else {
	    	for (int r = 0; r < R; r++) {
	    		for (int c = 0; c < C; c++) {
	    			out.print(board[r][c]);
	    		}
	    		out.println();
	    	}
    	}
    }
    
    public boolean verify (char[][] board) {
    	boolean[][] opened = new boolean[board.length][board[0].length];
    	Queue<int[]> q = new LinkedList<int[]> ();
    	q.add(new int[]{0, 0});
    	opened[0][0] = true;
    	while (!q.isEmpty()) {
    		int[] cur = q.poll();
    		int cnt = 0;
    		for (int r = cur[0]-1; r <= cur[0] + 1; r++) {
    			for (int c = cur[1] - 1; c <= cur[1] + 1; c++) {
    				if (r < 0 || r >= board.length || c < 0 || c >= board[0].length) continue;
    				if (board[r][c] == '*') cnt++;
    			}
    		}
    		if (cnt == 0) {
    			for (int r = cur[0]-1; r <= cur[0] + 1; r++) {
        			for (int c = cur[1] - 1; c <= cur[1] + 1; c++) {
        				if (r < 0 || r >= board.length || c < 0 || c >= board[0].length) continue;
        				if (!opened[r][c] && board[r][c] != '*') {
        					opened[r][c] = true;
        					q.add(new int[] {r, c});
        				}
        			}
        		}	
    		}
    	}
    	
    	for (int r = 0; r < board.length; r++) {
    		for (int c = 0; c < board[0].length; c++) {
    			if (board[r][c] != '*' && !opened[r][c]) return false;
    		}
    	}
    	return true;
    }
        
	public void solve() throws IOException {
		int T = nextInt();
		for(int t = 1; t <= T; t++){
			out.print("Case #" + (t) + ": ");
			task();
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new C().run();
	}
	
	public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            out = new PrintWriter(System.out);
            solve();
            reader.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

}
