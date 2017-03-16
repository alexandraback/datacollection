import java.util.*;
import java.io.*;

public class DDeceitfulWar
{
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new BufferedReader(new FileReader("D-small.in")));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("D-small.out")));
		
		int t = in.nextInt();
		for (int i = 1; i <= t; i++)
		{
			int n = in.nextInt();
			List<Double> naomi = new ArrayList<Double> (n);
			for (int j = 0; j < n; j++)
				naomi.add(in.nextDouble());
			List<Double> ken = new ArrayList<Double> (n);
			for (int j = 0; j < n; j++)
				ken.add(in.nextDouble());
			Collections.sort(naomi);
			Collections.sort(ken);
			out.println("Case #" + i + ": " + deceitful(naomi, ken) + " " + (n - Math.max(normal1(naomi, ken), normal2(naomi, ken))));
		}
		out.flush();
		out.close();
	}
	
	private static int normal1(List<Double> a, List<Double> b)
	{
		TreeSet<Double> set = new TreeSet<Double> (b);
		int count = 0;
		for (double d : a)
		{
			Double r = set.ceiling(d);
			if (r == null)
				set.remove(set.first());
			else
			{
				set.remove(r);
				count++;
			}
		}
		return count;
	}
	
	private static int normal2(List<Double> a, List<Double> b)
	{
		a = new ArrayList<Double> (a);
		Collections.reverse(a);
		TreeSet<Double> set = new TreeSet<Double> (b);
		int count = 0;
		for (double d : a)
		{
			Double r = set.ceiling(d);
			if (r == null)
				set.remove(set.first());
			else
			{
				set.remove(r);
				count++;
			}
		}
		return count;
	}
	
	private static int deceitful(List<Double> a, List<Double> b)
	{
		TreeSet<Double> set = new TreeSet<Double> (b);
		int count = 0;
		for (double n : a)
		{
			if (n < set.first())
				set.remove(set.last());
			else
			{
				set.remove(set.first());
				count++;
			}
		}
		return count;
	}
}
