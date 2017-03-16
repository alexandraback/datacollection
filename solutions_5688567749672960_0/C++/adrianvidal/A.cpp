#include<bits/stdc++.h>
using namespace std;
#define lim 1000001
int dist[lim];

int reverse(int n){
   int ans = 0;
   while(n>0){
      ans = 10*ans + n%10;
      n/=10;
   }
   return ans;
}

int main(){
   fill(dist,dist+lim,-1);
   queue<int> q;
   q.push(1); dist[1]=1;
   
   while(!q.empty()){
      int curr=q.front(); q.pop();
      if (curr+1 <=1000000 && dist[curr+1]==-1){
         dist[curr+1]=dist[curr]+1; q.push(curr+1);
      }
      int nxt = reverse(curr);
      if (nxt <= 1000000 && dist[nxt]==-1){
         dist[nxt]=dist[curr]+1; q.push(nxt);
      }
   }
   
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int n; scanf("%d",&n);
      printf("Case #%d: %d\n",cs+1,dist[n]);
   }
}