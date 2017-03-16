#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>

#define mp make_pair
#define pb push_back

using namespace std;

vector<long long> inp;
const int N = 14;
vector<pair<long long,pair<int,int> > > gen(vector<long long> mm)
{
    vector<pair<long long,pair<int,int> > > v;
    v.pb(mp(0ll,mp(0,0)));
    for(int i=0;i<N;i++)
    {
        cerr << "step " << i << ' ';
        vector<pair<long long,pair<int,int> > > nv=v;
        for(int j=0;j<v.size();j++)
        {
            long long s = v[j].first;
            int nm1 = v[j].second.first;
            int nm2 = v[j].second.second;
            nv.pb(mp(s+mm[i],mp(nm1|(1<<i),nm2)));
            nv.pb(mp(s-mm[i],mp(nm1,nm2|(1<<i))));
        }
        v = nv;
        cerr << v.size() << endl;
    }
    return v;
}
void tst()
{
    int n;
    cin >> n;
    inp.clear();
    inp.resize(n);
    for(int i=0;i<n;i++)
        cin >> inp[i];
    while(true)
    {
        random_shuffle(inp.begin(),inp.end());
        vector<long long> m1,m2;
        for(int i=0;i<N;i++)
            m1.pb(inp[i]);
        for(int i=N;i<2*N;i++)
            m2.pb(inp[i]);

        vector<pair<long long,pair<int,int> > > v1 = gen(m1);
        vector<pair<long long,pair<int,int> > > v2 = gen(m2);

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int i = 0, j = 0;
        while(i<v1.size() && j<v2.size())
        {
            if(v1[i].first == v2[j].first && v1[i].first!=0)
            {
                for(int it = 0;it<N;it++)
                    if(v1[i].second.second & (1<<it))
                        cout << ' ' << m1[it];
                for(int it = 0;it<N;it++)
                    if(v2[j].second.first & (1<<it))
                        cout << ' ' << m2[it];
                cout << endl;
                for(int it = 0;it<N;it++)
                    if(v1[i].second.first & (1<<it))
                        cout << ' ' << m1[it];
                for(int it = 0;it<N;it++)
                    if(v2[j].second.second & (1<<it))
                        cout << ' ' << m2[it];
                cout << endl;
                return;
            }
            if(v1[i].first > v2[j].first)
                j++;
            else
                i++;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cout << "Case #" << i << ":\n";
        tst();

    }

}
