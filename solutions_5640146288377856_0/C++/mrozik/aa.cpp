#include <iostream>
#include <algorithm>
#include <deque>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int R, C, W;

// o=miss, x=hit

bool canhit(const string& s, int ix) {
    if (s[ix]!='.') return false;
    int free = 1;
    for (int i=ix-1; i>=0 && s[i]!='o'; i--)
        free++;
    for (int i=ix+1; i<C && s[i]!='o'; i++)
        free++;
    return free >= W;
}

bool canmiss(const string& s, int ix) {
    if (s[ix]!='.') return false;
    int free = 0;
    bool enc=false;
    for (int i=0; i<int(s.length()); i++) {
        if (s[ix]=='x') enc=true;
        if (i==ix || s[i]=='o') {
            free=0;
            if (enc) return false;
        }
        else {
            free++;
            if (free>=W) return true;
        }
    }
    return false;
}

bool iswin(const string& s) {
    int free=0;
    for (int i=0; i<int(s.length()); i++) {
        if (s[i]!='x') free=0;
        else {
            free++;
            if (free==W) return true;
        }
    }
    return false;
}

string addhit(string s, int ix) {
    for (int i=0; i<int(s.size()); i++)
        if (abs(ix-i)>=W) s[i]='o';
    s[ix]='x';
    return s;
}


map<string, int> states;


int mymove(string s) {
    if (states.count(s) != 0) return states[s];
    if (iswin(s)) return 0;
    
    int res = 0x7fffffff;
    for (int ix=0; ix<int(s.size()); ix++) {
        if (s[ix]!='.') continue;
    
        int res2 = 0;
        
        if (!canhit(s, ix) && !canmiss(s, ix)) cerr<<"WTF "<<s<<" "<<ix<<endl;

        if (canhit(s, ix)) {
            string t = addhit(s, ix);
            res2 = max(res2, mymove(t)+1);
        }
        
        if (canmiss(s, ix)) {
            s[ix]='o';
            res2 = max(res2, mymove(s)+1);
            s[ix]='.';
        }

        res = min(res, res2);
    }

    states[s] = res;
    cerr<<s<<" "<<res<<endl;
    return res;
}




int main() {
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        cin>>R>>C>>W;
        states.clear();
        
        string s(C, '.');
        int result = mymove(s);

        cout<<"Case #"<<t<<": "<<result<<endl;
    }
    return 0;
}