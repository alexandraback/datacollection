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
int c,d,v;
vi denoms;
 bool dp[40][40];

int  solve(){
    REP(i,0,40) REP(j,0,40) dp[i][j]=false;
    REP(i,0,d){
        dp[i][denoms[i]]=true;
        if(i>0){
            REP(j,0,v+1){
                if(dp[i-1][j] && j+denoms[i]) {
                    dp[i][denoms[i]+j]=true;
                }
                if(dp[i-1][j]){
                    dp[i][j]=true;
                }
            }
        }
    }
    int count =0;
    int index = d-1;;
    while(true){
        bool end=true;
        int missing;
        REP(i,1,v+1){
            if(!dp[index][i]){
                count++;
                missing = i;
                end=false;
                break;
            }
        }
        if(!end){
            index++;
            dp[index][missing]=true;
            REP(j,0,v+1){
                if(dp[index-1][j] && j+missing) {
                    dp[index][j+missing]=true;
                }
                if(dp[index-1][j]){
                    dp[index][j]=true;
                }
            }
        }
        else return count;
        
    }
    
    
    return count;
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
        
        
        cin >> c >> d >> v;
        denoms = vi(d,0);
        REP(i,0,d) cin>> denoms[i];
        
         cout << "Case #" << (testcase+1) << ": " << solve() << endl;
       
    }
    
    return 0;
}