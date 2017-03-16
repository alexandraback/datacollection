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

const int N = 100000+5;
int n,x;
int mul[5][5] = {
    {},
    {0,1,2,3,4},
    {0,2,-1,4,-3},
    {0,3,-4,-1,2},
    {0,4,3,-2,-1}
};
map<char, int> M;
char buff[N];
char s[N];
int calc(int a,int b){
    int sign = (a * b > 0) ? 1 : -1;
    return sign * mul[abs(a)][abs(b)];
}
bool work(){
    memset(s,0,sizeof(s));
    M['i'] = 2;M['j'] = 3;M['k'] = 4;
    scanf("%d%d",&n,&x);
    scanf("%s",buff);
    int len = 0;
    int val = 1;
    for(int i = 0 ; i < x ; i ++){
        for(int j = 0 ; j < n ; j ++){
            s[len ++] = buff[j];
            val = calc(val,M[buff[j]]);
        }
    }
    int head = 0;
    if(val != -1)return false;
    n = len;
    val = 1;
    while(head < n && val != 2){
        val = calc(val,M[s[head]]);
        head ++;
    }
    if(val != 2)return false;
    val = 1;
    int tail = n-1;
    while(tail >= 0 && val != 4){
        val = calc(M[s[tail]],val);
        tail --;
    }
    if(val != 4)return false;
    if(tail < head)return false;
    return true;
}
void solve()
{
    if(work())puts("YES");
    else puts("NO");
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