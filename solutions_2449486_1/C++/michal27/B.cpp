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
typedef pair<int,pair<int,int> > Tri;

vector<int> H,V;
vector<Tri> A;

int main() {
    int t;
    scanf("%d ",&t);
    For(i1,t) {
        int n,m;
        scanf("%d %d ",&n,&m);
        A.clear();
        H.clear(); H.resize(m,0);
        V.clear(); V.resize(n,0);
        For(i,n) For(j,m) {
            int x;
            scanf("%d ",&x);
            V[i]=max(V[i],x);
            H[j]=max(H[j],x);
            A.push_back(mp(x,mp(i,j)));
        }
        bool ok=true;
        For(i,A.size()) {
            if(V[A[i].second.first]>A[i].first && H[A[i].second.second]>A[i].first) ok=false;
        }
        printf("Case #%d: ",i1+1);
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
return 0;
}
