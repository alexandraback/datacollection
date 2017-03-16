#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<int> H;
int Test,n,x,L,R,res;
int b[10],a[20];

int main()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d",&Test);	
	b[0]=1;
	for (int i=1;i<=7;++i) b[i]=b[i-1]*10; 	
	for (int t=1;t<=Test;++t){
		scanf("%d%d",&L,&R);
		res=0;
		for (int i=L;i<R;++i){
			H.clear();
			n=0;
			for (x=i;x;x/=10) a[++n]=x%10;
			x=i;
			for (int j=n+1;j<n+n;++j){
				x=(x-a[j-n])/10+a[j-n]*b[n-1];
				if (x>i && x<=R && H.find(x)==H.end()){
					++res;
					H.insert(x);
				}
			}
		}
		printf("Case #%d: %d\n",t,res);
	}
	
	return 0;
}
