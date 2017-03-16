import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;


public class ProblemB {
	enum Mode {SAMPLE,SMALL,LARGE}

	static Mode mode = Mode.SMALL;

	Scanner in;
	PrintStream out;

	public static void main(String[] args) throws FileNotFoundException {
		new ProblemB().run();
	}

	public void run() throws FileNotFoundException {

		switch (mode) {
			case SAMPLE:
				in = new Scanner(new BufferedReader(new FileReader("/Users/abaudoux/Documents/Taktik/Sources/problems/files/inb")));
				out = new PrintStream(new FileOutputStream("/Users/abaudoux/Documents/Taktik/Sources/problems/files/B-sample.out"));
				break;
			case SMALL:
				in = new Scanner(new BufferedReader(new FileReader("/Users/abaudoux/Downloads/B-small-attempt1.in")));
				out = new PrintStream(new FileOutputStream("/Users/abaudoux/Documents/Taktik/Sources/problems/files/B-small.out"));
				break;
			case LARGE:
				in = new Scanner(new BufferedReader(new FileReader("/Users/abaudoux/Downloads/B-large.in")));
				out = new PrintStream(new FileOutputStream("/Users/abaudoux/Documents/Taktik/Sources/problems/files/B-large.out"));
				break;
			default:
				throw new IllegalStateException();
		}

		int size = in.nextInt();

		for (int p = 0 ; p < size ; p++) {
			out.print("Case #" + (p+1) + ": " + solve(in.nextInt(), in.nextBigInteger()));
		}
		out.close();
	}


	public String solve(int b, BigInteger ways) {
		StringBuilder res = new StringBuilder();
		BigInteger maxWays = BigInteger.ONE;
		for (int i = 0 ; i < (b-2) ; i++) {
			maxWays = maxWays.multiply(BigInteger.valueOf(2));
		}

		int[][] matrix = new int[b][b];


		int bitLength = ways.bitLength();


		if (ways.compareTo(maxWays) > 0) {
			res.append("IMPOSSIBLE\n");
			return res.toString();
		} else {
			res.append("POSSIBLE\n");
		}

//		if (bitLength == (b - 2)) {
//			full(matrix, 0);
//		}

		for (int bit = 0 ; bit < bitLength ; bit++) {
			if (ways.testBit(bit)) {
				int from = matrix.length - 1 - bit -1;
				full(matrix, from);
				if (from > 0) {
					matrix[0][from] = 1;
				}
			}
		}

		res.append(matrixToString(matrix));
		return res.toString();
	}

	private String matrixToString(int[][] matrix) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0 ; i< matrix.length ; i++) {
			for (int j = 0 ; j < matrix.length ; j++) {
				sb.append(matrix[i][j]);
			}
			sb.append("\n");
		}
		return sb.toString();
	}

	private void full(int[][] matrix, int from ) {
		for (int start = from ; start < matrix.length; start ++) {
			for (int end = start+1 ; end < matrix.length ; end++) {
				matrix[start][end] = 1;
			}
		}
	}



}
