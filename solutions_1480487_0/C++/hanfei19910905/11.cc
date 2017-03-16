#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define re(i,n) for(int i=0;i<n;i++)
#define re1(i,n) for(int i=1;i<=n;i++)
#define re2(i,n) for(int i=0;i<=n;i++)
#define re3(i,n) for(int i=1;i<n;i++)
#define clr(a,n) memset(a,n,sizeof(a))
#define debug(n) cout<<#n<<"="<<n<<endl
double sum;
double num[205];
int t,n;
bool cal(double c,int p){
	double pnt = c*sum+num[p];
	double ans = 0;
	re(i,n) if(i!=p){
		if(num[i] >= pnt) continue;
		else ans += (pnt-num[i])/sum;
	}
//	cout<<c<<" "<<p<<" "<<ans+c<<endl;
	return ans + c > 1.0;
}
int main(){
	cin >>t;
	re1(oo,t){
		cin >>n;
		sum = 0;
		re(i,n) {scanf("%lf",&num[i]); sum += num[i];}
		printf("Case #%d:",oo);
		re(i,n){
			double ans=1;
			double l = 0.0, r = 1.0;
			re(j,200){
				double mid =(l+r)/2;
				if(cal(mid,i)) {ans = r = mid;}
				else l = mid;
			}
			printf(" %.6lf",ans*100);
		}
		puts("");
	}
}

