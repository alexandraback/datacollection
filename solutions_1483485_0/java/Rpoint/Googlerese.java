import java.io.*;
import java.util.*;

public class Googlerese
{
	public static void main(String[] args)
	{
		Map<Character, Character> table = new TreeMap<Character, Character>();
		String[] original={
				"a zoo",
				"our language is impossible to understand",
				"there are twenty six factorial possibilities",
				"so it is okay if you want to just give up"
		};
		String[] translated={
				"y qee",
				"ejp mysljylc kd kxveddknmc re jsicpdrysi",
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv"				
		};

		boolean[] mapped = new boolean[26];
		boolean[] mappedTo = new boolean[26];
		for(int i=0; i<original.length; ++i)
		{
			String o = original[i];
			String t = translated[i];
			for(int j=0; j<o.length(); ++j)
			{
				table.put(o.charAt(j), t.charAt(j));
				if(o.charAt(j) != ' ')
				{
					mapped[o.charAt(j) - 'a'] = true;
					mappedTo[t.charAt(j) - 'a'] = true;
				}
			}
		}

		int unMapped=0;
		int unMappedTo=0;
		for(int i=0; i<26; ++i) if(!mapped[i]) unMapped=i;
		for(int i=0; i<26; ++i) if(!mappedTo[i]) unMappedTo=i;
		table.put((char) ('a'+unMapped), (char)('a'+unMappedTo));
		
		Map<Character, Character> reverseTable = new TreeMap<Character, Character>();
		for(Map.Entry<Character, Character> e : table.entrySet())
		{
			reverseTable.put(e.getValue(), e.getKey());
		}
		
		try
		{
			BufferedReader in = new BufferedReader(new FileReader("A-small-attempt3.in"));
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
			Integer numCases = Integer.parseInt(in.readLine());
			String[] inputs = new String[30];
			for(int i=0; i<numCases; ++i)
			{
				inputs[i] = in.readLine();
			}
			
			for(int i=0; i<numCases; ++i)
			{
				out.write("Case #"+(i+1)+": ");
				for(int j=0; j<inputs[i].length(); ++j)
					out.write(reverseTable.get(inputs[i].charAt(j)));
				if(i != numCases-1)
					out.write('\n');
			}
			in.close();
			out.close();
		} catch (NumberFormatException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
