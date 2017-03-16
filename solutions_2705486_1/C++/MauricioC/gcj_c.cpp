#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int trie[1500000][26];
bool end[1500000];
int memo[4000][10];
vector<int> wrd;

bool possible(int pos, int size, int error1, int error2, int root) {
    if(size == 0) return end[root];

    if(pos == error1 || pos == error2) {
        for(int i = 0; i < 26; i++)
            if(trie[root][i] != -1 &&
               possible(pos+1, size-1, error1, error2, trie[root][i]))
                return true;
    } else {
        if(trie[root][wrd[pos]] != -1 &&
           possible(pos+1, size-1, error1, error2, trie[root][wrd[pos]]))
            return true;
    }

    return false;
}

int doit(int pos, int first_err) {
    if(pos == (int)wrd.size()) return 0;

    int& ret = memo[pos][first_err];
    if(ret != -1) return ret;
    ret = 0x3f3f3f3f;

    for(int size = 1; size <= 10 && size+pos <= (int)wrd.size(); size++) {
        for(int error1 = first_err; error1 < size; error1++) {
            for(int error2 = error1+5; error2 < size; error2++) {
                if(possible(pos, size, pos+error1, pos+error2, 0))
                    ret = min(ret, 2+doit(pos+size, max(0, 5-(size-error2))));
            }

            if(possible(pos, size, pos+error1, -1, 0))
                ret = min(ret, 1+doit(pos+size, max(0, 5-(size-error1))));
        }

        if(possible(pos, size, -1, -1, 0))
            ret = min(ret, doit(pos+size, max(0, first_err-size)));
    }

    return ret;
}

int main() {
    memset(trie, -1, sizeof trie);
    memset(end, 0, sizeof end);

    ifstream fin("garbled_email_dictionary.txt");
    string word;

    int num_nodes = 1;
    while(fin >> word) {
        int trie_node = 0;

        for(unsigned int i = 0; i < word.size(); i++) {
            if(trie[trie_node][word[i] - 'a'] == -1)
                trie[trie_node][word[i] - 'a'] = num_nodes++;
            trie_node = trie[trie_node][word[i] - 'a'];
        }

        end[trie_node] = true;
    }

    int t;
    cin >> t;

    for(int z = 1; z <= t; z++) {
        string inp;
        cin >> inp;

        memset(memo, -1, sizeof memo);
        wrd.clear();
        for(unsigned int i = 0; i < inp.size(); i++)
            wrd.push_back(inp[i] - 'a');

        cout << "Case #" << z << ": " << doit(0, 0) << endl;
    }
}
