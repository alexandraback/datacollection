#include <stdio.h>
#include <string.h>
#include <cassert>

long long ansa, ansb;
char s1[20], s2[20];

long long pow10[19];
void build(){
   pow10[0] = 1LL;
   for(int i=1; i<=18; ++i)
      pow10[i] = pow10[i-1] * 10;
}

long long abs(long long a){
   return a < 0? -a : a;
}

void dfs(int now, int n, long long a, long long b){
   if(now == n){
      if(abs(a-b) < abs(ansa-ansb) || 
            (abs(a-b) == abs(ansa-ansb) && a < ansa) ||
            (abs(a-b) == abs(ansa-ansb) && a == ansa && b < ansb)){
         ansa = a;
         ansb = b;
      }
      return;
   }
   long long nxta, nxtb;
   if(a > b){
      if(s1[now] != '?') 
         nxta = a + (s1[now]-'0') * pow10[n-now-1];
      else
         nxta = a;
      if(s2[now] != '?')
         nxtb = b + (s2[now]-'0') * pow10[n-now-1];
      else
         nxtb = b + 9 * pow10[n-now-1];
      dfs(now+1, n, nxta, nxtb);
   }
   else if(a < b){
      if(s1[now] != '?') 
         nxta = a + (s1[now]-'0') * pow10[n-now-1];
      else
         nxta = a + 9 * pow10[n-now-1];
      if(s2[now] != '?')
         nxtb = b + (s2[now]-'0') * pow10[n-now-1];
      else
         nxtb = b;
      dfs(now+1, n, nxta, nxtb);
   }
   else{
      if(s1[now] != '?' && s2[now] != '?'){
         nxta = a + (s1[now]-'0') * pow10[n-now-1];
         nxtb = b + (s2[now]-'0') * pow10[n-now-1];
         dfs(now+1, n, nxta, nxtb);
      }
      else if(s1[now] != '?' && s2[now] == '?'){
         nxta = a + (s1[now]-'0') * pow10[n-now-1];
         nxtb = b + (s1[now]-'0') * pow10[n-now-1]; 
         dfs(now+1, n, nxta, nxtb);
         if(s1[now] > '0')
            dfs(now+1, n, nxta, nxtb - pow10[n-now-1]);
         if(s1[now] < '9')
            dfs(now+1, n, nxta, nxtb + pow10[n-now-1]);
      }
      else if(s1[now] == '?' && s2[now] != '?'){
         nxta = a + (s2[now]-'0') * pow10[n-now-1];
         nxtb = b + (s2[now]-'0') * pow10[n-now-1]; 
         dfs(now+1, n, nxta, nxtb);
         if(s2[now] > '0')
            dfs(now+1, n, nxta - pow10[n-now-1], nxtb);
         if(s2[now] < '9')
            dfs(now+1, n, nxta + pow10[n-now-1], nxtb);
      }
      else{
         dfs(now+1, n, a, b);
         dfs(now+1, n, a + pow10[n-now-1], b);
         dfs(now+1, n, a, b + pow10[n-now-1]);
      }
   }
}

void print(long long a, int n){
   char s[20];
   s[n] = '\0';
   for(int i=n-1; i>=0; --i){
      s[i] = '0' + a%10;
      a /= 10;
   }
   printf("%s", s);
}

int main(){
   build();
   int T, n;
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      printf("Case #%d: ", t);
      scanf("%s%s", s1, s2);
      n = strlen(s1);
      ansa = pow10[n];
      ansb = 0;
      dfs(0, n, 0, 0);
      print(ansa, n);
      printf(" ");
      print(ansb, n);
      printf("\n");
   }
   return 0;
}
