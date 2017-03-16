#include<bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int t; scanf("%d",&t);
    for(int test=1;test<=t;test++){
        int n; ll m; scanf("%d%lld",&n,&m);
        vector< vector<int> >tab(n);
        for(int i=0;i<n;i++)tab[i].resize(n);
        vector<ll>ile(n);
        ile[n-1]=1;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++)
                if(ile[i]+ile[j]<=m && ile[i]+ile[j]>=0){
                    tab[i][j]=1;
                    ile[i]+=ile[j];
                }
        }
        if(ile[0]!=m)printf("Case #%d: IMPOSSIBLE\n",test);
        else{
            printf("Case #%d: POSSIBLE\n",test);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    printf("%d",tab[i][j]);
                puts("");
            }
        }

    }
    return 0;
}
