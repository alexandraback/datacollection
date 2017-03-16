#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<list>
#define maxn 1010
using namespace std;
char c[maxn];
int a[maxn];
list<int>ans;
int main()
{
	int T;
	cin>>T;
	for(int ii=1;ii<=T;++ii)
	{
		scanf("%s",c+1);
		printf("Case #%d: ",ii);
		int n=strlen(c+1);
		for(int i=1;i<=n;++i)
			a[i]=max(a[i-1],c[i]-'A');
		for(int i=1;i<=n;++i)
		{
			if(c[i]-'A'==a[i])
				ans.push_front(a[i]);
			else ans.push_back(c[i]-'A');
		}
		for(list<int>::iterator p=ans.begin();p!=ans.end();p++)
			printf("%c",*p+'A');
		printf("\n");
		ans.clear();
	}
	return 0;
}