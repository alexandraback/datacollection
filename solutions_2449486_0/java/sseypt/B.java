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

public class B
{
	private static void putput() throws IOException
	{
		int cases = INT();
		for (int cc = 1; cc<=cases; cc++)
		{
			int N = INT(); // y
			int M = INT(); // x
			int[][] field = new int[N][M];
			int[] yMin = new int[N]; Arrays.fill(yMin, 0);
			int[] xMin = new int[M]; Arrays.fill(xMin, 0);
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < M; x++) {
					field[y][x] = INT();
				}
			}
			
			// check row
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < M; x++) {
					xMin[x] = Math.max(xMin[x], field[y][x]);
					yMin[y] = Math.max(yMin[y], field[y][x]);
				}
			}
			
			String result = "YES";
			
			s: {
				for (int y = 0; y < N; y++) {
					for (int x = 0; x < M; x++) {
						if (field[y][x]<yMin[y] && field[y][x]<xMin[x])
						{
							result = "NO"; break s;
						}
					}
				}
				
				
			}
			
			println("Case #"+cc+": "+result);
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		// 01:35 - 
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
