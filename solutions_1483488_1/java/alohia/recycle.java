import java.io.*;
class recycle
{
	public static void main(String args[])throws Exception
	{
		FileReader R=new FileReader("input.txt");
		PrintWriter W=new PrintWriter(new FileWriter("output.txt"));
		BufferedReader ds=new BufferedReader(R);
		long n=Long.parseLong(ds.readLine());
		for(long j=1;j<=n;j++)
		{
			long i;
			String l=ds.readLine();
			for(i=0;i<l.length();i++)
			{
				if(l.charAt((int)i)==' ')
					break;
			}
			long a=Long.parseLong(l.substring(0,(int)i));
			long b=Long.parseLong(l.substring((int)i+1));
			long p=1,cnt=0;
			String x="",y="";
			for(i=a;i<=b;i++)
			{
				p=1;
				x=Long.toString(i);
				y=x.substring((int)p)+x.substring(0,(int)p);
				while(!(x.equals(y)))
				{
					if(Long.parseLong(y)>Long.parseLong(x) && Long.parseLong(y)<=b)
						cnt++;
					p++;
					y=x.substring((int)p)+x.substring(0,(int)p);
				}
			}
			W.println("Case #"+j+": "+cnt);
		}
		W.close();
	}
}