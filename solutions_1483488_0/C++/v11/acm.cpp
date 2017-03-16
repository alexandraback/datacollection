#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
#define N  2000010
bool num[N];
int ans;
void fun(int nu)
{
	int i,j,k;
	int tnum;
	num[nu] = 1;
	tnum = nu;
	int ten = 1;
	while(tnum){
		tnum/=10;
		ten*=10;
	}
	ten/=10;
	int pre = nu;
	while(1){
		tnum = pre / 10;
		tnum = tnum + (pre % 10 ) * ten;
		pre = tnum;
		if(pre == nu) break;
		if(num[pre] ) ans++;
	}
}
int main()
{
	int T,ca = 1,i,n,m;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	while(T-- && cin >>n>>m)
	{
		memset(num,0,sizeof(num));
		ans = 0;
		for(i = n;i<=m;i++)
		{
			fun(i);
		}
		printf("Case #%d: %d\n",ca++,ans);
	}
}