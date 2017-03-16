import java.util.*;
import java.io.*;
public class B {
	static double tc;
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new File("B-small-attempt0.in"));		
		PrintWriter out = new PrintWriter(new File("B.out"));
		tc = Double.parseDouble(in.nextLine());
		for(int i = 0; i < tc; i++)
		{
			StringTokenizer st = new StringTokenizer(in.nextLine());
			double c = Double.parseDouble(st.nextToken());
			double f = Double.parseDouble(st.nextToken());
			double x = Double.parseDouble(st.nextToken());
			out.printf("Case #%d: %.7f\n",i+1,solve(c,f,x,2));
		}
		out.close();
		System.exit(0);
	}
	static double solve(double c, double f, double x, double r)
	{
		//we wait till we have c
		double t1 = (x)/r; //we just continue
		double t2 = (c)/r+x/(r+f);
		if(t1<t2)
			return t1;
		return c/r+solve(c,f,x,r+f);		
	}
	static int i(String s)
	{
		return Integer.parseInt(s);
	}
}
