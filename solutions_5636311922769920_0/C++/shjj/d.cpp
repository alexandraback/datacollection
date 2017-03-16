//shjj-d

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int K,C,S;

int main()
{
	freopen("D0.in","r",stdin);
	freopen("D0.out","w",stdout);
	int T,Tt=0;scanf("%d",&T);
	for (;T--;)
	{
		scanf("%d%d%d",&K,&C,&S);
		printf("Case #%d:",++Tt);
		for (int i=1;i<=S;i++) printf(" %d",i);
		puts("");
	}
}