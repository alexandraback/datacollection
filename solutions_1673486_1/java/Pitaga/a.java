
import java.io.*;
import java.util.*;

public class a {
	
	public static void main(String[] args) throws IOException
	{
		Scanner qwe = new Scanner(new File("a-small.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("a.out"));
		int t = qwe.nextInt();
		for(int i=1; i <= t; i++)
		{
			int a = qwe.nextInt();
			int b = qwe.nextInt();
			double pallright = 1;
			double[] ps = new double[a];
			double[] backspaces = new double[a];
			double min = 30000000;
			int numbackspaces = a;
			for(int j= 0; j < a; j++)
			{
				backspaces[j] = pallright*(numbackspaces*2+b-a+1)+(1-pallright)*(numbackspaces*2+b-a+1+b+1);
				//System.out.println(backspaces[j]);
				min = Math.min(backspaces[j], min);
				ps[j] = qwe.nextDouble();
				pallright *= ps[j];
				numbackspaces--;
			}
			double one = pallright*(b-a+1)+(1-pallright)*(b-a+1+b+1);
			//System.out.println(one);
			double two = 1+b+1;
			min = Math.min(min, one);
			min = Math.min(min, two);
				out.write("Case #" + i + ": " + min+ "\n");	
		}
	out.close();
	}
	

}
