#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    int T, n, cont;
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    vector<pair<string,int> > v;
    int mapa[30];
    cin>>T;
    for(int k=1; k<=T; k++)
    {
        cin>>n;
        v.clear();
        v.resize(n);
        memset(mapa,0,sizeof mapa);
        for(int i=0;i<n;i++)
        {
            cin>>v[i].first;
            v[i].second = i;
        }
        cont = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<v[i].first.size();j++)
            {
                mapa[v[i].first[j]-'a']++;
            }
        }
        bool b = true;
        sort(v.begin(),v.end());
        do
        {
            string t = "";
            bool b = false;
            for(int i=0;i<n;i++)
                t+=v[i].first;
            for(int i=0;i<t.size();i++)
            {

                int x = mapa[t[i]-'a'];
                char c = t[i];
                b = false;
                for(int j = 0; j<x;j++)
                {
                    if(t[i+j] != c)
                        b = true;
                }
                if(b)
                    break;
                i+=x-1;
            }
            if(b)
                continue;
            cont++;
        } while ( next_permutation(v.begin(),v.end()) );
        printf("Case #%d: %d\n",k,cont);
    }
    return 0;
}
