import java.io.*;
import java.util.*;

class A
{
	public static void main(String[] args) 
	{
		try
		{
			BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
			PrintWriter pw = new PrintWriter(new FileWriter("A-large.out"));
			int T = Integer.parseInt(br.readLine());

			for(int i=0; i<T; i++)
			{
				String[] line = br.readLine().split(" ");
				int N = Integer.parseInt(line[0]);
				int S = 0;

				double[] J = new double[N];
				double[] P = new double[N];
				for(int j=0; j<N; j++) {
					J[j] = Integer.parseInt(line[j+1]);
					S += J[j];
				}

				for(int j=0; j<N; j++)
					P[j] = 100*((2.0/N) - (J[j]/S));

				int Z = 0;
				do {
					Z = 0;
					double ZS = 0;
					for(int j=0; j<N; j++)
						if(P[j] < 0) {
							ZS -= P[j];
							P[j] = 0;
							Z++;
						}

					for(int j=0; j<N; j++)
						if(P[j] > 0)
							P[j] -= ZS/(N-Z);
				}
				while (Z > 0);
				

				pw.printf("Case #%d:", i+1);
				for(int j=0; j<N; j++) {
					pw.printf(" %f", P[j]);
				}
				pw.printf("\n");
				pw.flush();
			}
		}
		catch(Exception e)
		{ 
			e.printStackTrace();
		}
	}
}
