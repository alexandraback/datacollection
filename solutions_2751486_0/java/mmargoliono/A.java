import java.util.*;
import java.io.*;

public class A
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		
		for (int ii = 1; ii<=n; ii++)
		{
			String[] line = reader.readLine().split(" ");
			String name = line[0];

			HashSet<Character> vowel = new HashSet<Character>();
			vowel.add('a');
			vowel.add('i');
			vowel.add('u');
			vowel.add('e');
			vowel.add('o');
			
			
			int min = Integer.parseInt(line[1]);
			int previousStart = 0;
			int currentStart = 0;
			int current = 0;
			int total = 0;
			int each = 0;
			
			ArrayList<Integer> start = new ArrayList<Integer>();
			start.add(-1);
			
			for(int i = 0; i<name.length(); i++)
			{
				Character currentChar = name.charAt(i);
				if(vowel.contains(currentChar))
				{
					current = 0;
				}
				else
				{
					current++;
					if(current >= min)
					{
						start.add(i - min + 1);
						int size = start.size();
						
						int addition = start.get(size - 1) - start.get(size - 2);
						each += addition;
					}
				}
				
				total += each;
			}
			
			System.out.println("Case #" + ii + ": " + total);
		}
	}
}