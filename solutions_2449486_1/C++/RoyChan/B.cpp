#include <iostream>
using namespace std;

bool checkup(int b[][200],int i, int j, int n, int m){
  int t=b[i][j];
  while(--i>=0&&b[i][j]<=t);
  return (i==-1);
}
bool checkdown(int b[][200],int i, int j, int n, int m){
  int t=b[i][j];
  while(++i<n&&b[i][j]<=t);
  return (i==n);
}
bool checkleft(int b[][200],int i, int j, int n, int m){
  int t=b[i][j];
  while(--j>=0&&b[i][j]<=t);
  return (j==-1);
}
bool checkright(int b[][200],int i, int j, int n, int m){
  int t=b[i][j];
  while(++j<m&&b[i][j]<=t);
  return (j==m);
}

int main(){
  int t,i,j,k,n,m,p;
  int b[200][200];
  bool b1[200][200];
  bool c,c1,c2;
  cin>>t;
  for (i=1; i<=t; i++){
    cout << "Case #" << i << ": ";
    cin>>n>>m;
    for(j=0;j<n;j++)
      for(k=0;k<m;k++){
        cin>>b[j][k];
        b1[j][k]=true;
      }
    c=true;
    for(j=0;j<n;j++)
      for(k=0;k<m;k++)
        if (b1[j][k]){
          c1 = checkup(b,j,k,n,m)&&checkdown(b,j,k,n,m);
          c2 = checkleft(b,j,k,n,m)&&checkright(b,j,k,n,m);
          if (c1)
            for (p=0; p<n; p++)
              if (b[p][k]==b[j][k]) b1[p][k]=false;
          if (c2)
            for (p=0; p<m; p++)
              if (b[j][p]==b[j][k]) b1[j][p]=false;
          if ((!c1)&&(!c2)){
            c=false;
            break;
          }
        }
    if (c) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
