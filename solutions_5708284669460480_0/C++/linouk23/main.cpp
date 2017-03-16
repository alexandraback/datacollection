#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#define     inf             2e9

using namespace std;

string tword, aliciakeys;
int K, TL, SL;

pair<int,int> solve(int unknownx, string s)
{
    if(unknownx==SL)
    {
        int ans = 0;
        for (int i = 0; i <= SL-TL; ++i)
        {
            if(!s.compare(i,TL,tword))ans++;
        }
        return make_pair(ans,ans);
    }
    pair<int,int> ans = make_pair(0,-inf);
    for (int i = 0; i <= K-1; ++i)
    {
        pair<int,int> tmp = solve(unknownx+1,s+aliciakeys[i]);
        ans.second = max(ans.second,tmp.second);
        ans.first += tmp.first;
    }
    return ans;
}
int functionformagic(int b, int p)
{
    int r = 1;
    int x = b;
    while(p)
    {
        if(p&1)r*=x;
        x*=x;p=(p>>1);
    }
    return r;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k)
    {
        cin >> K >> TL >> SL >> aliciakeys >> tword;
        pair<int,int> ans = solve(0,"");
        double result = (double) ans.second - double(ans.first)/double(functionformagic(K,SL));
        cout << "Case #" << k <<": " << setprecision(8) << result << endl;
    }
    return 0;
}

