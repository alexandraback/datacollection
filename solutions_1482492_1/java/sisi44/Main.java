import java.util.*;

public class Main{
	static boolean touche(double x1, double v1, double x2, double v2, double x3, double g)
	{
		if(x2>=x3)
			return false;
		double t = (x3-x2)/v2;
		double d = v1*t+0.5*g*t*t;
		if(d>=(x3-x1))
			return true;
		else
			return false;
	}
	static double timeToTouche(double x1, double v1, double x2, double v2, double x3, double g)
	{
		return (v2-v1)/g;
	}
	static double solve(double v, double g, double d)
	{
		return (-v+Math.sqrt(v*v+2*g*d))/g;
	}
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cc = 1; cc<=T; cc++)
		{
			double D = in.nextDouble();
			int N = in.nextInt();
			int A = in.nextInt();
			double t[] = new double[N];
			double x[] = new double[N];
			double v[] = new double[N];
			double g[] = new double[A];
			int K = -1;
			for(int i = 0; i<N; i++)
			{
				t[i] = in.nextDouble();
				x[i] = in.nextDouble();
				if(i>0)
					v[i-1] = (x[i]-x[i-1])/(t[i]-t[i-1]);
			}
			for(int i = 0; i<N; i++)
			{
				if(K==-1 && x[i]>=D-0.00000001)
					K = i;
			}
			if(K>0)
			{
				t[K] = (D-x[K-1])/v[K-1] +t[K-1];
				x[K] = D;
			}
			
			
			for(int i = 0; i<A; i++)
			{
				g[i] = in.nextDouble();
			}
			
			System.out.println("Case #"+cc+":");

			for(int i = 0; i<A; i++)
			{
				if(K>0)
				{
					double res[] = new double[K+1];
					double resF = 0;
					res[0] = 0;
					double xm = 0;
					double vm = 0;
					double xo = x[0];
					double vo = v[0];
					double x3 = x[1];
					for(int j = 1; j<K; j++)
					{
						if(!touche(xm, vm, xo, vo, x3, g[i]))
						{
							//System.out.println("notouche");
							double time = (x3-xo)/vo;
							res[j] = res[j-1]+time;
							xm = xm + vm*time+0.5*g[i]*time*time;
							vm = vm + g[i]*time;
							xo = x[j];
							vo = v[j];
							x3 = x[j+1];
						}
						else 
						{
							//System.out.println("touche");
							double t1 = timeToTouche(xm, vm, xo, vo, x3, g[i]);
							double time = (x3-xo)/vo;
							res[j] = res[j-1]+time;
							xm = x[j];
							vm = v[j-1];
							xo = x[j];
							vo = v[j];
							x3 = x[j+1];
						}
						//System.out.println("xm ="+xm+" vm ="+vm);
					}
					
					if(!touche(xm, vm, xo, vo, x3, g[i]))
					{
						//System.out.println("notouche");
						double time = (x3-xo)/vo;
						res[K] = res[K-1]+solve(vm, g[i], D-xm);
					}
					else 
					{
						//System.out.println("touche");
						double t1 = timeToTouche(xm, vm, xo, vo, x3, g[i]);
						double time = (x3-xo)/vo;
						res[K] = res[K-1]+time;
					}
					//System.out.println("xm ="+xm+" vm ="+vm+ " resK" +res[K]);
					//System.out.println(res[K]+"*+++" + xm +" "+ vm+" "+v[K-1]);
					if(xm >= D)
						resF = res[K];
					else
						resF = res[K];//+ solve(vm, g[i], D-xm);
					System.out.format("%.7f%n", resF);
				}
				else
				{
					System.out.format("%.7f%n", solve(0, g[i],D));
				}
			}
		}
	}
}