#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define CLR(a,b) memset(a,b,sizeof(a))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

/*
 
 1122
 4112
 4332
 4433
 
 */
const int N = 10+5;
const string win = "RICHARD", lose = "GABRIEL";
int idx[N][N];
int n,r,c;

bool work()
{
    scanf("%d%d%d",&n,&r,&c);
    if((r * c) % n != 0){
        return true;
    }
    if(n == 1)return false;
    if(n == 2)return false;
    if(n == 3){
        if(r * c == 3)return true;
        if(r * c == 6)return false;
        /*
         000
         000
         */
        if(r * c == 9)return false;
        /*
         000
         000
         000
         */
        if(r * c == 12)return false;
        /*
         0000
         0000
         0000
         */
    }
    if(n == 4){
        if(r * c == 4)return true;
        if(r * c == 8)return true;
        /*
         0000
         0000
         */
        if(r * c == 12)return false;
        /*
         0000
         0000
         0000
         */
        if(r * c == 16)return false;
    }
    return true;
}

void solve()
{
    if(work())cout << win << endl;
    else cout << lose << endl;
}

int main()
{
    freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/output.txt", "w", stdout);
    int T,cas = 0;
    scanf("%d",&T);
    while(T--){
        cas ++;
        printf("Case #%d: ",cas);
        solve();
    }
    return 0;
}