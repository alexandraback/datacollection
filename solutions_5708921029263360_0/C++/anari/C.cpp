#include <iostream>
#include <cstring>
using namespace std;
int Ta[3][3], Tb[3][3], Tc[3][3];
int mem[4][4][4][4];
int solve(int a, int b, int c, int k){
  if (k>c)
    k=c;
  if (mem[a][b][c][k]!=-1)
    return mem[a][b][c][k];
  int n=a*b*c;
  int ans=-1;
  int M;
  for (int m=0;m<(1<<n);++m){
    memset(Ta,0,sizeof(Ta));
    memset(Tb,0,sizeof(Tb));
    memset(Tc,0,sizeof(Tc));
    int cnt=__builtin_popcount(m);
    if (cnt<ans)
      continue;
    for (int ia=0;ia<a;++ia)
      for (int ib=0;ib<b;++ib)
        for (int ic=0;ic<c;++ic){
          int I=ic+c*(ib+b*ia);
          if ((m&(1<<I))!=0){
            ++Ta[ib][ic];
            ++Tb[ic][ia];
            ++Tc[ia][ib];
          }
        }
    bool flag = false;
    for (int ia=0;ia<a;++ia)
      for (int ib=0;ib<b;++ib)
        for (int ic=0;ic<c;++ic){
          if (Ta[ib][ic]>k)
            flag = true;
          if (Tb[ic][ia]>k)
            flag = true;
          if (Tc[ia][ib]>k)
            flag = true;
        }
    if (!flag && (cnt>ans)){
      ans=cnt;
      M = m;
    }
  }
  mem[a][b][c][k] = M;
  return M;
}
int main(){
  memset(mem, -1, sizeof mem);
  int tcou;
  cin>>tcou;
  for (int tnum=1;tnum<=tcou;++tnum){
    cout<<"Case #"<<tnum<<": ";
    int a, b, c, k;
    cin>>a>>b>>c>>k;
    int n=a*b*c;
    int M = solve(a, b, c, k);
    cout<<__builtin_popcount(M)<<endl;
    for (int ia=0;ia<a;++ia)
      for (int ib=0;ib<b;++ib)
        for (int ic=0;ic<c;++ic){
          int I=ic+c*(ib+b*ia);
          if ((M&(1<<I))!=0){
            cout<<ia+1<<' '<<ib+1<<' '<<ic+1<<endl;
          }
        }
  }
  return 0;
}
