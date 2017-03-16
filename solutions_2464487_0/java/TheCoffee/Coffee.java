import java.io.*;
import java.util.*;

public class Coffee
{
	public static void main(String[] args)
	{
		try
		{
			BufferedReader br = new BufferedReader(new FileReader("A-small-attempt1.in"));
			BufferedWriter bw = new BufferedWriter(new FileWriter(new File("output.txt")));
			
			int cases = Integer.parseInt(br.readLine());
			
			
			PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
			for(int i = 0; i < cases; i++)
			{
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				int r = Integer.parseInt(st.nextToken());
				int t = Integer.parseInt(st.nextToken());
				
				//System.out.print(");
				
				
				writer.println("Case #" + (i+1) + ": " + process(r, t) );
			}
			writer.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public static int process(int radius, int p)
	{
		double paintLeft = p;
		int circles = 0;
		
		
		//System.out.println();
		do
		{
			
			double nextCircle = Math.PI * (Math.pow(radius+1,2) - Math.pow(radius,2));
			//System.out.println("Paint left: " + paintLeft);
			//System.out.println("Circle " + circles + ": " + nextCircle);
			
			paintLeft = paintLeft - (nextCircle / (float)Math.PI);
			
			
			radius = radius + 2;
			circles++;
		}
		while(paintLeft > 0);
		
		
		return (circles-1);
		//System.out.println();
	}
	
}