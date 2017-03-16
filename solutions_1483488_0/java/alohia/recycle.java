import java.io.*;
class recycle
{
	public static void main(String args[])throws Exception
	{
		FileReader R=new FileReader("input.txt");
		BufferedReader ds=new BufferedReader(R);
		int n=Integer.parseInt(ds.readLine());
		for(int j=1;j<=n;j++)
		{
			int i;
			String l=ds.readLine();
			for(i=0;i<l.length();i++)
			{
				if(l.charAt(i)==' ')
					break;
			}
			int a=Integer.parseInt(l.substring(0,i));
			int b=Integer.parseInt(l.substring(i+1));
			int p=1,cnt=0;
			String x="",y="";
			for(i=a;i<=b;i++)
			{
				p=1;
				x=Integer.toString(i);
				y=x.substring(p)+x.substring(0,p);
				while(!(x.equals(y)))
				{
					if(Integer.parseInt(y)>Integer.parseInt(x) && Integer.parseInt(y)<=b)
						cnt++;
					p++;
					y=x.substring(p)+x.substring(0,p);
				}
			}
			System.out.println("Case #"+j+": "+cnt);
		}
	}
}