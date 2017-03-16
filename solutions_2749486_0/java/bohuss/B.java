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
	int N=400;
	int MSTEPS=30;
	String [] [] [] p = new String [N][N][200];
	boolean [] [] v = new boolean[N][N];
	public B(String inputFile)
	{
		openInput(inputFile);
		readNextLine();
		
		
		final int INF = 12341234;
		
		
		
		ArrayList <Integer> q = new ArrayList<Integer>();
		q.add(N/2*10000+N/2);
		p[N/2][N/2][0]="";
		int step=1;
		for(int i=0; i<MSTEPS; i++)
		{
			ArrayList <Integer> q2 = new ArrayList<Integer>();
			for(int a:q)
			{
				int x=a/10000;
				int y=a%10000;
				for(int j=0; j<4; j++)
				{
					add(x+step*dx[j], y+step*dy[j], q2, p[x][y][i]+dm[j], i+1);
				}
			}
			q=q2;
			step++;
			//System.out.println(missing());
		}

		int TC = NextInt();
		
		for(int tt=0; tt<TC; tt++)
		{	
			
			String output=solve();
			System.out.println("Case #"+(tt+1)+": "+output);
		}
		closeInput();
	}
	
	int missing()
	{
		int ret=0;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(!v[i][j])ret++;
		return ret;
	}
	private void add(int x, int y, ArrayList<Integer> q2, String s, int k) {
		
		if(x<0||x>=N||y<0||y>=N)return;
		if(p[x][y][k]!=null)return;
		//System.out.println(x+" "+y+" "+k+":"+s);
		p[x][y][k]=s;
		v[x][y]=true;
		q2.add(x*10000+y);
	}

	int [] dx={ -1, 0, 1, 0};
	int [] dy={ 0, -1, 0, 1};
	char [] dm={'W', 'S', 'E', 'N'}; 

	private String solve() {
		String ret="";
		readNextLine();
		int X=NextInt()+N/2, Y=NextInt()+N/2;
		for(int i=0; i<MSTEPS; i++)
		{
			if(p[X][Y][i]!=null)return p[X][Y][i];
		}
		
		return ret;
	}
	
	
}

