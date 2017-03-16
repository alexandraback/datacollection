#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int a,b;
double ans,s,p[111111];

int f(int a,int b,int x){
	return min(1+b,a-x+b-x)+1;
}

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int t=0;
	cin >> t;
	for (int e=1;e<=t;e++){
		cin >> a >> b;
		for (int i=0;i<a;i++)cin >> p[i];
		p[a]=0;
		s=1;
		ans=b+2;
		for (int i=0;i<=a;i++){
			ans=min(ans,(a-i+b-i+1)+(1-s)*(b+1));
			s*=p[i];
		}
		cout << "Case #" << e << ": ";
		printf("%.6lf\n",ans);
	}
	return 0;
}


