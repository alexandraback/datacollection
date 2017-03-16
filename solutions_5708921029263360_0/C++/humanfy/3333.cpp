#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
class node
{
	public:
		int a,b,c;
		node(int a,int b,int c):a(a),b(b),c(c){}
		node(){}
}answer[1111];
int test,a,b,c,d,ans;
map<node,int >hash;
bool operator <(node a,node b)
{
	if (a.a!=b.a) return a.a<b.a;
	if (a.b!=b.b) return a.b<b.b;
	return a.c<b.c;
}
int main()
{
	
	freopen("C-small-attempt1.in","r",stdin);
	freopen("34.out","w",stdout);
	cin>>test;
	for (int kk=1;kk<=test;kk++)
	{
		hash.clear();
		ans=0;
		printf("Case #%d: ",kk);
		cin>>c>>b>>a>>d;
		for (int i=1;i<=a;i++)
		for (int j=1;j<=b;j++)
		for (int k=1;k<=c;k++)
		{
			node temp1=node(i,j,1),temp2=node(i,k,2),temp3=node(j,k,3);
			if (hash[temp1]==d||hash[temp2]==d||hash[temp3]==d) continue;
			answer[++ans]=node(i,j,k);
			hash[temp1]++;
			hash[temp2]++;
			hash[temp3]++;
		}
		cout<<ans<<endl;
		for (int i=1;i<=ans;i++) printf("%d %d %d\n",answer[i].c,answer[i].b,answer[i].a);
	}
	return 0;
}
