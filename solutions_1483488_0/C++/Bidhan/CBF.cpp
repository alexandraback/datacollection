/*
 * Bidhan Roy
 * University of Dhaka
 */

using namespace std;

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define inf (1<<30)
#define eps 1e-9
#define pb push_back
#define ins insert
#define mp make_pair
#define sz(x) ((int)x.size())
#define clr clear()
#define all(x) x.begin(),x.end()
#define xx first
#define yy second
#define sqr(x) ((x)*(x))
#define mem(x,val) memset((x),(val),sizeof(x));
#define read(x) freopen(x,"r",stdin);
#define rite(x) freopen(x,"w",stdout);
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef map<int,st> mis;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
st itoa(i64 a){if(!a) return "0";st ret;for(i64 i=a; i>0; i=i/10) ret+=((i%10)+48);reverse(all(ret));return ret;}
#define mx 0
i64 forum(st &str,int start,int size){
	i64 mul=1,ret=0;
	for(int i=(start-1+size)%size,cnt=0; cnt<size; cnt++,i=(i-1+size)%size){
		ret+=(str[i]-'0')*mul;
		mul*=10;
	}
	return ret;
}
set<pii> ase;
void how_many(i64 num,i64 A,i64 B){
	st NUM=itoa(num);
	rep(i,sz(NUM)){
		if(i){
			i64 ans=forum(NUM,i,sz(NUM));
			if(num<ans && ans>=A && ans<=B){
				ase.insert(mp(num,ans));
			}
		}
	}
}

int main(){
	read("in");
	rite("out");
    double cl = clock();
    int test,kas=0;
    cin>>test;
    while(test--){
		int a,b;
		scanf("%d%d",&a,&b);
		ase.clr;
		for(int i=a; i<=b; i++) how_many(i,a,b);
		printf("Case #%d: %d\n",++kas,sz(ase));
	}
    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds", cl / CLOCKS_PER_SEC);
    return 0;
}
