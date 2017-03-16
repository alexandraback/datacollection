#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define NUMW 521196
#define MAXNODES 1200000

int trie[MAXNODES][26],cont = 1;
bool end[MAXNODES];

void trie_add(string &s){
    int L = s.size(),pos = 0;
    
    for(int i = 0;i < L;++i){
        int c = s[i] - 'a';
        
        if(trie[pos][c] == 0) trie[pos][c] = cont++;
        pos = trie[pos][c];
    }
    
    end[pos] = true;
}

#define MAXLEN 4000

string s;
int LS;
map<int, int> memo[MAXLEN];

int solve(int pos, int trie_pos){
    if(pos == LS){
        if(end[trie_pos]) return 0;
        return LS;
    }
    
    if(memo[pos].find(trie_pos) != memo[pos].end())
        return memo[pos][trie_pos];
    
    int ret = LS;
    
    for(int i = 0;i < 26;++i){
        int to = trie[trie_pos][i];
        
        if(to){
            if(s[pos] - 'a' == i){
                if(end[to]) ret = min(ret,solve(pos + 1,0));
                ret = min(ret,solve(pos + 1,to));
            }else{
                for(int mask = 0;mask < (1 << 5);++mask){
                    int pos2 = pos;
                    int cur = to;
                    bool ok = true;
                    
                    if((mask & 1) && !end[cur]) ok = false;
                    if(mask & 1) cur = 0;
                    
                    for(int j = 1;j <= 4 && pos2 + 1 < LS && ok;++j){
                        ++pos2;
                        cur = trie[cur][ s[pos2] - 'a' ];
                        if(cur == 0) ok = false;
                        if((mask & (1 << j)) && !end[cur]) ok = false;
                        if(mask & (1 << j)) cur = 0;
                    }
                    
                    if(ok){
                        if(end[cur]) ret = min(ret,1 + solve(pos2 + 1,0));
                        ret = min(ret,1 + solve(pos2 + 1,cur));
                    }
                }
                /*if(end[to]) ret = min(ret,1 + solve(pos + 1,pos,0));
                ret = min(ret,1 + solve(pos + 1,pos,to));*/
            }
        }
    }
    //cout << pos << " " << last + 1 << " " << trie_pos << " : " << ret << endl;
    memo[pos][trie_pos] = ret;
    return ret;
}

int main(){
    fstream fs;
    fs.open("garbled_email_dictionary.txt", fstream::in);
    string word;
    
    int maxlen = 0;
    
    for(int i = 0;i < NUMW;++i){
        fs >> word;
        trie_add(word);
    }
    
    fs.close();
    
    int T;
    
    cin >> T;
    
    for(int tc = 1;tc <= T;++tc){
        cin >> s;
        LS = s.size();
        
        if(tc > 1)
            for(int i = 0;i < MAXLEN;++i)
                memo[i].clear();
        
        cout << "Case #" << tc << ": " << solve(0,0) << endl;
    }
    
    return 0;
}
