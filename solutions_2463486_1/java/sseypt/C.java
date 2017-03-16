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
import java.math.*;

public class C
{
	static Map<String,String> sqrts = new HashMap<String, String>();
	static Map<String,Boolean> palindromes = new HashMap<String, Boolean>();

	static int preSize = 7;
	static boolean debug = false;
	static boolean debug_pre = true;
	
	static void pre()
	{
		for (long l = 1; l <= Math.pow(10, preSize); l++) {
			String ls = String.valueOf(l);
			if (palindrome(ls))
			{
				BigInteger i = BigInteger.valueOf(l);
				i = i.pow(2);
				String s = i.toString();
				
				if (palindrome(s))
				{
					sqrts.put(s, ls);
					if (debug_pre) System.out.println("pre: "+s+" "+ls+" ("+s.length()+")");
				}
			}
		}
	}
	
	static boolean palindrome (String s)
	{
		if (!palindromes.containsKey(s))
		{
			boolean b = s.equals(new StringBuilder(s).reverse().toString());
			if (b)
				palindromes.put(s, b);
			return b;
		}
		return palindromes.get(s);
	}
	
	private static void putput() throws IOException
	{
		pre();
		
		int cases = INT();
		
		for (int cc = 1; cc<=cases; cc++)
		{
			long A = LONG();
			long B = LONG();
			long count = 0;
			for (String square : sqrts.keySet()) {
				long l = Long.valueOf(square);
				if (A<=l && l<=B)
				{
					String sqrt = sqrts.get(square);
					if (debug) System.out.println(square+" "+sqrt);
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
		
//		String problemFile = "%s-small-attempt0";
		String problemFile = "%s-large-1";
		
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

class BigSquareRoot {

	private static BigDecimal ZERO = new BigDecimal("0");
	private static BigDecimal ONE = new BigDecimal("1");
	private static BigDecimal TWO = new BigDecimal("2");
	public static final int DEFAULT_MAX_ITERATIONS = 25;
	public static final int DEFAULT_SCALE = 6;

	private BigDecimal error;
	private int iterations;
	private int scale = DEFAULT_SCALE;
	private int maxIterations = DEFAULT_MAX_ITERATIONS;

	public BigDecimal getError() {
		return error;
	}

	public int getIterations() {
		return iterations;
	}

	public int getScale() {
		return scale;
	}

	public void setScale(int scale) {
		this.scale = scale;
	}

	public int getMaxIterations() {
		return maxIterations;
	}

	public void setMaxIterations(int maxIterations) {
		this.maxIterations = maxIterations;
	}

	private static BigDecimal getInitialApproximation(BigDecimal n) {
		BigInteger integerPart = n.toBigInteger();
		int length = integerPart.toString().length();
		if ((length % 2) == 0) {
			length--;
		}
		length /= 2;
		BigDecimal guess = ONE.movePointRight(length);
		return guess;
	}

	public BigDecimal get(BigInteger n) {
		return get(new BigDecimal(n));
	}

	public BigDecimal get(BigDecimal n) {
		if (n.compareTo(ZERO) <= 0) {
			throw new IllegalArgumentException();
		}

		BigDecimal initialGuess = getInitialApproximation(n);
		BigDecimal lastGuess = ZERO;
		BigDecimal guess = new BigDecimal(initialGuess.toString());

		iterations = 0;
		boolean more = true;
		while (more) {
			lastGuess = guess;
			guess = n.divide(guess, scale, BigDecimal.ROUND_HALF_UP);
			guess = guess.add(lastGuess);
			guess = guess.divide(TWO, scale, BigDecimal.ROUND_HALF_UP);
			error = n.subtract(guess.multiply(guess));
			if (++iterations >= maxIterations) {
				more = false;
			} else if (lastGuess.equals(guess)) {
				more = error.abs().compareTo(ONE) >= 0;
			}
		}
		return guess;

	}
}