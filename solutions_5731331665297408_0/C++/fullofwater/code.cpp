#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

int T,Cas=0;
int N, M, cpy[8];

bool mat[8][8], gray[8];
int arr[8], look[8];//, prev[8];

int main() {
	scanf("%d",&T);
	while (T--) {
    scanf("%d%d",&N,&M);
    map<int,int> conv;
    for (int i=0;i<N;i++) {
      scanf("%d",cpy+i);
      conv[cpy[i]]=i;
    }
    sort(cpy,cpy+N);
    for (int i=0;i<N;i++)
      look[conv[cpy[i]]]=i;
    //for (int i=0;i<N;i++)
    //  printf("%d -> %d\n", i+1,look[i]);
    memset(mat,0,sizeof(mat));
    int u,v;
    for (int i=0;i<M;i++) {
      scanf("%d%d",&u,&v);
      --u, --v;
      u=look[u], v=look[v];
      mat[u][v]=mat[v][u]=true;
      //printf("(%d,%d)\n",u,v);
    }
    for (int i=0;i<N;i++)
      arr[i]=i;
    do {
      bool yes=true;
      //memset(prev,-1,sizeof(prev));
      memset(gray,0,sizeof(gray));
      //for (int i=0;i<N;i++)
      //  printf("%d,",arr[i]);
      //puts("");
      for (int i=1;i<N;i++) {
        for (int j=i-1;j>=0;j--) {
          if (!gray[j] && mat[arr[j]][arr[i]]) {
            //prev[i]=j;
      //if (arr[0]==0 && arr[1]==2 && arr[2]==1) {
      //  printf("--- %d %d\n", j, i);
      //}
            for (int k=j+1;k<i;k++)
              gray[k]=true;
            break;
          }
          if (!j)
            yes=false;
        }
        if (!yes)
          break;
      }
      //out:
      if (!yes)
        continue;
      /*for (int i=2;i<N;i++) {
        for (int j=1;j<i;j++)
          if (prev[i]<j && prev[i]>prev[j]) {
            yes=false;
            goto out;
          }
      }*/
      printf("Case #%d: ", ++Cas);
      for (int i=0;i<N;i++)
        printf("%d", cpy[arr[i]]);
      puts("");
      break;
    } while (next_permutation(arr,arr+N));
	}
}
