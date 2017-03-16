#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>

using namespace std;

string toStr(int n, int tam)
{
    string s(tam, '0');
    int p = 0;
    while(n)
        s[p]=(n%10 + '0'), n/=10, p++;
    for(int i=0; i<s.size()/2; i++)
        swap(s[i], s[s.size()-1-i]);
    if(s.size())
        return s;
    return "0";
}

bool match(int n, string s)
{
    string k = toStr(n, s.size());

    for(int i=0; i<s.size(); i++)
        if(s[i] != '?')
            if(s[i] != k[i])
                return false;
    return true;
}

int main()
{
    ifstream in("in.in");
    ofstream out("s.txt");
    int tc;
    in >> tc;
    for(int w=1; w<=tc; w++)
    {
        cout << w << "/" << tc << endl;
        string a, b;
        in >> a >> b;

        int maxPot = 1;
        for(int i=0; i<a.size(); i++)
            maxPot *= 10;

        string ra, rb;
        int absD = 99999;
        for(int i=0; i<=maxPot; i++)
        {
            for(int j=0; j<=maxPot; j++)
            {
                //cout << i << " " << j << endl;
                if(match(i, a) && match(j, b))
                {
                    if(abs(i-j) < absD)
                    {
                        absD = abs(i-j);
                        ra = toStr(i, a.size());
                        rb = toStr(j, b.size());
                    }
                }
            }
        }
        out << "Case #" << w << ": " << ra << " " << rb << endl;
    }
    return 0;
}
