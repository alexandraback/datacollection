#include <cstdio>
#include <iostream>
#include <cstring>
#define maxn 1009
using namespace std;
int a[maxn],b[maxn],state[maxn];
int step,n;

// state 0:00 1:10 2:11
int find(int &x)
{
	int flag=0;
	for (int i=0;i<n;i++)
		if (state[i]<=1)
			if (b[i]<=x)
			{
				if (state[i]==0) x+=2;
				else x++;
				step++;
				state[i]=2;
				flag=1;
			}
	if (flag) return 0;

	int now=-1;
	for (int i=0;i<n;i++)
		if (!state[i] && a[i]<=x)
		{
			if (now==-1) now=i;
			else if (b[i]>b[now]) now=i;
		}
	if (now==-1) return -1;
	x++;
	step++;
	state[now]=1;
	return 0;
}

int main()
{
	int T,star;
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		memset(state,0,sizeof(state));
		printf("Case #%d: ",t);
		cin>>n;
		star=step=0;
		for (int i=0;i<n;i++) scanf("%d%d",a+i,b+i);
		int tobad=0;
		while (star<2*n) 
			if (find(star)==-1){tobad=1;break;}
		if (tobad) cout<<"Too Bad"<<endl;
		else cout<<step<<endl;
	}
	return 0;
}
