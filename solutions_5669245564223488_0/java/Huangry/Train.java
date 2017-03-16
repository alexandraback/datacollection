import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Train
{

	public static boolean isValid(String str)
	{
		boolean[] alphabet = new boolean[26];
		for (int i = 0; i < 26; i++)
			alphabet[i] = false;
		alphabet [str.charAt(0)-'a'] = true;
		for (int i = 1; i < str.length(); i++)
		{
			if (str.charAt(i) != str.charAt(i - 1))
			{
				int index = str.charAt(i) - 'a';
				if (alphabet[index])
					return false;
				else
					alphabet[index] = true;
			}
		}

		return true;
	}

	public static int permute(String[] train)
	{
		ArrayList<Integer> result = new ArrayList<Integer>();
		return permute(train, 0);

	}

	static int permute(String[] num, int start)
	{

		int total = 0;
		if (start >= num.length)
		{
			String item = convertArrayToString(num);
			if (isValid(item))
				total++;
		}

		for (int j = start; j <= num.length - 1; j++)
		{
			swap(num, start, j);
			total += permute(num, start + 1);
			swap(num, start, j);
		}
		return total;
	}

	private static String convertArrayToString(String[] num)
	{
		String str = "";
		for (int h = 0; h < num.length; h++)
		{
			str += (num[h]);
		}
		return str;
	}

	private static void swap(String[] a, int i, int j)
	{
		String temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		Scanner scan = new Scanner(new File("B-small-attempt0 (1).in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("q2.txt"));

		int t = scan.nextInt();

		for (int i = 1; i <= t; i++)
		{
			int n = scan.nextInt();
			String[] trains = new String[n];
			for (int k = 0; k < n; k++)
			{
				String train = scan.next();

				String compress = "" + train.charAt(0);
				for (int j = 1; j < train.length(); j++)
				{
					if (train.charAt(j) != train.charAt(j - 1))
						compress += train.charAt(j);
				}

				trains[k] = compress;

			}
			int answer = permute(trains);

			out.write("Case #" + i + ": " + answer + "\n");
		}

		out.close();
	}

}
