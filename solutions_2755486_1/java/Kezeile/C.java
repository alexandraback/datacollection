import java.util.*;

public class C
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();
		for(int kk = 1; kk<=tt;kk++)
		{
			int tribes = sc.nextInt();
			int[][] arr = new int[tribes][8];
			sc.nextLine();
			Map<String, Integer> map = new HashMap<String,Integer>();
			for(int i=0; i<tribes;i++)
			{
				String[] xx = sc.nextLine().split(" ");
				for(int j = 0; j< 8; j++)
					arr[i][j] = Integer.parseInt(xx[j]);
			}
			int pinakaleft = 0;
			int pinakaright = 0;
			/*for(int i = 0; i<tribes;i++)
			{
				int left = arr[i][2] + ((arr[i][1]-1)*arr[i][6]);
				int right = arr[i][3] + ((arr[i][1]-1)*arr[i][6]);
				if(pinakaright<right)
					pinakaright = right;
				if(pinakaleft>left)
					pinakaleft = left;
			}*/
			ArrayList<Attack> list = new ArrayList<Attack>();
			for(int i=0; i<tribes;i++)
			{
				for(int j = 0 ; j< arr[i][1];j++)
				{
					int l = arr[i][2] + (j*arr[i][6]);
					int r = arr[i][3] + (j*arr[i][6]);
					int s = arr[i][4] + (j*arr[i][7]);
					int d = arr[i][0] + (j*arr[i][5]);
					if(pinakaleft > l)
						pinakaleft = l;
					if(pinakaright < r)
						pinakaright = r;
					Attack temp = new Attack(l,r,s,d);
					list.add(temp);
				}
			}
			//System.out.println(pinakaleft+" "+pinakaright);
			for(int i = pinakaleft - 1; i<=pinakaright;i++)
			{
				String x = i+"-"+(i+1);
				map.put(x, 0);
			}
			//int prevDate = -1;
			int success = 0;
			Collections.sort(list);
			ArrayList<String> key = new ArrayList<String>();
			ArrayList<Integer> value = new ArrayList<Integer>();
			ArrayList<Integer> dates = new ArrayList<Integer>();
			for(int i=0; i<list.size();i++)
			{
				Attack dummy = list.get(i);
				dates.add(dummy.date);
			}
			dates.add(dates.get(list.size() - 1) + 1);
			for(int i= 0; i < list.size();i++)
			{
				Attack dummy = list.get(i);
				int nextDate = dates.get(i+1);
				boolean good = false;
				for(int j = dummy.left; j<dummy.right; j++)
				{
					String x = j+"-"+(j+1);
					//System.out.println(x);
					if(map.get(x) < dummy.strength)
					{
						good = true;
						key.add(x);
						value.add(dummy.strength);
					}
				}
				if(good)
				{
					success++;
				}
					//System.out.println(i+" "+dummy.strength+" "+good+" "+dummy.date+" "+nextDate);
				if(dummy.date < nextDate)
				{
					while(key.size() > 0)
					{
						String aaa = key.remove(0);
						int bbb = value.remove(0);
						int var = map.get(aaa);
						if(bbb>var)
							map.put(aaa, bbb); // update map
					}
				}
				//prevDate = dummy.date;
			}
			//int success = 0;
			System.out.printf("Case #%d: %d\n", kk, success);
		}	
	}
}
class Attack implements Comparable<Attack>
{
	int left, right, strength, date;
	public Attack(int l, int r, int s, int d)
	{
		left = l;
		right = r;
		strength = s;
		date = d;
	}
	public int compareTo(Attack e)
	{
		return this.date - e.date;
	}
}