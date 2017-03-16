import java.io.*;
import java.util.*;

class B
{
	public static void main(String[] args) 
	{
		try
		{
			BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
			PrintWriter pw = new PrintWriter(new FileWriter("B-small-attempt0.out"));
			int T = Integer.parseInt(br.readLine());

			for(int i=0; i<T; i++)
			{
				String[] line = br.readLine().split(" ");
				double D = Double.parseDouble(line[0]);
				int N = Integer.parseInt(line[1]);
				int A = Integer.parseInt(line[2]);

				double[] t = new double[N];
				double[] x = new double[N];

				for(int j=0; j<N; j++) {
					line = br.readLine().split(" ");
					t[j] = Double.parseDouble(line[0]);
					x[j] = Double.parseDouble(line[1]);
				}

				pw.printf("Case #%d:\n", i+1);

				line = br.readLine().split(" ");
				for(int j=0; j<A; j++) {
					double a = Double.parseDouble(line[j]);
					double s = 0;
					double p = 0;
					double v = 0;

					for(int k=1; k<N && p<D; k++) {
						double tx = t[k]-t[k-1];
						double dx = (k==1 ? x[k] : x[k]-x[k-1]);

						double dh = D-p;
						double dc = x[k]-p;
						double dt = v*tx + 0.5*a*Math.pow(tx, 2);

						if(dt <= dh && dt <= dc) {
							p += dt;
							s += tx;
							v = v + a*tx; 
						} else if(dt > dh && dh <= dc) {
							p += dh;
							s += Math.max(tx*dh/dx, (-v + Math.pow(Math.pow(v, 2) + 2*a*dh, .5))/a);
							v = dx/tx;
						} else {
							p += dc;
							s += tx;
							v = (-v + Math.pow(Math.pow(v, 2) + 2*a*dc, .5))/a;
						}

					}

					if(p < D)
						s += (-v + Math.pow(Math.pow(v, 2) + 2*a*(D-p), .5))/a;

					pw.printf("%f\n", s);
				}
				pw.flush();
			}
		}
		catch(Exception e)
		{ 
			e.printStackTrace();
		}
	}
}
