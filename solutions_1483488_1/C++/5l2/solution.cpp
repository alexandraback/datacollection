#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int  a, b, bits;
int  c[20];
void getbits()
{
	 int tmp=a;
	 bits=1;
	 while(tmp>0) tmp/=10, bits*=10;
}
int check(int  num)
{
	int  tmp=bits, ans=0, num1=num,i=0,j, flag=0;
	while(tmp>1)
	{
		num*=10;
		num= num/bits+num%bits;
		for(flag=j=0;j<i;++j)
		{
			if(c[j]==num) { flag=1; break;}
		}
		if(flag==0)
		{
			c[i++]=num;
			if(num>=a && num <=b && num1<num) ans++;
		}
		tmp/=10;
	}
	//if(ans) printf("%d: %d\n", num1, ans);
	return ans;

}
int main()
{
	int n,i,j,ans;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d\n",&n);
	for(i=1;i<=n;++i)
	{
		printf("Case #%d: ",i);
		scanf("%d%d",&a, &b);
		getbits();
		if(bits<=10) ans=0;
		else
		{
			for(ans=0,j=a;j<=b;++j)
			{
				ans+=check(j);
			}
		}
		printf("%d\n",ans);
	}

  /*
	for(i=0;i<26;++i)
	{
		printf("%c--->%c\n", i+'a', a[i]+'a');
	}
	*/
	return 0;
}