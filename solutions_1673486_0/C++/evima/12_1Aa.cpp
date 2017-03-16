#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define EPS 1e-9
#define INF MOD
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(it=X.begin();it!=X.end();it++)
#define iss istringstream
#define ite iterator
#define ll long long
#define mp make_pair
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define pi pair<int,int>
#define pb push_back
#define sec second
#define sh(i) (1LL<<i)
#define sst stringstream
#define sz size()
#define vi vector<int>
#define vc vector
#define vl vector<ll>
#define vs vector<string>

int A,B;
double p[100010];

int main(){
	int T;
	cin>>T;
	rep(tc,T){
		cout<<"Case #"<<tc+1<<": ";
		cin>>A>>B;
		rep(i,A)cin>>p[i];
		double ans=1 + B + 1;
		double P=1;
		rep(i,A+1){
			if(i>0)P*=p[i-1];
			int back=A-i;
			ans = min(ans, back + back + B-A + 1 + (1-P) * (B+1) );
		}
		cout<<setprecision(9)<<ans<<endl;
	}
}