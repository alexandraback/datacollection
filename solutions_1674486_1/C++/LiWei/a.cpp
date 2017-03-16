#include <iostream>
#include <string.h>
using namespace std;
class node
{
public:
	int t;
	int *a;
	void input()
	{
		cin>>t;
		if(t>0)
		{
			a = new int[t];
			for(int i=0;i<t;i++)
			{
				cin>>a[i];
				a[i]--;
			}
		}
	}
	void del()
	{
		if(t>0)
			delete [] a;
	}
};
node nodes[1000];
int n;
bool h[1000],h2[1000];
int stack[3100],st;
bool search1()
{
	int now,i;
	while(st>0)
	{
		now=stack[--st];
		if(h2[now])
			return true;
		h[now]=true;
		h2[now]=true;
		for(i=0;i<nodes[now].t;i++)
		{
			stack[st++]=nodes[now].a[i];
		}
	}
	return false;
}
bool search()
{
	memset(h,0,sizeof(bool)*1000);
	for(int i=0;i<n;i++)
	{
		if(!h[i])
		{
			memset(h2,0,sizeof(bool)*1000);
			st=1;stack[0]=i;
			if(search1())
				return true;
		}
	}
	return false;
}
int main()
{
	int c,t,i;
	cin>>t;
	for(c=0;c<t;c++)
	{
		cin>>n;
		for(i=0;i<n;i++)
			nodes[i].input();
		cout<<"Case #"<<c+1<<": ";
		if(search())
		{
			cout<<"Yes\n";
		}else cout<<"No\n";
		for(i=0;i<n;i++)
		{
			nodes[i].del();
		}
	}
}
