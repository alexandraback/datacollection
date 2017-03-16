#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

#define ll                      long long

#define inc(i,a,b)              for(int i=a;i<=b;++i)
#define dec(i,a,b)              for(int i=a;i>=b;--i)

#define sz(arr)                 ((int)(arr.size()))

const int mod = 1e9+7;

ll fact(ll x) {
    if(x==0) return 1;
    return (((x%mod)*fact(x-1))%mod);
}

int main() {
    int T; cin >> T;
    inc(t,1,T) {
        cout << "Case #" << t << ": ";
        
        int next[26], prev[26], mid[26], left[26], right[26], ent[26], vis[26];
        inc(i,0,25) next[i] = prev[i] = -1;
        inc(i,0,25) mid[i] = left[i] = right[i] = ent[i] = vis[i] = 0;
        
        ll ans = 1;
        
        int n; cin >> n;
        string str[n], fin[n];
        
        inc(i,0,n-1) {
            cin >> str[i];
            
            bool occ[26];
            inc(j,0,25) occ[j] = 0;
            
            inc(j,0,sz(str[i])-1) {
                int ch = str[i][j]-'a';
                if(occ[ch]) {
                    assert(j!=0);
                    if(str[i][j-1]!=str[i][j]) {
                        ans = 0;
                    }
                }
                occ[ch] = 1;
            }
            
            inc(j,0,25) mid[j] += occ[j];
            
            fin[i].push_back(str[i][0]);
            fin[i].push_back(str[i][sz(str[i])-1]);
            
            int l = fin[i][0]-'a', r = fin[i][1]-'a';
            
            if(l == r) {
                ent[l]++;
                mid[l]--;
            }
            else {
                left[l]++;
                right[r]++;
                mid[l]--;
                mid[r]--;
                
                next[l] = r;
                prev[r] = l;
            }
        }
        
        inc(i,0,25) {
            if(mid[i]>1) ans = 0;
            if(mid[i]==1 and (left[i]>0 or right[i]>0 or ent[i]>0)) ans = 0;
            
            if(left[i]>1 or right[i]>1) ans = 0;
            
            if(mid[i]>0) vis[i] = 1;
            if(mid[i]==0 and left[i]==0 and right[i]==0 and ent[i]==0) vis[i] = 1;
        }
        
        int components = 0;
        inc(i,0,25) {
            if(!vis[i]) {
                int j = next[i];
                while(j!=-1) {
                    if(vis[j]) {
                        ans = 0;
                        break;
                    }
                    
                    vis[j] = 1;
                    j = next[j];
                }
                j = prev[i];
                while(j!=-1) {
                    if(vis[j]) {
                        ans = 0;
                        break;
                    }
                    vis[j] = 1;
                    j = prev[j];
                }
                
                components++;
                vis[i] = 1;
            }
//             cerr << ent[i] << "\n";
            ans *= fact(ent[i]);
        }
//         cerr << components << "\n";
        ans *= fact(components);
        cout << ans << "\n";
    }
}