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
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.StringTokenizer;

import org.apache.commons.lang3.StringUtils;

public class C
{
	private static int debugCC = -1;
	private static int cc;

	private static boolean use_cache = true;
	
	public static Map<String,String> cacheMultiplyAll = new HashMap<String, String>(); 
	public static Map<String,Boolean> cacheJK = new HashMap<String, Boolean>(); 
	public static Map<String,Boolean> cacheIJK = new HashMap<String, Boolean>(); 
	
	private static void putput() throws IOException
	{
		int cases = INT();
		cc: for (cc = 1; cc<=cases; cc++)
		{
			int L = INT();
			int X = INT();
			String S = StringUtils.repeat(STRING(), X);

			if (L*X<3)
			{
				println("Case #"+cc+": "+"NO");
				continue;
			}
			
			debugln(S);

			QuaternionString qsI = new QuaternionString(S);
			
			List<String> subS_IJK = new ArrayList<String>();
			
			boolean first = true;
			i: while ( (first && qsI.sb.charAt(0)=='i') || qsI.next('i') )
			{
				first = false;
				debugln("I: "+qsI+"("+qsI.sb.length()+")");
				
				String tmpI = qsI.toString();
				subS_IJK.add(tmpI);
				
				// cache
				if (C.cacheIJK.containsKey(tmpI) && use_cache)
				{
					if (C.cacheIJK.get(tmpI)==true)
					{
						println("Case #"+cc+": "+"YES");
						continue cc;
					}
					else
					{
						continue i;
					}
				}
				
				// no cache
				QuaternionString qsJ = qsI.clone();
				qsJ.sb.deleteCharAt(0);
				
				List<String> subS_JK = new ArrayList<String>();
				
				first = true;
				while ( (first && qsJ.sb.length()>0 && qsJ.sb.charAt(0)=='j') || qsJ.next('j') )
				{
					first = false;
					
					String tmpJ = qsJ.toString();
					subS_JK.add(tmpJ);
					
					debugln("J: "+qsJ+"("+qsJ.sb.length()+")");
					
					// cache
					if (C.cacheJK.containsKey(tmpJ) && use_cache)
					{
						if (C.cacheJK.get(tmpJ)==true)
						{
							println("Case #"+cc+": "+"YES");
							continue cc;
						}
						else
						{
							continue i;
						}
					}
					
					// no cache
					QuaternionString qsK = qsJ.clone();
					qsK.sb.deleteCharAt(0);
					
					qsK.multiplyAll();
					
					debugln("K: "+qsK);
					
					if (qsK.toString().equals("k"))
					{
						println("Case #"+cc+": "+"YES");
						
						for (String key : subS_JK)
						{
							C.cacheIJK.put(key, true);
						}
						
						for (String key : subS_JK)
						{
							C.cacheJK.put(key, true);
						}
						
						continue cc;
					}
					
					for (String key : subS_JK)
					{
						C.cacheIJK.put(key, false);
					}
					
					for (String key : subS_JK)
					{
						C.cacheJK.put(key, false);
					}
				}
				first = false;
			}
			
//			qs.multiplyFirst();
//			
//			System.out.println(qs.toString());
			
//			println("Case #"+cc+": "+"YES");
			println("Case #"+cc+": "+"NO");
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		// 19:03 - 
//		String problemFile = "test";
		
//		String problemFile = "%s-small-attempt0";
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

class QuaternionString
{
	public StringBuilder sb;
	public boolean positive = true;
	
	private Quaternion q1, q2;
	
	public QuaternionString (String s)
	{
		this.sb = new StringBuilder(s);
		
		this.q1 = new Quaternion('1');
		this.q2 = new Quaternion('1');
	}
	
	private void invert() { positive = !positive; }
	
	public void multiplyFirst ()
	{
		if (sb.length()>1)
		{
			q1.reset(sb.charAt(0), positive);
			q2.reset(sb.charAt(1));
			q1.multiply(q2);
			
			positive = q1.positive;
			sb.setCharAt(0, q1.c);
			sb.deleteCharAt(1);
		}
	}
	
	public void multiplyAll()
	{
		String tmp = sb.toString();

		if (C.cacheMultiplyAll.containsKey(tmp))
		{
			sb = new StringBuilder(C.cacheMultiplyAll.get(tmp));
		}
		else
		{
			while (sb.length()>1)
			{
				multiplyFirst();
			}
			
			C.cacheMultiplyAll.put(tmp, sb.toString());
		}
	}
	
	public boolean next(char c)
	{
		if (sb.length()<2) return false;
		
		multiplyFirst();
		while (sb.charAt(0) != c && sb.length()>1)
		{
			multiplyFirst();
		}
		return sb.charAt(0)==c;
	}
	
	@Override
	public String toString() {
		return (positive?"":"-")+sb;
	}
	
	@Override
	public QuaternionString clone() {
		QuaternionString clone = new QuaternionString(sb.toString());
		clone.positive = positive;
		return clone;
	}
}

class Quaternion
{
	public char c;
	public boolean positive = true;
	
	public Quaternion(char c) { this.c = c; }
	private void invert() { positive = !positive; }

	public void reset(char c)
	{
		this.c = c;
		this.positive = true;
	}
	
	public void reset(char c, boolean positive)
	{
		this.c = c;
		this.positive = positive;
	}
	
	public void multiply (Quaternion q)
	{
		if (!q.positive) invert();
		
		if (c=='1')
		{
			if (q.c=='1') { c = '1'; }
			if (q.c=='i') { c = 'i'; }
			if (q.c=='j') { c = 'j'; }
			if (q.c=='k') { c = 'k'; }
		}
		else if (c=='i')
		{
			if (q.c=='1') { c = 'i'; }
			if (q.c=='i') { c = '1'; invert(); }
			if (q.c=='j') { c = 'k'; }
			if (q.c=='k') { c = 'j'; invert(); }
		}
		else if (c=='j')
		{
			if (q.c=='1') { c = 'j'; }
			if (q.c=='i') { c = 'k'; invert(); }
			if (q.c=='j') { c = '1'; invert(); }
			if (q.c=='k') { c = 'i'; }
		}
		else if (c=='k')
		{
			if (q.c=='1') { c = 'k'; }
			if (q.c=='i') { c = 'j'; }
			if (q.c=='j') { c = 'i'; invert(); }
			if (q.c=='k') { c = '1'; invert(); }
		}
	}
	
	@Override
	public String toString() {
		return positive?"":"-"+c;
	}
}