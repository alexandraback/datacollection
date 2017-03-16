import java.util.*;

class Liste extends ArrayList<Integer>{
	
}
public class Main{
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cc = 1; cc<=T; cc++)
		{
			int N = in.nextInt();
			boolean hasFather[] = new boolean[N];
			Liste l[] = new Liste[N];
			int deja[] = new int[N];
			Arrays.fill(hasFather, false);
			Arrays.fill(deja, 0);
			for(int i = 0; i<N; i++)
			{
				int Mi = in.nextInt();
				l[i] = new Liste();
				for(int j = 0; j<Mi; j++)
				{
					int a = in.nextInt();
					l[i].add(a-1);
					hasFather[a-1] = true;
				}
			}
			boolean fin = false;
			find:
			for(int i = 0; i<N; i++)
			{
				if(!hasFather[i])
				{
					Arrays.fill(deja, -1);
					Stack<Integer> Q = new Stack<Integer>();
					Q.add(i);
					while(!Q.isEmpty())
					{
						int v = Q.pop();
						if(deja[v] > 0)
						{
							fin = true;
							break find;
						}
						
						deja[v] = 1;
						for(Integer u: l[v])
						{
							Q.add(u);
						}
					}
				}
			}
			if(fin)
				System.out.println("Case #"+cc+": "+"Yes");
			else
				System.out.println("Case #"+cc+": "+"No");
		}
	}
}