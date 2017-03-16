package gcj2015.global_qr;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class D
{
	private static int debugCC = -1;
	private static int cc;
	private static void putput() throws IOException
	{
		int cases = INT();
		cc: for (cc = 1; cc<=cases; cc++)
		{
			int X = INT();
			int R = INT();
			int C = INT();
			
			if (R*C%X!=0)
			{
				// GABRIEL has no chance to fill the complete grid (too few cells on grid)
				debugln("few cells");
				println("Case #"+cc+": RICHARD");
			}
			else if (X>=7)
			{
				// GABRIEL has no chance to fill the hole
				debugln("hole");
				println("Case #"+cc+": RICHARD");
			}
			else if (
						(Math.min(R, C)<=1 && X>=3)
					||	(Math.min(R, C)<=2 && X>=5)
					||	(Math.min(R, C)<=3 && X>=7)
					||	(R<X && C<X)
			)
			{
				// GABRIEL has no chance to fit the N-omino RICHARD chose
				debugln("fit");
				println("Case #"+cc+": RICHARD");
			}
			else if (
						(Math.min(R, C)==2 && X==4)
					||	(Math.min(R, C)==3 && Math.max(R, C)==5 && X==5)
					||	(Math.min(R, C)==3 && X==6)
			)
			{
				// GABRIEL has no chance to fill the complete grid (RICHARD's N-omino will split the grid)
				debugln("split grid");
				println("Case #"+cc+": RICHARD");
			}
			else
			{
				println("Case #"+cc+": GABRIEL");
			}
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		// 21:58 - 23:43 
//		String problemFile = "test";
		
//		String problemFile = "%s-small-attempt0";
//		String problemFile = "%s-small-attempt1";
		String problemFile = "%s-large";
		
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
	private static int[] INT_ARRAY() throws IOException
	{
		String[] s = LINE().split(" ");
		int[] r = new int[s.length];
		for(int i=0; i<s.length; i++) r[i] = Integer.parseInt(s[i]);
		return r;
	}
	private static long[] LONG_ARRAY() throws IOException
	{
		String[] s = LINE().split(" ");
		long[] r = new long[s.length];
		for(int i=0; i<s.length; i++) r[i] = Long.parseLong(s[i]);
		return r;
	}
	
	// putput
	private static String DOUBLE_STRING(Double d)
	{
		NumberFormat f = NumberFormat.getInstance();
		f.setGroupingUsed(false);
//		f.setMaximumFractionDigits(7);
//		f.setMinimumFractionDigits(7);
		return f.format(d);
	}
	private static DecimalFormat _DF = new DecimalFormat("0000");
	private static String DF(int i)
	{
		return _DF.format(i);
	}
	private static DecimalFormat _DF2 = new DecimalFormat();
	private static String DF2(double i)
	{
		NumberFormat numberFormat = NumberFormat.getNumberInstance(Locale.US);
        ((DecimalFormat) numberFormat).applyPattern("#0.0000000"); 
		return numberFormat.format(i);
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
}
