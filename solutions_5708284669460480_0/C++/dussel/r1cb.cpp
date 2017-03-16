/* attention to overflow */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <queue>
#include <sstream>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <tuple>
#include <iomanip>

#define dump(x) cerr<< #x << " = " << x <<endl
#define ALL(container) (container).begin(),(container).end()

using namespace std;
const int INF = 1 << 25;
void io() { cin.tie(0); ios::sync_with_stdio(false);}
template <class S,class T> ostream& operator<<(ostream& os, const pair <S,T> &s){return os<<'('<<s.first<<','<<s.second<<')';}
/*printf("%.9Lf\n",cf);*/
const int MOD = 1000000007;
const long double EPS=1e-16;


int main() {
	io();
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int K,L,S;
		cin>>K>>L>>S;

		string key,target;
		cin>>key>>target;

		//cerr<<1<<endl;
		long double hit=1.0;
		bool flg=1;
		for(int i=0;i<L;i++){
			int cnt=0;
			for(int j=0;j<K;j++){
				if(target[i]==key[j]) cnt++;
			}
			if(cnt==0) flg=0;
			hit*=1.0*cnt/K;
		}
		hit*=1.0*(S-L+1);
		//cerr<<hit<<endl;

		//cerr<<1<<endl;
		long double ret=0;
		if(flg){
			int head_tail=0;
			for(int j=L-1;j>0;j--){
				bool check=1;
				for(int i=0;i<j;i++){
					if(target[i]!=target[L-j+i]) check=0;
				}
				if(check){
					head_tail=j;
					break;
				}
			}

			ret=1.0+(S-L)/(L-head_tail);
			//cerr<<ret<<endl;
			ret-=hit;
		}

		printf("Case #%d: %5.10Lf\n",t+1,ret);
	}


	return 0;
}