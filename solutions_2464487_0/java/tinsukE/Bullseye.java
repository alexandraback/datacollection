import java.io.File;
import java.io.FileWriter;
import java.io.FilenameFilter;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.Scanner;

public class Bullseye {

	private final static String DIR = ".";
	protected static final String PREFIX = "A-";
	private static final String SUFFIX = ".in";
	private static final String OUTPUT_SUFFIX = ".out";

	public static void main(String[] args) throws IOException {
		File[] files = listFiles(DIR, PREFIX, SUFFIX);

		for (File input : files) {
			FileWriter output = new FileWriter(input.getAbsolutePath().replace(
					SUFFIX, OUTPUT_SUFFIX), false);
			solveProblem(input, output);
		}
	}

	private static File[] listFiles(String dir, final String prefix,
			final String suffix) {
		File folder = new File(dir);
		System.out.println(folder.getAbsolutePath());
		File[] files = folder.listFiles(new FilenameFilter() {
			@Override
			public boolean accept(File file, String name) {
				return (name.startsWith(prefix) && name.endsWith(suffix));
			}
		});

		return files;
	}

	private static void solveProblem(File input, FileWriter output)
			throws IOException {
		Scanner scanner = new Scanner(input);
		int numCases = scanner.nextInt();

		for (int i = 0; i < numCases; i++) {
			String result = solveCase(scanner);
			String caseResult = "Case #" + String.valueOf(i + 1) + ": "
					+ result;

			System.out.println(caseResult);
			output.write(caseResult + '\n');
		}
		output.close();
	}

	private static String solveCase(Scanner input) {
		BigInteger firstRadius = input.nextBigInteger();
		BigInteger paintMl = input.nextBigInteger();
		
		BigInteger sum = BigInteger.ZERO;
		
		if (firstRadius.equals(BigInteger.ONE)) {
			paintMl = paintMl.subtract(BigInteger.valueOf(3));
			firstRadius = BigInteger.valueOf(3);
			if (paintMl.compareTo(BigInteger.valueOf(7)) < 0)
				return "1";
			sum = sum.add(BigInteger.ONE);
		}
		if (firstRadius.equals(BigInteger.valueOf(2))) {
			paintMl = paintMl.subtract(BigInteger.valueOf(5));
			firstRadius = BigInteger.valueOf(4);
			if (paintMl.compareTo(BigInteger.valueOf(9)) < 0)
				return "1";
			sum = sum.add(BigInteger.ONE);
		}
		
		BigInteger firstRadiusPlus1 = firstRadius.add(BigInteger.ONE);
		BigInteger vr = firstRadiusPlus1.multiply(firstRadiusPlus1).subtract(firstRadius.multiply(firstRadius));
		
		BigInteger result = solve2Grau(BigInteger.valueOf(2), vr.subtract(BigInteger.valueOf(2L)), paintMl.negate());
		result = result.add(sum);
		
		return String.valueOf(result);
	}

	private static BigInteger solve2Grau(BigInteger a, BigInteger b, BigInteger c) {
		BigInteger delta = b.multiply(b).subtract(BigInteger.valueOf(4L).multiply(a).multiply(c));
		return b.negate().add(bigSqrt(delta)).divide(BigInteger.valueOf(2L).multiply(a));
	}
	
	private static BigInteger bigSqrt(BigInteger n) {
		BigInteger a = BigInteger.ONE;
		BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8"))
				.toString());
		while (b.compareTo(a) >= 0) {
			BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
			if (mid.multiply(mid).compareTo(n) > 0)
				b = mid.subtract(BigInteger.ONE);
			else
				a = mid.add(BigInteger.ONE);
		}
		return a.subtract(BigInteger.ONE);
	}
	
//	private static BigDecimal bigSqrt(BigDecimal n) {
//		BigDecimal a = BigDecimal.ONE;
//		BigDecimal b = new BigDecimal(n.shiftRight(5).add(new BigInteger("8"))
//				.toString());
//		while (b.compareTo(a) >= 0) {
//			BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
//			if (mid.multiply(mid).compareTo(n) > 0)
//				b = mid.subtract(BigInteger.ONE);
//			else
//				a = mid.add(BigInteger.ONE);
//		}
//		return a.subtract(BigInteger.ONE);
//	}
	
	private static final BigDecimal SQRT_DIG = new BigDecimal(150);
	private static final BigDecimal SQRT_PRE = new BigDecimal(10).pow(SQRT_DIG.intValue());
	
	private static BigDecimal sqrtNewtonRaphson  (BigDecimal c, BigDecimal xn, BigDecimal precision)
	{
		BigDecimal fx = xn.pow(2).add(c.negate());
		BigDecimal fpx = xn.multiply(new BigDecimal(2));
		BigDecimal xn1 = fx.divide(fpx,2*SQRT_DIG.intValue(),RoundingMode.HALF_DOWN);
		xn1 = xn.add(xn1.negate());
		//----
		BigDecimal currentSquare = xn1.pow(2);
		BigDecimal currentPrecision = currentSquare.subtract(c);
		currentPrecision = currentPrecision.abs();
		if ( currentPrecision.compareTo(precision) <= -1 )
		{
			return xn1;
		}
		return sqrtNewtonRaphson(c, xn1,precision);
	}
	
	public static BigDecimal bigSqrt(BigDecimal c)
	{
		return sqrtNewtonRaphson(c,new BigDecimal(1),new BigDecimal(1).divide(SQRT_PRE));
	}

}
