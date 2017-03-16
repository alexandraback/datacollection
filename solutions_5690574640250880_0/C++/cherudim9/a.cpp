#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#define sz(a) ((int)(a).size())
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define Rep(i,j,k) for (int i=(j); i<=(k); i++)
#define Repd(i,j,k) for (int i=(j); i>=(k); i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
#define RAND ((rand()<<15)+rand())
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

int T;
int a[100][100], b[100][100], n, m, tot;

int main(){
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  cin>>T;
  Rep(tt,1,T){
    cout<<"Case #"<<tt<<": "<<endl;

    cin>>n>>m>>tot;
    memset(a,0,sizeof a);
    tot=n*m-tot;

    if (tot==1){
      for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
          if (i==1 && j==1) cout<<'c';else cout<<'*';
        cout<<endl;
      }
      continue;
    }

    if (n==1){
      cout<<'c';
      for(int j=2; j<=m; j++)
        if (j<=tot) cout<<"."; else cout<<'*';
      cout<<endl;
      continue;
    }

    if (m==1){
      cout<<'c'<<endl;
      for(int j=2; j<=n; j++)
        if (j<=tot) cout<<"."<<endl; else cout<<'*'<<endl;
      continue;
    }

    bool found=0;
    for(int i=2; i<=n && !found; i++)
      for(int j=2; j<=m && !found; j++)
        if (i*j>=tot){
          int rest=i*j-tot;
          memset(a,0,sizeof a);
          for(int i0=1; i0<=i; i0++)
            for(int j0=1; j0<=j; j0++)
              a[i0][j0]=1;
          for(int i0=i; i0>=3; i0--)
            for(int j0=j; j0>=3; j0--)
              if (rest){
                rest--;
                a[i0][j0]=0;
              }
          if (rest==0){
            found=1;
          }
        }

    if (!found) cout<<"Impossible"<<endl; else{
      for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
          if (i==1 && j==1)
            cout<<'c';
          else
            if (!a[i][j])
              cout<<'*';
            else
              cout<<'.';
        cout<<endl;
      }
    }

  }
  return 0;
}
