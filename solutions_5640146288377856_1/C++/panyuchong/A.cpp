#include <stdio.h>
#include <stdlib.h>
using namespace std;

int T,Case,n,m,w,i,j,k,ans;

int main(){
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d%d%d",&n,&m,&w);
		ans=n*(m/w+(m%w!=0))+w-1;
		++Case;
		printf("Case #%d: %d\n",Case,ans);
	}
}
