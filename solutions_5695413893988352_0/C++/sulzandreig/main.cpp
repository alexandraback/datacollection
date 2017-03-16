#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <fstream>
#include <cmath>
using namespace std;
ifstream in("data.in");
ofstream out("data.out");
vector<int> solutie;
int numar(char c)
{
    return (int)c-48;
}
bool fits(string s,int nr)
{
    int p = s.size()-1;
    while(p >=0)
    {
        if(nr%10 == numar(s[p]) || s[p] =='?')
        {
            nr /=10;
            p--;
            continue;
        }
        return false;
    }
    return true;
}
int cifre(int nr)
{
    int n = 0;
    if(nr == 0)
        return 1;
    while(nr)
    {
        n++;
        nr/=10;
    }
    return n;
}
void solve(string c,string j,int caz)
{
    //cout << c <<" "<<j<<'\n';
    int nr = max(c.size(),j.size()),p=1;
    while(nr--)
        p*=10;
    int a,b;
    int sola=10000,solb=1000,dif =10000;
    for( a = 0 ; a < p ; a++)
        for( b = 0 ; b < p ; b++)
        {
            bool ok1 = fits(c,a);
            bool ok2 = fits(j,b);
            if(ok1 && ok2)
            {
                if(abs(a-b)== dif)
                {
                    if(a == sola)
                    {
                        if(b < solb)
                            solb = b;
                    }
                    else if(a < sola)
                    {
                        sola = a;
                        if(b < solb)
                            solb = b;
                    }
                }
                else if(abs(a-b)<dif)
                {
                    dif = abs(a-b);
                    sola = a;
                    solb = b;
                }
            }
        }
    a = sola;
    b = solb;
   // cout<<a<<" "<<b<<'\n';
    out << "Case #"<<caz<<": ";
    if(cifre(a)<c.size())
    {
        int cif = cifre(a);
        while(cif<c.size())
        {
            out<<'0';
            cif++;
        }
        out<<a<<" ";
    }
    else
    {
        out <<a<<" ";
    }
    if(cifre(b)<j.size())
    {
        int cif = cifre(b);
        while(cif<j.size())
        {
            out<<'0';
            cif++;
        }
        out<<b<<" ";
    }
    else
    {
        out<<b<<" ";
    }
    out<<'\n';
    cout<<caz<<'\n';
}
int main()
{
    int t;
    string s,j;
    in>> t;
    for(int i = 0 ; i < t ; i ++)
    {

        in >> s >> j;
        //cout<<"main s:"<<s<<" j:"<<j;
        //cout<<"s size:"<<s.size()<<" j size:"<<j.size()<<'\n';
        solve(s,j,i+1);
    }
    return 0;
}
