//
//  main.cpp
//  testcpp
//
//  Created by 陈 建飞 on 12-11-11.
//  Copyright (c) 2012年 陈 建飞. All rights reserved.
//
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T gcd(T a,T b){return a==0?b:gcd(b%a,a);}
template<class T> inline int countbit(T n){return n==0?0:(1+countbit(n&(n-1)));}
template<class T> inline void pout(T A[],int n){cout<<"{";for (int i=0;i<n;i++)cout<<A[i]<<", ";cout<<"}\n";}
template<class T> inline void pout(vector<T> A,int n=-1){if (n==-1) n=A.size();cout<<"{";for (int i=0;i<n;i++)cout<<A[i]<<", ";cout<<"}\n";}

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define FORIT(a,aa) for(a=aa.begin();a!=aa.end();++a)
#define split(str) {vs.clear();istringstream sss(str);while(sss>>(str))vs.push_back(str);}

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;

const double eps=1e-9;

string solve();
string res;
int main()
{
    //	freopen("A-small-attempt.in","r",stdin);
    //	freopen("/Users/cjf/Desktop/testcpp/testcpp/testcpp.1/A.out","w",stdout);
    //   ofstream ofs("a.out");ofs<<"faf"<<endl;
	int T,l;
	cin>>T; //cout<<T<<endl;
	for (l=1;l<=T;l++)
	{
		res = solve();
		printf("Case #%d: ",l); cout<<res<<endl;//printf("%.6f\n",res);
	}
	return 0;
}

int a[101][101];
string solve()
{
    int n,m,i,j;
    cin>>n>>m;
    REP(i, n) REP(j, m) cin>>a[i][j];
    int lineMax[100]={0}, colMax[100]={0};//, lineMin[100]={100}, colMin[100]={100};
    REP(i, n) REP(j, m){
        checkmax(lineMax[i], a[i][j]);
        checkmax(colMax[j], a[i][j]);
 //       checkmin(lineMin[i], a[i][j]);
 //       checkmin(lineMin[j], a[i][j]);
    }
    REP(i, n) REP(j, m){
        int k = a[i][j];
        if (k != lineMax[i] && k != colMax[j]) return "NO";
    }
    return "YES";
}

/* a
string solve();
string res;
int main()
{
//	freopen("A-small-attempt.in","r",stdin);
//	freopen("/Users/cjf/Desktop/testcpp/testcpp/testcpp.1/A.out","w",stdout);
 //   ofstream ofs("a.out");ofs<<"faf"<<endl;
	int T,l;
	cin>>T; //cout<<T<<endl;
	for (l=1;l<=T;l++)
	{
		res = solve();
		printf("Case #%d: ",l); cout<<res<<endl;//printf("%.6f\n",res);
	}
	return 0;
}



string ss[] = {"X won", "O won", "Draw", "Game has not completed"};
string solve()
{
	int i,j;
    char s[4][4];
    REP(i, 4) REP(j,4) cin>>s[i][j];
    
    REP(i, 4) {
        REP(j,4) if (s[i][j]=='O' || s[i][j] == '.') break;
        if (j == 4) return ss[0];
        REP(j,4) if (s[i][j]=='X' || s[i][j] == '.') break;
        if (j == 4) return ss[1];
    }
    REP(i, 4) {
        REP(j,4) if (s[j][i]=='O' || s[j][i] == '.') break;
        if (j == 4) return ss[0];
        REP(j,4) if (s[j][i]=='X' || s[j][i] == '.') break;
        if (j == 4) return ss[1];
    }

    REP(i, 4) if (s[i][i] == 'O' || s[i][i] == '.') break;
    if (i==4) return ss[0];
    REP(i, 4) if (s[i][i] == 'X' || s[i][i] == '.') break;
    if (i==4) return ss[1];
    
    REP(i, 4) if (s[i][3-i] == 'O' || s[i][3-i] == '.') break;
    if (i==4) return ss[0];
    REP(i, 4) if (s[i][3-i] == 'X' || s[i][3-i] == '.') break;
    if (i==4) return ss[1];

    REP(i, 4) REP(j, 4) if (s[i][j] == '.') return ss[3];
	return ss[2];
}
*/

