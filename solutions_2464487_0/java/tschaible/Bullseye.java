import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.StringReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;


public class Bullseye {

	
	
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
	
	private static long[] getInput(BufferedReader reader) throws IOException
	{		
		String line = reader.readLine();		
		String [] input = line.split(" ");
		
		long [] output = new long[]{Long.parseLong(input[0]),Long.parseLong(input[1])};
		
		return output;		
	}
	
	public static void main(String [] args) throws IOException
	{
		for ( String fileName : new String[] {"bullseye.sample","bullseye.asmall"})
		{
			String file = readFile(fileName);
			FileWriter output = new FileWriter(fileName+".out");
			
			System.out.println(fileName + ": ");
			BufferedReader bufferedReader = new BufferedReader(new StringReader(file));
			int count = Integer.parseInt(bufferedReader.readLine());
			
			for ( int i = 0; i < count; i++)
			{
				long start = System.currentTimeMillis();
				long [] input = getInput(bufferedReader);
				
				long r = input[0];
				long t = input[1];
				
				long result = solve(r,t);
				System.out.println("Case #"+(i+1)+ ": " + result + "[" + (System.currentTimeMillis() - start) + " ms]");
				output.write("Case #"+(i+1)+ ": " + result +"\n");
			}
			
			output.close();
			System.out.println("");
			
		}
	}
	
	public static long solve(long r, long t)
	{
		long total = t;
		long count = 0;
		long radius = r;
		
		
		long nextRingPaint = (2*radius)+1;
		while ( total - nextRingPaint >= 0 )
		{			
			count++;
			total -= nextRingPaint;			
			radius+=2;
			
			nextRingPaint = (2*radius)+1;
		}
		return count;
	}
	

	
	
	
}
