import java.io.IOException;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Locale;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class Pogo {
	
	private void processInput() throws IOException {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();

		for (int testCase = 1; testCase <= T; testCase++) {
	        int x = in.nextInt();
            int y = in.nextInt();
	        
			String res = go(x, y);

			System.out.printf(Locale.ENGLISH, "Case #%d: %s\n", testCase, res);			
		}
		
		in.close();
	}
	
	class State {
	    int row;
	    int col;
	    String path;
	    State(int row, int col, String path) {
	        this.row = row;
	        this.col = col;
	        this.path = path;
	    }
        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + col;
            result = prime * result + row;
            return result;
        }
        @Override
        public boolean equals(Object obj) {
            State other = (State) obj;
            if (col != other.col)
                return false;
            if (row != other.row)
                return false;
            return true;
        }
	}

	int[] dx = {-1, 0, 1, 0};
	int[] dy = {0, -1, 0, 1};
	String dir = "WSEN";
	private String go(int x, int y) {
	    String res = bfsStr(x, y);

		return res;
	}

   public String bfsStr(int x, int y) {
        Queue<State> q = new LinkedList<State>();
        Set<State> d = new HashSet<State>(10000);

        State start = new State(0, 0, "");
        q.offer(start);
        d.add(start);
        while (!q.isEmpty()) {
            State u = q.poll();
            if (u.row == y && u.col == x) {
                return u.path;
            }

            for (int v = 0; v < dx.length; v++) {
                int nrow = u.row + dy[v] * (u.path.length() + 1);
                int ncol = u.col + dx[v] * (u.path.length() + 1);
                String npath = u.path + dir.charAt(v);
                State newState = new State(nrow, ncol, npath);
                if (!d.contains(newState)) {
                    q.offer(newState);
                    d.add(newState);
                }
            }
        }
        return "";
    }

	public static void main(String[] args) throws Exception {
		Pogo main = new Pogo();
		main.processInput();
	}
}
