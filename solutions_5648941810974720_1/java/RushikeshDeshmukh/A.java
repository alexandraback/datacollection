import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class A 
{

	String _ip;
	ArrayList<Integer> _nums;

	private A()
	{
		_nums = new ArrayList<Integer>(); 
	}

	private void readProblem(FileRWA iFrw) throws IOException
	{
		_ip = iFrw.readLine();
	}
	
	private void writeSolution(FileRWA iFrw) throws IOException
	{
		Collections.sort(_nums);
		String res = "";
		for(int i=0;i<_nums.size();i++)
			res+= _nums.get(i)+"";
		
		iFrw.write(res);
	}
	
	private void solve()
	{
		String[] l1 = {"Z", "W", "U", "X", "G"};
		String[] str1 = {"ZERO", "TWO", "FOUR", "SIX", "EIGHT"};
		int[] n1 = {0, 2, 4, 6, 8};
		for(int i=0;i<5;i++)
		{
			while(_ip.contains(l1[i]))
			{
				_nums.add(n1[i]);
				for(int j=0;j<str1[i].length();j++)
					_ip = _ip.replaceFirst(str1[i].substring(j, j+1), "");
			}
		}
		
		String[] l2 = {"R", "S", "F", "O"};
		String[] str2 = {"THREE", "SEVEN", "FIVE", "ONE"};
		int[] n2 = {3, 7, 5, 1};
		for(int i=0;i<4;i++)
		{
			while(_ip.contains(l2[i]))
			{
				_nums.add(n2[i]);
				for(int j=0;j<str2[i].length();j++)
					_ip = _ip.replaceFirst(str2[i].substring(j, j+1), "");
			}
		}
		
		String[] l3 = {"N"};
		String[] str3 = {"NINE"};
		int[] n3 = {9};
		for(int i=0;i<1;i++)
		{
			while(_ip.contains(l3[i]))
			{
				_nums.add(n3[i]);
				for(int j=0;j<str3[i].length();j++)
					_ip = _ip.replaceFirst(str3[i].substring(j, j+1), "");
			}
		}
	}
	
	public static void main(String[] args) 
	{
		try
		{
			FileRWA frw = new FileRWA(args[0], args[1]);
			
			int numTestCases = frw.readInt();
			
			for(int ind=1;ind<=numTestCases; ind++) 
			{
				
				frw.write("Case #"+ind+": ");
				
				A a = new A();
				a.readProblem(frw);
				a.solve();
				a.writeSolution(frw);
				
				frw.write("\n");
			}
			
			frw.close();
		}
		catch(IOException ioExc) { ioExc.printStackTrace();	}
	}
}

class FileRWA
{
	String ipFile;
	String opFile;

	FileReader fr; 
	BufferedReader br; 
	
	FileWriter fw; 
	BufferedWriter bw;
	
	public FileRWA(final String iInputFile, final String iOutputFile) throws IOException
	{

		this.ipFile = iInputFile;
		this.opFile = iOutputFile;

		this.fr = new FileReader(ipFile);
		this.br = new BufferedReader(fr);
		
		this.fw = new FileWriter(opFile);
		this.bw = new BufferedWriter(fw);
	}
	
	public String readLine() throws IOException
	{
		
		String line = null;
		line = br.readLine();
		
		return line;
	}
	
	public short readShort() throws IOException
	{
		
		String line = readLine();
		short value = Short.parseShort(line);
		
		return value;
	}

	public int readInt() throws IOException
	{
		
		String line = readLine();
		int value = Integer.parseInt(line);
		
		return value;
	}
	
	public long readLong() throws IOException
	{
		
		String line = readLine();
		long value = Long.parseLong(line);
		
		return value;
	}

	public float readFloat() throws IOException
	{
		
		String line = readLine();
		float value = Float.parseFloat(line);
		
		return value;
	}

	public double readDouble() throws IOException
	{
		
		String line = readLine();
		double value = Double.parseDouble(line);
		
		return value;
	}

	public int[] readIntArray(final int iBegInd, final String iDelimeter) throws IOException
	{
		
		String line = readLine();
		return getIntArray(line, iBegInd, iDelimeter);
	}
	
	public int[] getIntArray(final String iStr, final int iBegInd, final String iDelimiter) 
	{
		
		String[] values = iStr.split(iDelimiter);
		int[] oIntArray = new int[values.length-iBegInd];
		
		for(int ind=iBegInd; ind<values.length; ind++) 
		{

			int intValue = Integer.parseInt(values[ind]);
			oIntArray[ind-iBegInd] = intValue;
		}
		
		return oIntArray;
	}

	public short[] readShortArray(final short iBegInd, final String iDelimeter) throws IOException
	{
		
		String line = readLine();
		return getShortArray(line, iBegInd, iDelimeter);
	}
	
	public short[] getShortArray(final String iStr, final short iBegInd, final String iDelimiter) 
	{
		
		String[] values = iStr.split(iDelimiter);
		short[] oShortArray = new short[values.length-iBegInd];
		
		for(short ind=iBegInd; ind<values.length; ind++) 
		{

			short shortValue = Short.parseShort(values[ind]);
			oShortArray[ind-iBegInd] = shortValue;
		}
		
		return oShortArray;
	}
	
	public long[] readLongArray(final int iBegInd, final String iDelimeter) throws IOException
	{
		
		String line = readLine();
		return getLongArray(line, iBegInd, iDelimeter);
	}
	
	public long[] getLongArray(final String iStr, final int iBegInd, final String iDelimiter) 
	{
		
		String[] values = iStr.split(iDelimiter);
		long[] oLongArray = new long[values.length-iBegInd];
		
		for(int ind=iBegInd; ind<values.length; ind++) 
		{

			long longValue = Long.parseLong(values[ind]);
			oLongArray[ind-iBegInd] = longValue;
		}
		
		return oLongArray;
	}
	
	public float[] readFloatArray(final int iBegInd, final String iDelimiter) throws IOException 
	{
		
		String line = readLine();
		return getFloatArray(line, iBegInd, iDelimiter);
	}

	public float[] getFloatArray(final String iStr, final int iBegInd, final String iDelimiter) 
	{

		String[] values = iStr.split(iDelimiter);
		float[] oFloatArray = new float[values.length-iBegInd];
		
		for(int ind=iBegInd; ind<values.length; ind++) 
		{

			float floatValue = Float.parseFloat(values[ind]);
			oFloatArray[ind-iBegInd] = floatValue;
		}
		
		return oFloatArray;
	}
	
	public double[] readDoubleArray(final int iBegInd, final String iDelimiter) throws IOException
	{
		
		String line = readLine();
		return getDoubleArray(line, iBegInd, iDelimiter);
	}
	
	public double[] getDoubleArray(final String iStr, final int iBegInd, final String iDelimiter) 
	{
		
		String[] values = iStr.split(iDelimiter);
		double[] oDoubleArray = new double[values.length-iBegInd];
		
		for(int ind=iBegInd; ind<values.length; ind++) 
		{

			double doubleValue = Double.parseDouble(values[ind]);
			oDoubleArray[ind-iBegInd] = doubleValue;
		}
		
		return oDoubleArray;
	}

	public void write(String iString) throws IOException
	{
		bw.write(iString);
	}

	public void close() 
	{
		try 
		{
			br.close();
			fr.close();
			bw.close();
			fw.close();
		}
		catch(IOException exc)
		{
			System.out.println("Error in closing files : "+ipFile+" & "+opFile);
			exc.printStackTrace();
		}
	}
}
