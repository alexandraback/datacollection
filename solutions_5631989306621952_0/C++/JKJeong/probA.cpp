#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int t;
string dt[1010];

string solve(int x, string S, string ANS)
{
    if( x == S.size() ) return ANS;
    //if( dt[x] != "" ) return dt[x];
    return dt[x] = max( solve(x+1, S, ANS+S[x]), solve(x+1, S, S[x]+ANS) );
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("res.txt","w",stdout);
    cin>>t;
    for(int no = 1 ; no <= t ; no++ )
    {
        string S, ANS = "";
        cin>>S;
        for(int i = 0 ; i < S.size() ; i++ ) dt[i] = "";
        printf("Case #%d: %s\n", no, solve(0, S, ANS).c_str());
    }
    return 0;
}
