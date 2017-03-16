package loader;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Loader
{

	public static String[][] load(int linesPerCase, String fileName)
	{
		String[][] result = new String[1][1];
		try
		{
			BufferedReader reader = new BufferedReader(new FileReader(fileName));
			int cases = Integer.parseInt(reader.readLine());
			result = new String[cases*linesPerCase][];
			for(int i=0; i<cases*linesPerCase; i++) { result[i] = reader.readLine().split(" "); }
			reader.close();
		}
		catch (FileNotFoundException f)
		{
			System.out.println("file not found");
		}
		catch (IOException i)
		{
			System.out.println("IO stuff");
		}
		return result;
	}
	
}