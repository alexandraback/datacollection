import java.io.*;
import java.util.*;

public class C
{
	static int J,P,S,K;
	static int[][] jp,js,ps;
	
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int numRuns=in.nextInt();
		for (int run=1; run<=numRuns; run++)
		{
			J=in.nextInt();
			P=in.nextInt();
			S=in.nextInt();
			K=in.nextInt();
			
			int a=2, b=J*P*S;
			while (a<=b)
			{
				jp=new int[J+1][P];
				js=new int[J+1][S];
				ps=new int[P][S];
				int mid=(a+b)/2;
				if (recurse(0,0,0,mid)!=null)
					a=mid+1;
				else
					b=mid-1;
			}
			jp=new int[J+1][P];
			js=new int[J+1][S];
			ps=new int[P][S];
			System.out.printf("Case #%d: %d%n",run,a-1);
			System.out.print(recurse(0,0,0,a-1));
		}
	}
	
	static String recurse(int j,int p,int s,int steps)
	{
//for (int uu=-1; uu<steps; uu++) System.out.print("\t");System.out.println(j+" "+p+" "+s);
		if (steps==0)
			return "";
		if (j==J)
			return null;
		if ((J-j-1)*P*S+(P-p-1)*S+S-s<steps)
			return null;
		
		int sn=s+1;
		int pn=p+(sn/S);
		int jn=j+(pn/P);
		pn%=P;
		sn%=S;
		
		String sol=recurse(jn,pn,sn,steps);
		if (sol!=null)
			return sol;
		
		if (jp[j][p]<K && js[j][s]<K && ps[p][s]<K)
		{
			jp[j][p]++;
			js[j][s]++;
			ps[p][s]++;
			sol=recurse(jn,pn,sn,steps-1);
			if (sol!=null)
				return ""+(j+1)+" "+(p+1)+" "+(s+1)+"\n"+sol;
			jp[j][p]--;
			js[j][s]--;
			ps[p][s]--;
		}
		return null;
	}
}