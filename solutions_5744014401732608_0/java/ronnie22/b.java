import java.io.*;
import java.util.*;


public class b 
{

	public static void main(String[] args) throws FileNotFoundException 
	{
		Scanner sc = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter("output.txt");
		
		int n_case = sc.nextInt();
		for(int i=1;i<=n_case;i++)
		{
			long b = sc.nextLong();
			long m = sc.nextLong();
			String ris = solve(b,m);
			out.println("Case #"+i+": "+ris);
		}
		
		sc.close();
		out.close();
	}
	
	public static String solve(long b, long m)
	{

		
		String ris = new String();
		
		long maxPath = (long) Math.pow((double)2,(double) b-2);
		if(m>maxPath)
		{
			return "IMPOSSIBLE";
		}
		
		ris+="POSSIBLE\n";
		int mat[][] = new int [(int)b][(int)b];
		
		long pp[] = new long[(int)b];
		
		for(int i=1;i<b;i++)
		{
			long p = (long)Math.pow(2.0,(double) b-i-1);
			pp[i-1] = p;
		}
		pp[(int)b-1] = 1;
		
		
		for(int i=(int)b-1;i>=1;i--)
		{
			for(int j=i+1;j<b;j++)
			{
				if(m / pp[i] >= 1 )
				{
					mat[i][j] = 1;
				}
			}
		}
			
		long aus = m;
		for(int j=1;j<(int)b;j++)
		{
			if(pp[j] <= aus )
			{
				mat[0][j] = 1;
				aus -= pp[j];
			}
		}
		
		
		for(int i=0; i<(int)b;i++)
		{
			for(int j=0;j<(int)b;j++)
			{
				ris+=""+mat[i][j];
			}
			if(i!=b-1)
			{
				ris+="\n";
			}
		}
		return ris;
	}

}
