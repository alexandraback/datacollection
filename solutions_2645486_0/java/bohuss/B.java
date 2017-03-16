package actual;
import java.io.*;
import java.util.*;

public class B
{
	String line;
	StringTokenizer inputParser;
	BufferedReader is;
	FileInputStream fstream;
	DataInputStream in;
	
	void openInput(String file)
	{

		//is = new BufferedReader(new InputStreamReader(System.in));//stdin
		try{
			fstream = new FileInputStream(file);
			in = new DataInputStream(fstream);
			is = new BufferedReader(new InputStreamReader(in));
		}catch(Exception e)
		{
			System.err.println(e);
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
		
	}
	
	double NextDouble()
	{
		String n = inputParser.nextToken();
		double val = Double.parseDouble(n);
		
		//System.out.println("I read this number: " + val);
		return val;
	}
	
	int NextInt()
	{
		String n = inputParser.nextToken();
		int val = Integer.parseInt(n);
		
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
		new B(argv[0]);
	}

	int sortType=0;
	
	public B(String inputFile)
	{
		openInput(inputFile);
		readNextLine();

		int TC = NextInt();
		
		
		for(int t=0; t<TC; t++)
		{	
			readNextLine();
			int E=NextInt();
			int R=NextInt();
			int N=NextInt();
			readNextLine();
			int [] v = new int[N];
			for(int i=0; i<N; i++)
				v[i]=NextInt();
			
			long ret=0;
			
			HashMap<Integer, Integer>hm = new HashMap<Integer, Integer>();
			hm.put(E, 0);
			
			for(int i=0; i<N; i++)
			{
				HashMap<Integer, Integer>hm2 = new HashMap<Integer, Integer>();
				for(int x:hm.keySet())
				{
					int y=hm.get(x);
					for(int j=0; j<=x; j++)
					{
						int EE=Math.min(E, x-j+R);
						if(hm2.containsKey(EE))hm2.put(EE, Math.max(y+j*v[i], hm2.get(EE)));
						else hm2.put(EE, y+j*v[i]);
					}
				}
				hm=hm2;
			}
			for(int x:hm.values())
				ret=Math.max(ret, x);
			
			System.out.print("Case #"+(t+1)+": ");
			
			System.out.println(ret);
		}
		closeInput();
	}
	
	
	
}

