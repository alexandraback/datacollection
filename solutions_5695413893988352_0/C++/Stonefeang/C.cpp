#include <bits/stdc++.h>
using namespace std;

int t;

string a, b;

vector < pair <int,int> > wek;

int w1, w2;

int nal(int v, string u)
{
    for (int i=0; i<u.size(); i++)
    {
        if ((u[i]-'0')!=(v%10) && u[i]!='?')
        {
            return 0;
        }
        v/=10;
    }
    if (v)
    return 0;
    return 1;
}

bool mniej(pair <int,int> v, pair <int,int> u)
{
    if ((abs(v.first-v.second)!=abs(u.first-u.second)))
    return (abs(v.first-v.second)<abs(u.first-u.second));
    return v<u;
}

int main()
{
    cin >> t;
    for (int tt=1; tt<=t; tt++)
    {
        cout << "Case #" << tt << ": ";
        wek.clear();
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i=0; i<1000; i++)
        {
            for (int j=0; j<1000; j++)
            {
                if (nal(i, a) && nal(j, b))
                {
                    wek.push_back(make_pair(i, j));
                }
            }
        }
        sort(wek.begin(), wek.end(), mniej);
        w1=wek[0].first;
        w2=wek[0].second;

        if (w1<10 && a.size()>1)
        cout << 0;
        if (w1<100 && a.size()>2)
        cout << 0;
        cout << w1;
        cout << " ";
        if (w2<10 && b.size()>1)
        cout << 0;
        if (w2<100 && b.size()>2)
        cout << 0;
        cout << w2;
        cout << endl;
    }
    return 0;
}
