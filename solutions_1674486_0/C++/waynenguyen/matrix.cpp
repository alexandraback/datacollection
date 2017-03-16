#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <string>
#include <queue>
#include <fstream>
#include <stack>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)
#define FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define PB push_back
#define MP make_pair
#define ll long long 
#define F first
#define S second
#define RESET(c,x) memset(c,x,sizeof(c))
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()

#define REP(i,a) for(int i = 0; i < (a); i++)

#define sqr(x) ((x)*(x))
#define oo 1000000009
using namespace std;
/*************************TEMPLATE**********************************/
long long convertToNum(string s)
{
    long long val = 0; FR(i,s.size()) val = val * 10 + s[i] - '0';
    return val;
}
char bu[50];
string convertToString(int a) {
    sprintf(bu,"%d",a);
    return string(bu);
}
long long GCD(long long x,long long y)  {
    if (!x) return y; if (!y) return x;
    if (x == y) return x; if (x < y) return GCD(x,y%x); else return GCD(x%y,y);
}
long long POW(long long x,long long y,long long Base){
    if (!y) return 1; long long u = POW(x,y/2,Base);
    u = (u * u) % Base;
    if (y & 1) return (u * x) % Base; else return u;
}
void extended_euclid(long long A, long long B, long long &x,long long &y) {
    if (A == 1 && B == 0) {
        x = 1;
        y = 0;
        return;
    }
    if (A < B) extended_euclid(B,A,y,x);
    else {
        long long xx,yy;
        extended_euclid(A%B,B,xx,yy);
        x = xx;
        y = yy - (A/B)*xx;
        
    }
}
//newstate = (newstate-1) & oldstate
/**************************CODE HERE*****************************/

int T,N, temp, temp2;
vector<int> a;
bool graph[1000][1000], d0[1000][1000];
int d[1000];

bool dfs(int s, int v) {
	stack<int> st;
	FR(i,N) d[i] = 0;
	//d[s] = 1;
	st.push(s);
	while (!st.empty()) {
		int t = st.top();
		st.pop();
		d[t]++;
		FR(i,N) if (graph[t][i]) {
			st.push(i);
		}
	}
	return (d[v]>1);
}
void solve()
{
	FR(i,N) FR(j,N) {
		if (i==j) continue;
		bool t = dfs(i,j);
		if (t==true) {
			cout << "Yes" << endl;
			return;
		}		
	}
	cout << "No" << endl;
}



int main() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
	
    cin >> T;    
	//bool q[2000000];
	//memset(q,true,sizeof(q));
    FR(i,T)
    {   
	   cout << "Case #" << i+1 << ": ";
	   cin >> N;
	   FR(j,N) FR(k,N) graph[j][k] = false, d0[j][k]=false;
	   FR(j,N) {
		   cin >> temp;
		   FR(k,temp) {
			   cin >> temp2;
			   graph[j][temp2-1] = true;
		   }
	   }
	   solve();
    }
    return 0;
}
