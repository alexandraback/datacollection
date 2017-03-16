#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<complex>
#include<map>
#include<list>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

typedef long double D;

int n,x,y;
bool dia[10000][20100];
const int G = 10000;

D drop(int h,int w,D prob,int num);

D rec(int num, D prob){
  if(num==n){
    if(dia[y][x+G])return prob;
    else return 0;
  }
  int h = 0,w = G;
  for(int i=99;i>=0;i--){
    if(dia[i][G]){
      h = i+2;
      break;
    }
  }
  return drop(h,w,prob,num);
}

D drop(int h,int w,D prob,int num){
  D res = 0;
  if(h<=0){
    dia[h][w] = 1;
    res += rec(num+1,prob);
    dia[h][w] = 0;
    return res;
  }

  if(dia[h-1][w-1] && dia[h-1][w+1]){
    dia[h][w] = 1;
    res += rec(num+1,prob);
    dia[h][w] = 0;
    return res;
  }

  if(dia[h-1][w-1]){
    res += drop(h-1,w+1,prob,num);
    return res;
  }

  if(dia[h-1][w+1]){
    res += drop(h-1,w-1,prob,num);
    return res;
  }

  res += drop(h-1,w-1,prob/2,num);
  res += drop(h-1,w+1,prob/2,num);
  return res;
}
    
int main(){
  int testcase;
  D ans;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    cin >> n >> x >> y;
    
    for(int i=0;i<10000;i++)
      for(int j=0;j<=20000;j++)dia[i][j] = 0;
    ans = rec(0,1.0);

    cout << "Case #" << casenum << ": ";
    printf("%.9Lf\n",ans);
  }
}
