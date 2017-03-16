#include <stdio.h>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string,int> leftt,rightt;
int m;
pair<string,string> ma[20];
int maxfake(int now)
{
	if(now==m+1)
		return 0;
	int maxx,a;
	maxx=maxfake(now+1);
	if(leftt[ma[now].first]>1&&rightt[ma[now].second]>1)
	{
		leftt[ma[now].first]--;
		rightt[ma[now].second]--;
		a=1+maxfake(now+1);
		if(a>maxx)
			maxx=a;
		leftt[ma[now].first]++;
		rightt[ma[now].second]++;
	}
	return maxx;
}
void doe(int x)
{
	leftt.clear();
	rightt.clear();
	cin>>m;
	int i;
	for(i=1;i<=m;i++)
	{
		cin>>ma[i].first;
		cin>>ma[i].second;
		if(leftt.find(ma[i].first)==leftt.end())
			leftt[ma[i].first]=1;
		else
			leftt[ma[i].first]++;
		if(rightt.find(ma[i].second)==rightt.end())
			rightt[ma[i].second]=1;
		else
			rightt[ma[i].second]++;
	}
	printf("Case #%d: ",x);
	printf("%d\n",maxfake(1));
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("Cout.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		doe(i);
	return 0;
}
