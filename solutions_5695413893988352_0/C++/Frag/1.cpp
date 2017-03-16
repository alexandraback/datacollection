#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
string a1;
string a2;
string lt1;
string lt2;
string lt3;
string lt4;
int ans=1234567890;
int Abs()
{
	int a=0,b=0;
	for(int i=0;i<lt1.length();i++)
	{
		a=a*10+lt1[i]-'0';
		b=b*10+lt2[i]-'0';
	}
	return abs(double(a-b));
}
void Doit(int n)
{
	if(lt1=="797"||lt1=="798")
	{
		n++;
		n--;
	}
	if(n==lt1.length())
	{
		int lt=Abs();
		if(lt<ans)
		{
			ans=lt;
			a1=lt1;
			a2=lt2;
		}
		else if(lt==ans)
		{
			if(lt1<a1)
			{
				a1=lt1;
				a2=lt2;
			}
			else if(lt1==a1)
			{
				if(lt2<a2)
				{
					a1=lt1;
					a2=lt2;
				}
			}
		}
		return ;
	}
	if(lt3[n]=='?'&&lt4[n]=='?')
	{
		for(int i=0;i<=9;i++)
			for(int j=0;j<=9;j++)
			{
				lt1[n]=i+'0';
				lt2[n]=j+'0';
				Doit(n+1);
			}
	}
	else if(lt3[n]=='?')
	{
		for(int j=0;j<=9;j++)
		{
			lt1[n]=j+'0';
			Doit(n+1);
		}
	}
	else if(lt4[n]=='?')
	{
		for(int j=0;j<=9;j++)
		{
			lt2[n]=j+'0';
			Doit(n+1);
		}
	}
	else 
		Doit(n+1);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		cin>>lt1>>lt2;
		ans=1234567890;
		lt3=lt1;
		lt4=lt2;
		Doit(0);
		printf("Case #%d: ",i);
		cout<<a1<<" "<<a2;
		printf("\n");
	}
	return 0;
}
