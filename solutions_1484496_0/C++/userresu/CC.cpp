#include <cstdio>
#include <vector>
using namespace std;

int N;
int A[21];
bool chosen[21];
vector<int> found[2000001];
bool fin;
void search (int i,int sum) {
     if (fin) return;
     if (i>N) {
        if (found[sum].empty()) {
           for (int j=1;j<=N;++j) if (chosen[j]) found[sum].push_back(A[j]);
        }
        else {
             fin=1;
             vector<int> v1,v2;
             for (int a=0;a<found[sum].size();++a) {
                 bool f=0;
                 for (int b=1;b<=N;++b) if (found[sum][a]==A[b] && chosen[b]) {
                     f=1;
                     break;
                 }
                 if (!f) v1.push_back(found[sum][a]);
             }
             for (int a=1;a<=N;++a) if (chosen[a]) {
                 bool f=0;
                 for (int b=0;b<found[sum].size();++b) if (found[sum][b]==A[a]) {
                     f=1;
                     break;
                 }
                 if (!f) v2.push_back(A[a]);
             }
             for (int j=0;j<v1.size();++j) {
                 printf("%d",v1[j]);
                 if (j!=v1.size()-1) printf(" ");
             }
             printf("\n");
             for (int j=0;j<v2.size();++j) {
                 printf("%d",v2[j]);
                 if (j!=v2.size()-1) printf(" ");
             }
             printf("\n");
        }
        return;
     }
     chosen[i]=1;
     search(i+1,sum+A[i]);
     chosen[i]=0;
     search(i+1,sum);
}
int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
    fin=0;
    for (int i=0;i<=2000000;++i) found[i].clear();
    printf("Case #%d:\n",z);
    scanf("%d",&N);
    for (int i=1;i<=N;++i) scanf("%d",&A[i]);
    search(1,0);}
    return 0;
}
