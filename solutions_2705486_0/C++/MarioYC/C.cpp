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

string s;
int LS;
map<int, int> memo[50][51];

int solve(int pos, int last, int trie_pos){
    if(pos == LS){
        if(end[trie_pos]) return 0;
        return LS;
    }
    
    if(memo[pos][last + 1].find(trie_pos) != memo[pos][last + 1].end())
        return memo[pos][last + 1][trie_pos];
    
    int ret = LS;
    
    for(int i = 0;i < 26;++i){
        int to = trie[trie_pos][i];
        
        if(to && (last == -1 || s[pos] - 'a' == i || pos - last >= 5)){
            if(s[pos] - 'a' == i){
                ret = min(ret,solve(pos + 1,last,to));
                if(end[to]) ret = min(ret,solve(pos + 1,last,0));
            }else{
                ret = min(ret,1 + solve(pos + 1,pos,to));
                if(end[to]) ret = min(ret,1 + solve(pos + 1,pos,0));
            }
        }
    }
    //cout << pos << " " << last + 1 << " " << trie_pos << " : " << ret << endl;
    memo[pos][last + 1][trie_pos] = ret;
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
        
        if(tc > 1){
            for(int i = 0;i < 50;++i)
                for(int j = 0;j <= 50;++j)
                    memo[i][j].clear();
        }
        
        cout << "Case #" << tc << ": " << solve(0,-1,0) << endl;
    }
    
    return 0;
}
