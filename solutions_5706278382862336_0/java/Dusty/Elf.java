import java.io.*;

public class Elf
{
	public static void main(String[] args) throws Exception
	{
		PrintWriter writer = new PrintWriter("output.txt","UTF-8");
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		int t= Integer.parseInt(br.readLine());
		for(int x = 0;x<t;x++)
		{
			String[] thingies = br.readLine().split("/");
			int P = Integer.parseInt(thingies[0]);
			int Q = Integer.parseInt(thingies[1]);
			int n = 40;
			String tbp = "";
			int its = 0;
			if(P==Q)
				tbp += 0;
			else if ((its =divby2(Q))==0)
			{
				tbp+="impossible";
			}
			else
			{
				System.out.println(its);
				tbp += (its-nearesttwo(P));
			}


			String out = "Case #"+(x+1)+": "+tbp;
			writer.println(out);
		}
		writer.close();
	}

		static int recurse(int p, int q, int depth, int max)
		{
			if(p==q)
			{
				return p;
			}
			return 0;
		}

		static int divby2(int n)
		{
			int its = 0;
			while(n!=1)
			{
				if(n%2!=0)
					return 0;
				n = n/2;
				its++;
			}
			return its;
		}

		static int nearesttwo(int n)
		{
			int pow = 2;
			for(int x = 1;x<n;x++)
			{
				if(pow==n)
					return x;
				else if(pow>n)
					return x-1;
				pow*=2;
			}
			return 0;
		}
}