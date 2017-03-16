import java.util.*;
class Elf{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int T=in.nextInt();
		for(int t=1;t<=T;t++)
		{
			String s=in.next();
			String[] str=s.split("/");
			long p=Long.parseLong(str[0]);
			long q=Long.parseLong(str[1]);
			int ans=1;
			long a=p,b=q;
			while(2*a<b)
			{
				a=a*2;
				ans++;
			}
			if(check(p,q,0))
			System.out.println("Case #"+t+": "+ans);
			else
			System.out.println("Case #"+t+": impossible");
		}
	}
	public static boolean check(long a,long b,int count)
	{
		if(count>40)
		return false;
		if(a%b==0){
//			System.out.println(count);
			return true;
		}	
		int ans=1;
		while(2*a<b)
		{
			a=2*a;
			ans++;
		}
		return check((2*a)%b,b,count+ans);
	}
}
