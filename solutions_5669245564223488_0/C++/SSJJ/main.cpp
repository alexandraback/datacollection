#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
#include <memory>
#include <time.h>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
const double EPS = 1e-9;
const double PI  = acos(-1.0);

int main(){
	int num_cases;
	cin>>num_cases;
	REP(test_case,num_cases){
		int n;
		cin>>n;
		vector<pair<int,string>> cars(n);
		REP(i,n){
			cin>>cars[i].second;
			cars[i].first=i;
		}
		int ans=0;
		do{
			string s;
			REP(i,cars.size()){
				s+=cars[i].second;
			}
			bool ok=true;
			vi used(26);
			char cur=' ';
			REP(i,s.size()){
				if(cur!=s[i]){
					if(used[s[i]-'a']){
						ok=false;
						break;
					}else{
						cur=s[i];
						used[s[i]-'a']=1;
					}
				}
			}
			if(ok){
				ans++;
				ans%=1000000007;
			}
		}while(next_permutation(ALL(cars)));
		cout<<"Case #"<<test_case+1<<": "<<ans<<endl;
	}
}