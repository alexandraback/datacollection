#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define ll                      long long

#define inc(i,a,b)              for(int i=a;i<=b;++i)
#define dec(i,a,b)              for(int i=a;i>=b;--i)

int main() {
    int T; cin >> T;
    
    inc(t,1,T) {
        int n, m, k;
        cin >> n >> m >> k;
        
        int ans = 1e9;
        
        int s = n*m;
        inc(i,0,(1<<s)-1) {
            queue<int> q;
            int vis[s];
            
            inc(j,0,s-1) {
                vis[j] = 0;
                
                if(i&(1<<j)) continue;
                
                if((j<m || (j>=(n-1)*m))) {
                    q.push(j);
                    vis[j] = 1;
                }
                else if(j%m==0 || (j+1)%m==0) {
                    q.push(j);
                    vis[j] = 1;
                }
            }
            
            while(!q.empty()) {
                int x = q.front();
                q.pop();
                
                if((x+1)%m != 0) {
                    if(!vis[x+1] && (i&(1<<(x+1)))==0) {
                        q.push(x+1);
                        vis[x+1] = 1;
                    }
                }
                if(x%m != 0) {
                    if(!vis[x-1] && (i&(1<<(x-1)))==0) {
                        q.push(x-1);
                        vis[x-1] = 1;
                    }
                }
                if(x>=m) {
                    if(!vis[x-m] && (i&(1<<(x-m)))==0) {
                        q.push(x-m);
                        vis[x-m] = 1;
                    }
                }
                if(x<(n-1)*m) {
                    if(!vis[x+m] && (i&(1<<(x+m)))==0) {
                        q.push(x+m);
                        vis[x+m] = 1;
                    }
                }
            }
            
            int stones = 0, inter = 0;
            inc(j,0,s-1) {
                if(i&(1<<j)) stones++;
                if(!vis[j]) inter++;
            }
            
            
            if(inter>=k) ans = min(ans,stones);
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}