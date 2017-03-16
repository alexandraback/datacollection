#include <iostream>
#include <string>
#include <map>
#include <string.h>
using namespace std;



/*==================================================*\
 | Dinic最大流 O(V^2 * E)
 | INIT: ne=2; head[]置为0; addedge()加入所有弧;
 | CALL: flow(n, s, t);
\*==================================================*/
#define typec int                   // type of cost
const int N = 10000, E = 1000000;
const typec inf = 0x3f3f3f3f;       // max of cost
struct edge { int x, y, nxt; typec c; } bf[E];
int ne, head[N], cur[N], ps[N], dep[N];
void addedge(int x, int y, typec c)
{	// add an arc(x -> y, c); vertex: 0 ~ n-1;
	bf[ne].x = x; bf[ne].y = y; bf[ne].c = c;
	bf[ne].nxt = head[x]; head[x] = ne++;
	bf[ne].x = y; bf[ne].y = x; bf[ne].c = 0;
	bf[ne].nxt = head[y]; head[y] = ne++;
}
typec flow(int n, int s, int t)
{
	typec tr, res = 0;
    int i, j, k, f, r, top;
    while (1) {
        memset(dep, -1, n * sizeof(int));
		for (f = dep[ps[0] = s] = 0, r = 1; f != r; )
			for (i = ps[f++], j = head[i]; j; j = bf[j].nxt)
{
				if (bf[j].c && -1 == dep[k = bf[j].y]){
					dep[k] = dep[i] + 1; ps[r++] = k;
					if (k == t) { f = r; break; }
				}
			}
        if (-1 == dep[t]) break;

        memcpy(cur, head, n * sizeof(int));
        for (i = s, top = 0; ; ) {
            if (i == t) {
                for (k = 0, tr = inf; k < top; ++k)
				if (bf[ps[k]].c < tr)
tr = bf[ps[f = k]].c;
                for (k = 0; k < top; ++k)
                    bf[ps[k]].c -= tr, bf[ps[k]^1].c += tr;
                res += tr;  i = bf[ps[top = f]].x;
            }
            for (j=cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)
                if (bf[j].c && dep[i]+1 == dep[bf[j].y]) break;
            if (cur[i]) {
                ps[top++] = cur[i];
                i = bf[cur[i]].y;
            }
            else {
				if (0 == top) break;
                dep[i] = -1; i = bf[ps[--top]].x;
            }
        }
    }
    return res;
}



int main()
{
    int T;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca)
    {
        int n;
        cin >> n;
        map<string, int> F, S;
        int nF = 0, nS = 0;
        int first[10000], second[10000];
        for(int i = 0; i < n; ++i)
        {
            string a, b;
            cin >> a >> b;
            if( F.find(a) == F.end() )
            {
                F[a] = nF++;
            }
            if( S.find(b) == S.end() )
            {
                S[b] = nS++;
            }
            first[i] = F[a];
            second[i] = S[b];
        }
        ne = 2;
        memset(head, 0, sizeof(head) );
        // S: 0
        // First Word: 1..nF
        // Second Word: nF+1, nF+nS
        // T: nF+nS+1
        int SS = 0, TT = nF+nS+2;
        for(int i = 0; i < nF; ++i)
        {
            addedge(SS, i+1, 1);
        }
        for(int i = 0; i < nS; ++i)
        {
            addedge(i+nF+1, TT, 1);
        }
        for(int i = 0; i < n; ++i)
        {
            addedge(first[i]+1, second[i]+nF+1, 1);
        }
        int f = flow(TT+1, SS, TT);
        int mincover = nF+nS-f;
        int maxfake = n-mincover;
        cout << "Case #" << ca << ": " << maxfake << endl;
    }
}
