#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;

char re[100][100];
char hoge[10][3][4]={
  {},{"c**","***","***"},
  {},{},
  {"c.*","..*","***"},{},
  {"c..","...","***"},{},
  {"c..","...","..*"},{"c..","...","..."}};


bool solve(int R,int C,int M){
  int i,j;
  for(i=0;i<R;i++)for(j=0;j<C;j++)re[i][j]='.';
  re[0][0]='c';
  if(R==1){
    for(i=0;i<M;i++)
      re[0][i]='*';
    for(;i<C;i++)
      re[0][i]='.';
    re[0][C-1]='c';
  }else if(R==2){
    if(M%2||R*C-M==2)return 1;
    for(i=0;i*2<M;i++)
      re[0][i]=re[1][i]='*';
    for(;i<C;i++)
      re[0][i]=re[1][i]='.';
    re[1][C-1]='c';
  }else{
    if(R*C-M==2 || R*C-M==3 ||
       R*C-M==5 || R*C-M==7)
      return 1;
    if(R*C-M<10)
      for(i=0;i<3;i++)
        for(j=0;j<3;j++)
          re[i][j]=hoge[R*C-M][i][j];
    for(i=C-1;i>2;i--){
      for(j=R-1;j>=0;j--){
        if(M==0){
          if(j==0){
            re[1][i]='.';
            re[R-1][i-1]='*';
          }
          return 0;
        }
        re[j][i]='*';
        M--;
      }
    }
    for(i=R-1;i>2;i--){
      for(j=2;j>=0;j--){
        if(M==0){
          if(j==0){
            re[i][1]='.';
            re[i-1][2]='*';
          }return 0;
        }
        re[i][j]='*';
        M--;
      }
    }
  }

  return 0;
}
int main(){
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++){
    cout<<"Case #"<<t<<": "<<endl;
    int i,j,M,R,C,swp=0;
    cin>>R>>C>>M;
    if(M==0){
      for(i=0;i<R;i++){
        for(j=0;j<C;j++){
          if(i+j)
            printf(".");
          else
            printf("c");
        }printf("\n");
      }
    }else if(R*C-M==1){
      for(i=0;i<R;i++){
        for(j=0;j<C;j++){
          printf((i+j)?"*":"c");
        }printf("\n");
      }continue;
    }else{
      if(R>C){
        swp=1;
        swap(R,C);
      }
      if(solve(R,C,M)){
        printf("Impossible\n");
        continue;
      }
      if(swp)swap(R,C);
      for(i=0;i<R;i++){
        for(j=0;j<C;j++){
          printf("%c",(swp?re[j][i]:re[i][j]));
        }printf("\n");
      }
    }
  }
  return 0;
}