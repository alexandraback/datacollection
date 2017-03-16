#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<map>
#include<set>
#include<cstring>
#include<string>
#include<queue>
#include<cctype>
#include<functional>
#include<fstream>
#include<sstream>
#include<complex>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

#define EPS 1.0e-10
#define ALL(t) t.begin(),t.end()
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(it,c) for(__typeof((c).begin()) it = (c).begin();it != (c).end();++it)
#define ll long long
#define mp make_pair
#define pb push_back
#define F first
#define S second
const ll mod=1000000007LL;
const int SIZE = 100010;
double p[SIZE];
int main(){
	int T;
	cin>>T;
	REP(test,T){
		int A,B;
		cin>>A>>B;
		double ans,sum=0,now=1.0,sa=B-A+1,k[16];
		double s=1.0;
		REP(i,A){
			cin>>p[i];
			s*=p[i];
			p[i]=s;
		}
		ans=min(B+2,A+B+1);
		REP(j,A){
			double h=(p[A-1-j]*(sa+j*2))+((1.0-p[A-1-j])*(sa+B+1+j*2));
			ans=min(h,ans);
		}
		printf("Case #%d: %f\n",test+1,ans);
	}
	return 0;
}
