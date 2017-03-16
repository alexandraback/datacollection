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

struct data{
	double x,y;
};

int n,m,ca;
double dist;
data b[100];

void init(){
	cin>>dist>>n>>m;
	for (int i=0; i<n; i++) cin>>b[i].x>>b[i].y;
}

void solve(){
	double a;
	for (int i=0; i<m; i++){
		cin>>a;
		if (n==1 || b[0].y>=dist){
			printf("%.7lf\n",sqrt(2*dist/a));
		} else{
			double v=(b[1].y-b[0].y)/(b[1].x-b[0].x);
			double dist2=dist-(b[0].y-b[0].x*v);
			if (dist2<0) dist2=0;
			double ret=max(sqrt(2*dist/a),dist2/v);
			printf("%.7lf\n",ret);
		}
	}
}

int main(){
	freopen("B.out","w",stdout);
	cin>>ca;
	for (int i=1; i<=ca; i++){
		cout<<"Case #"<<i<<":"<<endl;
		init();
		solve();
	}
	return 0;
}

