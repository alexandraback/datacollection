#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>
#include <fstream>

using namespace std;

vector<string> words;

#define INF 4611686018427387904

struct node {
    char c;
    bool complete;
    node() : c('\0'), complete(false), descendants() {}
    node(char c_) : c(c_), complete(false), descendants() {}
    
    set<node> descendants;
    bool operator<(const node & rhs) const
    {
        return c < rhs.c;
    }
};

node root;

void possibilities(std::string & s, int word_delim, int at_pos, set<char> &maybe, bool &complete)
{
    const node *at_node = &root;
    for(int i = word_delim; i <= at_pos; ++i)
    {
        set<node>::const_iterator new_node = at_node->descendants.find(node(s.at(i)));
        if(at_pos == i)
        {
            for(set<node>::const_iterator jt = at_node->descendants.begin(); jt != at_node->descendants.end(); ++jt)
            {
                maybe.insert(jt->c);
            }
        }
        
        if(new_node == at_node->descendants.end())
        {
            complete = false;
            return;
        }
        
        at_node = &(*new_node);
    }
    complete = at_node->complete;
}

struct key
{
    key(int lastchange_, const std::string & s_, int word_delim_, int at_pos_) :
    lastchange(lastchange_), s(s_), word_delim(word_delim_), at_pos(at_pos_) {}
    bool operator<(const key & rhs) const
    {
        if(lastchange != rhs.lastchange) return lastchange < rhs.lastchange;
        if(s != rhs.s) return s < rhs.s;
        if(word_delim != rhs.word_delim) return word_delim < rhs.word_delim;
        return at_pos < rhs.at_pos;
    }
    int lastchange, word_delim, at_pos;
    std::string s;
};

map<key, long long> results;

long long recurse(int lastchange, std::string &s, int word_delim, int at_pos)
{
    if(at_pos == s.size() && word_delim == at_pos) { return 0; }
    if(at_pos == s.size() && binary_search(words.begin(), words.end(), s.substr(word_delim))) { return 0; }
    if(at_pos == s.size()) { /*cout << "end; word_delim=" << word_delim << " at_pos=" << at_pos << endl; */return INF; }
    key mykey(lastchange, s.substr(word_delim), word_delim, at_pos);
    map<key, long long>::iterator rit = results.find(mykey);
    if(rit != results.end()) return rit->second;
    
    long long min_ = INF;
    /*if(binary_search(words.begin(), words.end(), s.substr(word_delim, word_delim - at_pos + 1)))
    {
        min_ = min(min_, recurse(lastchange, s, at_pos + 1, at_pos + 1));
    }*/
    
    set<char> maybe;
    bool complete;
    possibilities(s, word_delim, at_pos, maybe, complete);
    /*if(maybe.empty() && !complete)
    {
        results.insert(make_pair(key(lastchange,word_delim,at_pos), INF));
        return INF;
    }*/
    
    if(/*(at_pos - word_delim) > 0 && */ complete)
    {
        min_ = min(min_, recurse(lastchange, s, at_pos + 1, at_pos + 1));
    }
    
    if(/* !maybe.empty() && */ (at_pos - lastchange) >= 5)
    {
        char orig = s.at(at_pos);
        for(set<char>::iterator mt = maybe.begin(); mt != maybe.end(); ++mt)
        {
            s.at(at_pos) = *mt;
            //cerr << "trying change " << at_pos << " = " << *mt << endl;
            min_ = min(min_, recurse(at_pos, s, word_delim, at_pos) + 1);
        }
        /*for(char mt = 'a'; mt <= 'z'; ++mt)
        {
            s.at(at_pos) = mt;
            //cerr << "trying change " << at_pos << " = " << *mt << endl;
            min_ = min(min_, recurse(at_pos, s, word_delim, at_pos) + 1);
        }*/
        s.at(at_pos) = orig;
    }
    
    min_ = min(min_, recurse(lastchange, s, word_delim, at_pos + 1));
    results.insert(make_pair(mykey, min_));
    return min_;
}

void testcase(int tst)
{
    string s;
    cin >> s;
    //cout << s << "asdf" << endl;
    cout << "Case #" << tst << ": " << recurse(-5, s, 0, 0) << endl;
    results.clear();
}

int main(int argc, char *argv[])
{
    if(argc < 2) return 1;
    ifstream file(argv[1]);
    if(!file) return 2;
    string word;
    while(file >> word)
    {
        node *at_node = &root;
        for(int i = 0; i < word.size(); ++i)
        {
            at_node = const_cast<node*>(&(*at_node->descendants.insert(node(word.at(i))).first));
        }
        at_node->complete = true;
        //cout << "inserted word " << word << endl;
        words.push_back(word);
    }
    sort(words.begin(), words.end());
    
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        testcase(t);
    }
    return 0;
}
