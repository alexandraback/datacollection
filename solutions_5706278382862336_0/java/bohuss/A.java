package actual;
import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

public class A
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
		new A(argv[0]);
	}
	
	int [] [] p;
	public A(String inputFile)
	{
		openInput(inputFile);
		readNextLine();

		int TC = NextInt();
		ArrayList <X> gen = new ArrayList<A.X>();
		gen.add(new X(0,1,0));
		gen.add(new X(1,1,0));
		int R=2049;
		p = new int[R][R];
		for(int i=0; i<R; i++)
			for(int j=0; j<R; j++)
				p[i][j]=-1;
		for(X x:gen)
			if(p[x.a][x.b]==-1)p[x.a][x.b]=x.g;
		for(int t=0; t<10; t++)
		{
			ArrayList <X> gen2 = new ArrayList<A.X>();
			for(X x:gen)
				for(X y:gen)
				{
					int gg=Math.max(x.g, y.g)+1;
					if((x.a==1&&x.b==1)||(y.a==1&&y.b==1))gg=1;
					X xx = new X(x.a*y.b+x.b*y.a, 2*x.b*y.b, gg);
					//System.out.println(xx.a+" "+xx.b+" "+xx.g);
					if(p[xx.a][xx.b]==-1)
					{
						p[xx.a][xx.b]=xx.g;
						gen2.add(xx);
						//System.out.println(xx.a+" "+xx.b+" "+xx.g);
						//System.out.println(x.a+" "+x.b+"+"+y.a+" "+y.b);
					}
				}
			gen.addAll(gen2);
			for(X x:gen)
				if(p[x.a][x.b]==-1)p[x.a][x.b]=x.g;
		}
		for(int tt=0; tt<TC; tt++)
		{	
			
			String output=solve();
			System.out.println("Case #"+(tt+1)+": "+output);
		}
		closeInput();
	}
	
	private String solve() {
		readNextLine();
		StringTokenizer st = new StringTokenizer(line, "/");
		long P=Long.parseLong(st.nextToken());
		long Q=Long.parseLong(st.nextToken());/*
		long x=GCD(P,Q);
		P/=x;
		Q/=x;
		if(P*2>Q)
		{
			P=Q-P;
		}
		if(Q%P>0)return line+" "+"impossible";
		int ret=0;
		long y=1;
		while(y<Q)
		{
			ret++;
			y*=2;
		}*/
		int pp=(int)P;
		int q=(int)Q;
		if(p[pp][q]==-1)return "impossible";
		
		return ""+p[pp][q];
	}
	
	private long GCD(long a, long b)
	{
		return(b==0?a:GCD(b, a%b));
	}
	
	private int GCD(int a, int b)
	{
		return(b==0?a:GCD(b, a%b));
	}
	
	private class X
	{
		int a,b,g;
		X(int a, int b, int g)
		{
			this.a=a;
			this.b=b;
			this.g=g;
			int d=GCD(a,b);
			this.a/=d;
			this.b/=d;
		}
	}
}

