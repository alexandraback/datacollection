import java.util.*;
import java.math.*;
public class Main
{
	static Scanner cin = new Scanner(System.in);
	public static void main(String[] args)
	{
		//预处理素数
		int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
		BigInteger Prime[] =new BigInteger[26];
		for(int i=0;i<26;++i)Prime[i]=BigInteger.valueOf(prime[i]);
		//预处理幂次
		BigInteger v0=BigInteger.valueOf(0);
		BigInteger v1=BigInteger.valueOf(1);
		BigInteger pow[][]=new BigInteger [12][32];
		for(int i=2;i<=10;++i)
		{
			pow[i][0]=v1;
			for(int j=1;j<32;++j)pow[i][j]=pow[i][j-1].multiply(BigInteger.valueOf(i));
		}
		//solve
		int a[]=new int[32];
		int ans[]=new int[12];
		int n=16;
		int m=50;
		int cnt=0;
		for(int sta=1;;sta+=2)
		{
			int len=0;
			for(int tmp=sta;tmp>0;tmp>>=1)a[len++]=tmp&1;
			boolean ok=true;
			for(int i=2;i<=10;++i)
			{
				BigInteger bas=pow[i][n-1];
				for(int p=0;p<len;++p)if(a[p]==1)bas=bas.add(pow[i][p]);
				boolean flag=false;
				for(int j=0;j<26;++j)
				{
					if(bas.mod(Prime[j])==v0)
					{
						ans[i]=prime[j];
						flag=true;
						break;
					}
				}
				if(!flag)
				{
					ok=false;
					break;
				}
			}
			if(ok)
			{
				System.out.print("1");
				for(int i=n-2;i>=len;--i)System.out.print("0");
				for(int i=len-1;i>=0;--i)System.out.print(a[i]);
				for(int i=2;i<=10;++i)System.out.print(" "+ans[i]);
				System.out.println();
				if(++cnt==m)break;
			}
		}
		//System.out.println(cnt);
	}
}
/**/