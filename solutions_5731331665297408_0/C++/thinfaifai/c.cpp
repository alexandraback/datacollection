#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define LL long long

vector<int> e[55];
int n,m,ed[55][55],cod[55],used[55][55],pv[55],v[55],rt,chain[55],chsz;

bool cmp(int a,int b) {
    return cod[a] < cod[b];
}

void check(int at) {
    v[at] = 1;
    for (int i=0; i<e[at].size(); i++)
        if (v[e[at][i]] == 0 && used[at][e[at][i]] < 2) {
            check(e[at][i]);
        }
}

int main() {
    int tc;
    scanf("%d",&tc);
    for (int t=1; t<=tc; t++) {
        scanf("%d%d",&n,&m);
        rt = 0;
        for (int i=0; i<n; i++) {
            scanf("%d",&cod[i]);
            e[i].clear();
            if (cod[i] < cod[rt]) rt = i;
        }
        memset(ed,0,sizeof(ed));
        for (int i=0; i<m; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            a--; b--;
            ed[a][b] = ed[b][a] = 1;
            e[a].push_back(b);
            e[b].push_back(a);
        }

        printf("Case #%d: ",t);
        memset(pv,0,sizeof(pv));
        memset(used,0,sizeof(used));
        printf("%d",cod[rt]);
        pv[rt] = 1;
        chain[0] = rt;
        chsz = 1;
        for (int x=1; x<n; x++) {
            vector<int> rea;
            for (int i=chsz-1; i>=0; i--)
                for (int j=0; j<e[chain[i]].size(); j++)
                    if (pv[e[chain[i]][j]] == 0)
                        rea.push_back(e[chain[i]][j]);
            sort(rea.begin(),rea.end(),cmp);
            for (int i=0; i<rea.size(); i++) {
                //printf("%d: now %d (%d)\n",x,rea[i],chsz);
                for (int j=chsz-1; j>=0; j--)
                    if (ed[chain[j]][rea[i]] == 1) {
                        used[chain[j]][rea[i]] = used[rea[i]][chain[j]] = 1;
                        for (int k=j; k<chsz-1; k++)
                            used[chain[k]][chain[k+1]] = used[chain[k+1]][chain[k]] = 2;

                        int ok = 1;
                        memcpy(v,pv,sizeof(v));
                        for (int k=0; k<=j; k++)
                            check(chain[k]);
                        for (int k=0; k<n; k++)
                            if (v[k] == 0 && pv[k] == 0) ok = 0;
                        //printf("  try %d->%d  %d\n",chain[j],rea[i],ok);

                        if (ok) {
                            chain[j+1] = rea[i];
                            printf("%d",cod[rea[i]]);
                            pv[rea[i]] = 1;
                            chsz = j+2;
                            goto bye;
                        }
                        else {
                            for (int k=j; k<chsz-1; k++)
                                used[chain[k]][chain[k+1]] = used[chain[k+1]][chain[k]] = 1;
                            used[chain[j]][rea[i]] = used[rea[i]][chain[j]] = 0;
                        }

                    }
            }
            bye: ;
        }
        puts("");
    }
	return 0;
}
