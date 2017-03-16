#include<bits/stdc++.h>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb push_back
using namespace std;
string solve()
{
    string s;
    cin >> s;
    string ans="";
    ans=ans+s.at(0);
    rep(i,1,s.size())
    {
        if(s.at(i)-'A'>=ans.at(0)-'A')
            ans=s.at(i)+ans;
        else
            ans=ans+s.at(i);
    }
    return ans;
}
int main()  
{
    int t;
    cin >> t;
    int j;
    for(j=0;j<t;j++)
    {
         cout << "Case #" << j+1 << ": " << solve() << "\n";
    }
    return 0;
    
}