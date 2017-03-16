#include<cstdio>
#include<vector>
using namespace std;

vector< vector<long> > v;
bool visited[1001];

bool DFS(long c){
   if(visited[c]) return true;
   visited[c] = true;
   long l = v[c].size();
   bool done = false;
   for(long d = 0; (d < l) && !done; d++){
      done = DFS(v[c][d]);
   }
   return done;
}

int main(){
   long t, n, m;
   scanf("%ld", &t);
   for(long a = 0; a < t; a++){
      v.clear();
      scanf("%ld", &n);

      for(long c = 0; c < n; c++){
         visited[c] = false;
         vector<long> vc;
         v.push_back(vc);
         scanf("%ld", &m);
         for(long d = 0; d < m; d++){
            long temp;
            scanf("%ld", &temp);
            v[c].push_back(temp-1);
         }
      }
      bool done = false;
      for(long c = 0; (c < n) && !done; c++){
         for(long d = 0; d < n; d++){
            visited[d] = false;
         }
         done = DFS(c);
      }
      if(done){
         printf("Case #%ld: Yes\n", a+1);
      }
      else{
         printf("Case #%ld: No\n", a+1);
      }
   }
}
