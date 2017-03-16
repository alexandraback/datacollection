import java.io.*;
import java.util.*;

public class ProblemA
{
	public static void main(String[] args) throws Exception
	{
		char def = ',';
		char[] letters = new char[26];
		for (int i=0;i<26;i++)
			letters[i]=def;
		letters[25]='q';
		letters[16]='z';
		BufferedReader reader = new BufferedReader(new FileReader("example.dat"));
		while (reader.ready())
		{
			String weird = reader.readLine().toLowerCase();
			String normal = reader.readLine().toLowerCase();
			for (int i=0;i<weird.length();i++)
			{
				char w = weird.charAt(i);
				if (w>='a' && w<='z' && letters[w-'a']==def)
					letters[w-'a']=normal.charAt(i);
			}
		}
		reader.close();
		final String base = "A-small-attempt0";
		reader = new BufferedReader(new FileReader(base+".in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter(base+".out"));
		reader.readLine();
		int place=0;
		while (reader.ready())
		{
			String in = reader.readLine().toLowerCase();
			String out = "";
			for (char c : in.toCharArray())
			{
				if (c >= 'a' && c <= 'z')
					out+=letters[c-'a'];
				else
					out+=c;
			}
			writer.write("Case #" + (++place) + ": " + out+'\n');
		}
		writer.close();
	}
}
