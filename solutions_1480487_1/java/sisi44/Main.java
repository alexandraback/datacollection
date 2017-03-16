import java.util.*;

class Player implements Comparable<Player>{
	int s;
	int indice;
	Player(int  a, int b)
	{
		s = a;
		indice = b;
	}
	@Override
	public int compareTo(Player o) {
		// TODO Auto-generated method stub
		return s-o.s;
	}
	
}

public class Main{
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cc = 1; cc<=T;cc++)
		{
			int N = in.nextInt();
			Player[] P = new Player[N];
			int somme =0;
			for(int i = 0;i<N; i++)
			{
				int a = in.nextInt();
				P[i] = new Player(a, i);
				somme+= a;
			}
			double[] res = new double[N];
			Arrays.fill(res, 100.0);
			Arrays.sort(P);
			for(int i= 0; i<N; i++)
			{
				int niveau = 0;
				int C = 0;
				for(int j = 0; j<N; j++)
				{
					if(j!= i)
					{
						niveau ++;
						C += P[j].s;
						double resC = ((double)(C+somme)/(double)(niveau)-P[i].s)
						/((double)somme+(double)somme/(double)niveau);
						double resCF = resC*100.0;
						if(resCF <res[P[i].indice])
						{
							if(resCF>0)
								res[P[i].indice] = resCF;
							else
								res[P[i].indice] = 0.;
						}
					}
				}
			}
			System.out.print("Case #"+cc+":");
			for(int i = 0; i<N; i++)
			{
				System.out.format(" %.7f", res[i]);
			}
			System.out.println();
		}
	}
}