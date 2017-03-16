import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class problem2
{
	public static char[] vowels = new char[]
	{ 'a', 'e', 'i', 'o', 'u' };

	public int nvalue(String name, int n)
	{
		int sublength = 0;
		int nvalue = 0;
		for (int i = 0; i < name.length(); i++)
		{
			boolean vowel = false;
			char letter = name.charAt(i);
			for (int j = 0; j < 5; j++)
			{
				if (letter == vowels[j])
				{
					vowel = true;
					break;
				}
			}
			if (!vowel && i != name.length() - 1)
			{
				sublength++;
			} else
			{
				if (sublength >= n)
				{

				}

			}

		}
		return 0;
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		BufferedWriter out;
		out = new BufferedWriter(new FileWriter("consanantsout.txt"));
		File inFile = new File("A-small-attempt1.in");
		Scanner scan = new Scanner(inFile);

		int T = scan.nextInt();

		ArrayList<Character> vowelList = new ArrayList<Character>();
		vowelList.add('a');
		vowelList.add('e');
		vowelList.add('i');
		vowelList.add('o');
		vowelList.add('u');

		for (int test = 1; test <= T; test++)
		{
			String name = scan.next();
			int n = scan.nextInt();
			int nvalue = 0;
			int lastIndex = -1;
			for (int i = 0; i < name.length(); i++)
			{
				boolean consecutive = false;
				if (i + n <= name.length())
				{
					consecutive = true;
					for (int j = i; j < i + n; j++)
					{
						if (vowelList.contains(name.charAt(j)))
						{
							consecutive = false;
							break;
						}
					}
				}
				if (consecutive)
				{
					int before = i-lastIndex;
					int after = name.length()-i - n+1;
					nvalue += before*after;
					//nvalue += name.length() - lastIndex - n +1;
					lastIndex = i;
				}
			}

			System.out.println("Case #" + test + ": " + nvalue);
			out.write("Case #" + test + ": " + nvalue + "/n");
		}
		out.close();

	}

}
