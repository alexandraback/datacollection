import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class B 
{
	String _num1;
	String _num2;
	
	String _res1;
	String _res2;

	private B()
	{
	}

	private void readProblem(FileRWB iFrw) throws IOException
	{
		String str = iFrw.readLine();
		String[] data = str.split(" ");
		_num1 = data[0];
		_num2 = data[1];
	}
	
	private void writeSolution(FileRWB iFrw) throws IOException
	{
		iFrw.write(_res1+" "+_res2);
	}
	
	private void solve()
	{
		_num1 = _num1.replace('?', '#');
		_num2 = _num2.replace('?', '#');
		
		for(int i=0;i<_num1.length();i++)
		{
			String s1 = _num1.substring(i, i+1);
			String s2 = _num2.substring(i, i+1);
			
			if( s1.equals("#") && !s2.equals("#"))
				_num1 = _num1.replaceFirst("#", s2);
			
			if( s2.equals("#") && !s1.equals("#"))
				_num2 = _num2.replaceFirst("#", s1);
			
			if( s2.equals("#") && s1.equals("#"))
			{
				_num1 = _num1.replaceFirst("#", "0");
				_num2 = _num2.replaceFirst("#", "0");
			}
		}
		
		_res1 = _num1;
		_res2 = _num2;
		
		/*ArrayList<String> ip1 = new ArrayList<String>();
		ip1.add(_num1);
		while(_num1.contains("#"))
		{
			ArrayList<String> res = getNums(ip1);
			ip1 = res;
			_num1 = _num1.replaceFirst("#", "");
		}
		
	    

		ArrayList<String> ip2 = new ArrayList<String>();
		ip2.add(_num2);
		while(_num2.contains("#"))
		{
			ArrayList<String> res = getNums(ip2);
			ip2 = res;
			_num2 = _num2.replaceFirst("#", "");
		}

		ArrayList<Score> scores = new ArrayList<Score>();
		for(int i=0;i<ip1.size();i++)
		{
			for(int j=0;j<ip2.size();j++)
			{
				Score score = new Score(Long.parseLong(ip1.get(i)), ip1.get(i), Long.parseLong(ip2.get(j)), ip2.get(j) );
				scores.add(score);
			}
		}
		
		Collections.sort(scores);
		_res1 = scores.get(0)._Cstr;
		_res2 = scores.get(0)._JStr;*/
	}
	
	private ArrayList<String> getNums(ArrayList<String> iStr)
	{
		ArrayList<String> oRes = new ArrayList<String>();
		
		for(int i=0;i<iStr.size();i++)
		{
			String str = iStr.get(i);
		
			for(int j=0;j<10;j++)
			{
				String str1 = str.replaceFirst("#", j+"");
				oRes.add(str1);
			}
		}

		return oRes;
	}
	public static void main(String[] args) 
	{
		try
		{
			FileRWB frw = new FileRWB(args[0], args[1]);
			
			int numTestCases = frw.readInt();
			
			for(int ind=1;ind<=numTestCases; ind++) 
			{
				
				frw.write("Case #"+ind+": ");
				
				B b = new B();
				b.readProblem(frw);
				b.solve();
				b.writeSolution(frw);
				
				frw.write("\n");
			}
			
			frw.close();
		}
		catch(IOException ioExc) { ioExc.printStackTrace();	}
	}
}

class Score implements Comparable<Score>
{
	long _cScore;
	String _Cstr;
	long _jScore;
	String _JStr;
	
	public Score(long iC, String iCStr, long iJ, String iJStr)
	{
		_cScore = iC;
		_jScore = iJ;
		_Cstr = iCStr;
		_JStr = iJStr;
	}
	
	public int compareTo(Score iScore)
	{
		long diff1 = Math.abs(_cScore - _jScore);
		long diff2 = Math.abs(iScore._cScore - iScore._jScore);
		
		if(diff1 < diff2)
			return -1;
		
		if(diff1 > diff2)
			return 1;
		
		if(diff1 == diff2)
		{
			if(this._cScore < iScore._cScore)
				return -1;
			
			if(this._cScore > iScore._cScore)
				return 1;
		}
		
		if( (diff1 == diff2) && (this._cScore == iScore._cScore))
		{
			if(this._jScore < iScore._jScore)
				return -1;
			
			if(this._jScore > iScore._jScore)
				return 1;
		}
		
		return 0;
	}
}

class FileRWB
{
	String ipFile;
	String opFile;

	FileReader fr; 
	BufferedReader br; 
	
	FileWriter fw; 
	BufferedWriter bw;
	
	public FileRWB(final String iInputFile, final String iOutputFile) throws IOException
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
