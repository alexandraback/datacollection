package gcj2013.round1c;

import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.BufferedWriter;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

import java.text.NumberFormat;
import java.text.DecimalFormat;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

import java.util.*;

public class A
{
	static boolean consecutiveStringCheck(String name, int N) throws IOException
	{
		int count = 0;
		for (int i = 0; i < name.length(); i++) {
			if (name.charAt(i)!='a'
					&& name.charAt(i)!='e'
					&& name.charAt(i)!='i'
					&& name.charAt(i)!='o'
					&& name.charAt(i)!='u')
				count++;
			else
				count = 0;
			
			if (count>=N) break;
		}
		
		return (count>=N);
	}
	
	private static int cc;
	private static void putput() throws IOException
	{
		int cases = INT();
		cc: for (cc = 1; cc<=cases; cc++)
		{
			String name = STRING();
			int N = INT();
			int count = 0;
			
			debug(name);
			debugln(" "+N);

			if (name.length()==1)
			{
				if (consecutiveStringCheck(name,N))
				{
					count++;
				}
			}
			else
			{
				for (int i = 0; i < name.length(); i++) {
					for (int j = i+1; j <= name.length(); j++) {
						if (consecutiveStringCheck(name.substring(i,j),N))
						{
							count++;
							debug ("true ("+i+","+j+"): ");
						}
						debugln(name.substring(i,j));
					}
				}
			}
			
			println("Case #"+cc+": "+count);
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		// 11:00 - / 12:48 -
//		String problemFile = "test";
		
//		String problemFile = "%s-small-attempt0";
//		String problemFile = "%s-small-attempt1";
		String problemFile = "%s-small-attempt2";
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
		debug(str,true);
	}
	private static void println (String str) throws IOException
	{
		print(str+"\r\n");
	}
	private static void debug (String str, boolean force) throws IOException
	{
		if (debugCC==0 || cc==debugCC || force)
			System.out.print(str);
	}
	private static void debug (String str) throws IOException
	{
		if (debugCC==0 || cc==debugCC)
			System.out.print(str);
	}
	private static void debugln (String str) throws IOException
	{
		debug(str+"\r\n");
	}
	private static int debugCC = -1;
}
