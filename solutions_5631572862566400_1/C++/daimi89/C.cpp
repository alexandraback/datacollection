#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

int C[MAXN], // component 
  F[MAXN], // friend 
  R[MAXN], // root of component
  L[MAXN], // circle length of component
  nextC,
  CD[MAXN], // distance to cycle
  CE[MAXN], // cycle entry node
  CN[MAXN], // node on cycle
  PL[MAXN]; // path length from cycle node

  
bool visited[MAXN];

int dfs(int i) { // returns component id
  if (C[i]>=0) return C[i];
  if (visited[i]) { // found circle;
    C[i]=nextC++;
    L[C[i]]=1;
    CN[i]=true,CD[i]=0;
    for (int j=F[i]; j!=i; j=F[j]) L[C[i]]++, CN[j]=true,CD[j]=0;
    R[C[i]]=i;
    return C[i];
  } else {
    visited[i]=true;
    C[i]=dfs(F[i]);
    if (!CN[i]) CD[i]=1+CD[F[i]], CE[i]=CN[F[i]]? F[i] : CE[F[i]];
    return C[i];
  };
};

main() {
  int T;
  cin >> T;
  for (int x=1; x<=T; x++) {
    cout << "Case #" << x << ": ";
    int N;
    cin >> N;
    for (int i=0; i<N; i++) { 
      cin >> F[i]; 
      F[i]--; 
      C[i]=-1;
      visited[i]=false;
      CN[i]=false;
      PL[i]=0;
    }
    nextC=0;
    for (int v=0; v<N; v++)
      dfs(v);
    
    for (int i=0; i<N; i++)
      if (!CN[i] && PL[CE[i]]<CD[i]) PL[CE[i]]=CD[i];

    int single_cycle=0,path_sum=0;
    for (int i=0; i<nextC; i++) {
      if (single_cycle<L[i]) single_cycle=L[i];
      if (R[i]==F[F[R[i]]]) // cycle length two
	path_sum += 2 + PL[R[i]] + PL[F[R[i]]];
    };


    //    cout << single_cycle << " " << path_sum;
    
    cout << max(single_cycle,path_sum);
    cout << endl;
  }
};
