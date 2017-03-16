import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A
{
	String line;
	StringTokenizer inputParser;
	BufferedReader is;
	FileInputStream fstream;
	DataInputStream in;
	String FInput="";
	
	void openInput(String file)
	{

		if(file==null)is = new BufferedReader(new InputStreamReader(System.in));//stdin
		else
		{
			try{
		
				
			fstream = new FileInputStream(file);
			in = new DataInputStream(fstream);
			is = new BufferedReader(new InputStreamReader(in));
			}catch(Exception e)
			{
				System.err.println(e);
			}
		}

	}
	
	void readNextLine()
	{
		try {
			line = is.readLine();
			inputParser = new StringTokenizer(line, " ");
			//System.err.println("Input: " + line);
		} catch (IOException e) {
			System.err.println("Unexpected IO ERROR: " + e);
		}	
		catch (NullPointerException e)
		{
			line=null;
			
		}
		
	}
	
	int NextInt()
	{
		String n = inputParser.nextToken();
		int val = Integer.parseInt(n);
		
		//System.out.println("I read this number: " + val);
		return val;
	}
	
	long NextLong()
	{
		String n = inputParser.nextToken();
		long val = Long.parseLong(n);
		
		//System.out.println("I read this number: " + val);
		return val;
	}
	
	double NextDouble()
	{
		String n = inputParser.nextToken();
		double val = Double.parseDouble(n);
		
		//System.out.println("I read this number: " + val);
		return val;
	}
	
	String NextString()
	{
		String n = inputParser.nextToken();
		return n;
	}
	
	void closeInput()
	{
		try {
			is.close();
		} catch (IOException e) {
			System.err.println("Unexpected IO ERROR: " + e);
		}
			
	}
	
	
	public static void main(String [] argv)
	{
		//String filePath="input.txt";
        String filePath=null;
		if(argv.length>0)filePath=argv[0];
		new A(filePath);
	}
	
	public void readFInput()
	{
		for(;;)
		{
			try
			{
				readNextLine();
				FInput+=line+" ";
			}
			catch(Exception e)
			{
				break;
			}
		}
		inputParser = new StringTokenizer(FInput, " ");
	}
	
	
	ArrayList <Integer> [] chests;
	boolean[] v;
	int K,N;
	int [] types;
	
	public A(String inputFile)
	{
		openInput(inputFile);
		readNextLine();
    	
    	int T=NextInt();
    	int idlin=2;
    	for(int t=1; t<=T; t++)
    	{
    		seen=new HashSet<Long>();
    		//System.err.println(idlin);
    		readNextLine();
    		K=NextInt();
    		N=NextInt();
    		idlin+=(2+N);
    		readNextLine();
    		ArrayList <Integer> keys = new ArrayList<Integer>();
    		chests = new ArrayList[N];
    		types = new int[N];
    		v = new boolean[N];
    		for(int i=0; i<K; i++)
    			keys.add(NextInt());
    		for(int i=0; i<N; i++)
    		{
    			readNextLine();
    			types[i]=NextInt();
    			chests[i]=new ArrayList<Integer>();
    			int num=NextInt();
    			for(int j=0; j<num; j++)
    				chests[i].add(NextInt());
    		}
    		String ret="IMPOSSIBLE ";
    		//if(isPossible(keys))
    		{
	    		for(int i=0; i<N; i++)
	    		{
	    			if(keys.contains(types[i]))
	    			{
	    				keys.remove((Integer)types[i]);
	    				keys.addAll(chests[i]);
	    				ret=dfs(1, i, keys);
	    				if(!ret.contains("IMP"))break;
	    				keys.removeAll(chests[i]);
	    				keys.add(types[i]);
	    			}    			
	    		}
    		}
    		ret=ret.substring(0, ret.length()-1);
    		
    		System.out.println("Case #" + t + ": " + ret);
    	}
	    
	    	
		closeInput();			
	}
	private boolean isPossible(ArrayList<Integer> keys) {
		ArrayList<Integer> all = new ArrayList<Integer>();
		all.addAll(keys);
		for(int i=0; i<N; i++)
			all.addAll(chests[i]);
		for(int i=0; i<N; i++)
			if(!all.remove((Integer)types[i]))return false;
		return true;
	}
	HashSet<Long>seen;
	String dfs(int cnt, int x, ArrayList <Integer> keys)
	{
		
		String ret=(x+1)+" ";
		if(cnt==N)return ret;
		v[x]=true;
		long code=getCode(v);
		if(seen.contains(code))
		{
			v[x]=false;
			return "IMPOSSIBLE ";
		}
		seen.add(code);
		for(int i=0; i<N; i++)
		{
			if(v[i])continue;
			
			if(keys.contains(types[i]))
			{
				keys.remove((Integer)types[i]);
				keys.addAll(chests[i]);
				String now=dfs(cnt+1, i, keys);
				if(!now.contains("IMP"))return ret+now;
				keys.removeAll(chests[i]);
				keys.add(types[i]);
			}
		}
		v[x]=false;
		return "IMPOSSIBLE ";
	}
	
	private long getCode(boolean[] v2) {
		long ret=0;
		for(int i=0; i<v2.length; i++)
			if(v2[i])ret|=(1<<i);		
		return ret;
	}

	public static void out(Object s)
	{
		try
		{
		    FileWriter fstream = new FileWriter("output.txt");
			BufferedWriter out = new BufferedWriter(fstream);
			out.write(s.toString());
			out.close();
		}catch (Exception e){
			System.err.println("Error: " + e.getMessage());
		}
	}
	

}