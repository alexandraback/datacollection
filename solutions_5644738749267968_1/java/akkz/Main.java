import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main
{
	private static Scanner in = new Scanner(System.in);
	private static PrintStream out = System.out;

	public static void main(String[] args)
	{
		int current = in.nextInt() + 1;
		for (int i = 1; i < current; i++)
		{
			check(i);
		}
	}

	private static void check(int current)
	{
		int num = in.nextInt();
		
		double[] a = new double[num];
		double[] b = new double[num];
		
		for(int i=0; i<num; i++)
		{
			a[i] = in.nextDouble();
		}
		
		for(int i=0; i<num; i++)
		{
			b[i] = in.nextDouble();
		}
		
		Arrays.sort(a);
		Arrays.sort(b);
		
		out.println("Case #" + current + ": " + (num-figure(clone(b), clone(a))) + " " + figure(clone(a), clone(b)));
	}


	private static int figure(ArrayList<Double> a, ArrayList<Double> b)
	{
		int num = 0;
		
		while(a.size() > 0)
		{
			if(a.get(0) > b.get(0))
			{
				a.remove(0);
				b.remove(b.size()-1);
				
				num++;
			}
			else
			{
				int i=0;
				for(; i<b.size(); i++)
				{
					if(a.get(0) > b.get(i))
						break;
				}
				
				a.remove(0);
				b.remove(i-1);
			}
		}
		
		return num;
	}

	private static ArrayList<Double> clone(double[] a)
	{
		ArrayList<Double> c = new ArrayList<Double>();
		
		for(int i=a.length-1; i>-1; i--)
		{
			c.add(a[i]);
		}
		
		return c;
	}
	
}
