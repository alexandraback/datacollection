/*
 * 
 * To compile: javac <filename>.java
 * To run: java <filename> <input_file> > <output_file>
 * 
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CopyOfFairAndSquare
{

	private static class FnSFinder
	{
		private static List<BigInteger> fnsNumbers = new ArrayList<BigInteger>(100);

		private static BigInteger LIMIT = new BigInteger("100000000000000");

		private BigInteger A, B;

		private static final BigInteger FOUR = new BigInteger("4");

		private static final BigInteger NINE = new BigInteger("9");

		private static final BigInteger TEN = new BigInteger("10");

		static
		{
			initList();
//			System.out.println("List: " + fnsNumbers);
//			System.out.println("Size: " + fnsNumbers.size());
		}

		public FnSFinder(BigInteger A, BigInteger B)
		{
			this.A = A;
			this.B = B;
		}

		private static boolean isPalindrome(BigInteger n)
		{
			String s = n.toString();

			int l = s.length();
			for (int i = 0; i < l / 2; i++)
			{
				if (s.charAt(i) != s.charAt(l - 1 - i))
					return false;
			}
			return true;
		}

		/**
		 * Must return only palindrome number
		 * 
		 * @param x
		 * @return
		 */
		private static BigInteger nextProbableFnSSeed(BigInteger x)
		{
			if (x.compareTo(NINE) == -1)
				return x.add(BigInteger.ONE);

			x = x.add(BigInteger.ONE);
			while (!isPalindrome(x))
			{
				x = x.add(BigInteger.ONE);
			}
			return x;
		}

		public static void initList()
		{
			BigInteger seed = BigInteger.ONE;
			BigInteger square = seed.multiply(seed);

			while (square.compareTo(LIMIT) != 1)
			{
				if (isPalindrome(square))
				{
					fnsNumbers.add(square);
				}

				seed = nextProbableFnSSeed(seed);
				square = seed.multiply(seed);
			}

		}

		public BigInteger solve()
		{
			BigInteger answer = BigInteger.ZERO;

			for (BigInteger bint : fnsNumbers)
			{
				boolean greaterThanA = bint.compareTo(A) != -1;
				boolean lessThanB = B.compareTo(bint) != -1;
				if (greaterThanA && lessThanB)
					answer = answer.add(BigInteger.ONE);
			}
			// while (square.compareTo(B) != 1)
			// {
			// if (isPalindrome(square))
			// {
			// if (A.compareTo(square) == 1)
			// answerA = answerA.add(BigInteger.ONE);
			// answerB = answerB.add(BigInteger.ONE);
			// }
			//
			// seed = nextProbableFnSSeed(seed);
			// square = seed.multiply(seed);
			// }

			return answer;
		}
	}

	public static void main(String[] args)
	{
		if (args.length != 1)
		{
			System.err.println("Run it with 1 command line argument i.e. filename of input file");
		}
		File file = new File(args[0]);
		Scanner scan = null;
		try
		{
			scan = new Scanner(file);
		}
		catch (FileNotFoundException e)
		{
			System.err.println("File not found");
			e.printStackTrace();
		}

		int T = scan.nextInt();
		FnSFinder fnsFinder;

		for (int i = 0; i < T; i++)
		{
			BigInteger A = scan.nextBigInteger();
			BigInteger B = scan.nextBigInteger();

			fnsFinder = new FnSFinder(A, B);
			System.out.println("Case #" + (i + 1) + ": " + fnsFinder.solve().toString());
		}
	}
}
