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
    freopen("res11.txt","w",stdout);
    cin>>t;
    for(int no = 1 ; no <= t ; no++ )
    {
        string S, ANS = "";
        cin>>S;
        for(int i = 0 ; i < S.size() ; i++ )
        {
            if( i == 0 ) ANS = S[i];
            else if( ANS[0] <= S[i] ) ANS=S[i]+ANS;
            else ANS += S[i];
        }
        printf("Case #%d: %s\n", no, ANS.c_str());
    }
    return 0;
}
