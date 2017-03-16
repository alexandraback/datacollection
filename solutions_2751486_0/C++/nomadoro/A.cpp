#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

bool is_consonant(const char a)
{
    return !(a=='a'||a=='e'||a=='i'||a=='o'||a=='u');
}

ll count(const string & s, int n)
{
    vector<int> vb, ve, vc;
    for(int i = 0; i < s.size(); i++)
    {
        if((i==0 && is_consonant(s[0])) || (i>0 && is_consonant(s[i]) && !is_consonant(s[i-1])))
            vb.push_back(i);
        if(i>0 && is_consonant(s[i-1]) && !is_consonant(s[i]))
        {
            if(i-vb.back()>=n)
                ve.push_back(i), vc.push_back(i-vb.back());
            else
                vb.pop_back();
        }
    }
    if(is_consonant(s[s.size()-1]))
    {
        if(s.size()-vb.back()>=n)
            ve.push_back(s.size()), vc.push_back(s.size()-vb.back());
        else
            vb.pop_back();
    }

    ll tot = 0;
/*
    for(int k = 0; k < vc.size(); k++)
    {
        if(vc[k]>n)
            tot += ll(2+vc[k]-n)*(1+vc[k]-n)/2-1;
    }

    for(int d = 0; d < vb.size(); d++)
    {
        for(int k = 0; k+d < vb.size(); k++)
        {
            tot+=ll(vb[k]+1)*(s.size()-ve[k+d]+1)*(d%2==0?1:-1);
        }
    }
*/

    for(int k = 0; k < vb.size(); k++)
    {
        tot += ll(k==0?vb[0]:(vb[k]-ve[k-1]+n-1))*(s.size()-(vb[k]+n)+1);
        tot += ll(2*s.size()-vb[k]-ve[k]-n+2)*(ve[k]-vb[k]-n+1)/2;
    }

    return tot;
}


int main()
{
    int T;
    cin >> T;
    for(int k = 1; k <= T; k++)
    {
        string s;
        int n;
        cin >> s >> n;
        cout << "Case #" << k << ": " << count(s, n) << endl;
    }
}
