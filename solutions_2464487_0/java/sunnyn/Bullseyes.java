import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Bullseyes {
	static int N;
	public static void main(String args[]) throws IOException
	{
		long time = System.currentTimeMillis();
		BufferedReader in = new BufferedReader(new FileReader("test.in"));
		PrintWriter out = new PrintWriter( new BufferedWriter( new FileWriter("test.out")));
		N = Integer.parseInt(in.readLine());
		for(int i=0; i<N; i++)
		{
			StringTokenizer st = new StringTokenizer(in.readLine());
			long rr = Long.parseLong(st.nextToken());
			long tt = Long.parseLong(st.nextToken());
			out.println("Case #"+(i+1)+": "+res(rr,tt));
			System.out.println("Case #"+(i+1)+": "+res(rr,tt)+"("+rr+","+tt+")");
		}
		System.out.println(res(155,311));
		in.close();
		out.close();
		System.out.println("Runtime: "+(System.currentTimeMillis()-time));
		System.exit(0);
	}
	public static long res(long r, long t)
	{
		double tt = t*Math.PI; 
		double d =  (Math.sqrt(Math.PI)*Math.sqrt(4*Math.PI*r*r-4*Math.PI*r+8*tt+Math.PI)-2*Math.PI*r+Math.PI)/(4*Math.PI);
		long l = (long)d;
		if(1-(d-l)<Math.pow(10, -10)) l+=1;
		return l;
	}
	public static double rest(long r, long t)
	{
		double tt = t*Math.PI; 
		double d =  (Math.sqrt(Math.PI)*Math.sqrt(4*Math.PI*r*r-4*Math.PI*r+8*tt+Math.PI)-2*Math.PI*r+Math.PI)/(4*Math.PI);
		return d;
	}
}
