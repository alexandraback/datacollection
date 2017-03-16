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


public class Pogo {

	
	
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
		for ( String fileName : new String[] {"pogo.sample","pogo.bsmall"})
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
				
				long x = input[0];
				long y = input[1];
				
				
				
				String result = solveBy1(x,y);
				System.out.println("Case #"+(i+1)+ ": " + result + "[" + result.length() + "][" + (System.currentTimeMillis() - start) + " ms]");
				output.write("Case #"+(i+1)+ ": " + result +"\n");
			}
			
			output.close();
			System.out.println("");
			
		}
	}
	
	
	
	
	public static String solve(long goalX, long goalY)
	{
		StringBuffer result = new StringBuffer();
		
		int moveLength = 1;
		int x = 0, y= 0;
		
		while ( x != goalX || y != goalY)
		{
			
			
			//go for the next jump = goal first
			if ( Math.abs(x-goalX) == moveLength ) 
			{
				result.append(x<goalX?"E":"W");
				x+= x<goalX?moveLength:-moveLength;
				moveLength++;
				continue;
			}
			
			if ( Math.abs(y-goalY) == moveLength ) 
			{
				result.append(y<goalY?"N":"S");
				y+= y<goalY?moveLength:-moveLength;
				moveLength++;
				continue;
			}
			
			if ( x != goalX )
			{
				result.append(x<goalX?"E":"W");
				x+= x<goalX?moveLength:-moveLength;
				moveLength++;
				continue;
			}
			
			if ( y != goalY )
			{
				result.append(y<goalY?"N":"S");
				y+= y<goalY?moveLength:-moveLength;
				moveLength++;
				continue;
			}
		}
		
		return result.toString();
	}
	
	public static String solveBy1(long goalX, long goalY)
	{
		StringBuffer result = new StringBuffer();
		
		int moveLength = 1;
		int x = 0, y= 0;
		
		while ( x != goalX )
		{
			if ( x < goalX )
			{
				result.append("WE");
				x++;
				moveLength++;
				moveLength++;
			}
			else 
			{
				result.append("EW");
				x--;
				moveLength++;
				moveLength++;
			}
			
			//go for the next jump = goal first
			if ( Math.abs(x-goalX) == moveLength ) 
			{
				result.append(x<goalX?"E":"W");
				x+= x<goalX?moveLength:-moveLength;
				moveLength++;
				continue;
			}			
		}
		
		while ( y != goalY )
		{
			if ( y < goalY )
			{
				result.append("SN");
				y++;
				moveLength++;
				moveLength++;
			}
			else 
			{
				result.append("NS");
				y--;
				moveLength++;
				moveLength++;
			}
			
			//go for the next jump = goal first
			if ( Math.abs(x-goalX) == moveLength ) 
			{
				result.append(x<goalX?"E":"W");
				x+= x<goalX?moveLength:-moveLength;
				moveLength++;
				continue;
			}			
		}
		
		return result.toString();
	}
	
	
	
	
}
