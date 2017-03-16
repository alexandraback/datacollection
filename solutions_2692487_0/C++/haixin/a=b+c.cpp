#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int t,q,n,a[1100000],ans,x;
int doit(){
	if(q==1)return n;
	ans=n;
	x=n;
	for(int i=1;i<=n;i++){
	    x--;
		while(q<=a[i]){
			q+=q-1;
			x++;
		}
		q+=a[i];
		if(x<ans)ans=x;
	}
	return ans;
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&t);
    for(int c=1;c<=t;c++){
		scanf("%d%d",&q,&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		sort(a+1,a+n+1);
	    printf("Case #%d: %d\n",c,doit());
	}
}
