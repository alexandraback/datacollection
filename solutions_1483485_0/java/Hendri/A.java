import java.util.*;
import java.io.*;

class A
{
	BufferedReader input;
	StringTokenizer token;
	BufferedWriter out;

	void solve() throws IOException
	{
		input = new BufferedReader(new FileReader("2of12inf.txt"));
		input = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(input.readLine());
		Hashtable<Character,Character> table = new Hashtable<Character,Character>();
		table.put('a','y');
		table.put('b','h');
		table.put('c','e');
		table.put('d','s');
		table.put('e','o');
		table.put('f','c');
		table.put('g','v');
		table.put('h','x');
		table.put('i','d');
		table.put('j','u');
		table.put('k','i');
		table.put('l','g');
		table.put('m','l');
		table.put('n','b');
		table.put('o','k');
		table.put('p','r');
		table.put('q','z');
		table.put('r','t');
		table.put('s','n');
		table.put('t','w');
		table.put('u','j');
		table.put('v','p');
		table.put('w','f');
		table.put('x','m');
		table.put('y','a');
		table.put('z','q');
		for(int t = 1; t <= tc; t++)
		{
			String temp = input.readLine();
			System.out.print("Case #" + t + ": ");
			for(int i = 0; i < temp.length(); i++)
			{
				if(temp.charAt(i) == ' ')System.out.print(" ");
				else System.out.print(table.get(temp.charAt(i)));
			}
			System.out.println();
		}
	}

	int nextInt() throws IOException
	{
		if(token == null || !token.hasMoreTokens())
			token = new StringTokenizer(input.readLine());
		return Integer.parseInt(token.nextToken());
	}

	Long nextLong() throws IOException
	{
		if(token == null || !token.hasMoreTokens())
			token = new StringTokenizer(input.readLine());
		return Long.parseLong(token.nextToken());
	}

	String next() throws IOException
	{
		if(token == null || !token.hasMoreTokens())
			token = new StringTokenizer(input.readLine());
		return token.nextToken();
	}

	public static void main(String[] args) throws Exception
	{
		new A().solve();
	}
}