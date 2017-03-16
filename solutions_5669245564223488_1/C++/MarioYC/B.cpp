#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define MOD 1000000007

int N;
string s[100];
int len[100];
vector<int> start[26],end[26];
int cont[26],cont_all[26];
int cont_comp;

long long fact[1001];

int parent[26];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

bool Union(int x, int y){
    x = Find(x), y = Find(y);
    
    if(x != y){
        parent[x] = y;
        --cont_comp;
        return true;
    }else return false;
}

int main(){
    //ios::sync_with_stdio(0);
    fact[0] = 1;
    
    for(int i = 1;i <= 100;++i)
        fact[i] = fact[i - 1] * i % MOD;
    
    int TC;
    
    cin >> TC;
    
    for(int tc = 1;tc <= TC;++tc){
        cin >> N;
        bool ok = true;
        
        memset(cont,0,sizeof cont);
        memset(cont_all,0,sizeof cont_all);
        
        for(int i = 0;i < 26;++i){
            start[i].clear();
            end[i].clear();
        }
        
        for(int i = 0;i < N;++i){
            cin >> s[i];
            len[i] = s[i].size();
            
            for(int j = 0;j < len[i];++j)
                ++cont[ s[i][j] - 'a' ];
        }
        
        cont_comp = 0;
        
        for(int i = 0;i < N;++i){
            char c1 = s[i][0],c2 = s[i][ len[i] - 1 ];
            int l1 = 0,l2 = 0;
            
            while(l1 < len[i] && s[i][l1] == c1) ++l1;
            while(l2 < len[i] && s[i][ len[i] - 1 - l2 ] == c2) ++l2;
            
            if(l1 == len[i]){
                ++cont_all[c1 - 'a'];
            }else{
                end[c1 - 'a'].push_back(i);
                start[c2 - 'a'].push_back(i);
                ++cont_comp;
                
                for(int j = l1;j < len[i] - l2;){
                    int e = j;
                    
                    while(e < len[i] - l2 && s[i][e] == s[i][j])
                        ++e;
                    
                    if(e - j != cont[ s[i][j] - 'a' ]) ok = false;
                    j = e;
                }
            }
        }
        
        //cout << ok << endl;
        
        for(int i = 0;i < 26;++i)
            if(start[i].size() > 1 || end[i].size() > 1)
                ok = false;
        
        //cout << ok << endl;
        
        for(int i = 0;i < 26;++i)
            parent[i] = i;
        
        for(int i = 0;i < 26;++i){
            if(!start[i].empty() && !end[i].empty() && !Union(start[i][0],end[i][0]))
                ok = false;
            //if(!start[i].empty() && !end[i].empty()) cout << i << " "  << start[i][0] << " " << end[i][0] << " " << ok << endl;
        }
        
        //cout << ok << endl;
        
        cout << "Case #" << tc << ": ";
        
        if(!ok) cout << 0 << '\n';
        else{
            long long ans = 1;
            
            for(int i = 0;i < 26;++i){
                ans = ans * fact[ cont_all[i] ] % MOD;
                
                if(cont_all[i] > 0 && start[i].empty() && end[i].empty())
                    ++cont_comp;
            }
            
            ans = ans * fact[ cont_comp ] % MOD;
            
            cout << ans << '\n';
        }
    }
    
    return 0;
}
