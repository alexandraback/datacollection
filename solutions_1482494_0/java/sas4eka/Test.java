import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter writer;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws IOException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream("bsm.in")));
		tokenizer = null;
		writer = new PrintWriter("bsm.out");
		solve();
		reader.close();
		writer.close();
	}

	private static void test() throws IOException
	{
		int n = nextInt();
		Level []mas = new Level[n];
		for(int i=0;i<n;i++)
		{
			int a = nextInt();
			int b = nextInt();
			mas[i] = new Level(a,b);
		}

		Arrays.sort(mas);
		
//		for(int i=0;i<n;i++)
//		{
//			System.out.println(mas[i].a+" "+mas[i].b);
//		}
		
		int[] st = new int[n];
		
		int cs = 0;
		boolean got = false;
		int res=0;
		while(!(cs == 2*n))
		{
			got=false;
			for(int i=0;i<n;i++)
			{
				if(st[i]==0 && mas[i].b<=cs)
				{
					//System.out.println("02 "+i);
					got=true;
					st[i]=2;
					cs+=2;
					res++;
					break;
				}
			}
			if(got==true)
				continue;
			
			for(int i=0;i<n;i++)
			{
				if(st[i]==1 && mas[i].b<=cs)
				{
					//System.out.println("12 "+i);
					got=true;
					st[i]=2;
					cs+=1;
					res++;
					break;
				}
			}
			if(got==true)
				continue;
			
			for(int i=0;i<n;i++)
			{
				if(st[i]==0 && mas[i].a<=cs)
				{
					//System.out.println("01 "+i);
					got=true;
					st[i]=1;
					cs+=1;
					res++;
					break;
				}
			}
			if(got==false)
				break;
		}
		//System.out.println();
		if(cs==2*n)
		{
			writer.print(res);
		}
		else
		{
			writer.print("Too Bad");
		}
	}
	
	private static void solve() throws IOException {		
		int t = nextInt();
		for(int i=1;i<=t;i++)
		{
			writer.print("Case #"+i+": ");
			test();
			writer.println();
		}
	}
}

class Level implements Comparable <Level>
{
	public int a;
	public int b;
	
	public Level(int a, int b) {
		this.a = a;
		this.b = b;
	}

	public int compareTo(Level o) {
		return o.b-b;
	}
}
