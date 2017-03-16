package codjam2014qual;

import java.util.Scanner;
import java.util.TreeSet;

public class ProbD {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		LOOP: for (int curcase = 1; curcase <= n; curcase++) {
			int N = sc.nextInt();
			TreeSet<Double> naomi = new TreeSet<Double>();
			TreeSet<Double> ken = new TreeSet<Double>();
			for(int i=0;i<N;i++)
			{
				naomi.add(sc.nextDouble());
			}
			for(int i=0;i<N;i++)
			{
				ken.add(sc.nextDouble());				
			}
			//System.out.println(naomi.toString());
			//System.out.println(ken.toString());
			//int normscore = normwarscore(naomi,ken);
			//int bestsofar = normscore;
			/*while(!naomi.isEmpty())
			{
				naomi.remove(naomi.first());
				ken.remove(ken.last());
				if(bestsofar<normwarscore(naomi,ken))
				{
					bestsofar = normwarscore(naomi,ken);
				}
			}*/
			System.out.println("Case #" + curcase + ": "+Dnormwarscore(naomi,ken)+" "+normwarscore(naomi,ken));
		}
	}
	
	public static int normwarscore(TreeSet<Double> nn,TreeSet<Double> kk)
	{
		TreeSet<Double> naomi = new TreeSet<Double>(nn);
		TreeSet<Double> ken = new TreeSet<Double>(kk);
		if(naomi.size()==0)
			return 0;
		Double botn = naomi.first();
		Double bestbeat = ken.ceiling(botn);
		if(bestbeat == null)
		{
			naomi.remove(botn);
			ken.remove(ken.first());
			return 1+normwarscore(naomi,ken);
		}else
		{
			naomi.remove(botn);
			ken.remove(bestbeat);
			return normwarscore(naomi,ken);
		}
	}
	
	public static int Dnormwarscore(TreeSet<Double> nn,TreeSet<Double> kk)
	{
		TreeSet<Double> naomi = new TreeSet<Double>(nn);
		TreeSet<Double> ken = new TreeSet<Double>(kk);
		if(naomi.size()==0)
			return 0;
		Double botn = naomi.first();
		Double botk = ken.first();
		if(botk>botn)
		{
			naomi.remove(botn);
			ken.remove(ken.last());
			return Dnormwarscore(naomi,ken);
		}else{
			naomi.remove(botn);
			ken.remove(botk);
			return 1+ Dnormwarscore(naomi,ken);
		}
			
	}
}
