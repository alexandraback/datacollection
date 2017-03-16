package gcj2013.round1c;

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
import java.util.Map;
import java.util.StringTokenizer;

public class C
{
	static class Tribe
	{
		int d,n,w,e,s,dd,dp,ds;
		
		public Tribe(int _d, int _n, int _w, int _e, int _s, int _dd, int _dp, int _ds) {
			d = _d;
			n = _n;
			dd = _dd;
			
			w = _w;
			e = _e;
			dp = _dp;
			
			s = _s;
			ds = _ds;
		}
		
		void attack ()
		{
			n--;
			d += dd;
			
			e += dp;
			w += dp;
			
			s += ds;
		}
		
		@Override
		public String toString() {
			return d+" "+n+" "+w+" "+e+" "+s+" "+dd+" "+dp+" "+ds;
		}
	}
	
	static void clearTribes() throws IOException
	{
		List<Tribe> remove = new ArrayList<Tribe>();
		for (Tribe tribe : tribes) {
			if (tribe.n==0)
			{
				remove.add(tribe);	
			}
		}
		for (Tribe tribe : remove) {
			tribes.remove(tribe);
		}
	}
	
	private static int cc;
	private static List<Tribe> tribes;
	private static void putput() throws IOException
	{
		int cases = INT();
		cc: for (cc = 1; cc<=cases; cc++)
		{
			int N = INT();
			tribes = new ArrayList<Tribe>();
			for (int i = 0; i < N; i++) {
				int d = INT();
				int n = INT();
				int w = INT();
				int e = INT();
				int s = INT();
				int dd = INT();
				int dp = INT();
				int ds = INT();
				Tribe tribe = new Tribe(d,n,w,e,s,dd,dp,ds);
				debugln(tribe.toString());
				tribes.add(tribe);
			}
			
			int day = 0;
			int successFullAttacks = 0;
			Map<Double,Integer> wall = new HashMap<Double,Integer>(); 
			while (tribes.size()>0)
			{
				debugln("day: "+day+" tribes: "+tribes.size());
				Map<Double,Integer> build = new HashMap<Double,Integer>(); 
				for (Tribe tribe : tribes) {
					if (tribe.d==day)
					{
						debugln("attack: "+tribe.toString());
						boolean succeeds = false;
						for (double e = tribe.w; e<=tribe.e; e+=0.5)
						{
							if (!wall.containsKey(e)) wall.put(e, 0);
							if (wall.get(e)<tribe.s)
							{
								succeeds = true;
								
								if (!build.containsKey(e)) build.put(e, tribe.s);
								else build.put(e, Math.max(build.get(e), tribe.s));
							}
						}
						if (succeeds)
						{
							successFullAttacks++;
							debugln("succeeds: "+tribe.toString());
						}
						tribe.attack();
					}
				}
				
				for (double i : build.keySet()) {
					wall.put(i, build.get(i));
				}
				
				clearTribes();
				day++;
			}
			
			println("Case #"+cc+": "+successFullAttacks);
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		// 11:40 - 
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
