import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Diamond {
	
	private Scanner scanner = null;
	private PrintWriter out = null;
	
	private boolean has(int k, int x, int y) {
		return (y < k && Math.abs(x) <= (k - y - 1));
	}

	public void solveSingleTest(int testNumber) {
		int n = scanner.nextInt();
		int x = scanner.nextInt();
		int y = scanner.nextInt();
		
		int k = 0;
		for (k = 1;; k += 2)
			if (k * (k + 1) / 2 > n) {
				k -= 2;
				break;
			}
		
		n -= k * (k + 1) / 2;
		
		out.printf("Case #%d: ", testNumber);
		
		if (has(k, x, y)) {
			out.println("1.0");
			return;
		}
		
		if (!has(k + 2, x, y)) {
			out.println("0.0");
			return;
		}
		
		double[][] p = new double[2000][2000];
		p[0][0] = 1.0;
		for (int i = 0; i <= k + 1; i++)
			for (int j = 0; j <= k + 1; j++)
				if (i == k + 1) {
					p[i][j + 1]	+= p[i][j];
				}
				else if (j == k + 1) {
					p[i + 1][j] += p[i][j];
				}
				else {
					p[i + 1][j] += p[i][j] * 0.5;
					p[i][j + 1] += p[i][j] * 0.5;
				}
		
		double res = 0.0;
		for (int i = 0; i <= k + 1; i++)
			for (int j = 0; j <= k + 1; j++)
				if (i + j == n && i > y) {
					res += p[i][j];
				}
		out.printf("%.8f\n", res);
	}
	
	public Diamond() {
		try {
			scanner = new Scanner(new File("input.txt"));
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		int T = scanner.nextInt();
		for (int test = 1; test <= T; test++) {
			solveSingleTest(test);
		}
		
		out.close();
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Diamond();
	}

}
