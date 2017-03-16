import java.util.*;

class Pair implements Comparable<Pair>{
	int debut;
	int l;
	int indice;
	int debut2;
	Pair(int a, int b, int c, int d)
	{
		debut = a;
		l = b;
		indice = c;
		debut2 = d;
	}
	@Override
	public int compareTo(Pair o) {
		// TODO Auto-generated method stub
		if(debut != o.debut)
			return debut - o.debut;
		else if(o.l != l)
			return o.l-l;
		else if(o.debut2 != debut2)
			return o.debut2 - debut2;
		else
			return indice - o.indice;
		
	}
	
}

public class Main{
	static int[] L1;
	static int[] L2;
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cc = 1; cc<= T; cc++)
		{
			int N = in.nextInt();
			TreeSet<Pair> t = new TreeSet<Pair>();
			L1 = new int[N];
			L2 = new int[N];
			for(int i = 0; i< N; i++)
			{
				int a = in.nextInt();
				int b = in.nextInt();
				t.add(new Pair(a, 1, i, b));
				t.add(new Pair(b, 2, i, a));
				L1[i] = a;
				L2[i] = b;
			}
			boolean l[] = new boolean[N];
			Arrays.fill(l, false);
			int step = 0;
			int debut = 0;
			boolean possible = true;
			while(!t.isEmpty())
			{
				int k = debut;
				SortedSet<Pair> s1 = t.subSet(new Pair(0, 3, 0, 0), new Pair(k+1, 3, 0,0));
				boolean change = false;
				Pair toCh = new Pair(0, 0 , 0,0);
				for(Pair p : s1)
				{
					if(p.l == 2)
					{
						change = true;
						toCh = p;
					}		
				}
				if(change)
				{
					if(toCh.l == 2 && !l[toCh.indice])
					{
						debut += 2;
						t.remove(new Pair(L1[toCh.indice], 1, toCh.indice, L2[toCh.indice]));
						t.remove(toCh);
						l[toCh.indice] = true;
						step ++;
						//System.out.println(toCh.indice +" " + 2 +"change");
					}
					else // p.l == 2 && l[p.indice]
					{
						debut += 1;
						t.remove(toCh);
						step ++;
						//System.out.println(toCh.indice +" " + 2 +"change" );
					}
				}
				else
				{
					
					SortedSet<Pair> s = t.subSet(new Pair(k, 3, 0,0), new Pair(k+1, 3, 0, 0));
					while(k>0 && s.isEmpty())
					{
						k--;
						s = t.subSet(new Pair(k, 3, 0,0), new Pair(k+1, 3, 0,0));
					}
					if(s.isEmpty())
					{
						possible = false;
						//System.out.println(k);
						break;
					}
					else
					{
						Pair p = s.first();
						if(p.l == 1 && !l[p.indice])
						{
							debut += 1;
							t.remove(p);
							l[p.indice] = true;
							step ++;
							//System.out.println(p.indice +" " + 1);
						}
						else if(p.l == 2 && !l[p.indice])
						{
							debut += 2;
							t.remove(new Pair(L1[p.indice], 1, p.indice, L2[p.indice]));
							t.remove(p);
							l[p.indice] = true;
							step ++;
							//System.out.println(p.indice +" " + 2 + "false");
						}
						else // p.l == 2 && l[p.indice]
						{
							debut += 1;
							t.remove(p);
							l[p.indice] = true;
							step ++;
							//System.out.println(p.indice +" " + 2 + "true");
						}
					}
				}
			}
			if(!possible)
				System.out.println("Case #"+cc+": Too Bad");
			else 
				System.out.println("Case #"+cc+": "+step);
		}
	}
}