#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define X first
#define Y second
#define LI long long
#define MP make_pair
#define PB push_back
#define SZ size()
#define SQ(a) ((a)*(a))
#define FOR(i,x,y) for(int i=(int)x; i<(int)y; i++)
#define RFOR(i,x,y) for(int i=(int)x; i>(int)y; i--)
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define IN(a,pos,c) insert(a.begin()+pos,1,c)
#define DEL(a,pos,cant) erase(a.begin()+pos,cant)
#define INF 1000000

int main(){
	int kases; cin>>kases;
	for(int kase=1;kase<=kases;kase++){
		int A, B, K;
		cin>>A>>B>>K;
		int res = 0;
		for(int a = 0; a < A; a++){
			for(int b = 0; b < B; b++){
				if((a&b) < K) res++;
			}
		}
		cout<<"Case #"<<kase<<": "<<res<<endl;		
	}
}
