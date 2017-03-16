package gcj2013.global_qr;

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
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;


class Chest
{
	Integer id;
	Integer key;
	List<Integer> keys;
	boolean done = false;
	
	Chest(int _id, int _key, List<Integer> _keys) {
		this.id = _id;
		this.key = _key;
		this.keys = _keys;
	}
}

public class D
{
	static String attemptHash (List<Chest> result)
	{
		String r = "";
		for (Chest chest : result) { r += "#"+chest.id; }	
		return r;
	}
	
	private static void putput() throws IOException
	{
		int cases = INT();
		cc: for (int cc = 1; cc<=cases; cc++)
		{
			int K = INT();
			int N = INT();
			
			List<Integer> keys = new ArrayList<Integer>();
			for (int i = 0; i < K; i++) {
				keys.add(INT());
			}

			Map<Integer, Chest> chests = new TreeMap<Integer, Chest>();
			for (int i = 1; i <= N; i++) {
				Integer key = INT();
				List<Integer> ck = new ArrayList<Integer>();;
				int Ki = INT();
				for (int j = 0; j < Ki; j++) {
					ck.add(INT());
				}
				chests.put(i, new Chest(i, key, ck));
			}
			
			List<Chest> result = new ArrayList<Chest>();
			
			int index = 1;
			List<String> attempts = new ArrayList<String>();
			List<Integer> missingKeys = new ArrayList<Integer>();
			c: while (result.size() < chests.size())
			{
				missingKeys = new ArrayList<Integer>();
				
				// next attempt
				for (int i = index; i <= chests.size(); i++) {
					Chest chest = chests.get(i);
					if (chest.done) continue; 
					
					if (keys.contains(chest.key))
					{
						result.add(chest);
						String hash = attemptHash(result);

						if (attempts.contains(hash))
						{
							result.remove(result.size() - 1);
							continue;
						}
						
						attempts.add(hash);
						keys.remove(chest.key);
						keys.addAll(chest.keys);
						chest.done = true;
						index = 1;
						
						continue c;
					}
					else
					{
						missingKeys.add(chest.key);
					}
				}
				
				// revert
				Collections.reverse(missingKeys);
				for (Integer missingKey : missingKeys)
				{
					r: while (result.size()>0)
					{
						Chest chest = result.remove(result.size() - 1);
						
						keys.add(chest.key);
						for (Integer key : chest.keys) {
							keys.remove(key);
						}

						chest.done = false;
						index = 1;

						if (chest.key != missingKey)
							continue r;
						
						continue c;
					}
				
					if (keys.contains(missingKey))
						continue c;
				}
				
				println("Case #"+cc+": "+"IMPOSSIBLE");
				continue cc;
			}
			
			String s = "";
			for (Chest chest : result) { s += " "+chest.id; }
			println("Case #"+cc+":"+s);
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		// 02:25 - v2: 04:50 - 
//		String problemFile = "test";
		
//		String problemFile = "%s-small-attempt0";
		String problemFile = "%s-small-attempt1";
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
