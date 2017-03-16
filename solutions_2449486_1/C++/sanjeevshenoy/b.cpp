#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<limits>
#include<cassert>

using namespace std;

const int max_n=105;

int T,n,m;
int a[max_n][max_n];
int gr[max_n],gc[max_n];

int main()
{
    scanf("%d",&T);
	for(int z=1; z<=T; z++)
	{
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d",&a[i][j]);
		
		fill(gr,gr+n,0);fill(gc,gc+m,0);
		
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				gr[i]=max(gr[i],a[i][j]);
				
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				gc[i]=max(gc[i],a[j][i]);
		
		bool res=1;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(a[i][j]!=gr[i] and a[i][j]!=gc[j])
					res=0;
		
		printf("Case #%d: ",z);
		if(res)
			printf("YES\n");
		else
			printf("NO\n");
    }
	
    return 0;
}
