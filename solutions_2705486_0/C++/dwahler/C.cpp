// David Wahler <dwahler@gmail.com>
// Google Code Jam submission: 

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define D(x) 

struct TrieNode {
    char children;
    int index;
    bool isWord;
    char *childChars;
    TrieNode **childPtrs;
};

TrieNode *buildTrie(const vector<string>& words, int index, int& startPos, string prefix, vector<TrieNode *>& nodeArray) {
    TrieNode *result = new TrieNode;
    result->children = 0;
    result->isWord = false;
    if (words[startPos].length() == index) {
        result->isWord = true;
        startPos++;
    }

    result->index = nodeArray.size();
    nodeArray.push_back(result);

    
    vector<char> childChars;
    vector<TrieNode *> childPtrs;

    for (char c = 'a'; c <= 'z'; c++) {
        if (startPos >= words.size()) break;
        if (words[startPos].substr(0, index) != prefix) break;

        if (words[startPos][index] == c) {
            childChars.push_back(c);
            childPtrs.push_back(buildTrie(words, index+1, startPos, prefix+c, nodeArray));
        }
    }

    if (childChars.size() > 0) {
        result->children = childChars.size();
        result->childChars = new char[childChars.size()];
        result->childPtrs = new TrieNode *[childChars.size()];
        for (int i = 0; i < childChars.size(); i++) {
            result->childChars[i] = childChars[i];
            result->childPtrs[i] = childPtrs[i];
        }
    }
    return result;
}

vector<TrieNode *> convertToTrie(vector<string>& words) {
    vector<TrieNode*> result;
    sort(words.begin(), words.end());
    int i = 0;
    buildTrie(words, 0, i, "", result);
    return result;
}

void dumpTrie(TrieNode *node, ostream& out, string prefix) {
    for (int i = 0; i < prefix.length(); i++) {
        out << "\t";
    }
    out << ((prefix == "") ? "(root)" : prefix);
    if (node->isWord) out << " *";
    out << " @ " << node->index;
    out << endl;

    for (int i = 0; i < node->children; i++) {
        dumpTrie(node->childPtrs[i], out, prefix+node->childChars[i]);
    }
}

struct state {
    int node;
    int tillChange;

    state(int node, int tillChange) : node(node), tillChange(tillChange) {
        this->tillChange = max(this->tillChange, 0);
    }

    bool operator<(const struct state& other) const {
        if (node < other.node) return true;
        if (node > other.node) return false;

        if (tillChange < other.tillChange) return true;
        return false;
    }
};

void putMap(map<state, int>& m, state s, int cost) {
    map<state, int>::iterator it = m.find(s);
    if (it == m.end()) {
        m[s] = cost;
    } else {
        it->second = min(it->second, cost);
    }
}

int main(int argc, char **argv) {
    string dictFile = argv[1];

    vector<string> dictWords;
    ifstream dictStream(dictFile.c_str());
    string dictWord;
    while (dictStream >> dictWord) {
        dictWords.push_back(dictWord);
    }

    vector<TrieNode *> trie = convertToTrie(dictWords);
    dictWords.clear();

    D(dumpTrie(trie[0], cerr, ""));
    int nodes = trie.size();
    D(cerr << nodes << " nodes" << endl);
    
    int T;
    cin >> T;
    
    for (int testCase = 1; testCase <= T; testCase++) {
        string S;
        cin >> S;

        map<state, int> current, next;
        current[state(0, 0)] = 0;

        for (int i = 0; i < S.length(); i++) {
            char c = S[i];
            next.clear();
            D(cerr << "i=" << i << endl);

            for (map<state, int>::const_iterator it = current.begin(); it != current.end(); it++) {
                state s = it->first;
                int cost = it->second;
                D(cerr << "state=(" << s.node << "," << s.tillChange << "), cost=" << cost << endl);

                TrieNode *node = trie[s.node];
                for (int childIndex = 0; childIndex < node->children; childIndex++) {
                    TrieNode *child = node->childPtrs[childIndex];
                    D(cerr << "c=" << c << ", considering node " << child->index << " for " << node->childChars[childIndex] << endl);
                    if (node->childChars[childIndex] == c) {
                        putMap(next, state(child->index, s.tillChange-1), cost);
                        if (child->isWord) {
                            putMap(next, state(0, s.tillChange-1), cost);
                        }
                    } else if (s.tillChange == 0) {
                        putMap(next, state(child->index, 4), cost+1);
                        if (child->isWord) {
                            putMap(next, state(0, 4), cost+1);
                        }
                    }
                }
            }

            swap(current, next);
        }

        int minCost = 999999;
        for (map<state, int>::iterator it = current.begin(); it != current.end(); it++) {
            if (it->first.node == 0) {
                minCost = min(minCost, it->second);
            }
        }

        cout << "Case #" << testCase << ": ";
        cout << minCost;
        cout << endl;
    }
}
