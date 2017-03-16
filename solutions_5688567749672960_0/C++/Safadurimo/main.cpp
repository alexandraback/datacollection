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

int x[2002][2002];

ll reverse(ll number){
    
    ll reverse=0;
    for( ; number!= 0 ; )
    {
        reverse = reverse * 10;
        reverse = reverse + number%10;
        number = number/10;
    }
    return reverse;
}

ll solvebfs(ll n){
    queue<pair<ll, int> > q;
    set<int> s;
    pair<ll, int> p = make_pair(1,1);
    q.push(p);
    s.insert(1);
    while(!q.empty()){
        pair<ll, int> d = q.front();q.pop();
        if(d.first==n){
            return d.second;
        }
        ll a=d.first+1;
        if(! present(s,a)){
            q.push(make_pair(a,d.second+1));
            s.insert(a);
        }
        ll b=reverse(d.first);
        if(! present(s,b)){
            q.push(make_pair(b,d.second+1));
            s.insert(b);
        }

    }
    return -1;
}



int main(){
    
    
    
#ifndef ONLINE_JUDGE
    ifstream arq(getenv("INPUT"));
    cin.rdbuf(arq.rdbuf());
    
    ofstream brq(getenv("OUTPUT"));
    cout.rdbuf(brq.rdbuf());
#endif
    // Number of Testcases
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        ll x; cin >> x;
        
        cout << "Case #" << (t+1) << ": " << solvebfs(x) << endl;
    }
    
    return 0;
    
}