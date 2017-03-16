#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#define FOR(i, b, e) for (typeof(b) i = (b); i != (e); ++i)
#define VAR(a,b) typeof(b) a=b
#define dout cout
using namespace std;
typedef long long LL;

void run(int Case)
{
	int a[100][100];
	int mi[100]={0};
	int mj[100]={0};
	int N, M;
	cin >> N >> M;
	FOR(i,0,N){
		FOR(j,0,M){
			cin >> a[i][j];
		}
	}

	FOR(i,0,N){
		FOR(j,0,M){
			mi[i]=max(mi[i],a[i][j]);
			mj[j]=max(mj[j],a[i][j]);
		}
	}

	bool ok=true;
	FOR(i,0,N){
		FOR(j,0,M){
			if(a[i][j] < mi[i] && a[i][j] < mj[j]){
				ok=false;
			}
		}
	}

	cout << "Case #" << Case << ": " << (ok ? "YES": "NO") << endl;
}

int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		run(t);
	}
}
