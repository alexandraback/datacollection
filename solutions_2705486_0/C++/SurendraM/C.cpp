/*	SURENDRA KUMAR MEENA	*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <queue>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
#define FF(i,m,n)	for(int i=m;i<n;i++)
#define F(i,n)	FF(i,0,n)
#define CLR(s,v) memset(s,v,sizeof(s))

set<string> wordSet;
struct node {
    int ind;
    char ch;
    map<char, node*> nxt;
    bool isLast;
}*root,*tmp;

void loadDictionary() {
    fstream fin("dictionary.txt",ios::in);
    string s;
    int index = 1;
    root = new node();
    root->isLast = false;
    root->nxt.clear();
    root->ind = index++;
    while(fin>>s) {
        wordSet.insert(s);
        tmp = root;
        F(i,s.size()) {
            if(tmp->nxt[s[i]]==NULL) {
                node *nd = new node();
                nd->ch = s[i];
                nd->nxt.clear();
                nd->isLast = false;
                nd->ind = index++;
                tmp->nxt[s[i]] = nd;
            }
            tmp = tmp->nxt[s[i]];
            if(i==s.size()-1) {
                tmp->isLast = true;
            }
        }
    }
}

void checkValid(string s) {
    tmp = root;
    F(i,s.size()) {
        if(tmp->nxt[s[i]]==NULL) {
            cout<<"No\n";
        }
        tmp = tmp->nxt[s[i]];
    }
    cout<<(tmp->isLast?1:0)<<endl;
}

int len;
string s;
map<int, int> mem[52][6];

int fn(int pos, int dist, node* nd, string ss) {
    if(pos>=len) {
        if(nd->isLast==false) return 1000;
        return 0;
    }
    if(mem[pos][dist].find(nd->ind)!=mem[pos][dist].end()) {
        return mem[pos][dist][nd->ind];
    }
    int& ret = mem[pos][dist][nd->ind];
    ret = 1000;
    
    if(nd->isLast) {
        ret = min(ret, fn(pos, dist, root, ss));
    }
    if(nd->nxt.find(s[pos]) != nd->nxt.end()) {
        ret = min(ret, fn(pos+1, min(5,dist+1), nd->nxt[s[pos]], ss));
    }
    if(dist>4) {
        for(char ch='a'; ch<='z'; ch++) {
            if(ch==s[pos])  continue;
            if(nd->nxt.find(ch) != nd->nxt.end()) {
                string sss= ss;
                sss[pos] = ch;
                ret = min(ret, 1+fn(pos+1, 1, nd->nxt[ch], sss));
            }
        }
    }
    return ret;
}

int main(){
    loadDictionary();
//    checkValid("aaabeyes");
//    checkValid("aaabeyd");
    int t;
    cin>>t;
    FF(kase,1,t+1){
        cout<<"Case #"<<kase<<": ";
        F(i,52) F(j,6)  mem[i][j].clear();
        cin>>s;
        len = s.size();
        cout<<fn(0, 5, root, s)<<endl;
    }
    return 0;
}
