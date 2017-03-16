#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
#define rep(i,n) for(int i=1;i<=(n);++i)
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
int n=32,nj=500;
char buf[40];
bool isprime[65537];
__int128 divider[65537];
__int128 tprime[65537];int pprime;
void initprime()
{
	for(int i=2;i<=65536;++i)isprime[i]=true;
	for(int i=2;i<=65536;++i)
	{
		if(isprime[i])
		{
			tprime[++pprime]=i;
			if(i<1000)
			for(int j=i*i;j<=65536;j+=i)
			{
				isprime[j]=false;
				divider[j]=i;
			}
		}
	}
}
__int128 tdiv;
bool testprime(__int128 in)
{
	if(in<=65536)
	{
		tdiv=divider[in];
		return isprime[in];
	}
	rep(p,pprime)
	{
		if(in%tprime[p]==0)
		{
			tdiv=tprime[p];
			return false;
		}
	}
	return true;
}
void task()
{
	int tj=0;
	__int128 nz=1<<n;
	for(__int128 iz=1<<n-1;iz<nz;++iz)
	{
		if(!(iz&1))continue;
		ltoa(iz,buf,2);
		//cout<<buf<<endl;
		for(int ib=2;ib<=10;++ib)
		{
			__int128 tget=0;
			for(char *c=buf;*c;++c)
			{
				tget=tget*ib+*c-'0';
			}
			//cout<<tget<<endl;
			if(testprime(tget))goto die;
		}
		printf("%s",buf);
		for(int ib=2;ib<=10;++ib)
		{
			__int128 tget=0;
			for(char *c=buf;*c;++c)
			{
				tget=tget*ib+*c-'0';
			}
			//tget=strtoll(buf,0,ib);
			testprime(tget);
			printf(" %lld",(long long)tdiv);
		}
		printf("\n");
		++tj;
		if(tj==nj)return;
		
		die:;
	}
}
int main()
{
	freopen("C.out","w",stdout);
	initprime();
	int nt=1;
	rep(i,nt)
	{
		printf("Case #%d:\n",i);
		task();
	}
	
}
