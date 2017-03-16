import java.io.*;
import java.util.*;

public class test
{

	public static void main(String[] args)
	{
		new test().run();
	}

	PrintWriter out = null;
	HashMap<Character, Character> hm = new HashMap<Character, Character>();

	void Add(String a, String b)
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a.charAt(i) == ' ')
				continue;

			hm.put(b.charAt(i), a.charAt(i));
		}
	}

	void BuildHM()
	{
		hm.put('y', 'a');
		hm.put('e', 'o');
		hm.put('q', 'z');
		hm.put('z', 'q');

		Add("our language is impossible to understand",
				"ejp mysljylc kd kxveddknmc re jsicpdrysi");
		Add("there are twenty six factorial possibilities",
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
		Add("so it is okay if you want to just give up",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv");
	}

	void run()
	{
		Scanner in = new Scanner(System.in);
		out = new PrintWriter(System.out);

		BuildHM();

		int n = Integer.parseInt(in.nextLine());
		for (int i = 0; i < n; i++)
		{
			char[] arr = in.nextLine().toCharArray();
			for (int j = 0; j < arr.length; j++)
			{
				if (arr[j] != ' ')
					arr[j] = hm.get(arr[j]);
			}

			out.printf("Case #%d: %s", i + 1, new String(arr));
			out.println();
		}

		out.close();
	}
}
