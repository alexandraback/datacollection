package Y2013.Qualification;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

//JScience library was obtained from http://java.net/projects/jscience/downloads
import org.jscience.mathematics.number.LargeInteger;

public class FairAndSquare {
	private static final String PATH = "E:\\Projects\\Java\\CodeJam\\src\\Y2013\\Qualification\\InOut\\";
	private static final String FILE_NAME = "C-large-1";
	
	private StringBuilder strBuilder = new StringBuilder(150);

	private List<CaseData> cases;

	public static void main(String[] args) {
		FairAndSquare solver = new FairAndSquare();

		solver.convertInput();

		solver.readInput();
		//solver.test();
		solver.solve();
		solver.writeOutput();
	}

	public void solve() {
		for (CaseData caseData : cases) {
			//caseData.countStr = countThemSmall(caseData);
			//caseData.countStr = countThemLarge1(caseData);
			caseData.countStr = countThemLarge2(caseData);
		}
	}
	
	public void test() {
		String str;
		long i = 0L;
		
		str = firstPalindrome("10");
		
		//countThemLarge2(cases.get(99));
		
		/*
		while (i < 10000L) {
			str = Long.toString(i);
			str = nextPalindrome(str);
			i = Long.valueOf(str);
			
			//System.out.println(str);
		}
		*/
	}
	
	private String countThemSmall(CaseData caseData) {
		long min = caseData.min.longValue();
		long max = caseData.max.longValue();
		long count = 0;
		long tmpSqrt;
		
		for (long i = min; i <= max; ++i) {
			if (isPalindrome(Long.toString(i))) {
				tmpSqrt = Math.round(Math.sqrt((double)i));
				
				if (tmpSqrt*tmpSqrt == i && isPalindrome(Long.toString(tmpSqrt))) {
					++count;
					//System.out.println(i);
				}
			}
		}
		
		return Long.toString(count);
	}
	
	private String countThemLarge1(CaseData caseData) {
		LargeInteger min = LargeInteger.valueOf(caseData.min);
		LargeInteger max = LargeInteger.valueOf(caseData.max);
		LargeInteger sqrtMin = min.sqrt();
		LargeInteger sqrtMax = max.sqrt().plus(1);
		//LargeInteger count = LargeInteger.ZERO;
		long sqrtMinLong = sqrtMin.longValue();
		long sqrtMaxLong = sqrtMax.longValue();
		LargeInteger curSqr;
		long count = 0;
		
		for (long i = sqrtMinLong; i <= sqrtMaxLong; ++i) {
			if (isPalindrome(Long.toString(i))) {
				curSqr = LargeInteger.valueOf(i);
				curSqr = curSqr.times(curSqr);
				
				if (curSqr.compareTo(min) >= 0 && curSqr.compareTo(max) <= 0
						&& isPalindrome(curSqr.toString())) {
					
					++count;
					//System.out.println(i);
				}
			}
		}
		
		return Long.toString(count);
	}
	
	private String countThemLarge2(CaseData caseData) {
		LargeInteger min = LargeInteger.valueOf(caseData.min);
		LargeInteger max = LargeInteger.valueOf(caseData.max);
		LargeInteger sqrtMin = min.sqrt();
		LargeInteger sqrtMax = max.sqrt().plus(1);
		//LargeInteger count = LargeInteger.ZERO;
		long sqrtMinLong = sqrtMin.longValue();
		long sqrtMaxLong = sqrtMax.longValue();
		LargeInteger curSqr;
		long count = 0;
		long i;
		String str;
		
		str = Long.toString(sqrtMinLong);
		str = firstPalindrome(str);
		i = Long.valueOf(str);
		
		while (i <= sqrtMaxLong) {
			if (isPalindrome(Long.toString(i))) {
				curSqr = LargeInteger.valueOf(i);
				curSqr = curSqr.times(curSqr);
				
				if (curSqr.compareTo(min) >= 0 && curSqr.compareTo(max) <= 0
						&& isPalindrome(curSqr.toString())) {
					
					//count = count.plus(1);
					++count;
					//System.out.println(i);
				}
			}
			
			//++i;
			str = Long.toString(i);
			str = nextPalindrome(str);
			i = Long.valueOf(str);
		}
		
		return Long.toString(count);
	}
	
	private boolean isPalindrome(String numberStr) {
		int len = numberStr.length();
		int len2 = len/2;
		//int odd = len % 2;
		char a, b;
		boolean palindrome = true;
		int i = 0;
		
		while (i <= len2 && palindrome) {
			a = numberStr.charAt(i);
			b = numberStr.charAt(len - i - 1);
			
			palindrome = (a == b);
			
			++i;
		}
		
		return palindrome;
	}
	
	private String firstPalindrome(String minNumber) {
		int len = minNumber.length();
		int len2 = len/2;
		boolean even = (len % 2 == 0);
		String half = minNumber.substring(0, len2);
		String firstPalindrome;
		long num; 
		
		if (even) {
			strBuilder.setLength(0);
			strBuilder.append(half);
			strBuilder.reverse();
			
			firstPalindrome = half + strBuilder.toString();
		} else {
			String middle = minNumber.substring(len2, len2 + 1);
			
			strBuilder.setLength(0);
			strBuilder.append(half);
			strBuilder.reverse();
			
			firstPalindrome = half + middle + strBuilder.toString();
		}
		
		if (firstPalindrome.compareTo(minNumber) < 0) {
			firstPalindrome = nextPalindrome(minNumber);
		}
		
		
		return firstPalindrome;
	}
	
	private String nextPalindrome(String palindrome) {
		int len = palindrome.length();
		int len2 = len/2;
		boolean even = (len % 2 == 0);
		String half = palindrome.substring(0, len2);
		final String nextPalindrome;
		long num; 
		
		if (even) {
			num = Long.valueOf(half);
			++num;
			
			half = Long.toString(num);
			if (half.length() == len2) {
				strBuilder.setLength(0);
				strBuilder.append(half);
				strBuilder.reverse();
				
				nextPalindrome = half + strBuilder.toString();
			} else {
				// 99 -> 100, 999 -> 1000
				// We need 100 -> 10001, 1000 -> 1000001
				// So we take zeroes from "half" and add "1"
				nextPalindrome = half + half.substring(1, len2) + "1";
			}
		} else {
			String middle = palindrome.substring(len2, len2 + 1);
			int middleDigit = Integer.valueOf(middle);
			
			if (middleDigit < 9) {
				++middleDigit;
				
				strBuilder.setLength(0);
				strBuilder.append(half);
				strBuilder.reverse();
				
				nextPalindrome = half + Integer.toString(middleDigit) + strBuilder.toString();
			} else {
				middleDigit = 0;
				if (len2 > 0) {
					num = Long.valueOf(half);
					++num;
					half = Long.toString(num);
					
					if (half.length() == len2) {
						strBuilder.setLength(0);
						strBuilder.append(half);
						strBuilder.reverse();
						
						nextPalindrome = half + "0" + strBuilder.toString();
					} else {
						String formatString = "%0" + (len - 1) + "d";
						nextPalindrome = "1" + String.format(formatString, 0) + "1";
					}
				} else {
					// 9 -> 11 is a very hard case
					nextPalindrome = "11";
				}
			}
		}
		
		
		return nextPalindrome;
	}
	
	private void convertInput() {
		File in = new File(PATH + FILE_NAME + ".in");
		File out = new File(PATH + FILE_NAME + ".in2");

		try {
			Scanner scanner = new Scanner(in);
			PrintWriter writer = new PrintWriter(out);
			String line;

			while (scanner.hasNext()) {
				line = scanner.nextLine();
				writer.println(line);
			}

			scanner.close();
			writer.close();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	private void readInput() {
		File in = new File(PATH + FILE_NAME + ".in");

		try (final Scanner scanner = new Scanner(in)) {
			CaseData caseData;

			int casesCount = scanner.nextInt();
			scanner.nextLine();

			cases = new ArrayList<>(casesCount);

			for (int i = 0; i < casesCount; ++i) {
				caseData = new CaseData();
				
				caseData.min = scanner.nextBigInteger();
				caseData.max = scanner.nextBigInteger();
				
				cases.add(caseData);
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	private void writeOutput() {
		File out = new File(PATH + FILE_NAME + ".out");

		try (final PrintWriter writer = new PrintWriter(out)) {
			String line;
			CaseData caseData;

			for (int i = 0; i < cases.size(); ++i) {
				caseData = cases.get(i);
				line = "Case #" + (i + 1) + ": ";
				
				line += caseData.countStr;
				
				writer.println(line);
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	private static class CaseData {
		BigInteger min;
		BigInteger max;
		String countStr = "";
	}
}
