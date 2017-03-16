import java.io.*;
import java.util.*;

/*
 * Round 1B Problem B: Falling Diamonds
 */
public class ProblemB_1B {
	public static double solve(int N, int x, int y) {
		double[][] p_table = new double[10001][10001];
		for (int i=0; i<p_table.length; i++) {
			for (int j=0; j<p_table[i].length; j++) {
				p_table[i][j] = 0;
			}
		}
		for (int i=0; i<N; i++) {
			if (i == 0) {
				p_table[0][0] = 1;
				continue;
			}
			int p_y = 0;
			double min = 0.5;
			int diff = 0;
			while (p_table[0][p_y] == 1) {
				p_y += 2;
				diff++;
				min = min / 2;
			}
			
			int right_x = diff * 2;
			double p = 0.5;
			boolean doAdd = true;
			for (int j=0; j<p_y; j++) {
				if (p_table[right_x][j] == 0) {
					doAdd = false;
					for (int k=j; k>=0; k--) {
						p_table[right_x][k] += p;
						right_x++;
					}
				}
				p = p / 2;
				right_x--;
			}
			if (doAdd) {
				if (p < min) {
					p = min;
				}
				right_x = diff * 2;
				for (int k=0; k<p_y; k++) {
					p_table[right_x][k] += p;
					if (p_table[right_x][k] > 1) {
						p_table[right_x][k] = 1;
					}
					right_x--;
				}
			}
		}
		return p_table[Math.abs(x)][y];
	}
	
	public static void main(String[] args) {
		try {
			// Init Scanner / Writer
			String filename = "B-small-attempt0";
			Scanner sc = new Scanner(new File(filename + ".in"));
			BufferedWriter out = new BufferedWriter(new FileWriter(filename + ".out"));
			
			// Start reading file
			int T = sc.nextInt();
			for (int i=1; i<=T; i++) {
				sc.nextLine();
				int N = sc.nextInt();
				int x = sc.nextInt();
				int y = sc.nextInt();
				out.write("Case #");
				out.write(Integer.toString(i));
				out.write(": ");
				out.write(Double.toString(solve(N, x, y)));
				out.write("\n");
			}
			out.close();
			sc.close();
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}
