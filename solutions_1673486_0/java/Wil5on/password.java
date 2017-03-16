import java.io.*;
import java.util.*;
import java.text.*;

class password
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader r=new BufferedReader(new InputStreamReader(System.in));
		String inp;
		int i,j;
		DecimalFormat df = new DecimalFormat("#.000000");
				
		int T=Integer.valueOf(r.readLine());
		for(int a=0;a<T;a++)
		{
			String[] tmp =r.readLine().split("\\s");
			int A = Integer.valueOf(tmp[0]);
			int B = Integer.valueOf(tmp[1]);
			
			tmp =r.readLine().split("\\s");
			double[] p = new double[A];
			for (i=0;i<A;i++) {
				p[i] = Double.valueOf(tmp[i]);
			}
			
			double d = B+2; //degenerate, retype
			double pr = 1.0;
			for (int bs=0;bs<=A;bs++) {//backspace to bs
				double ev = (2*(A-bs))+(B-A)+1+((1.0-pr)*(B+1));   //(A-bs) + 1 + (pr * (B-((A-bs)+1))) + ((1.0-pr) * ((B-((A-bs)+1))+(B+2)));
				if(bs<A) pr = pr * p[bs];
				if(ev<d) d=ev;
			}

			System.out.println("Case #"+(a+1)+": "+df.format(d));
		}
	}
}
