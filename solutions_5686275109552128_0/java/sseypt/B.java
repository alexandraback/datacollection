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
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.StringTokenizer;

import org.apache.commons.lang3.ArrayUtils;
import org.apache.commons.lang3.StringUtils;

public class B
{
	private static int debugCC = -1;
	private static int cc;
	
	private static Map<Integer,int[][]> special;
	
	private static void putput() throws IOException
	{
		// P -> target minutes, special minutes used, minutes saved
		special = new HashMap<Integer,int[][]>();
		special.put(10, new int[][]{{6,1,3}});
//		special.put(9, new int[][]{{5,2,4},{6,1,3}});
		special.put(9, new int[][]{{5,2,4}});
		special.put(8, new int[][]{{5,1,3}});
		special.put(7, new int[][]{{5,1,2}});
		special.put(6, new int[][]{{4,1,2}});
		special.put(5, new int[][]{{4,1,1}});
		special.put(4, new int[][]{{3,1,1}});

		int cases = INT();
		cc: for (cc = 1; cc<=cases; cc++)
		{
			if (cc == debugCC)
			{
				debugln("-"+debugCC);
			}
			
			int D = INT();
			int[] P = INT_ARRAY();
			
			int[] P_org = Arrays.copyOf(P, P.length);
			Arrays.sort(P_org);
			ArrayUtils.reverse(P_org);
			
			int best = doSpecial2(P);
			
//			// need to cover first case for 9 somehow
//			while (doSpecial(P)) {};
//			best = Math.min(best, P[0]);
			
//			println("Case #"+cc+": "+best+" "+(P_org[0]-best)+" "+Arrays.toString(P_org));
			println("Case #"+cc+": "+best);
		}
	}
	
	private static boolean doSpecial(int[] P)
	{
		Arrays.sort(P);
		ArrayUtils.reverse(P);
		
		int p = P[0];
		if (special.containsKey(p))
		{
			int[][] ss = special.get(p);
			
			for (int[] s : ss)
			{
				if (P.length==1 || 2<=P.length && P[1]+s[1] <= s[0])
				{
					P[0] = s[0];
					for (int i = 1; i < P.length; i++)
					{
						P[i] += s[1];
					}
					
					Arrays.sort(P);
					ArrayUtils.reverse(P);
					
					return p==9&&P.length>1?true:false;
				}
			}
		}
		
		return false;
	}
	
	private static int doSpecial2(int[] P) throws IOException
	{
		Arrays.sort(P);
		ArrayUtils.reverse(P);
		
		debugln(Arrays.toString(P));

		int best = P[0];
		
		// hack the 9
		int nine_count = 0;
		for (int i = 0; i < P.length; i++)
		{
			if (P[i]==9) nine_count++;
		}
		for (int nine_perm = 0; nine_perm<Math.pow(2, nine_count); nine_perm++)
		{
			String nine_brute = Integer.toBinaryString(nine_perm);
			nine_brute = StringUtils.repeat("0", nine_count-nine_brute.length()) + nine_brute;
			
			debugln("nine: "+nine_brute);
			
			nine_count = 0;
			for (int i = 0; i < P.length; i++)
			{
				if (P[i]==9)
				{
					if (nine_brute.charAt(nine_count)=='1') P[i]=10;
					nine_count++;
				}
			}
			
			for (int i = 1; i<Math.pow(2, P.length); i++)
			{
				String brute = Integer.toBinaryString(i);
				brute = StringUtils.repeat("0", P.length-brute.length()) + brute;
				
				debugln(brute);
				
				int[] P_copy = Arrays.copyOf(P, P.length);
				int[] P_add = new int[P.length];
				
				Arrays.fill(P_add, 0);
				for (int j = 0; j<P.length; j++)
				{
					if (brute.charAt(j)=='1')
					{
						int p = P_copy[j];
						if (special.containsKey(p))
						{
							int[][] ss = special.get(p);
							
							ss: for (int[] s : ss)
							{
	//							if (p == 9 && s[0] == 5) continue; // ignore this case for now
								
								P_copy[j] = s[0];
								for (int k = 0; k < P.length; k++)
								{
									if (j==k) continue;
									P_add[k] += s[1];
								}
							}
						}
					}
				}
				
				for (int l = 0; l < P.length; l++)
				{
					P_copy[l] += P_add[l];
				}
				
				debugln(Arrays.toString(P_copy));
				
				Arrays.sort(P_copy);
				ArrayUtils.reverse(P_copy);
	
				best = Math.min(best, P_copy[0]);
			}
		}
		
		return best;
	}
	
	public static void main(String[] args) throws IOException
	{
		// 23:44 - 
//		String problemFile = "test";
		
//		String problemFile = "%s-small-attempt0";
		String problemFile = "%s-small-attempt6";
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
