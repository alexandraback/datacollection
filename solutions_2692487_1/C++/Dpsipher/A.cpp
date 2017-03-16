/*
 * A.cpp
 *
 *  Created on: 04-May-2013
 *      Author: rishabh
 */





#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

#define rep(i,a) for((i)=0;(int)(i)<(a);(i)++)
#define maX(a,b) ((a)>(b)?(a):(b))
#define miN(a,b) ((a)<(b)?(a):(b))
#define pb(x) push_back(x)
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define vi vector<int>

template<class T> T abs(T x){return x>0?x:-x;}
inline int toInt(string s) {int v;istringstream sin(s);sin>>v;return v;}
inline ll toll(string s) {ll v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T gcd(T a,T b) {if (a<0) a=-a;if (b<0) b=-b;return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {return a*(b/gcd(a,b));}

int main()
{
    int tests,testno;
    cin>>tests;
    for(testno=1;testno<=tests;testno++){
		printf("Case #%d: ",testno);
		ll i,n,A,left,AA;
		cin>>AA>>n;
		vector<ll> m(n);
		rep(i,n){
			cin>>m[i];
		}
		sort(m.begin(),m.end());
		ll res=0,ans=1ll<<50;
		//cout<<ans;
		if(AA==1)cout<<n<<endl;
		else{
		for(left=0;left<=n;left++){
			i=0,res=0;
			A=AA;
			while(i<left){
				if(A>m[i]){
					A+=m[i];
					i++;
				}
				else {
					res++;
					A+=(A-1);
				}
			}
			ans=miN(ans,res+n-left);
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;}
    }

}
