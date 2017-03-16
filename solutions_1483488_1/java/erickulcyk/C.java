package c;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {

	Set<Integer>[] c = new HashSet[2000001];

	public C()
	{
		Scanner s = new Scanner(System.in);

		int t = s.nextInt();

		for(int i =0; i < t;i ++)
		{
			int a = s.nextInt();
			int b = s.nextInt();

			for(int j = a; j <=b; j++)
			{
				c[j]= new HashSet<Integer>();
			}

			int digits = (a+"").toCharArray().length;

			for(int j = Math.min(a, b); j<=Math.max(a, b); j++)
			{
				int newJ = j;

				for(int k = 1; k < digits; k++)
				{
					int dig = newJ%10;
					newJ = newJ/10;
					newJ += dig*Math.pow(10, digits-1);


					if(newJ>=a && newJ<=b && newJ!=j)
					{
						int min = Math.min(newJ, j);
						int max = Math.max(newJ, j);
						c[min].add(max);
						//System.out.println(j+" "+min+" "+max);
					}
				}
			}
			
			long tot = 0;
			
			for(int j = a; j <=b; j++)
			{
				tot+=c[j].size();
			}
			
			System.out.println("Case #"+(i+1)+": "+tot);
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new C();

	}

}
