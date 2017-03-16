#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
int t,n,l;
char s[1000005];
vector<pair<int,int> >kya;
bool con(char c){
	return (c!= 'a' && c!='i' && c!='u' && c!='e' && c!='o');
}

int main(){
	scanf("%d",&t);
	for (int tc = 1; tc <=t; ++tc){
		scanf("%s %d",s,&n);
		l = strlen(s);
		kya.clear();
		int r = 0,c=0;
		long long ans = 0;
		for (int i = 0; i <l; ++i){
			if (!con(s[i])){
				c = 0;
				continue;
			}
			else c++;
			if (c == 1) kya.pb(mp(i,i));
			else kya[kya.size()-1].se = i;
		}
		int p = 0;
		for (int i = 0; i < l; ++i){
			while (p < kya.size()){
				if (kya[p].se-max(i,kya[p].fi)+1 >=n) break;
				++p;
			}
			if (p >=kya.size()) break;
			ans += 1LL*(l-(max(kya[p].fi,i)+n-1));
		}
		printf("Case #%d: %lld\n",tc,ans);
	}
}