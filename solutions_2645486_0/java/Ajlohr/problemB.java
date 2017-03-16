import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;


public class problemB {
public static void main(String[] args)
{
	Scanner sc = new Scanner(System.in);
	int numcases = sc.nextInt();
	for(int casenum = 1;casenum<=numcases;casenum++)
	{
		int E = sc.nextInt();
		int R = sc.nextInt();
		int N = sc.nextInt();
		sc.nextLine();
		int[] vals = new int[N];
		int[] nextHigher = new int[N];
		TreeMap<Integer,Integer> looking = new TreeMap<Integer,Integer>();

		for(int i=0;i<N;i++)
		{
			vals[i] = sc.nextInt();
			while(looking.floorEntry(vals[i])!=null)
			{
				int ii = looking.floorEntry(vals[i]).getKey();
				nextHigher[looking.get(ii)] = i;
				looking.remove(ii);
			}
			looking.put(vals[i],i);
		}
		for(int k : looking.keySet())
		{
			nextHigher[looking.get(k)] = Integer.MAX_VALUE;
		}
		long energy = E;
		long value = 0;
		for(int i=0;i<N;i++)
		{
			long spent = -1;
			if(nextHigher[i] ==Integer.MAX_VALUE)
				spent = energy;
			else
			 spent = Math.min(energy+ R*(nextHigher[i] - i)- E,energy);
			if(spent <0)
				spent = 0;
			energy -=spent;
			assert (energy >=0);
			value+= spent * vals[i];
			energy +=R;
		}
		System.out.println("Case #"+casenum+": "+value);
		
		
		
		
	}
}
	
}
