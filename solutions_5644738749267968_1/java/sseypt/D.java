package gcj2014.global_qr;

import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.BufferedWriter;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.StringTokenizer;

import java.text.NumberFormat;
import java.text.DecimalFormat;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

import java.util.*;

public class D
{
	private static int debugCC = -1;
	
	private static int cc;
	private static void putput() throws IOException
	{
		int cases = INT();
		cc: for (cc = 1; cc<=cases; cc++)
		{
			int N = INT();
			double[] Na = new double[N]; for(int i=0;i<N;i++) Na[i] = DOUBLE();
			double[] Ke = new double[N]; for(int i=0;i<N;i++) Ke[i] = DOUBLE();
			java.util.Arrays.sort(Na);
			java.util.Arrays.sort(Ke);
			
			debugln(Arrays.toString(Na));
			debugln(Arrays.toString(Ke));
			
			// calc Ke War points
			int[] NaX = new int[N];
			int cKe = 0;
			int iNa = 0;
			for (int iKe=0;(iKe<N && iNa<N);iKe++)
			{
				if (Ke[iKe]<Na[iNa]) cKe++;	
				else
				{
					while (iNa<N && Ke[iKe]>Na[iNa])
					{
						NaX[iNa] = cKe;
						iNa++;
					}
					cKe++;
				}
			}
			while (iNa<N)
			{
				NaX[iNa] = cKe;
				iNa++;
			}
			debugln (Arrays.toString(NaX));
			int PKeWar = 0; for (int i = N-1;i>=0;i--) PKeWar = PKeWar + ((NaX[i]>=(N-PKeWar))?0:1);
			// ---end
			
			// special
			if (N == 1)
			{
				if (Na[0]>Ke[0])	println("Case #"+cc+": 1 1");
				else				println("Case #"+cc+": 0 0");
				continue cc;
			}
			// ---end
			
			int PNa = N;
			int round = 0;
			
			while (round<N && !agb(Na,Ke))
			{
				PNa--;
				round++;
				
				double[] arr=new double[Na.length-1];
				System.arraycopy(Na,1,arr,0,arr.length); Na = arr;
				arr=new double[Ke.length-1];
				System.arraycopy(Ke,0,arr,0,arr.length); Ke = arr;
				
				debugln(Arrays.toString(Na));
				debugln(Arrays.toString(Ke));
			}
			
			println("Case #"+cc+": "+PNa+" "+(N-PKeWar));
		}
	}
	
	public static boolean agb (double[] a, double[] b) throws IOException
	{
		for(int i=0;i<a.length;i++) if (a[i]<b[i]) return false;
		return true;
	}
	
	public static void main(String[] args) throws IOException
	{
		// 02:44 - 
//		String problemFile = "test";
//		String problemFile = "%s-small-practice";
		
//		String problemFile = "%s-small-attempt0";
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
}
