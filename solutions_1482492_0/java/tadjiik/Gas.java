import java.util.*;

public class Gas {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();
		for(int ii = 1; ii <= tt; ii++)
		{
			System.out.println("Case #" + ii + ":" );
			double d = sc.nextDouble();
			int n = sc.nextInt();
			int A = sc.nextInt();
			
			double ts[] = new double[n];
			double ps[] = new double[n];
			for(int i = 0; i < n; i++)
			{
				ts[i] = sc.nextDouble();
				ps[i] = sc.nextDouble();
				if(ps[i] > d)
				{
					if(i != 0)
					{
						ts[i] = ts[i-1] + (ts[i]-ts[i-1])*((ps[i]-d)/(ps[i]-ps[i-1]));
					}
					
					ps[i] = d;
				}
			}
			
			double currpos = 0.0;
			double currv = 0.0;
			
			for(int k = 0; k < A; k++)
			{
				double a = sc.nextDouble();
				for(int i = 1; i < n; i++)
				{
					double t = ts[i] - ts[i-1];
					double s = ps[i] - ps[i-1];
					double try_v = (s - (0.5*a*t*t))/t;
					
					
					if(try_v > currv)
					{
						currpos += (0.5*a*t*t)+(currv*t);
						currv += (t*a);
					} else if(try_v > 0)
					{
						currpos = ps[i];
						currv = try_v + (t*a);
					} else 
					{
						currpos = ps[i];
						double acct = Math.sqrt((2*s)/a);
						currv = acct*a;
					}					
				}
				double final_t = ts[n-1]; 
				// Last distance
				{
		
					double s = d - currpos;
					double t = (Math.sqrt((currv*currv)+(2*a*s))-currv)/a;
					final_t += t;
				}
				System.out.println(final_t);
			}
			
		}
	}

}
