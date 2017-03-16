import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class C {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
		PrintWriter p = new PrintWriter("out.txt");
		boolean[] fair_sqr = new boolean[1050];
		for(int i = 0 ; i*i < 1020;i++)
			if(pal(i+""))
				fair_sqr[i*i] = pal((i*i)+"");
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T;t++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int res = 0;
			for(int i = a; i  <= b;i++)
				if(fair_sqr[i])
					res++;
			p.println("Case #"+t+": "+res);
		}
		p.close();
	}

	private static boolean pal(String s)
	{
		char[] c = s.toCharArray();
		int len = c.length;
		for(int i = 0;  i < len/2;i++)
			if(c[i] != c[len-1-i])
				return false;
		return true;
	}

}
