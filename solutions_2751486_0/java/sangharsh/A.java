/*
 * 
 * To compile: javac <filename>.java
 * To run: java <filename> <input_file> > <output_file>
 * 
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class A
{

	private int n, L;

	private String name;

	private List<Pair> list;

	public A(String name, int n)
	{
		this.n = n;
		this.name = name;

		this.L = name.length();
		list = new ArrayList<Pair>();
	}

	public long solve()
	{
		int counter = 0;
		for (int i = 0; i < L; i++)
		{
			if (isVowel(name.charAt(i)))
			{
				counter = 0;
			}
			else
			{
				counter++;
			}
			if (counter >= n)
			{
				list.add(new Pair(i - n + 1, i));
			}
		}

		long answer = 0;
		int start = 0;
		int end = L - 1;
		for (int i = 0; i < list.size(); i++)
		{
			Pair p = list.get(i);
			answer += (p.x - start + 1) * (end - p.y + 1);
			start = p.x + 1;
		}

		return answer;
	}

	public static boolean isVowel(char c)
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			return true;
		return false;
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

		for (int i = 0; i < T; i++)
		{
			String name = scan.next();
			int n = scan.nextInt();

			A a = new A(name, n);
			System.out.println("Case #" + (i + 1) + ": " + a.solve());
		}
	}
}
