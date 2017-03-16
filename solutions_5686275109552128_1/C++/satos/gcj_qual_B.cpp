#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reg(i,a,b) for(int i=(a);i<=(b);i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=(b);i>=(a);i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX




int main(void){
	int qn;
	scanf("%d",&qn);
	reg(qq,1,qn){
		int n;
		vector<lli> dat;
		scanf("%d",&n);
		rep(i,n){
			lli a;
			scanf("%lld",&a);
			dat.push_back(a);
		}
		
		lli ans = 10000000;
		
		for(lli i=1;i<1010;i++){
			lli na = i;
			rep(j,n){
				na += (dat[j]-1)/i;
			}
			
			ans = min(ans,na);
		}
		printf("Case #%d: %lld\n",qq,ans);
	}
	return 0;
}




