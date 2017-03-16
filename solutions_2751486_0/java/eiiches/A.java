package gcj;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.TreeSet;

public class A 
{

	public static void main( String[] args ) throws NumberFormatException, IOException
	{
		final A a = new A();
		final BufferedReader reader = new BufferedReader(new FileReader(new File(args[0])));
		final int T = Integer.valueOf(reader.readLine());
		for (int i = 0; i < T; ++i) {
			final String[] columns = reader.readLine().split(" ");
			final String name = columns[0];
			final int n = Integer.valueOf(columns[1]);
			final int value = a.solve2(name, n);
			System.out.printf("Case #%d: %d%n", i + 1, value);
		}
	}
	
	public boolean isConsonant(final char ch) {
		return ! isVowel(ch);
	}

	public boolean isVowel(final char ch) {
		switch (ch) {
		case 'a':
		case 'i':
		case 'u':
		case 'e':
		case 'o':
			return true;
		default:
			return false;
		}
	}
	
	public int solve(final String name, final int n) {
		return solve(name, name.length(), n, name.length());
	}
	
	public boolean endWithNConsonant(final String name, final int end, final int n) {
		for (int i = end - n; i < end; ++i)
			if (!isConsonant((char) name.codePointAt(i)))
				return false;
		return true;
	}

	public int solve(final String name, final int end, final int n, final int last) {
		if (end < n)
			return 0;
		if (endWithNConsonant(name, end, n))
			return solve(name, end - 1, n, end - 1) + (end - n + 1) + (last - end + 1) - 1;
		return solve(name, end - 1, n, last);
	}
	
	public boolean beginWithNConsonant(final String name, final int begin, final int n) {
		for (int i = begin; i < begin + n; ++i)
			if (!isConsonant((char) name.codePointAt(i)))
				return false;
		return true;
	}
	
	public int solve2(final String name, final int n) {
		final TreeSet<Integer> begins = new TreeSet<Integer>();
		for (int begin = 0; begin + n <= name.length(); ++begin)
			if (beginWithNConsonant(name, begin, n))
				begins.add(begin);
		
		int sum = 0;
		for (int i = 0; i < name.length(); ++i) {
			final Integer c = begins.ceiling(i);
			if (c == null)
				continue;
			sum += name.length() - (c + n) + 1;
		}
		
		return sum;
	}
}
