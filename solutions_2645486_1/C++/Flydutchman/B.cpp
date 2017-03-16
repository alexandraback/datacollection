#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (lint i = l; i <= r; ++i)
#define Cor(i,l,r) for (lint i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 20304
#define MaxM 302030
#define MaxNode 1020304
#define MD 1000000007
#define update(a,b) { a = max(a,(b)); }
#define lint long long

struct Tflow{
       #define op(z) (z + ((z & 1)?(1) : (-1)))
       lint v[MaxM],w[MaxM],next[MaxM],c[MaxM],h[MaxN],tot;
       void add(lint b,lint e,lint wei,lint f) {
				//cerr << b <<  ' ' << e << ' ' << wei << ' ' << f << endl;
            v[++tot]=e;next[tot]=h[b];h[b]=tot;w[tot]=wei;c[tot]=f;
            v[++tot]=b;next[tot]=h[e];h[e]=tot;w[tot]=-wei;c[tot]=0;
       }
       lint S,T;
       void Init(){
            Fill(h,0); tot = 0;
       }
       lint e[MaxN],pre[MaxN],edg[MaxN],q[MaxN],d[MaxN],vis[MaxN];
       bool spfa(lint S) {
            lint hd(0),tl(1); q[1] = S; Fill(d,-INF); d[S] = 0; vis[S] = true; pre[S] = 0;
            while (hd != tl) {
                hd = (hd + 1) % MaxN; lint vex = q[hd]; vis[vex] = false;
                for (lint z = h[vex]; z; z = next[z]) if (c[z] && d[v[z]] < d[vex] + w[z]) {
                    d[v[z]] = d[vex] + w[z]; pre[v[z]] = vex; edg[v[z]] = z;
                    if (!vis[v[z]]) { tl = (tl + 1) % MaxN; q[tl] = v[z]; }
                }
            }
            return (d[T]>=0);
       }
       lint ans;
       void Aug() {
            lint flow = INF; 
            for(lint p = T; pre[p]; p = pre[p]) flow = min(flow,c[edg[p]]);
            for(lint p = T; pre[p]; p = pre[p]) {
                lint z = edg[p];
                c[z] -= flow; c[op(z)] += flow; ans += (lint)w[z] * flow;
            }
       }
       void Sol(lint s,lint t){
            S = s; T = t;
            ans = 0;
            while (spfa(S)) {
				//cerr << "T_T" << endl;
				Aug();
			}
       }
}TF;

lint v[MaxN],f[102][102]; lint e,r,n; lint a[MaxN];
int main() {
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	lint T; cin >> T;
	For(TTT,1,T) { cerr << TTT << endl; printf("Case #%I64d: ",TTT);
				if(TTT==10){
					lint z=TTT;
				}
		TF.Init();
		cin >> e >> r >> n;
		For(i,1,n) scanf("%I64d",&a[i]);
		For(i,1,n - 1) TF.add(i,i + n,0,e);
		For(i,1,n - 1) TF.add(i + n,i + 1,0,e);
		lint S = n + n, T = S + 1; TF.add(S,1,0,e);
		For(i,1,n - 1) TF.add(S,n + i,0,r);
		For(i,1,n) TF.add(i,T,a[i],e);
		TF.Sol(S,T);
		cout << TF.ans << endl;
	}
	return 0;
}

