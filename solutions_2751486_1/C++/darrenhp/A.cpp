#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

const int MAXL = 1024*1024;
int T;
int n;
int L;
char a[MAXL];
int c[MAXL];
int S;


int solve(){
  int s = 0;
  int l, r;
  l = r = 0;
  memset(c, 0, sizeof(c));
  for (int i = 1; i <= L; i++){
    char ch = a[i-1];
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
      c[i] = 0;
    else{
      if (i == 0)
        c[i] = 1;
      c[i] = c[i-1]+1;
    }
  }
  for (r = 1; r <= L; r++){
    if (c[r] >= n){
      l = r - n + 1;
    }
    s += r-l;
  }
  return L*(L+1)/2-s;
}

int main(){
  scanf("%d", &T);
  for (int CASE = 1; CASE <= T; CASE++){
    scanf("%s%d", a, &n);
    L = strlen(a); 
    S = solve();
    printf("Case #%d: %d\n", CASE, S);
  }
}
    

