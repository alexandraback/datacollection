#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <climits>
#include <cassert>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORD(i,n) for(int i=n;i>=0;i--)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define FORRD(i,n,s) for(int i=n,_s=s;i>=_s;i--)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 100000
using namespace std;
typedef long long ll;

ll d[32][2][2][2];
ll A,B,K;
ll f(int bit,int as,int bs,int ks){
	as = (as > 0 ? 1 : 0);
	bs = (bs > 0? 1 : 0);
	ks = (ks > 0 ? 1 : 0);
	if(bit == -1) return 1LL;
	if(d[bit][as][bs][ks] != -1) return d[bit][as][bs][ks];
		
	ll& res = d[bit][as][bs][ks];
	res = 0LL;

	int msk = (1 << bit);
	if((K & msk) || ks){
		if((as || (A & msk)) && (bs || (B & msk))) // 11
			res += f(bit - 1,as,bs,ks);
	}
	
	if(K & msk) ks = 1;
	if(as || (A & msk)) // 10
		res += f(bit - 1,as,(bs ? bs : (B & msk)),ks);
	if(bs || (B & msk))
		res += f(bit - 1,(as ? as : (A & msk)),bs,ks); // 01
	res += f(bit - 1,(as ? as : (A & msk)),(bs ? bs : (B & msk)),ks);
	
	return res;
}
int main(){
	int T;
	cin>>T;
	FORR(tt,1,T + 1){
		cin>>A>>B>>K;
		A--; B--; K--;
		cout<<"Case #"<<tt<<": ";
		
		memset(d,-1,sizeof d);
		if(K >= A && K >= B)
			cout<<(A + 1) * (B + 1)<<"\n";
		else cout<<f(30,0,0,0)<<"\n";
	}
	return 0;
}
