import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class A {

	private Scanner in;
	private PrintWriter out;

	public static void main(String[] args) throws FileNotFoundException {
		new A(args[0]).start();
	}

	public A(String filename) throws FileNotFoundException {
		in = new Scanner(new File(filename));
		out = new PrintWriter("A.out");
	}

	private void start() {

		int T = Integer.parseInt(in.nextLine());

		for (int i = 1; i <= T; i++) {
			out.write("Case #" + i + ": " + solve() + "\n");
		}

		out.close();
	}

	private int solve() {
		int R, C, W, sol;
		String[] temp = in.nextLine().split(" ");
		R = Integer.parseInt(temp[0]);
		C = Integer.parseInt(temp[1]);
		W = Integer.parseInt(temp[2]);

		if (W == 1)
			return R * C;

		int rowMiss = (int) C / W;
		sol = rowMiss * R;
		
		sol += W;
		
		if(W==C) {
			sol -= rowMiss;
		} else if (rowMiss > 1 && C%W == 0) {
			sol--;
		}
		
		return sol;
	}

}