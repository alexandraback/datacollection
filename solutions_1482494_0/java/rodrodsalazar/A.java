import java.util.*;

class A
{
	public static class L implements Comparable<L>
	{
		int a,b;
		L(int _,int __)
		{
			a = _;
			b = __;
		}
		public int compareTo(L o) {
			if(this.a < o.a)
				return -1;
			if(this.a > o.a)
				return 1;
			if(this.b < o.b)
				return -1;
			if(this.b > o.b)
				return 1;
			return 0;
		}
	}

	public static void main(String[] args)
	{
		int t;
		Scanner in = new Scanner(System.in);
		t = in.nextInt();
		bigloop: for(int casen = 1; casen <=t;++casen)
		{
			int n = in.nextInt();
			int onestars [] = new int[n];
			int twostars [] = new int[n];
			L stars [] = new L[n];
			
			HashSet<Integer> levels = new HashSet<Integer>();
			for(int i=0;i<n;++i)
			{
				int a,b;
				a= in.nextInt();
				b = in.nextInt();
				stars[i] = new L(a,b);
				levels.add(i);
			}
			Arrays.sort(stars);
			for(int i=0;i<stars.length;++i)
			{
				L curr = stars[i];
				onestars[i] = curr.a;
				twostars[i] = curr.b;
			}
			
			int currstars = 0;
			int beats = 0;
			while(levels.size() > 0)
			{
				int maxstars = -1;
				int maxarg = -1;
				int lowerscore = 0;
				
				for(int i=0;i<n;++i)
				{
					if(onestars[i] != -1 && twostars[i] != -1 && twostars[i] <= currstars)
					{
						maxstars = 2;
						maxarg = i;
						break;
					}
				}
				
				if(maxstars == -1)
				{
					for(int i=0;i<n;++i)
					{
						if(onestars[i] == -1 && twostars[i] != -1 && twostars[i] <= currstars)
						{
							maxstars = 2;
							maxarg = i;
							lowerscore = 1;
							break;
						}
					}
				}
				
				if(maxstars == -1)
				{
					for(int i=0;i<n;++i)
					{
						if(onestars[i] != -1 && onestars[i] <= currstars)
						{
							if(maxarg == -1 || twostars[i] > twostars[maxarg]) 
							{
								maxstars = 1;
								maxarg = i;
							}
						}
					}
				}
				
				if(maxarg == -1)
				{
					System.out.println("Case #" + casen + ": Too Bad");
					continue bigloop;
				}
				
				currstars += maxstars;
				currstars -= lowerscore;
				beats++;
				if(maxstars == 2)
				{
					twostars[maxarg] = -1;
					onestars[maxarg] = -1;
					levels.remove(maxarg);
					//System.out.println("Did level " + maxarg + ", 2 star level (now @ " + currstars );
				}
				else if(maxstars == 1)
				{
					onestars[maxarg] = -1;
					//System.out.println("Did level " + maxarg + ", 1 star level (now @ " + currstars ) ;
				}
			}
			System.out.println("Case #" + casen + ": " + beats);
		}	
	}
}
