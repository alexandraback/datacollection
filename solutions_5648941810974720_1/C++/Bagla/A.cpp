#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<bitset>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<cstring>
#include<sstream>
#include<climits>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define S(x) scanf("%d",&x)
#define SD(x) scanf("%lf",&x)
#define SL(x) scanf("%lld",&x)
#define pb(x) push_back(x)
#define mp make_pair
#define F(i, a, b) for (int i = int(a); i < int(b); i++)
#define forit(it, a) for (it = (a).begin(); it != (a).end(); it++)
#define M(x,i) memset(x,i,sizeof(x))

/* -------------------CODE GOES HERE---------------------- */

int main(){

	int T, tst = 1; S(T);
	string s;
	int A[26];
	int ans[10];

	while(T--){

		cin>>s;
		M(A,0);
		M(ans,0);

		F(i,0,s.length()){
			A[s[i]-'A']++;
		}

		if(A['Z'-'A'] > 0){
			ans[0] = A['Z'-'A'];
			A['E'-'A'] = A['E'-'A'] - A['Z'-'A'];
			A['R'-'A'] = A['R'-'A'] - A['Z'-'A'];
			A['O'-'A'] = A['O'-'A'] - A['Z'-'A'];
			A['Z'-'A'] = A['Z'-'A'] - A['Z'-'A'];
		}

		if(A['W'-'A'] > 0){
			ans[2] = A['W'-'A'];
			A['T'-'A'] = A['T'-'A'] - A['W'-'A'];
			A['O'-'A'] = A['O'-'A'] - A['W'-'A'];
			A['W'-'A'] = A['W'-'A'] - A['W'-'A'];
		}

		if(A['X'-'A'] > 0){
			ans[6] = A['X'-'A'];
			A['S'-'A'] = A['S'-'A'] - A['X'-'A'];
			A['I'-'A'] = A['I'-'A'] - A['X'-'A'];
			A['X'-'A'] = A['X'-'A'] - A['X'-'A'];
		}

		if(A['S'-'A'] > 0){
			ans[7] = A['S'-'A'];
			A['E'-'A'] = A['E'-'A'] - 2*A['S'-'A'];
			A['V'-'A'] = A['V'-'A'] - A['S'-'A'];
			A['N'-'A'] = A['N'-'A'] - A['S'-'A'];
			A['S'-'A'] = A['S'-'A'] - A['S'-'A'];
		}

		if(A['V'-'A'] > 0){
			ans[5] = A['V'-'A'];
			A['F'-'A'] = A['F'-'A'] - A['V'-'A'];
			A['I'-'A'] = A['I'-'A'] - A['V'-'A'];
			A['E'-'A'] = A['E'-'A'] - A['V'-'A'];
			A['V'-'A'] = A['V'-'A'] - A['V'-'A'];
		}

		if(A['F'-'A'] > 0){
			ans[4] = A['F'-'A'];
			A['O'-'A'] = A['O'-'A'] - A['F'-'A'];
			A['U'-'A'] = A['U'-'A'] - A['F'-'A'];
			A['R'-'A'] = A['R'-'A'] - A['F'-'A'];
			A['F'-'A'] = A['F'-'A'] - A['F'-'A'];
		}

		if(A['O'-'A'] > 0){
			ans[1] = A['O'-'A'];
			A['N'-'A'] = A['N'-'A'] - A['O'-'A'];
			A['E'-'A'] = A['E'-'A'] - A['O'-'A'];
			A['O'-'A'] = A['O'-'A'] - A['O'-'A'];
		}

		if(A['R'-'A'] > 0){
			ans[3] = A['R'-'A'];
			A['T'-'A'] = A['T'-'A'] - A['R'-'A'];
			A['H'-'A'] = A['H'-'A'] - A['R'-'A'];
			A['E'-'A'] = A['E'-'A'] - 2*A['R'-'A'];
			A['R'-'A'] = A['R'-'A'] - A['R'-'A'];
		}

		if(A['G'-'A'] > 0){
			ans[8] = A['G'-'A'];
			A['E'-'A'] = A['E'-'A'] - A['G'-'A'];
			A['I'-'A'] = A['I'-'A'] - A['G'-'A'];
			A['H'-'A'] = A['H'-'A'] - A['G'-'A'];
			A['T'-'A'] = A['T'-'A'] - A['G'-'A'];
			A['G'-'A'] = A['G'-'A'] - A['G'-'A'];
		}

		if(A['I'-'A'] > 0){
			ans[9] = A['I'-'A'];
			A['N'-'A'] = A['N'-'A'] - 2*A['I'-'A'];
			A['E'-'A'] = A['E'-'A'] - A['I'-'A'];
			A['I'-'A'] = A['O'-'A'] - A['I'-'A'];
		}

		printf("Case #%d: ", tst++);
		F(i,0,10){
			F(j,0,ans[i]){
				printf("%d", i);
			}
		}
		printf("\n");
	}
}
