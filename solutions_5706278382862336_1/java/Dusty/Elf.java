import java.io.*;

public class Elf
{
	public static void main(String[] args) throws Exception
	{
		PrintWriter writer = new PrintWriter("output.txt","UTF-8");
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		int t= Integer.parseInt(br.readLine());
		for(long x = 0;x<t;x++)
		{
			String[] thingies = br.readLine().split("/");
			long P = Long.parseLong(thingies[0]);
			long Q = Long.parseLong(thingies[1]);
			long n = 40;
			String tbp = "";
			long its = 0;

			long redu = reduceE(P,Q);
			P = P/redu;
			Q = Q/redu;

			if(P==Q)
				tbp += 0;
			else if ((its =divby2(Q))==0)
			{
				tbp+="impossible";
			}
			else
			{
				long temp = nearesttwo(P);
				if(its-temp>40)
					tbp+= "impossible";
				else
					tbp += (its-temp);
			}


			String out = "Case #"+(x+1)+": "+tbp;
			writer.println(out);
		}
		writer.close();
	}

		static long divby2(long n)
		{
			long its = 0;
			while(n!=1)
			{
				if(n%2!=0)
					return 0;
				n = n/2;
				its++;
			}
			return its;
		}

		static long nearesttwo(long n)
		{
			long pow = 2;
			for(long x = 1;x<n;x++)
			{
				if(pow==n)
					return x;
				else if(pow>n)
					return x-1;
				pow*=2;
			}
			return 0;
		}

		static long reduceE(long p, long q)
		{
			while(p>0)
			{
				long temp = p;
				p = q%p;
				q = temp;
			}
			return q;
		}
}