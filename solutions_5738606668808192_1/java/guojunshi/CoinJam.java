import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

public class CoinJam {
//	public static String inPath = "/Users/guojunshi/Downloads/C-large.in.txt";
//	public static String outPath = "/Users/guojunshi/Downloads/C-large.out.txt";

	public static String inPath = "C-large.in.txt";
	public static String outPath = "C-large.out.txt";

	public static BigInteger[] figures;
	public static BufferedWriter out;

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader in = new BufferedReader(new FileReader(inPath));
		out = new BufferedWriter(new FileWriter(outPath));
		int T = Integer.parseInt(in.readLine());
		for (int i = 0; i < T; i++) {
			out.write("Case #" + (i + 1) + ":\n");
			String line = in.readLine();
			String[] eles = line.trim().split("\\s+");
			OneCase(Integer.parseInt(eles[0]), Integer.parseInt(eles[1]));
		}
		in.close();
		out.close();
	}

	public static int remain;
	public static BigInteger two = new BigInteger("2");
	public static BigInteger three = new BigInteger("3");
	public static BigInteger up = new BigInteger("2000");

	public static void OneCase(int N, int J) throws IOException {
		figures = new BigInteger[N];
		figures[0] = figures[N - 1] = BigInteger.ONE;
		for (int i = 1; i < N - 1; i++) {
			figures[i] = BigInteger.ZERO;
		}
		remain = J;
		findAndOutput(N, 1);
	}

	public static void findAndOutput(int N, int index) {
		if (remain == 0) {
			return;
		}
		if (index == N - 1) {
			String result = jamTest();
			if (result != null) {
				try {
					out.write(getNumber() + result);
					out.newLine();
					remain--;
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return;
		}
		if (remain > 0) {
			figures[index] = BigInteger.ZERO;
			findAndOutput(N, index + 1);
		}
		if (remain > 0) {
			figures[index] = BigInteger.ONE;
			findAndOutput(N, index + 1);
		}
	}

	public static String jamTest() {
		StringBuilder sb = new StringBuilder();
		for (int base = 2; base <= 10; base++) {
			long factor = findFactor(base);
			if (factor == -1) {
				return null;
			}
			sb.append(" " + factor);
		}
		return sb.toString();
	}

	public static long findFactor(int b) {
		BigInteger base = new BigInteger("" + b);
		int len = figures.length;
		BigInteger num = new BigInteger("0");
		for (int i = 0; i < len; i++) {
			num = num.multiply(base).add(figures[i]);
		}
		if (num.isProbablePrime(1)) {
			return -1;
		}
		if (num.mod(two).equals(BigInteger.ZERO)) {
			return 2;
		}
		for (BigInteger i = three; i.compareTo(up) < 0; i = i.add(two)) {
			if (num.mod(i).equals(BigInteger.ZERO)) {
				return i.longValue();
			}
		}
		return -1;
	}

	public static String getNumber() {
		StringBuilder sb = new StringBuilder();
		for (BigInteger figure : figures) {
			sb.append(figure.longValue());
		}
		return sb.toString();
	}

}
