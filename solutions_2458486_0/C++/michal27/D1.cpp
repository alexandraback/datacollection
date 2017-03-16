#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;

vector<int> K;
vector<vector<int> > A;
vector<int> P;
int k,n;

bool otvor(int p, int typ) {
    vector<int> Pom; Pom.resize(247,0);
    For(i,k) Pom[K[i]]++;
    For(i,n) {
        if(!(p&(1<<i))) continue;
        For(j,A[i].size()) Pom[A[i][j]]++;
        Pom[P[i]]--;
    }
    For(i,242) if(Pom[i]<0) return false;
    if(Pom[typ]==0) return false;
    return true;
}

bool D[1<<21];
vector<vector<int> > S;

int main() {
    int t;
    scanf("%d ",&t);
    For(i1,t) {
        scanf("%d %d ",&k,&n);
        K.clear(); K.resize(k);
        P.clear(); P.resize(n);
        A.clear(); A.resize(n);
        S.clear(); S.resize(1<<n);
        For(i,k) scanf("%d ",&K[i]);
        For(i,n) {
            scanf("%d ",&P[i]);
            int x; scanf("%d ",&x);
            A[i].resize(x);
            For(j,x) scanf("%d ",&A[i][j]);
        }
        For(i,1<<21) D[i]=false;
        D[0]=true;
        for(int i=1; i<(1<<n); i++) {
            For(j,n) {
                if(!(i&(1<<j))) continue;
                if(!D[i^(1<<j)]) continue;
                if(!otvor(i^(1<<j),P[j])) continue;
                D[i]=true;
                if(S[i].size()==0) {S[i]=S[i^(1<<j)]; S[i].push_back(j);}
                else {
                    vector<int> Pomoc = S[i^(1<<j)]; Pomoc.push_back(j);
                    S[i]=min(S[i],Pomoc);
                }
            }
        }
        //For(i,1<<n) printf("%d ",D[i]); printf("\n");
        printf("Case #%d:",i1+1);
        bool zle=!(D[(1<<n)-1]);
        if(zle) {printf(" IMPOSSIBLE\n"); continue;}
        /*vector<int> Vys;
        int mz=(1<<n)-1;
        while(mz!=0) {
            int k=S[mz];
            //For(i,n) if(mz&(1<<i) && D[mz^(1<<i)]) k=i;
            Vys.push_back(k);
            mz=mz^(1<<k);
        }
        reverse(Vys.begin(),Vys.end());*/
        For(i,S[(1<<n)-1].size()) printf(" %d",S[(1<<n)-1][i]+1); printf("\n");
    }
return 0;
}
