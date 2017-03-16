#include <iostream>
#include <fstream>
#include <string>

using namespace std;

unsigned n,T,sol;
string s,a;

bool consec_cons()
{
    unsigned c=0,mx=0;
    for(unsigned i=0;i<s.size();i++)
        if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')
        {
            c++;
            if(c>mx)
                mx=c;
        }
        else
            c=0;
    return (mx>=n);
}

int main()
{
    ifstream f1("1.in");
    ofstream f2("1.out");
    f1>>T;
    for(unsigned c=0;c<T;c++)
    {
        sol=0;
        f1>>a>>n;
        for(unsigned i=a.size();i>=n;i--)
            for(unsigned j=0;j<=a.size()-i;j++)
            {
                s=a.substr(j,i);
                if(consec_cons())
                    sol++;
            }
        f2<<"Case #"<<c+1<<": "<<sol<<'\n';
    }
    f1.close();
    f2.close();
    return 0;
}
