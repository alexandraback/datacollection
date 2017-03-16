#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <utility>
#include <iterator>
#include <fstream>
#include <stdio.h>

using namespace std;

template<class T>
string tostring(T a){stringstream ss; ss<<a; return ss.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])

int main(){
	ifstream be("A-small-attempt0.in");
	ofstream ki("ki.txt");
	int T;
	be>>T;
	FOR(tt,T){
		int a,n; be>>a>>n;
		VI ms;
		FOR(i,n){
			int x; be>>x;
			ms.push_back(x);
		}
		sort(ALL(ms));

		if(a!=1){
			const int inf=1000000000;
			int mi=inf;
			int c=0;
			int i=0;
			while(i<n){
				while(i<n && ms[i]<a){
					a+=ms[i];
					i++;
				}
				int cur=c+n-i;
				mi=min(mi,cur);
				c++;
				a+=a-1;
			}

			ki<<"Case #"<<tt+1<<": "<<mi<<endl;
		}else{
			ki<<"Case #"<<tt+1<<": "<<n<<endl;
		}
	}
	

	ki.close();
	return 0;
}