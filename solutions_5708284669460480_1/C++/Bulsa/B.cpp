#include <bits/stdc++.h>

#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)
#define FORD(i,a,b) for(ll i=ll(b)-1; i>=(a); --i)
using namespace std;

using ll = long long;

//aho corasick from github.com/ADJA/algos/blob/master/Strings/Aho-Corasick.cpp

struct node {
    int suff_link, par;
    char c;
    map < char, int > go;
    bool is_word;   

    node() {
        suff_link = -1, par = -1;
        is_word = false;
    }
};

int n;
vector <node> trie;

void trieInsert(const char * s) {
    int cur_node = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int go = trie[cur_node].go[s[i]];
        if (go == 0) {
            node add;
            add.par = cur_node; add.c = s[i];
            trie.push_back(add);
            go = (int) trie.size() - 1;
            trie[cur_node].go[s[i]] = go;
        }
        cur_node = go;
    }   
    trie[cur_node].is_word = true;
}

int go(int cur_node, char c);

int getSuffLink(int cur_node) {
    if (trie[cur_node].suff_link != -1)
        return trie[cur_node].suff_link;
    if (trie[cur_node].par == 0) 
        return trie[cur_node].suff_link = 0;
    char c = trie[cur_node].c;
    int parent = trie[cur_node].par;
    return trie[cur_node].suff_link = go(trie[parent].suff_link, c); 
}

int go(int cur_node, char c) {
    if (trie[cur_node].go.count(c) > 0)
        return trie[cur_node].go[c];
    if (cur_node == 0)
        return trie[cur_node].go[c] = 0;
    int suff_link = getSuffLink(cur_node);
    return trie[cur_node].go[c] = go(suff_link, c);
}

void buildAhoCorasick() {
    queue <int> q;
    q.push(0);
    while (!q.empty()) {
        int cur_node = q.front();
        q.pop();

        for (map <char, int> :: iterator it = trie[cur_node].go.begin(); it != trie[cur_node].go.end(); it++) {
            q.push(it->second);
        }

        int suff_link = getSuffLink(cur_node);
        trie[cur_node].suff_link = suff_link;
        if (trie[suff_link].is_word)
            trie[cur_node].is_word = true;
    }
}


static string letters;
static string target;
static ll K, L, S; 

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    FOR(tc,1,T+1) {
        cin >> K >> L >> S;
        cin >> letters >> target;
        node root;
        root.suff_link = 0;
        trie.clear();
        trie.push_back(root);
        trieInsert(target.c_str());
        buildAhoCorasick();
        map<pair<ll,ll>,double> props {{make_pair(0,0),1}};
        FOR(i,0,S) {
            decltype(props) nprops;
            for(const auto & x : props) {
                int cur_node = x.first.first;
                int found = x.first.second;
                double p = x.second;
                for(char c : letters) {
                    int nnode = go(cur_node, c);
                    int nfound = found;
                    if(trie[nnode].is_word) ++ nfound;
                    nprops[{nnode,nfound}] += p/letters.size();
                }
            }
            swap(props,nprops);
        }
        ll ma = 0;
        for(const auto &x : props) {
            ma = max(ma, x.first.second);
        }
        double res = 0;
        for(const auto &x : props) {
            res += x.second*(ma-x.first.second);
        }
        cout << "Case #" << tc << ": " << fixed << setprecision(10) << res << endl;
    }
}
