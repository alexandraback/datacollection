import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;

// A very dump implementation....
public class MinesweeperMaster {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		FileReader fr = new FileReader("C-small-attempt0.in");
		BufferedReader br = new BufferedReader(fr);
		FileWriter fw = new FileWriter("out");
		BufferedWriter bw = new BufferedWriter(fw);
		MinesweeperMaster me = new MinesweeperMaster();

		int T = Integer.valueOf(br.readLine());
		String[] tokens = null;
		char[][] result = null;

		for (int i = 1; i <= T; i++) {
			tokens = br.readLine().split(" +");
			result = me.getResult(Integer.valueOf(tokens[0]),
					Integer.valueOf(tokens[1]), Integer.valueOf(tokens[2]));

			bw.write("Case #" + i + ":");
			bw.write('\n');

			if (result == null) {
				bw.write("Impossible");
				bw.write('\n');
			} else {
				for (int m = 0; m < result.length; m++) {
					bw.write(result[m]);
					bw.write('\n');
				}
			}

		}// T loop

		br.close();
		fr.close();
		bw.close();
		fw.close();
	}

	private char[][] getResult(int r, int c, int M) {

		int target = r * c - M;
		ArrayList<Integer> edges = new ArrayList<Integer>();
		char[][] board = new char[r][c];
		this.setAllChar(board, '*');
		board[0][0] = 'c';
		if (target == 1)
			return board;
		char[][] result = null;
		edges.add(0);
		edges.add(0);

		// start from top left corner.try if there is a solution.
		result = this.setEmpties(board, edges, 1, target);

		if (result != null)
			return result;

		if (r > 1 && c > 1) {
			board[0][0] = '*';
			board[1][1] = 'c';
			edges.clear();
			edges.add(1);
			edges.add(1);
			result = this.setEmpties(board, edges, 1, target);
		}
		if (result != null)
			return result;

		if (r > 1) {
			
			board[1][1] = '*';
			board[1][0] = 'c';
			
			edges.clear();
			edges.add(1);
			edges.add(0);
		
			result = this.setEmpties(board,edges, 1, target);
		}
		if (result != null)
			return result;

		return null;
	}

	// recursively try to set mines on the edge of the current clique.

	private char[][] setEmpties(char[][] board, ArrayList<Integer> edges,
			int left, int target) {

		int r;
		int c;
		int add = 0;
		char[][] newboard = null;
		ArrayList<Integer> newedges = null;

		if (left > target)
			return null;
		if (left == target)
			return board;

		//this.printBoard(board);

		// for each edge.

		for (int i = 0; i < edges.size(); i = i + 2) {
			r = edges.get(i);
			c = edges.get(i + 1);
			add = 0;
			
			
			newboard = this.deepcopy(board);
			
			
			newedges = new ArrayList<Integer>();

			if (r > 0 && c > 0) {
				if (newboard[r - 1][c - 1] == '*') {
					newboard[r - 1][c - 1] = '.';
					add++;
					newedges.add(r - 1);
					newedges.add(c - 1);
				}
			}

			if (r > 0) {
				if (newboard[r - 1][c] == '*') {
					newboard[r - 1][c] = '.';
					add++;
					newedges.add(r - 1);
					newedges.add(c);
				}
			}

			if (r > 0 && c < newboard[0].length - 1) {
				if (newboard[r - 1][c + 1] == '*') {
					newboard[r - 1][c + 1] = '.';
					add++;
					newedges.add(r - 1);
					newedges.add(c + 1);
				}
			}

			if (c < newboard[0].length - 1) {
				if (newboard[r][c + 1] == '*') {
					newboard[r][c + 1] = '.';
					add++;
					newedges.add(r);
					newedges.add(c + 1);
				}
			}

			if (r < newboard.length - 1 && c < newboard[0].length - 1) {
				if (newboard[r + 1][c + 1] == '*') {
					newboard[r + 1][c + 1] = '.';
					add++;
					newedges.add(r + 1);
					newedges.add(c + 1);
				}
			}

			if (r < newboard.length - 1) {
				if (newboard[r + 1][c] == '*') {
					newboard[r + 1][c] = '.';
					add++;
					newedges.add(r + 1);
					newedges.add(c);
				}
			}

			if (c > 0 && r < newboard.length - 1) {
				if (newboard[r + 1][c - 1] == '*') {
					newboard[r + 1][c - 1] = '.';
					add++;
					newedges.add(r + 1);
					newedges.add(c - 1);
				}
			}

			if (c > 0) {
				if (newboard[r][c - 1] == '*') {
					newboard[r][c - 1] = '.';
					add++;
					newedges.add(r);
					newedges.add(c - 1);

				}
			}

			if (add == 0) {
				continue;
			}

			for (int m = 0; m < edges.size(); m = m + 2) {

				if (this.isEdge(newboard, edges.get(m), edges.get(m + 1))) {
					newedges.add(edges.get(m));
					newedges.add(edges.get(m + 1));

				}

			}

			newboard = this.setEmpties(newboard, newedges, left + add, target);
			if (newboard != null)
				return newboard;

		}// each edge loop.

		return null;
	}

	private void setAllChar(char[][] result, char c) {
		for (int i = 0; i < result.length; i++) {
			for (int m = 0; m < result[0].length; m++) {
				result[i][m] = c;
			}
		}
	}

	private boolean isEdge(char[][] board, int r, int c) {
		if (r > 0 && c > 0) {
			if (board[r - 1][c - 1] == '*') {
				return true;
			}
		}

		if (r > 0) {
			if (board[r - 1][c] == '*') {
				return true;
			}
		}

		if (r > 0 && c < board[0].length - 1) {
			if (board[r - 1][c + 1] == '*') {
				return true;
			}
		}

		if (c < board[0].length - 1) {
			if (board[r][c + 1] == '*') {
				return true;
			}
		}

		if (r < board.length - 1 && c < board[0].length - 1) {
			if (board[r + 1][c + 1] == '*') {
				return true;
			}
		}

		if (r < board.length - 1) {
			if (board[r + 1][c] == '*') {
				return true;
			}
		}

		if (c > 0 && r < board.length - 1) {
			if (board[r + 1][c - 1] == '*') {
				return true;
			}
		}

		if (c > 0) {
			if (board[r][c - 1] == '*') {
				return true;
			}
		}

		return false;
	}

	// for debug.
	private void printBoard(char[][] board) {
		System.out.println();
		for (int m = 0; m < board.length; m++) {
			System.out.println(board[m]);
		}
	}

	private char[][] deepcopy(char[][] board) {
		char[][] result = new char[board.length][board[0].length];
		for(int r = 0;r< board.length;r++){
			for(int c = 0;c< board[0].length;c++){
				result[r][c] = board[r][c];
			}
		}
		return result;
	}
	
	
}
