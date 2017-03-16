/*
 * B.cpp
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

int main()
{
    int tests,testno;
    cin>>tests;
    for(testno=1;testno<=tests;testno++){
		printf("Case #%d: ",testno);
		int x,y,i;
		cin>>x>>y;
		string h2,h,v,v1;
		string res;
		if(x<0){h="W";h2="EW";x*=-1;}
		else{ h="E";h2="WE";}
		if(y<0){
			v="NS";
			v1="SN";
		}
		else{
			v="SN";
			v1="NS";
		}
		if(x==0){
			rep(i,abs(y)){
				res+=v;
			}
		}
		else if(y==0){
			rep(i,abs(x)){
				res+=h2;
			}
		}
		else{
			if(x%2){
				v="SN";
				v1="NS";
				rep(i,x/2){
					res+=v;
				}
				res+=h;
				int val=y-(x/2);
				if(val<0){
					rep(i,abs(val)){
						res+=v1;
					}
				}
				else{
					rep(i,abs(val)){
						res+=v;
					}
				}
			}
			else{
				v="SN";
				v1="NS";
				rep(i,x/2){
					res+=v;
				}
				res[sz(res)-1]=h[0];
				res+="N";
				int val=y-((x/2)+1);
				if(val<0){
					rep(i,abs(val)){
						res+=v1;
					}
				}
				else{
					rep(i,abs(val)){
						res+=v;
					}
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
