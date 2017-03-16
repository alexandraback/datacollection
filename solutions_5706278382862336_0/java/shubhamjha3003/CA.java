import java.io.*;
class CA
{
	public static long computeGCD(long a,long b)
	{
		if(b==0)
			return a;
		else
			return computeGCD(b,a%b);
	}	
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));	
		int t=Integer.parseInt(br.readLine());
		String str;
		String[] data;
		long a,b,temp;
		int i,count;
		for(i=1;i<=t;i++)
		{
			str=br.readLine();
			count=0;
			data=str.split("/");
			a=Long.parseLong(data[0]);
			b=Long.parseLong(data[1]);	
			temp=computeGCD(a,b);			
			a/=temp;
			b/=temp;
			System.out.print("Case #"+i+": ");
			if(a>b)
			{
				System.out.print("impossible");	
			}
			else
			{
				temp=b;
				while(temp%2==0)
				{
					temp/=2;
				}			
				if(temp!=1)
				{
					System.out.print("impossible");			
				}
				else
				{
					count=0;
					temp=1;
					while(a*temp-b<0)
					{
						temp*=2;
						count++;	
					}
					System.out.print(count);
				}
			}
			System.out.println();
		}
	}
}