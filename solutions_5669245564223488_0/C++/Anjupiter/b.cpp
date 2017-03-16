//TAG : 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<algorithm>
#include <climits>
using namespace std;

#define rep(i,n)	for(int (i)=0;(i)<(n);(i)++)
#define repd(i,n)	for(int (i)=(n)-1;(i)>=0;(i)--)
#define REP(i,n) for (int (i)=0,_n=(n); (i) < _n; (i)++)
#define FOR(i,a,b) for (int _b=(b), (i)=(a); (i) <= _b; (i)++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset((x),0,sizeof(x));
#define CLEARA(x) memset(&(x),0,sizeof(x));
#define FILL(x,v) memset((x),(v),sizeof(x));
#define FILLA(x,v) memset(&(x),(v),sizeof(x));

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
//const double pi = acos(-1.0);
#define EPS 1e-9

#define LL long long

#ifdef _MSC_VER
#include <intrin.h>
int ctz(unsigned v){
	unsigned long index;
	_BitScanForward(&index,v);
	return index;
}
#define strtoll	_strtoi64
int __popcnt64(unsigned long long v)
{
	return __popcnt((unsigned)(v>>32))+__popcnt((unsigned)(v&UINT_MAX));
}
#else
#define ctz(x) __builtin_ctz(x)
#define __popcnt	__builtin_popcount 
#define __popcnt64	__builtin_popcountll
#endif

int N;
string train[100];
map<vector<bool>,LL > table;

LL solve(vector<bool> mask)
{
	//count 'false'
	vector<int> pos;
	rep(i,N)if(!mask[i])pos.pb(i);
	if(pos.size()<=1)return 0;
	if(table.count(mask)>0)
		return table[mask];
	LL ans=0;
	if(pos.size()==2){
		int a=pos[0],b=pos[1];
		if(train[a][train[a].length()-1]==train[b][0])
			ans++;
		if(train[b][train[b].length()-1]==train[a][0])
			ans++;
	}else if(pos.size()==3){
		do{
			int a=pos[0],b=pos[1],c=pos[2];
			if(train[a][train[a].length()-1]==train[b][0] && 
				train[b][train[b].length()-1]==train[c][0])
				ans++;
		}while(next_permutation(ALL(pos)));
	}else{
		//Select 2
		REP(i,pos.size())FOR(j,i+1,pos.size()-1){
			int a=pos[i],b=pos[j];
			REP(k,pos.size())
				mask[pos[k]]=(k==i || k==j);
			LL value = solve(mask);
			REP(k,pos.size())
				mask[pos[k]]=!(k==i || k==j);
			LL value2 =solve(mask);
			ans+=value * value2;
		}
	}
	table[mask]=ans % 1000000007;
	return ans;
}

int main()
{
	int test_case;
	scanf("%d",&test_case);
	FOR(t,1,test_case){
		cin>>N;
		rep(i,N)cin>>train[i];
		table.clear();
		if(N==1){
			printf("Case #%d: 1\n",t);
		}else{
			vector<bool> init(N,false);
			LL ans = solve(init);
			printf("Case #%d: %lld\n",t,ans);
		}
	}
	return 0;
}