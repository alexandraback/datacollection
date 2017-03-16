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

	public B(String inputFile)
	{
		openInput(inputFile);
		readNextLine();

		int TC = NextInt();
		
		for(int t=0; t<TC; t++)
		{	
			readNextLine();
			double D=NextDouble();
			int N=NextInt();
			int A=NextInt();
			
			readNextLine();
			double t0=NextDouble();
			double x0=NextDouble();
			double fin=0.0;
			
			if(N==2)
			{
				readNextLine();
				double t1=NextDouble();
				double x1=NextDouble();
				double dx=x1-x0;
				double dt=t1-t0;
				double v=dx/dt;
				fin=(double)(D-x0)/v;
				
			}
			
			
			readNextLine();
			System.out.println("Case #"+(t+1)+": ");
			for(int a=0; a<A; a++)
			{
				double aa=NextDouble();
				double time=Math.sqrt(2*(double)D/aa);
				if(time<fin)time=fin;
				System.out.println(time);
			}
		}
		closeInput();
	}
	

	
}

