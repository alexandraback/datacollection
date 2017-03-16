#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int t,n,x,y;
double doit(){
	if(x<0)x=-x;
	long long d=x+y;
	if(d%2==0)d-=2;
	else d-=1;
	long long b=(2+d)*(d+1)/2;
	n=n-b;
	y++;
	if(n<y)return 0;
	if(x==0&&n<y*2-1)return 0;
	if(n>=d+2+y)return 1;
	double ans=0,he=1;
	for(int i=1;i<=n;i++)
	he=he/2;
	int k=1;
	for(int i=0;i<=n-y;i++){
		ans+=he;
		he*=double(n-i)/(i+1);
		}
	return ans;
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&t);
    for(int c=1;c<=t;c++){
		scanf("%d%d%d",&n,&x,&y);
	    printf("Case #%d: %.6lf\n",c,doit());
	}
} 
