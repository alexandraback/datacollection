#include <bits/stdc++.h>

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int main()
{
	int T;
	cin>>T;
	REP(k, T){
		string S;
		cin>>S;
		int kant = 0;
		for (int i = S.size() - 1; i >= 0; i--){
			if (S[i] == '+'){
				kant += (kant % 2);	
			}
			else{
				kant += ((kant + 1) % 2);	
			}
		}
		printf("Case #%d: %d\n", k + 1, kant);
	}
	return 0;
}

