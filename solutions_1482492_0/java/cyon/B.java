import java.util.Arrays;
import java.util.Scanner;

public class B {

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int c = 1; c <= t; c++)
		{
			System.out.println("Case #" + c + ": " + solve(sc));
		}
	}
	
	private static String solve(Scanner sc)
	{
		double D=sc.nextDouble();
		int N=sc.nextInt();
		int A=sc.nextInt();
		
		double[]x=new double[N];
		double[]t=new double[N];
		
		double[]a=new double[A];
		
		for(int i=0;i<N;i++)
		{
			t[i]=sc.nextDouble();
			x[i]=sc.nextDouble();
		}
		for(int i=0;i<A;i++)
		{
			a[i]=sc.nextDouble();
		}
	
		StringBuilder sb=new StringBuilder();
		sb.append("\n");
		
		double v=0;
		if(N==1)
		{
			for(int i=0;i<A;i++)
			{
				double tres = Math.sqrt(D*2/a[i]);
				sb.append(tres + 1e-8);
				if(i!=A-1)
					sb.append("\n");
			}
			return sb.toString();
		}
		else
		{
			v = (x[1]-x[0])/(t[1]-t[0]);
		}
		
		for(int i=0;i<A;i++)
		{
			double dis = Math.sqrt(4*v*v + 8*x[0]*a[i]);
			double tt1 = (2*v + dis)/(2*a[i]);
			double tt2 = (2*v - dis)/(2*a[i]);
			
//			if(tt1 < 0 && tt2 < 0)
//				debug("WARN");
			
			double tm = Math.max(tt1, tt2);
			
			double xm = tm*v + x[0];
			
			if(xm > D)
			{
				double tres = Math.sqrt(D*2/a[i]);
				sb.append(tres + 1e-8);
			}
			else
			{
				//debug("here",v,tm,xm,D-xm, (D-x[0])/v);
				double tres = tm + (D-xm)/v;
				sb.append(tres + 1e-8);
			}
			if(i!=A-1)
				sb.append("\n");
		}
		
		return sb.toString();
	}

	static void debug(Object... objects)
	{
		System.out.println(Arrays.deepToString(objects));
	}

}