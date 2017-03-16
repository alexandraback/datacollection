#include<bits/stdc++.h>
using namespace std;
const int L=16,V=1000000;
int T,n,dis[V+1]={},q[V+1]={},head=0,tail=0;
int reverse(int s)
{
	int a[L]={},tot=0,sum=0;
	for(; s; s/=10)
		a[++tot]=s%10;
	for(int i=1;i<=tot;++i)
		sum=sum*10+a[i];
	return sum;
}
void bfs()
{
	dis[1]=1;
	q[++tail]=1;
	while(head!=tail)
	{
		int s=q[++head];
		if(s==V)
			continue;
		int t1=s+1,t2=reverse(s);
		if(!dis[t1])
			dis[t1]=dis[s]+1,q[++tail]=t1;
		if(!dis[t2])
			dis[t2]=dis[s]+1,q[++tail]=t2;
	}
}
int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
	bfs();
	cin>>T;
	for(int testcase=1;testcase<=T;++testcase)
	{
		cin>>n;
		cout<<"Case #"<<testcase<<": "<<dis[n]<<endl;
	}
	return 0;
}
