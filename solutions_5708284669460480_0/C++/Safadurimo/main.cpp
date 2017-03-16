#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>
#include <limits>
#include <string>
#include <cstring> // memset
#include <iostream> // cin, cout
#include <fstream> // io redirection
#include <sstream> // topcoder testcase
#include <iomanip>      // std::setprecision

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
#define OUTBOOL(boolean,true_string,false_string) cout << ((boolean) ? true_string : false_string)<< endl

#define MOD 1000000007

// Input per testcase
int k,l,s;
string keyboard,target;

set<char> keyboardset;
set<char> targetset;
map<char,int> freq;
string test;
double erw;

int b(){
    int x=sz(target);
    REP(i,1,sz(target)){
        string nu =target.substr(i);
        string na =target.substr(0,sz(target)-i);
        if(nu==na){
            x=i;
            break;
        }
    }
    int counter=0;
    int index=0;
    while(index+sz(target)<=s){
        counter++;
        index+=x;
    }
           
    return counter;
}

void dfs(int i){
    if(i==s){
        // cout << test << endl;
        
        double count=0;
        REP(i,0,s-sz(target)+1){
            if(test.substr(i,sz(target))==target) count++;
        }
        double prob=1.0;
        REP(i,0,sz(test)){
            prob*= ((double) freq[test[i]])/sz(keyboard);
        }
        
        erw+=prob*count;
        
    }
    else {
        for(auto f: keyboardset){
            test[i]=f;
            dfs(i+1);
        }
    }
    
}

double solve(){
    keyboardset.clear();
    freq.clear();
    test.resize(s);
    erw=0.0;
    REP(i,0,sz(keyboard)) {
        keyboardset.insert(keyboard[i]);
        freq[keyboard[i]]++;
    }
    REP(i,0,sz(target)) {
        if(!present(keyboardset,target[i])) return 0.0;
    }
    
    dfs(0);
    int ba = b();
    
    return ba -erw;
  
}




int main()
{
    
#ifndef ONLINE_JUDGE
    ifstream arq(getenv("INPUT"));
    cin.rdbuf(arq.rdbuf());
    
   ofstream brq(getenv("OUTPUT"));
    cout.rdbuf(brq.rdbuf());
#endif
    int T;
    cin >> T;
    
    
    
    for(int testcase=0;testcase<T;testcase++){
        
        
        cin >> k >> l >> s;
        cin >> keyboard>>target;
        
         cout << "Case #" << (testcase+1) << ": " << std::setprecision(9) << std::fixed << solve() << endl;
       
    }
    
    return 0;
}