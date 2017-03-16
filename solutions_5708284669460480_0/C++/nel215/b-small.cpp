#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

int K,L,S;
string KEYS;
string TARGET;

void rec(string s, vector<string> &words){
    if((int)s.size()==S){
        words.push_back(s);
    }else{
        REP(i,KEYS.size()){
            string next_s = s;
            next_s.push_back(KEYS[i]);
            rec(next_s,words);
        }
    }
}

int check(string s){
    int res = 0;
    REP(i,s.size()){
        if((int)TARGET.size()+i>(int)s.size())break;
        bool ok = true;
        REP(j,TARGET.size()){
            ok = ok && (s[i+j]==TARGET[j]);
        }
        if(ok)res++;
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    REP(testCase,T){
        cin >> K >> L >> S;
        cin >> KEYS >> TARGET;
        vector<string> words;
        rec("",words);
        double mx = 0;
        double sum = 0;
        REP(i,words.size()){
            double c = check(words[i]);
            mx = max(mx,c);
            sum += c;
        }
        double res = 0;
        if(mx>0){
            res = mx - sum/words.size();
        }
        printf("Case #%d: %.7f\n", testCase+1, res);

    }
    return 0;
}
