#include<stdio.h>
#include<vector>

using namespace std;
typedef long long int lnt;
vector<lnt>r;
int bs(lnt k){
	int x=1<<20,ans=-1;
	for(;x;x/=2)
		if(ans+x<r.size()&&r[ans+x]<=k)
			ans+=x;
	return ans+1;
	}
lnt u[100];
int p(lnt k){
	int d=0;
	for(;k;k/=10)
		u[d++]=k%10;
	for(int i=0;i<d;i++)
		if(u[i]!=u[d-i-1])
			return 0;
	return 1;
	}
int main(){
	for(lnt i=1;i<=10000000;i++){
		if(p(i)&&p(i*i)){
			r.push_back(i*i);
			//printf("%I64d ",i*i);
			}
		}
	freopen("C-small-attempt0.in","r",stdin);
	freopen("PC.txt","w",stdout);
	int t;
	scanf("%d",&t);
	lnt a,b;
	for(int ti=1;ti<=t;ti++){
		scanf("%I64d %I64d",&a,&b);
		printf("Case #%d: %d\n",ti,bs(b)-bs(a-1));
		}
	return 0;
	}
