#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <set>
#include <limits>
using namespace std;

#define FOR(i,f,t) for(int i=f; i<t; i++)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define pb push_back
#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d %d", &x, &y)
#define SYNC ios_base::sync_with_stdio(false)

typedef long long ll;

string word[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int n[10] = {0, 6, 2, 8, 3, 7, 5, 4, 1, 9};
char c[10] = {'Z', 'X', 'W', 'G', 'H', 'S', 'V', 'F', 'O', 'I'};
int cnt[30];
int ans[10];
string S;
int main(){
	int TC; cin>>TC;
	FOR(tc,1,TC+1){
		cin>>S;
		ms(cnt,0);
		ms(ans,0);
		FOR(i,0,S.length()){
			cnt[S[i]-'A']++;
		}
		FOR(dig,0,10){
			int d = n[dig];
			int rep = cnt[c[dig]-'A'];
			ans[d] = rep;
			FOR(i,0,word[d].length()){
				cnt[word[d][i]-'A']-=rep;
			}
		}
		cout<<"Case #"<<tc<<": ";
		FOR(i,0,10) FOR(j,0,ans[i]) cout<<i;
		cout<<endl;
	}

	
}

