import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class DeceitfulWar {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for (int t = 1; t <= T; t++)
		{
			runMe(in, t);
		}
	}
	
	private static void runMe(Scanner in, int t)
	{
		int n = in.nextInt();
		ArrayList<Double> 	naomi1 = new ArrayList<Double>(),
							ken1 = new ArrayList<Double>();
		
		for (int i = 0; i < n; i++)
		{
			naomi1.add(in.nextDouble());
		}
		for (int i = 0; i < n; i++)
		{
			ken1.add(in.nextDouble());
		}
		
		Collections.sort(naomi1);
		Collections.sort(ken1);
		ArrayList<Double> naomi2 = new ArrayList<Double>(naomi1);
		ArrayList<Double> ken2 = new ArrayList<Double>(ken1);
		
		System.out.println("Case #" + t + ": " + deceit(naomi1, ken1)
				+ " " + war(naomi2, ken2));
	}
	
	private static int war(ArrayList<Double> naomi, ArrayList<Double> ken)
	{		
		int count = 0;
		int size = naomi.size();
		
		while (size > 0)
		{
			double 	n = naomi.remove(size-1),
					k = ken.get(size-1);
			
			if (k < n)
			{
				k = ken.remove(0);
				count++;
			}
			
			size--;
		}
		
		return count;
	}
	
	private static int deceit(ArrayList<Double> naomi, ArrayList<Double> ken)
	{		
		int count = 0;
		
		while (naomi.size() > 0)
		{
			//remove smallest naomi & largest ken
			if (naomi.get(0) < ken.get(0))
			{
				naomi.remove(0);
				ken.remove(ken.size()-1);
			}
			//remove smallest naomi & smallest ken
			else
			{
				naomi.remove(0);
				ken.remove(0);
				count++;
			}
		}
		
		return count;
	}

}
