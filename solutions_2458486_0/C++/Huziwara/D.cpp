#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n,C[200],M[200],T[200][400];
vector<vector<int> > e;

bool pos(bool a[200],int K[200])
{
  int S[200];
  for(int i=0;i<n;i++){
    S[i]=a[i];
  }
  queue<int> Q;
  for(int i=0;i<n;i++){
    if(!S[i]&&K[C[i]]){
      Q.push(i);
      S[i]=1;
    }
  }
  while(!Q.empty()){
    int i=Q.front();
    Q.pop();
    for(int j=0;j<e[i].size();j++){
      int k=e[i][j];
      if(!S[k]){
	Q.push(k);
	S[k]=1;
      }
    }
  }
  bool b=1;
  for(int i=0;i<n;i++){
    if(!S[i]){
      b=0;
    }
  }
  return b;
}

int main()
{
  int t;
  scanf("%d",&t);
  for(int CS=1;CS<=t;CS++){
    int k;
    scanf("%d%d",&k,&n);
    int K[200]={0};
    for(int i=0;i<k;i++){
      int a;
      scanf("%d",&a);
      a--;
      K[a]++;
    }
    bool H[200][200]={0};
    for(int i=0;i<n;i++){
      scanf("%d%d",C+i,M+i);
      C[i]--;
      for(int j=0;j<M[i];j++){
	scanf("%d",T[i]+j);
	T[i][j]--;
	H[i][T[i][j]]=1;
      }
    }
    e.clear();
    for(int i=0;i<n;i++){
      vector<int> E;
      for(int j=0;j<n;j++){
	if(H[i][C[j]]){
	  E.push_back(j);
	}
      }
      e.push_back(E);
    }
    bool a[200]={0};
    printf("Case #%d:",CS);
    int L[200];
    int i;
    for(i=0;i<n;i++){
      int j;
      for(j=0;j<n;j++){
	if(a[j]||!K[C[j]]){
	  continue;
	}
	a[j]=1;
	K[C[j]]--;
	for(int l=0;l<M[j];l++){
	  K[T[j][l]]++;
	}
	if(pos(a,K)){
	  L[i]=j;
	  break;
	}
	a[j]=0;
	K[C[j]]++;
	for(int l=0;l<M[j];l++){
	  K[T[j][l]]--;
	}
      }
      if(j==n){
	break;
      }
    }
    if(i<n){
      printf(" IMPOSSIBLE\n");
    }
    else{
      for(int i=0;i<n;i++){
	printf(" %d",L[i]+1);
      }
      putchar('\n');
    }
  }
  return 0;
}
