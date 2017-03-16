import java.io.*;
import java.util.*;

class A
{
	public static void main(String[] args) 
	{
		try
		{
			BufferedReader br = new BufferedReader(new FileReader("A-small-attempt1.in"));
			PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt1.out"));
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

				int Z = 0;
				double ZS = 0;
				for(int j=0; j<N; j++) {
					P[j] = 100*((2.0/N) - (J[j]/S));
					if(P[j] < 0) {
						ZS -= P[j];
						P[j] = 0;
						Z++;
					}
				}

				for(int j=0; j<N; j++)
					if(P[j] > 0)
						P[j] -= ZS/(N-Z);

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
