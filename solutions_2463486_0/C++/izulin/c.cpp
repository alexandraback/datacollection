#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

vector<string> allsq;

vector<int> pal;
vector<int> sqpal;

int l;

void rek(int u)
{
    int v = l-1-u;
    if(u>v)
    {
        string p;
        for(auto& i : sqpal)
            p += '0'+i;
        allsq.push_back(p);
        return;
    }
    vector<int> pos;
    pos.push_back(u);
    if(v!=u)
        pos.push_back(v);
    for(int d=(u==0?1:0);d<10;d++)
    {
        bool ok = true;
        for(auto& U : pos)
        {
            pal[U] += d;
            for(int i=0;i<l;i++)
            {
                if(i==U)
                    sqpal[i+U] += pal[U]*pal[i];
                else
                    sqpal[i+U] += 2*pal[U]*pal[i];
                if(sqpal[i+U]>=10)
                    ok = false;
            }
        }
        if(ok)
            rek(u+1);
        for(auto& U : pos)
        {
            for(int i=0;i<l;i++)
            {
                if(i==U)
                    sqpal[i+U] -= pal[U]*pal[i];
                else
                    sqpal[i+U] -= 2*pal[U]*pal[i];
            }
            pal[U] -= d;
        }

    }
}

void gen_len(int _l)
{
    l = _l;
    pal.clear();
    sqpal.clear();
    pal.resize(l);
    sqpal.resize(2*l-1);
    rek(0);
}

bool smaller(string a,string b)
{
    if(a.size() < b.size())
        return true;
    if(a.size() > b.size())
        return false;
    for(int i=0;i<a.size();i++)
        if(a[i]<b[i])
            return true;
        else if(a[i]>b[i])
            return false;
    return false;
}


int main()
{
    for(int i=1;i<=51;i++)
    {
        gen_len(i);
    }
    int t;
    cin >> t;
    for(int tt=1;tt<=t;tt++)
    {
        string A,B;
        cin >> A >> B;
        int ans = 0;
        for(auto& X : allsq)
            if(!smaller(X,A) && !smaller(B,X))
                ans++;
        cout << "Case #" << tt << ": " << ans << endl;
    }
}
