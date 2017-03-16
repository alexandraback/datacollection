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

	Solution [] sols = new Solution[21];
	
	public B(String inputFile)
	{
		openInput(inputFile);
		readNextLine();

		int TC = NextInt();
		
		
		for(int i=0; i<sols.length; i++)
			sols[i]=new Solution();
		Diamonds base = new Diamonds();
		base.p[6][0] = true;
		sols[1].a.add(base);
		
		for(int t=2; t<sols.length; t++)
		{
			if(t==6||t==15)
			{
				sols[t].a.add(sols[t-1].a.get(0).fall());
				continue;
			}
			for(Diamonds x:sols[t-1].a)
			{
				Diamonds attempt=x.go(true);
				if(attempt!=null)sols[t].a.add(attempt);
				attempt=x.go(false);
				if(attempt!=null)sols[t].a.add(attempt);
			}
		}
		
		
		for(int tt=0; tt<TC; tt++)
		{	
			
			String output=solve();
			System.out.println("Case #"+(tt+1)+": "+output);
		}
		closeInput();
	}
	
	private class Solution
	{
		ArrayList<Diamonds> a = new ArrayList<B.Diamonds>();
	}
	private class Diamonds
	{
		boolean [] [] p = new boolean [13][7];

		public Diamonds go(boolean b) {
			int x=6, y=6;
			while(!p[x][y-2])y-=2;
			int d=1;
			if(b)d=-1;
			while(y>0&&!p[x+d][y-1]){x+=d;y--;}
			if(x==6)return null;
			Diamonds ret = new Diamonds();
			for(int i=0; i<13; i++)
				for(int j=0; j<7; j++)
					ret.p[i][j]=p[i][j];
			ret.p[x][y]=true;
			return ret;
		}

		public Diamonds fall() {
			int x=6, y=6;
			while(!p[x][y-2])y-=2;
			Diamonds ret = new Diamonds();
			for(int i=0; i<13; i++)
				for(int j=0; j<7; j++)
					ret.p[i][j]=p[i][j];
			ret.p[x][y]=true;
			return ret;
		}
		
	
	}
	private String solve() {
		String ret="";
		readNextLine();
		int N=NextInt(), X=NextInt(), Y=NextInt();
		int cnt=0;
		if(Math.abs(X)>6)return "0.0";
		if(Y>6)return "0.0";
		for(Diamonds x:sols[N].a)
		{
			if(x.p[X+6][Y])cnt++;
		}
		double res=(double)cnt/sols[N].a.size();
		ret=""+res;
		return ret;
	}
	
	
}

