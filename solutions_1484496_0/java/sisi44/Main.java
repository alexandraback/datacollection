import java.util.*;

class MyList extends TreeSet<Integer>{
	
}
public class Main{
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cc = 1; cc<=T; cc++)
		{
			int N = in.nextInt();
			int[] t = new int[N];
			int[] tt = new int[2*N];
			int max = 0;
			int somme = 0;
			for(int i = 0; i<N; i++)
			{
				t[i] = in.nextInt();
				tt[i] = t[i];
				if(t[i]>max) max = t[i];
				somme += t[i];
			}
			Arrays.sort(t);
			int R = somme+1;
			boolean etat[] = new boolean[R*2];
			MyList l[] = new MyList[R*2];
			MyList res = new MyList();
			boolean fin = false;
			find:
			for(int i= 0; i<N;i++)
			{
				for(int j = t[i]; j<R*2-t[i]; j++)
				{
					
					if(etat[j])
					{
						if(j+t[i] == R && l[j]!= null)
						{
							//System.out.println(t[i]+" sqf");
							res = (MyList)l[j].clone();

							res.add(t[i]);
							//System.out.println(t[i]+" sqf");
							fin = true;
							break find;
						}
						else if(j-t[i] == R && l[j]!= null)
						{
							res = (MyList)l[j].clone();
							res.add(-t[i]);
							//System.out.println(t[i]+" sssqf" + j+ " "+ (j-t[i])+ " "+R);
							fin = true;
							break find;
						}
						if(!etat[j+t[i]]&& l[j]!= null)
						{
							MyList ml = (MyList)l[j].clone();
							ml.add(t[i]);
							l[j+t[i]] = ml;
						}
						if(!etat[j-t[i]]&& l[j]!= null)
						{
							MyList mll = (MyList)l[j].clone();
							mll.add(-t[i]);
							l[j-t[i]] = mll;
						}
					}
				}
				if(!etat[R+t[i]])
				{
					l[R+t[i]] = new MyList();
					l[R+t[i]].add(t[i]);
				}
				if(!etat[R-t[i]])
				{
					l[R-t[i]] = new MyList();
					l[R-t[i]].add(-t[i]);
				}
				for(int j = t[i]; j<R*2-t[i]; j++)
				{
					if(etat[j])
					{
						etat[j+t[i]] =true;
						etat[j-t[i]] =true;
					}
				}
				etat[R+t[i]] = true;
				etat[R-t[i]] = true;

			}
			System.out.println("Case #"+cc+":");
			if(!fin)
			{
				System.out.println("Impossible");
			}
			else
			{
				for(int i: res)
				{
					if(i>0)
					System.out.print(i+" ");
				}
				System.out.println();
				for(int i: res)
				{
					if(i<0)
					System.out.print(-i+" ");
				}
				System.out.println();
			}
			
		}
	}
}