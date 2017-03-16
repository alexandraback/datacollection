#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>
#include <bitset>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef complex<ld> vec;

typedef pair<int,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

#define MAXN 1005
char S[MAXN];
int main() {
    int TEST;
    scanf("%d",&TEST);
    FOR(test,TEST) {
    	scanf("%s",&S[0]);
    	int N = strlen(S);
    	string ans;

    	FOR(i,N) {
    		if (i == 0 || S[i] >= ans[0]) ans = string("") + S[i] + ans;
    		else ans += S[i];
    	}

    	printf("Case #%d: %s\n", test+1,ans.c_str());
    }
}































