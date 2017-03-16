#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
#include <sstream>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long ll;
typedef unsigned int uint;

inline int toi(string s){int v; istringstream iss(s);iss>>v;return v;}
template<class T> inline string tos(T x){ostringstream oss;oss<<x;return oss.str();}

#define All(a)  (a).begin(),(a).end()
#define Rall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define exist(s,e) ((s).find(e)!=(s).end())

#define Forall(i,v)   for(int i=0;i<(int)v.size();++i)
#define For(i,a,b)    for(int i=(a);i<(b);++i)
#define ForD(i,a,b)   for(int i=(a);i>(b);--i)
#define Step(i,a,b,s) for(int i=(a);i<(b);i+=(s))
#define Rep(i,n)      for(int i=0;i<(n);++i)
#define Each(i,c)     for(typeof((c).begin()) i=(c).begin();i!=(c).end();++i)

#define Fill(a,b)   memset(a,b,sizeof(a))
#define Clear(a)    memset((a),0,sizeof(a))
#define Sort(c)     sort((c).begin(),(c).end())

#define MinOf(x)    *min_element(All(x))
#define MaxOf(x)    *max_element(All(x))

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


bool consonants(char c){
	switch(c){
	case 'a':
	case 'i':
	case 'u':
	case 'e':
	case 'o':
		return false;
		break;
	}
	return true;
}

void main2(void){
	string s;
	int n;
	cin >> s >> n;
	int l = s.length();
	VI cc(l,0);
	int c = 0;
	Rep(i,l){
		if(consonants(s[i])){
			c += 1;
			if(c>=n){
				cc[i-n+1] = 1;
			}
		}else{
			c = 0;
		}
	}
	int ph = -1;
	c = 0;
	Rep(i,l){
		if(cc[i]>0){
			c += (i-ph)*(l-i-n+1);
			ph = i;
		}
	}
	cout << " " << c << endl;
}

int main(void){
	int T,t;
	cin >> T;
	REP(t,T){
		printf("Case #%d:",t+1);
		main2();
	}
	return 0;
}
