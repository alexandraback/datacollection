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

public class A
{
	private static void putput() throws IOException
	{
		int cases = INT();
		for (int cc = 1; cc<=cases; cc++)
		{
			char[][] field = new char[4][4];
			for (int y = 0; y < 4; y++) {
				field[y] = STRING().toCharArray();
			}
			
			String result = "";
			
			game: {
				// check rows
				y: for (int y = 0; y < 4; y++) {
					char marker = field[y][0]; if (marker == '.') continue y;
					for (int x = 1; x < 4; x++) {
						marker = (marker == 'T' && field[y][x] != '.') ? field[y][x] : marker;
						if (field[y][x] != marker && field[y][x] != 'T') continue y;
					}
					result = marker+" won"; break game;
				}
				// check cols
				x: for (int x = 0; x < 4; x++) {
					char marker = field[0][x]; if (marker == '.') continue x;
					for (int y = 1; y < 4; y++) {
						marker = (marker == 'T' && field[y][x] != '.') ? field[y][x] : marker;
						if (field[y][x] != marker && field[y][x] != 'T') continue x;
					}
					result = marker+" won"; break game;
				}
				// tl -> br
				d1: {
					char marker = field[0][0]; if (marker == '.') break d1;
					for (int i = 1; i < 4; i++) {
						marker = (marker == 'T' && field[i][i] != '.') ? field[i][i] : marker;
						if (field[i][i] != marker && field[i][i] != 'T') break d1;
					}
					result = marker+" won"; break game;
				}
				// tr -> bl
				d2: {
					char marker = field[0][3]; if (marker == '.') break d2;
					for (int i = 1; i < 4; i++) {
						marker = (marker == 'T' && field[i][3-i] != '.') ? field[i][3-i] : marker;
						if (field[i][3-i] != marker && field[i][3-i] != 'T') break d2;
					}
					result = marker+" won"; break game;
				}
				// draw
				d: for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (field[i][j]=='.')
						{
							result = "Game has not completed"; break game;
						}
					}
				}
				result = "Draw";
			}
			
			println("Case #"+cc+": "+result);
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		// 01:00 - 
//		String problemFile = "test";
//		String problemFile = "%s-small-practice";
//		String problemFile = "%s-large-practice";
		
//		String problemFile = "%s-small";
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
		System.out.print(str);
	}
	private static void println (String str) throws IOException
	{
		print(str+"\r\n");
	}
}
