#include <iostream>
#include <stdio.h>
using namespace std;
int m[4][4] = {{1,2,3,4},
               {2,-1,4,-3},
               {3,-4,-1,2},
               {4,3,-2,-1}};
int a[10000+5], is[10000+5], ks[10000+5];
int abs(int a){
  return a<0?-1*a:a;
}
int calc(int a, int b){
  int ret = a*b<0?-1:1;
  return ret*m[abs(a)-1][abs(b)-1];
}
bool Solve(char s[], int L, int X){
  for(int i = 0; i < L; i++)
    if(s[i]=='i')a[i] = 2;
      else
        if(s[i]=='j')a[i] = 3;
          else
            a[i] = 4;
  fill(ks, ks+L*X+1, -1);
  fill(is, is+L*X+1, -1);
  ks[L*X]=1;
  for(int i = L*X-1; i >= 0; i--){
    ks[i] = calc(a[i%L], ks[i+1]);
  }
  for(int i = 0; i < L*X; i++){
    if(i==0)is[i] = a[i];
      else is[i] = calc(is[i-1],a[i%L]);
  }
  for(int i = 1; i < L*X-1; i++)if(is[i-1]==2){
    for(int j = i; j < L*X-1; j++)if(ks[j+1]==4){
      if(calc(is[i-1],3)==is[j])return true;
    }
  }
  return false;
}

int main(){
  freopen("C-small-attempt0.in","r",stdin);
  freopen("output.txt","w",stdout);
  int T, L, X;
  char s[10000+5];
  scanf("%d",&T);
  for(int t = 1; t <= T; t++){
    scanf("%d%d",&L,&X);
    //cout<<L<<" "<<X<<endl;
    gets(s);
    gets(s);
    //cout<<s<<endl;
    printf("Case #%d: ",t);
    if(Solve(s,L,X))printf("YES\n");
      else 
        printf("NO\n");
  }
  return 0;
}