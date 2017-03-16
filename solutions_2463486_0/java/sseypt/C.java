package gcj2013.global_qr;

import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.BufferedWriter;

import java.io.IOException;
import java.util.StringTokenizer;

import java.text.NumberFormat;
import java.text.DecimalFormat;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

import java.util.*;

public class C
{
	static Map<String,Long> sqrts = new HashMap<String, Long>();
	static Map<String,Boolean> isSqrts = new HashMap<String, Boolean>();
	static Map<String,Boolean> palindromes = new HashMap<String, Boolean>();

	static boolean palindrome (String s)
	{
		if (!palindromes.containsKey(s))
			palindromes.put(s, s.equals(new StringBuilder(s).reverse().toString()));
		return palindromes.get(s);
	}
	static boolean palindrome (long l)
	{
		return palindrome(String.valueOf(l));
	}
	static long sqrt (String s, long l)
	{
		if (!sqrts.containsKey(s))
			sqrts.put(s, (long)Math.sqrt(l));
		return sqrts.get(s);
	}
	static boolean isSqrt (String s, long l)
	{
		if (!isSqrts.containsKey(s))
			isSqrts.put(s, (long)Math.pow(sqrt(s,l), 2)==l);
		return isSqrts.get(s);
	}
	
	private static void putput() throws IOException
	{
		int cases = INT();
		
		for (int cc = 1; cc<=cases; cc++)
		{
			long A = INT();
			long B = INT();
			long count = 0;
			for (long l = A; l <= B; l++) {
				String s = String.valueOf(l);
				if (palindrome(s) && isSqrt(s,l) && palindrome(sqrt(s,l)))
				{
					count++;
				}
			}
			println("Case #"+cc+": "+count);
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		// 02:05 - 
//		String problemFile = "test";
		
		String problemFile = "%s-small-attempt0";
//		String problemFile = "%s-large";
		
		try
		{
			String problem = new Object(){}.getClass().getEnclosingClass().getSimpleName();
			String folder = "_"+new Object(){}.getClass().getPackage().getName();
			
			init(folder+"/"+String.format(problemFile, problem));
			putput(); 
			done();
		}
		catch (Throwable e)
		{
			e.printStackTrace();
			System.exit(1);
		}
	}

	private static File input;
	private static FileReader inputReader;
	private static BufferedReader in;
	private static File output;
	private static FileWriter outputWriter;
	private static BufferedWriter out;
	private static StringTokenizer st;

	private static void init (String fileName) throws IOException
	{
		// input
		input = new File(fileName+".in");
		inputReader = new FileReader(input);
		in = new BufferedReader(inputReader);
		
		// output
		output = new File(fileName+".out");
		outputWriter = new FileWriter(output);
		out = new BufferedWriter(outputWriter);
	}
	
	private static void done ()
	{
		try	{in.close();} catch (Exception e){}
		try	{inputReader.close();} catch (Exception e){}
		try	{out.close();} catch (Exception e){}
		try	{outputWriter.close();} catch (Exception e){}
	}
	
	// in
	private static String LINE() throws IOException
	{
		return in.readLine();
	}
	private static String TOKEN() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
		{
			st = new StringTokenizer(LINE());
		}
		return st.nextToken();
	}
	private static int INT() throws IOException
	{
		return parseInt(TOKEN());
	}
	private static long LONG() throws IOException
	{
		return parseLong(TOKEN());
	}
	private static double DOUBLE() throws IOException
	{
		return parseDouble(TOKEN());
	}
	private static String STRING() throws IOException
	{
		return TOKEN();
	}
	
	// putput
	private static String DOUBLE_STRING(Double d)
	{
		NumberFormat f = NumberFormat.getInstance();
		f.setGroupingUsed(false);
		return f.format(d);
	}
	private static DecimalFormat _DF = new DecimalFormat("0000");
	private static String DF(int i)
	{
		return _DF.format(i);
	}
	
	// out
	private static void print (String str) throws IOException
	{
		out.write(str);
		System.out.print(str);
	}
	private static void println (String str) throws IOException
	{
		print(str+"\r\n");
	}
}
