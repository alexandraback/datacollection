import java.util.*;
import java.io.*;

class War
{
	public static void main(String[] args) throws Exception
	{
		//sort first
		String file = "D-small-attempt1.in";
		Scanner in = new Scanner(new File(file));
		//BufferedReader in = new BufferedReader(new FileReader(file));
		PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
		int testcase = in.nextInt();
		for (int test = 1; test <= testcase; ++test)
		{
			int N = in.nextInt();
			double[] naomi = new double[N];
			double[] ken = new double[N];
			for (int i = 0; i < N; ++i)
			{
				naomi[i] = in.nextDouble();
			}
			for (int i = 0; i < N; ++i)
			{
				ken[i] = in.nextDouble();
			}
			Arrays.sort(naomi);
			Arrays.sort(ken);
			int deceit = deceitfulwar(naomi,ken);
			int real = realwar(naomi,ken);
			out.format("Case #%d: %d %d\n", test, deceit, real);
		}
		out.close();
		in.close();
	}

	public static int deceitfulwar(double[] naomi, double[] ken)
	{
		int index = 0;
		int nextKen = 0;
		int count = 0;
		while (index < naomi.length)
		{
			if (naomi[index] < ken[nextKen])
			{
				++index;
			} else
			{
				++index;
				++nextKen;
				++count;
			}
		}
		return count;
	}
	public static int realwar(double[] naomi, double[] ken)
	{
		ArrayList<Double> Naomi = new ArrayList<Double>();
		ArrayList<Double> Ken = new ArrayList<Double>();
		for (int i = 0; i < naomi.length; ++i)
		{
			Naomi.add(naomi[i]);
			Ken.add(ken[i]);
		}
		int naomi_score = 0;
		while (Naomi.size() != 0)
		{
			if(Double.compare(Naomi.get(0), Ken.get(Ken.size()-1)) == -1 && Double.compare(Naomi.get(0), Ken.get(0)) == 1)
			{
				int min_big = Ken.size() - 1;
				while (Double.compare(Naomi.get(0), Ken.get(min_big)) == -1)
				{
					--min_big;
				}
				++min_big;
				Naomi.remove(0);
				Ken.remove(min_big);
			} else if(Double.compare(Naomi.get(0), Ken.get(0)) == -1)
			{
				Naomi.remove(0);
				Ken.remove(0);
			}else
			{
				Naomi.remove(0);
				Ken.remove(0);
				++naomi_score;
			}
		}
		return naomi_score;
	}
}