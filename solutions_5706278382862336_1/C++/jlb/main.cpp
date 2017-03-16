#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <iterator>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <random>
#include <limits>
#include <cmath>

using namespace std;
#define FOR(i,n) for(size_t i=0;i<(size_t)(n);i++)
#define REP(i,n,m) for(size_t i=(size_t)(n);i<(size_t)(m);i++)
#define REPR(i,n,m) for(size_t i=(size_t)(n);i>(size_t)(m);i--)
#define MF(i,val) memset(i,val,sizeof(i))
#define MP(a,b) make_pair((a),(b))
typedef  pair<int,int> ipair;
//typedef __int64 int64;
typedef long long int64;
typedef unsigned long long uint64;
template<class T> T min_val(T val,T&minVal){return minVal=min(val,minVal);}
template<class T> T max_str(T val,T&maxVal){return maxVal=max(val,maxVal);}
typedef pair<uint64,uint64> lpair;

map<lpair,int> cache;

uint64 gcd(uint64 a,uint64 b){
	if(b==0)return a;
	return gcd(b,a%b);
}

vector<int> getPos(uint64 num){
	vector<int> pos;
	uint64 val,one;
	one=1;
	FOR(i,41){
		val=one<<i;
		if((num&val)!=0){
			pos.push_back(i);
		}else if(num<val){
			break;
		}
	}
	return pos;
}

int main(int argc,char** argv){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	std::ios::sync_with_stdio(false);
	int TC,ans;
	cin>>TC;
	FOR(tc,TC){
		uint64 P,Q,g;
		char t;
		cin>>P>>t>>Q;
		g=gcd(P,Q);
		P=P/g;
		Q=Q/g;
		vector<int> pos4P,pos4Q;
		pos4Q=getPos(Q);
		if(pos4Q.size()!=1){
			cout<<"Case #"<<tc+1<<": impossible"<<endl;
		}else{
			pos4P=getPos(P);
			ans=pos4Q.back()-pos4P.back();
			cout<<"Case #"<<tc+1<<": "<<ans<<endl;
		}
		

		
	}
	return 0;
}