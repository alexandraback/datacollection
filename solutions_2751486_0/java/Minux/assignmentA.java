import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class assignmentA
{
	//private static String filename = "test";
	private static String filename = "A-small-attempt0";

	private static boolean debug = false;

	private static int caseindex = 1;

	public static void main(String[] args) throws Exception
	{
		if (debug)
			System.out.println("Start out buffer");

		BufferedWriter out = new BufferedWriter(new FileWriter(filename + ".out"));
		BufferedReader in = new BufferedReader(new FileReader(filename + ".in"));

		performAtStart();

		readFile(in, out);

		out.close();
		in.close();
	}

	public static void writeToFile(BufferedWriter out, String s)
	{
		try
		{
			if (debug == true)
			{
				String write = "Case #" + caseindex + ": " + s;
				System.out.println("write: " + write);
				out.write(write);
			}
			else
				out.write("Case #" + caseindex + ": " + s);
			out.newLine();
			caseindex++;
		}
		catch (Exception e)
		{
		}
	}

	public static void readFile(BufferedReader in, BufferedWriter out)
	{
		try
		{
			String str;
			//skip first
			in.readLine();
			while ((str = in.readLine()) != null)
			{
				if (debug == true)
					System.out.println("read: " + str);
				writeToFile(out, performAction(str.split(" ")));
			}
		}
		catch (IOException e)
		{
		}
	}

	public static void performAtStart()
	{

	}

	public static String performAction(String[] parm)
	{
		String name = parm[0];
		int n = Integer.parseInt(parm[1]);
		int found = 0;
		for (int i = 0; i < name.length(); i++)
		{
			for (int j = i + 1; j <= name.length(); j++)
			{
				if (match(name.substring(i, j), n) == true)
				{
					found++;
				}
			}
		}

		return "" + found;
	}

	public static boolean match(String sub, int n)
	{
		char[] skip =
		{ 'a', 'e', 'u', 'i', 'o' };
		char[] letters = sub.toCharArray();
		int c = 0;
		boolean b = false;
		for (int i = 0; i < letters.length; i++)
		{
			if (c >= n)
				return true;
			b = false;
			for (int j = 0; j < skip.length; j++)
				if (skip[j] == letters[i])
				{
					b = true;
					break;
				}
			if (b == false)
				c++;
			else
				c = 0;
		}
		return c >= n;
	}
}
