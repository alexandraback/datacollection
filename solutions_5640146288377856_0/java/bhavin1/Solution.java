import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Solution {

	Scanner in;
	BufferedWriter out;

	public Solution() throws IOException {
		in = new Scanner(new File("C:\\Users\\Bhavin\\workspace\\CodeJam\\src\\prob.in"));
		out = new BufferedWriter(new FileWriter("C:\\Users\\Bhavin\\workspace\\CodeJam\\src\\prob.out"));
	}

	public void solve() throws IOException {

		int numCases = in.nextInt();
		for (int i = 1; i <= numCases; i++) {
			runCase(i);
		}
		out.close();
		in.close();
	}

	private void runCase(int caseNum) throws IOException {

		System.out.println("Case: " + caseNum);

		int row = in.nextInt();
		int col = in.nextInt();
		int W = in.nextInt();
		//int[] answers = new int[col];
		int result =1000000;
		if (W==1) result = row*col;
		else if(W==col) result = row+col-1;
		else {
			
			if(col % W == 0) {
				result =  (int) Math.ceil(col/W);
				result+=W-1;
			} else {
				result =  (int) Math.floorDiv(col,W);
				result+=W;
				
			}
			
			if(row>1) {
				result+= Math.floorDiv(col, W)*(row-1);
			}			
		}


		output(out, caseNum, result);

	}

	private int recurse(int score, int col_i, int col, int W, int[] answers, int ans, int guessed ) {
		
		if(notpossible(ans, W, col, col_i, answers)) return 100000;
		guessed++;
		if(guessed == W) return score;
		answers[col_i]=ans;
		for(int i=0; i< col+1 ; i++) {
			if(i!=col_i) {
				recurse(score++, i, col, W, answers, 1, guessed);
				recurse(score++, i, col, W, answers, -1, guessed);
			}
		}
		return score;
	}

	private boolean notpossible(int ans, int W, int col, int col_i, int[] answers) {

		answers[col_i]=-1;
		if(ans==1) {
			for(int i=0; i<col; i++) {
				if(answers[i] == 1 && (Math.abs(i-col_i) +1)>W) {
					return true;
				} 
			}
		}
		int count=0;
		for(int i=0; i<col; i++) {
			if(answers[i] >= 0) {
				count++;
				if(count==W) return true;
			} else count=0;
		}
		return false;
	}

	public static void main(String[] args) throws IOException {
		Solution s = new Solution();
		s.solve();

	}

	public void output(BufferedWriter out, int caseNum, int string) throws IOException {
		out.write("Case #" + caseNum + ": " + string + "\n");
	}

	public void output(BufferedWriter out, int caseNum, String string) throws IOException {
		out.write("Case #" + caseNum + ": " + string + "\n");
	}

}
 