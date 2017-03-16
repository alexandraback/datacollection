#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <numeric>
#include <climits>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);++i)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);++i)
#define forall(i,c) for(typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define dforn(i,n) for(int i=((int)(n)-1);i>=0;--i)
#define dforsn(i,s,n) for(int i=((int)(n)-1);i>=(int)(s);--i)
#define all(v) (v).begin(),(v).end()
#define dbg(x) cerr << #x << " = " << x << endl
#define raya cerr << "=============================================" << endl

typedef long long tint;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pii > vii;

int main()
{
	int tests; cin >> tests;
	forsn(test,1,tests+1){
		int a,n; cin >> a >> n;
		vector<int> motes(n);
		forn(i,n) cin >> motes[i];
		sort(all(motes));
		tint mote = a;	

		vector<bool> eaten(n,false);
		int mini = 1000000000,count=0;
	
		while(true){
			bool ok = true;
			forn(i,n){
				if(!eaten[i] && motes[i] < mote){
					mote += motes[i];
					eaten[i] = true;
				}else if(!eaten[i]) 
					ok =  false;
			}
			int remove = 0;
			forn(i,n) if(!eaten[i]) remove++;
			mini = min(mini,count+remove);
			if(ok) break;
			if(mote == 1) break;
			mote += mote-1;
			count++;
		}
	
		cout << "Case #" << test << ": " << mini << endl;
	}
	return 0;
}
