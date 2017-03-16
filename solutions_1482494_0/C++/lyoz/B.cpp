#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <complex>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <functional>
#include <iterator>

using namespace std;

#define dump(n) cerr<<"# "<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define iter(c) __typeof__((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)
#define all(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;

using namespace std::placeholders;

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a)
{
	os<<'[';
	rep(i,a.size())
		os<<(i?" ":"")<<a[i];
	return os<<']';
}

void solve()
{
	int n; cin>>n;
	vi as(n),bs(n);
	rep(i,n)
		cin>>as[i]>>bs[i];
	
	//dump(n); dump(as); dump(bs);
	
	priority_queue<pii,vector<pii>,greater<pii>> pq1,pq2;
	rep(i,n){
		pq1.emplace(as[i],i);
		pq2.emplace(bs[i],i);
	}
	
	vi fs(n);
	int star=0,res=0;
	for(;;){
		if(all_of(all(fs),bind(equal_to<int>(),_1,2)))
			break;
		
		bool update=false;
		
		rep(i,n) if(fs[i]<2){
			if(star>=bs[i]){
				//printf("2-star: %d\n",i);
				star+=2-fs[i];
				res++;
				fs[i]=2;
				update=true;
				break;
			}
		}
		
		if(update)
			continue;
		
		int j=-1;
		rep(i,n) if(fs[i]==0){
			if(star>=as[i])
				if(j==-1 || bs[i]>bs[j])
					j=i;
		}
		
		if(j==-1){
			cout<<"Too Bad"<<endl;
			return;
		}
		//printf("1-star: %d\n",j);
		star++;
		res++;
		fs[j]=1;
	}
	cout<<res<<endl;
}

int main()
{
	int cases; scanf("%d ",&cases);
	rep(i,cases){
		printf("Case #%d: ",i+1);
		solve();
	}
	
	return 0;
}
