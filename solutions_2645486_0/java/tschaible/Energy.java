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


public class Energy {

	
	
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
		
		long [] output = new long[]{Long.parseLong(input[0]),Long.parseLong(input[1]),Long.parseLong(input[2])};
		
		return output;		
	}
	
	private static long[] getInputValues(BufferedReader reader, long N) throws IOException
	{		
		String line = reader.readLine();		
		String [] input = line.split(" ");
		
		long [] output = new long[(int)N];
		for (int i = 0; i < N; i++)
		{
			output[i] = Long.parseLong(input[i]);
		}
		
		return output;		
	}
	
	public static void main(String [] args) throws IOException
	{
		for ( String fileName : new String[] {"energy.sample","energy.small"})
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
				
				long E = input[0];
				long R = input[1];
				long N = input[2];
				long [] values = getInputValues(bufferedReader,N);
				
				
				long result = solve(E,R,values);
				System.out.println("Case #"+(i+1)+ ": " + result + "[" + (System.currentTimeMillis() - start) + " ms]");
				output.write("Case #"+(i+1)+ ": " + result +"\n");
			}
			
			output.close();
			System.out.println("");
			
		}
	}
	
	public static long solve(long E, long R, long [] values)
	{
		
		long minimumSpend = R;
		
		
		long [] spend = new long[values.length];
		
		for ( int i = 0; i < spend.length; i++)
		{
			spend[i] = minimumSpend;
		}
		
		
		
		int pick = -1;
		while ( (pick = greedyPick(E,R,spend,getRemainingEnergy(E,R,spend),values)) != -1 )
		{
			spend[pick]++;
		}
		
		System.out.println("Spend: " + Arrays.toString(spend));
		System.out.println("Energy: " + Arrays.toString(getRemainingEnergy(E,R,spend)));
		
		long gain = 0;
		for ( int i = 0;i < spend.length; i++ )
		{
			gain += spend[i]*values[i];
		}
		
		return gain;
		
	}
	
	public static int greedyPick(long E, long R, long [] spend, long [] energy, long [] values)
	{
		int pick = -1;
		long maxValue = 0; 
		for ( int i = 0; i < spend.length; i++ )
		{
			if ( canPick(E,R,spend,i)  && values[i] > maxValue )
			{
				pick = i;
				maxValue = values[i];
			}
		}
		
		return pick;
	}
	
	public static boolean canPick(long E, long R, long [] spend,  int pick )
	{
		long [] newSpend = Arrays.copyOf(spend, spend.length);
		newSpend[pick]++;
		long [] energy = getRemainingEnergy(E,R,newSpend);
		for ( int i = 0; i < newSpend.length; i++)
		{
			if ( energy[i]<0 )
			{
				return false;
			}
		}
		return true;
		
	}
	

	public static long [] getRemainingEnergy(long E, long R, long [] spend)
	{
		long [] energy = new long[spend.length];
		energy[0] = E - spend[0];
		for ( int i = 1; i < spend.length; i++ )
		{
			energy[i] = (((energy[i-1]+R) > E) ? E : (energy[i-1]+R)) - spend[i];
		}
		return energy;
	}
	
}
