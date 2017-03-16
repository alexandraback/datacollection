#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int T, p, i, j, a, b, n;
string s, ans;
ifstream fin("in.in");
ofstream fout("out.out");

int main()
{   
    fin >>T;
    for(p = 1; p <= T; p++)
    {
        fin >>s;
        ans = s[0];
        for(i = 1; i < s.length(); i++)
            if(ans[0]<=s[i]) ans = s[i] + ans;
            else ans += s[i];
        fout <<"Case #" <<p <<": "<<ans <<endl;
    }
    return 0;
} 
