import java.util.PriorityQueue;
import java.util.Scanner;


public class B 
{
	static class Entrada implements Comparable <Entrada>
	{
		int i, j;
		double valor;
		
		Entrada(int i, int j, double valor)
		{
			super();
			this.i = i;
			this.j = j;
			this.valor = valor;
		}

		@Override
		public int compareTo(Entrada o)
		{
			return Double.compare(valor, o.valor);
		}
		
	}
	
	static int[][] diffs = new int[][] {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i = 1; i <= t; i++)
		{
			System.out.print("Case #" + i + ": ");
			int h = sc.nextInt();
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[][] techo = new int[n][m];
			int[][] piso = new int[n][m];
			for(int j = 0; j < n; j++)
				for(int k = 0; k < m; k++)
					techo[j][k] = sc.nextInt();
			for(int j = 0; j < n; j++)
				for(int k = 0; k < m; k++)
					piso[j][k] = sc.nextInt();
			boolean[][] visitados = new boolean[n][m];
			double[][] mejor = new double[n][m];
			for(int j = 0; j < n; j++)
				for(int k = 0; k < m; k++)
					mejor[j][k] = Double.POSITIVE_INFINITY;
			mejor[0][0] = 0;
			PriorityQueue <Entrada> pq = new PriorityQueue <Entrada> ();
			pq.add(new Entrada(0, 0, 0));
			while(!pq.isEmpty())
			{
				Entrada actual = pq.poll();
				if(visitados[actual.i][actual.j] || mejor[actual.i][actual.j] != actual.valor)
					continue;
				visitados[actual.i][actual.j] = true;
				for(int[] d : diffs)
				{
					int iN = actual.i + d[0];
					int jN = actual.j + d[1];
					if(iN >= n || iN < 0 || jN >= m || jN < 0)
						continue;
					double hA = h - actual.valor * 10;
					if(piso[actual.i][actual.j] > techo[iN][jN] - 50 || piso[iN][jN] > techo[iN][jN] - 50)
						continue;
					if(piso[iN][jN] > techo[actual.i][actual.j] - 50)
						continue;
					double extra = hA > techo[iN][jN] - 50 ? ((hA - techo[iN][jN] + 50) / 10) : 0;
					if(hA > techo[iN][jN] - 50)
						hA = techo[iN][jN] - 50;
					if(actual.valor + extra == 0)
					{
						if(0 < mejor[iN][jN])
						{
							mejor[iN][jN] = 0;
							pq.add(new Entrada(iN, jN, 0));
						}
					}
					else
					{
						double nuevo = actual.valor + (hA - piso[actual.i][actual.j] >= 20 ? 1 : 10) + extra;
						if(nuevo < mejor[iN][jN])
						{
							mejor[iN][jN] = nuevo;
							pq.add(new Entrada(iN, jN, nuevo));
						}
					}
 				}
			}
			System.out.println(mejor[n - 1][m - 1]);
		}
	}

}
