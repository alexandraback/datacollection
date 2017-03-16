#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=100001;
const int INF=0x7FFFFFFF;
const double eps=1e-8;
const double pi=acos(-1.0);

int n,ca;
double a[10000];
double ans[1000];

void init(){
	cin>>n;
	for (int i=0; i<n; i++) cin>>a[i];
}

void solve(){
	double sum=0;
	for (int i=0; i<n; i++) sum+=a[i];
	double av=sum*2/n;
	for (int i=0; i<n; i++){
		double temp=(av-a[i])/sum;
		ans[i]=temp;
		//printf(" %.6lf",temp*100);
	}
	int t=0;
	double ret=0;
	for (int i=0; i<n; i++)
		if (ans[i]<-eps){
			ret+=ans[i];
		} else ++t;
	for (int i=0; i<n; i++)
		if (ans[i]<eps) ans[i]=0; else ans[i]+=ret/t;
	for (int i=0; i<n; i++) printf(" %.6lf",ans[i]*100);
}

int main(){
	freopen("AA.out","w",stdout);
	cin>>ca;
	for (int i=0; i<ca; i++){
		init();
		cout<<"Case #"<<i+1<<":";
		solve();
		cout<<endl;
	}
	return 0;
}

