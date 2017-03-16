import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;


public class Prob1 
{

	public String in = "";
	
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		
		int numCases = sc.nextInt();
		
		for(int i = 0; i < numCases; i++)
		{
			int numLevels = sc.nextInt();
			//Star[] levs = new Star[numLevels];
			Star[] levs2 = new Star[numLevels];
			for(int j = 0; j < numLevels; j++)
			{
				Star curr = new Star();
				curr.one = sc.nextInt();
				curr.two = sc.nextInt();
				//levs[j] = curr;
				levs2[j] = curr;
			}
			
			/*
			Arrays.sort(levs, new Comparator<Star>() {

				@Override
				public int compare(Star o1, Star o2) {
					return (5000*o1.one - o1.two) - (5000*o2.one - o2.two);
				}
				
			});
			*/
			
			Arrays.sort(levs2, new Comparator<Star>() {

				@Override
				public int compare(Star o1, Star o2) {
					return o1.two - o2.two;
				}
				
			});
			
			
			//int l1=0;
			int l2=0;
			int turn = 0;
			int stars = 0;
			boolean fail = false;
			boolean g = false;
			
			while(true)
			{
				g = false;
				if(l2 >= numLevels )
				{
					break;
				}
				if(stars >= levs2[l2].two)
				{
					if(!levs2[l2].done2)
					{ 
						if(!levs2[l2].done){ stars += 2; }
						else { stars += 1; }
						levs2[l2].done = true;
						levs2[l2].done2 = true;
						turn++;
					}
					l2++;
					continue;
				}
				for(int p = numLevels-1; p >= 0; p--)
				{
					if(levs2[p].done){ continue; }
					if(stars >= levs2[p].one)
					{
						stars += 1;
						levs2[p].done = true;
						turn++;
						g = true;
						break;
					}
				}
				if(!g)
				{
					fail = true;
					break;
				}
					/*
					if(!levs[l1].done && !levs[l1].done2)
					{
						stars += 1;
						levs[l1].done = true;
						turn++;
					}
					*/
					//l1++;

			}
			
			String out = "Case #" + (i+1) + ": ";
			if(fail){ out += "Too Bad"; }
			else{ out += turn; }
			
			System.out.println(out);
			
		}
		
	}

}

class Star
{
	public int one;
	public int two;
	public boolean done = false;
	public boolean done2 = false;
}
