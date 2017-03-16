// #include <bits/stdc++.h>
#include "iostream"
#include "cstdio"
#include "algorithm"
#include "math.h"
#include "queue"
#include "map"
#include "set"
#include "stack"
#include "fstream"
#include "cstring"
#include "string"
#define L(x) (x<<1+1)
#define R(x) (x<<1+2)
#define REP(a,b) for(int a=0;a<b;a++)
#define REP1(a,b) for(int a=1;a<=b;a++)
#define RREP(a,b) for(int a=b-1;a>=0;a--)
#define RREP1(a,b) for(int a=b;a>0;a--)
#define ITR(a,b) for(;a!=b;a++)
using namespace std;
#define P 1000000007LL
#define MAXN 100
#define E7 10000000LL
typedef long long ll;
int T;

int main(){
	cin>>T;
	REP1(number,T){
		int ans=0;
		int r,c,w;
		cin>>r>>c>>w;
		if(r>1)ans+=(r-1)*c/w;
		if(c/w>1)ans+=c/w-1;
		ans+=w;
		if(c%w!=0)ans++;
		cout<<"Case #"<<number<<": "<<ans<<endl;
	}
	return 0;
}
