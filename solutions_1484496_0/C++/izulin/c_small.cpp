#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<int,int> rev;

int lowest(int x)
{
    return rev[x-(x&(x-1))];
}

void tst()
{
    int n;
    cin >> n;
    vector<int> inp(n);
    for(int i=0;i<n;i++)
        cin >> inp[i];
    vector<int> ssum(1<<n);
    ssum[0] = 0;
    for(int mask=1;mask<(1<<n);mask++)
        ssum[mask] = ssum[mask & (mask-1)] + inp[lowest(mask)];
    vector<pair<int,int> > pp(1<<n);
    for(int i=0;i<(1<<n);i++)
        pp[i] = make_pair(ssum[i],i);
    sort(pp.begin(),pp.end());
    for(int i=1;i+1<(1<<n);i++)
        if(pp[i].first == pp[i+1].first)
        {
            int mask1 = pp[i].second;
            int mask2 = pp[i+1].second;
            for(int i=0;i<n;i++)
                if(mask1 & (1<<i))
                    cout << inp[i] << ' ';
            cout << endl;
            for(int i=0;i<n;i++)
                if(mask2 & (1<<i))
                    cout << inp[i] << ' ';
            cout << endl;
            return;
        }
    cout << "Impossible" << endl;
}
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<20;i++)
        rev[1<<i] = i;
    for(int i=1;i<=t;i++)
    {
        cout << "Case #" << i << ":\n";
        tst();

    }

}
