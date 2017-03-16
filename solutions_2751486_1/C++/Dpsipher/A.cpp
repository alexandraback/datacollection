/*
 * A.cpp
 *
 *  Created on: 12-May-2013
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

#define rep(i,a) for((i)=0;(i)<(a);(i)++)
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

bool vowel(char c)
{
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return true;
	return false;
}
int main()
{
    int tests,testno,n,i;
    cin>>tests;
    string s;
    for(testno=1;testno<=tests;testno++){
		printf("Case #%d: ",testno);
		cin>>s>>n;
		vi cons;
		int last=-1;
		int c=0;
		ll res=0ll;
		for(i=0;i<sz(s);i++){
			if(!vowel(s[i])){
				c++;
			}
			else c=0;
			if(c>=n){
				last=i-n+1;
			}
			if(last!=-1){
				res+=(ll)(last+1);
			}
		}
		cout<<res<<endl;
    }
    return 0;
}
