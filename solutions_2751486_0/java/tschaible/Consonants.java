import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.StringReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;


public class Consonants {

	
	
	private static String readFile(String file) throws IOException
	{
		InputStream is = new FileInputStream(file);
		ByteArrayOutputStream out = new ByteArrayOutputStream();
		
		byte read;
		while ( (read = (byte) is.read()) != -1 )
		{
			out.write(read);
		}
		
		is.close();
		out.close();
		
		return new String(out.toByteArray());
	}
	
	private static String[] getInput(BufferedReader reader) throws IOException
	{		
		String line = reader.readLine();		
		String [] input = line.split(" ");
		
		
		
		return input;		
	}
	
	
	
	public static void main(String [] args) throws IOException
	{
		for ( String fileName : new String[] {"consonants.sample","consonants.asmall"})
		{
			String file = readFile(fileName);
			FileWriter output = new FileWriter(fileName+".out");
			
			System.out.println(fileName + ": ");
			BufferedReader bufferedReader = new BufferedReader(new StringReader(file));
			int count = Integer.parseInt(bufferedReader.readLine());
			
			for ( int i = 0; i < count; i++)
			{
				long start = System.currentTimeMillis();
				String [] input = getInput(bufferedReader);
				
				String name = input[0];
				long n = Long.parseLong(input[1]);
				
				
				
				long result = solve(name, n);
				System.out.println("Case #"+(i+1)+ ": " + result + "[" + (System.currentTimeMillis() - start) + " ms]");
				output.write("Case #"+(i+1)+ ": " + result +"\n");
			}
			
			output.close();
			System.out.println("");
			
		}
	}
	
	private static final List<Character> VOWELS = Arrays.asList(new Character[] {'a','e','i','o','u'});
	
	
	public static long solve(String name, long n)
	{
		Set<String> substrings = new HashSet<String>();
		for ( long i = 0; i < name.length(); i++ )
		{
			if ( isN(name,i,n) )
			{
				for (long j = i; j >= 0; j-- )
				{
					for ( long k = i+n; k <= name.length(); k++ )
					{
						substrings.add(j+"-"+k);
					}
				}
			}
		}
		return substrings.size();
	}
	
	public static boolean isN(String name, long pos, long n)
	{
		if ( name.length() - pos < n )
		{
			return false;
		}
		for ( long i = pos; i < pos+n; i++ )
		{
			if ( VOWELS.contains(name.charAt((int)i)) )
			{
				return false;
			}
		}
		return true;
	}
	
	
	
	
}
