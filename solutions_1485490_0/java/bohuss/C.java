package actual;
import java.io.*;
import java.util.*;

public class C
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
		new C(argv[0]);
	}
	public C(String inputFile)
	{
		openInput(inputFile);
		readNextLine();

		int TC = NextInt();
		
		for(int t=0; t<TC; t++)
		{	
			long ret=0;
			readNextLine();
			int N=NextInt();
			int M=NextInt();
			readNextLine();
			
			long [] a=new long [N];
			int [] A=new int [N];
			
			long [] b=new long [M];
			int [] B=new int [M];
			
			for(int i=0; i<N; i++)
			{
				a[i]=NextLong();
				A[i]=NextInt();
			}
			readNextLine();
			for(int i=0; i<M; i++)
			{
				b[i]=NextLong();
				B[i]=NextInt();
			}
			
			ArrayList <State> states= new ArrayList<State>();
			states.add(new State(0,0,0));
			
			for(int i=0; i<N; i++)
			{
				int X=states.size();
				for(int j=0; j<X; j++)
				{
					long r=states.get(j).res;
					int d=states.get(j).box;
					long c=states.get(j).cnt;
					
					for(int y=d; y<M; y++)
					{
						if(B[y]==A[i])
						{
							long maxN=b[y]-c;
							if(maxN>a[i])maxN=a[i];
							if(r+maxN>ret)ret=r+maxN;
							if(maxN>0)
								states.add(new State(r+maxN, y, b[y]-c-maxN));
							
						}
					}
					
				}
			}
			
			System.out.println("Case #"+(t+1)+": "+ret);
		}
		closeInput();
	}

	private class State
	{
		long res, cnt;
		int box;
		
		State(long r, int b, long c)
		{
			res=r;
			box=b;
			cnt=c;
		}
	}
	
}

