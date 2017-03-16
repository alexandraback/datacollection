#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long
#define PII pair<int,int>
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define SIZE(v) (int)v.size()

int T,A,N;
int m[111];

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	scanf("%d",&T);
	for(int cs=1;cs<=T;++cs) {
		scanf("%d%d",&A,&N);
		for(int i=0;i<N;++i) scanf("%d",m+i);
		sort(m, m+N);
		
		int i = 0;
		while(m[i] < A && i < N) A += m[i++];

		vector<int> ANS;
		int ans = 0;
		for(;i<N;++i) {
			if(m[i] < A) A += m[i];
			else if(A - 1 > 0 && A + A - 1 > m[i]) ans++, A += A - 1 + m[i];
			else {
				if(A - 1 == 0) ans++;
				else {
					ANS.push_back(ans + N - i);
					while(A <= m[i]) A += A - 1, ans++;
					A += m[i];
				}
			}
		} ANS.push_back(ans);
		sort(ANS.begin(), ANS.end());
		printf("Case #%d: %d\n",cs,ANS[0]);
	}
}