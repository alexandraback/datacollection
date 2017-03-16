#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <vector>
#include <iterator>
#include <set>
#include <bitset>
#include <ctime>
#include <iomanip>
#include <map>

using namespace std;

const int M = 1e9 + 7;
typedef long long int lli;
lli modulo(lli a, lli b) {
	if(a==0) 	return 0;
	lli x=1, y=a%M;
	while(b > 0) {
		if(b%2)		x=(x*y)%M;
		y = (y*y)%M;
		b >>= 1;
	} 
	return x; 
}

lli modinv(lli a) {
	return modulo(a, M-2);
}

const int K = 26;

int adj[K + 1][K + 1], cnt[K + 1], vis[K + 1];
lli fact[110];

lli dfs(int node) {
	vis[node] = 1;
	lli res = fact[cnt[node]];
	for(int j=0; j<K+1; j++) {
		if(adj[node][j] && !vis[node])
			res = (res*1LL*dfs(j))%M;
	}
	return res;
}

void precompute() {
	fact[0] = 1LL;
	for(int i=1; i<101; i++)
		fact[i] = (fact[i-1]*i) % M;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int i, j;
	precompute();
	for(int test = 1; test <= t; test++) {
		memset(adj, 0, sizeof adj);
		memset(cnt, 0, sizeof cnt);
		int n;
		cin>>n;
		int f = 1;
        string s[n+9];
        int idx[27];
        memset(idx,0,sizeof(idx));
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++) {
            cin>>s[i];
            int st=s[i][0]-'a';
            int gg=0;
            for(j=1;j<s[i].length();j++) {
                int val=s[i][j]-'a';
                if(val==st)
                    continue;
                gg=1;
                adj[st][val]++;
                idx[val]++;
                if(adj[st][val]>1)
                    f=0;
                st=val;
            }
            if(!gg)
                cnt[st]++;
        }
 
        for(i=0;i<26;i++) {
            int c=0;
            for(j=0;j<26;j++) {
                if(i==j)
                    continue;
                if(adj[i][j])
                    c++;
            }
            if(c>1)
                f=0;
        }
        cout<<"Case #"<<test<<": ";
        if(!f)
            cout<<"0\n";
        else {
            lli ans=1LL;
            int c=0;
            for(i=0;i<26;i++) {
                if(vis[i]||idx[i])
                   continue;
                int zz=0;
                if(cnt[i])
                    zz=1;
                for(j=0;j<26;j++) {
                    if(adj[i][j])
                    zz=1;
                }
                if(!zz)
                    continue;
                lli z=dfs(i);
                ans=(ans*1LL*z)%M;
                c++;
            }
            ans=(ans*1LL*fact[c])%M;
            cout<<ans<<"\n";
        }
	}
	return 0;
}