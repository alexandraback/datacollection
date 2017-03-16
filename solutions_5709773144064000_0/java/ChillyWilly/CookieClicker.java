
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Adrian Buturuga
 */
public class CookieClicker
{
	private static final BigDecimal two = new BigDecimal(2);
	private static final int precision = 20;

	private static void solveTestCase(int testCase, Scanner input, FileOutputStream output) throws IOException
	{
		float cost = input.nextFloat();
		float factor = input.nextFloat();
		float target = input.nextFloat();
		BigDecimal C = new BigDecimal(cost);
		BigDecimal F = new BigDecimal(factor);
		BigDecimal X = new BigDecimal(target);

		int farms = 0;
		BigDecimal current; 
		BigDecimal next;
		do {
			current = f(farms, C, F, X);
			next = f(++farms, C, F, X);
		} while (next.compareTo(current) == -1);
		output.write(("Case #"+testCase+": ").getBytes());
		output.write((current.setScale(7, RoundingMode.HALF_UP)+"\n").getBytes());
	}

	private static BigDecimal f(int farms, BigDecimal C, BigDecimal F, BigDecimal X)
	{
		BigDecimal sum = BigDecimal.ZERO;
		for (int i = 0; i < farms; i++)
		{
			sum = sum.add(BigDecimal.ONE.divide(two.add(new BigDecimal(i).multiply(F)), precision, RoundingMode.HALF_UP));
		}
		return C.multiply(sum).add(X.divide(new BigDecimal(farms).multiply(F).add(two), precision, RoundingMode.HALF_UP));
	}

	public static void main(String args[]) throws Exception
	{
		File inputFile = new File("B-small-attempt0.in");
		Scanner input = new Scanner(inputFile);
		input.useLocale(Locale.US);

		File outputFile = new File("B-small-attempt0.out");
		FileOutputStream fos = new FileOutputStream(outputFile);

		int testCases = input.nextInt();

		for (int i = 1; i <= testCases; i++)
		{
			solveTestCase(i, input, fos);
		}

		input.close();
		fos.close();
	}
}
