#include <cstdio>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int N;
ll A[501];
bool chosen[501];
map<ll,vector<ll> > mp;
bool fin;

void search (int i,int n,ll sum) {
     if (fin) return;
     if (i>N) {
        if (n) return;
        map<ll,vector<ll> >::iterator I = mp.find(sum);
        if (I==mp.end()) {
           mp[sum]=vector<ll>();
           for (int i=1;i<=N;++i) if (chosen[i]) mp[sum].push_back(A[i]);
        }
        else {
           fin=1;
           vector<ll> v1,v2;
           for (int a=0;a<mp[sum].size();++a) {
                 bool f=0;
                 for (int b=1;b<=N;++b) if (mp[sum][a]==A[b] && chosen[b]) {
                     f=1;
                     break;
                 }
                 if (!f) v1.push_back(mp[sum][a]);
             }
             for (int a=1;a<=N;++a) if (chosen[a]) {
                 bool f=0;
                 for (int b=0;b<mp[sum].size();++b) if (mp[sum][b]==A[a]) {
                     f=1;
                     break;
                 }
                 if (!f) v2.push_back(A[a]);
             }
             for (int j=0;j<v1.size();++j) {
                 printf("%lld",v1[j]);
                 if (j!=v1.size()-1) printf(" ");
             }
             printf("\n");
             for (int j=0;j<v2.size();++j) {
                 printf("%lld",v2[j]);
                 if (j!=v2.size()-1) printf(" ");
             }
             printf("\n");
        }
        return;
     }
     chosen[i]=0;
     search(i+1,n,sum);
     if (n>0) {
        chosen[i]=1;
        search(i+1,n-1,sum+A[i]);
     }
}

int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
        fin=0;
        printf("Case #%d:\n",z);
        mp.clear();
    scanf("%d",&N);
    for (int i=1;i<=N;++i) {
        scanf("%d",&A[i]);
    }
    for (int i=1;;++i) {
        search(1,i,0);
        if (fin) break;
    }}
    return 0;
}
