#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	REP(q,t){
		LL result = 0;
		int A,B,K;
		cin>>A>>B>>K;
		REP(i,B){
			REP(j,A){
				if((i&j) < K){
					result++;
				}
			}
		}
		cout<<"Case #"<<q + 1<<": "<<result<<'\n';
	}

	return 0;
}

