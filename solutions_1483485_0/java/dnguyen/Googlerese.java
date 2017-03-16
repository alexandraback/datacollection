import java.io.*;
import java.util.*;

class Googlerese
{
	public static void main (String [] args) throws IOException 
	{
		BufferedReader in = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt0.out")));
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int numCases = Integer.parseInt(st.nextToken());
		
		for ( int i = 0; i < numCases; i ++ )
		{
			out.print("Case #" + (i+1) + ": ");
			
			st = new StringTokenizer(in.readLine());
			
			while (st.hasMoreTokens())
			{
				out.print(translateWord(st.nextToken()) + " ");
			}

			out.println();
		}
		
		out.close();
	}
	
	public static char translateChar(char c)
	{
		switch(c)
		{
			case 'a': return 'y';
			case 'b': return 'h';
			case 'c': return 'e';
			case 'd': return 's';
			case 'e': return 'o';
			case 'f': return 'c';
			case 'g': return 'v';
			case 'h': return 'x';
			case 'i': return 'd';
			case 'j': return 'u';
			case 'k': return 'i';
			case 'l': return 'g';
			case 'm': return 'l';
			case 'n': return 'b';
			case 'o': return 'k';
			case 'p': return 'r';
			case 'q': return 'z';
			case 'r': return 't';
			case 's': return 'n';
			case 't': return 'w';
			case 'u': return 'j';
			case 'v': return 'p';
			case 'w': return 'f';
			case 'x': return 'm';
			case 'y': return 'a';
			case 'z': return 'q';
			default: return '1';
		}
	}
	
	public static String translateWord(String s)
	{
		String result = "";
		for (int i = 0; i < s.length(); i++)
		{
			result += translateChar(s.charAt(i));
		}
		
		return result;
	}
}