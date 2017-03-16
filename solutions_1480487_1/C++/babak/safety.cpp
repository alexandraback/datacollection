/// In The Name Of God

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstring>


using namespace std;

#define REP(i,n) for((i)=0;(i)<(n);(i)++)
typedef long long ll;

const int maxn = 256;
const double eps = 1e-9;
double d[maxn];
int n;
double sum;

double check(int i,double mid,double sum){
	int j;
	double ans=0.0;
	REP(j,n)if(j!=i){
		double tmp=mid*sum+d[i]-d[j];
		if(tmp>eps)
			ans+=tmp;
	}
	return ans/sum+mid-1>eps;
}

double f(int i,double sum){
	double ans=1.0;
	double mid,low,up;
	low=0.0;up=1.0;
	while(up-low>eps){
		mid=(up+low)/2.0;
		if(check(i,mid,sum))
			up=mid;
		else
			low=mid;
	}
	return mid;
}

int main(){
	ios::sync_with_stdio(false);
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int t, tsc,i;
	cin>>tsc;
	REP(t,tsc){
		sum=0.0;
		cin>>n;
		cout<<"Case #"<<t+1<<":";
		REP(i,n){
			cin>>d[i];
			sum+=d[i];
		}
		REP(i,n)
			printf(" %.5lf",100*f(i,sum));
		cout<<endl;
	}
	return 0;
}