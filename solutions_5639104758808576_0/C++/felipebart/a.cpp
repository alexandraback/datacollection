#include <iostream>
#include <string>

using namespace std;

int calc(const string& s)
{
    int resp = 0;
    int total = 0;
    for(int i=0;i<s.size();++i)
    {
        int n = s[i] - '0';
        if((n > 0) && (total < i))
        {
            resp += i - total;
            total = i;
        }
        
        total += n;
    }
    
    return resp;
}

int main()
{
    int t;
    cin >> t;
    for(int lp=1;lp<=t;++lp)
    {
        int n;
        string s;
        cin >> n >> s;
        cout << "Case #" << lp << ": " << calc(s) << "\n";
    }
    return 0;
}