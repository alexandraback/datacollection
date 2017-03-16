#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <set>
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
string result;
string tempresult;
vector<int> V;
int m,n;
set<int> a[9];
string b[9];
bool check(){
	tempresult = "";
	int akt = -1;
	int root = -1;
	int back[9];
	bool ok = true;
	FOREACH(it, V){
		tempresult += b[(*it)];
		while(true){
			if(akt == -1){
				akt = (*it);
				root = (*it);
				break;
			}
			if(a[akt].find(*it) == a[akt].end()){
				if(akt == root){
					ok = false;
					break;
				} else{
					akt = back[akt];
				}
			} else{
				back[(*it)] = akt;
				akt = (*it);
				break;
			}
		}
		if(akt != (*it)){
			ok = false;
			break;
		}
	}
	if(ok){
		if(tempresult < result){
			result = tempresult;
			return true;
		}
	} else{
		return false;
	}
	return false;
}

void ANTY(int m) {
	if (m==1) { /* Rob cos z permutacja */
		check();
	} else
		REP(i,m) {
			ANTY(m-1);
			if(i<m-1) {
				swap(V[i],V[m-1]);
				for(int i=0,j=m-2; i<j; swap(V[j--], V[i++]));
			}
		}
}

void PermAntyLex(vector<int>& l){
	V=l;
	ANTY(l.size());
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	REP(q,t){
		cin>>n>>m;
		result = "";
		REP(i,n){
			a[i].clear();
		}
		V.clear();
		REP(i,n){
			cin>>b[i];
			REP(j,5){
				result.PB('9');
			}
		}
		REP(i,m){
			int t1,t2;
			cin>>t1>>t2;
			t1--; t2--;
			a[t1].insert(t2);
			a[t2].insert(t1);
		}
		vector<int> el;
		REP(x,n) el.PB(x);
		PermAntyLex(el);
		cout<<"Case #"<<q+1<<": "<<result<<endl;
	}

	return 0;
}

