#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cout<<"Case #"<<t<<": ";

        int J,P,S,K;
        cin>>J>>P>>S>>K;

        map<pair<int,int>,int> JP,PS,JS;
        map<int,set<pair<int,int> > > m;

        int total=0;

        for(int j=1;j<=J;j++)
        {
            for(int p=1;p<=P;p++)
            {
                for(int s=1;s<=S;s++)
                {
                    pair<int,int> jp=make_pair(j,p);
                    pair<int,int> ps=make_pair(p,s);
                    pair<int,int> js=make_pair(j,s);

                    if(JP.find(jp)==JP.end())
                        JP[jp]=0;
                    if(PS.find(ps)==PS.end())
                        PS[ps]=0;
                    if(JS.find(js)==JS.end())
                        JS[js]=0;

                    if(m.find(j)!=m.end() && m[j].find(ps)!=m[j].end())
                        continue;

                    if(JP[jp]<K && PS[ps]<K && JS[js]<K)
                    {
                        m[j].insert(ps);
                        total++;
                        JP[jp]++;
                        PS[ps]++;
                        JS[js]++;
                    }
                }
            }
        }

        cout<<total<<endl;
        for(map<int,set<pair<int,int> > >::iterator it=m.begin();it!=m.end();it++)
        {
            for(set<pair<int,int> >::iterator it2=it->second.begin();it2!=it->second.end();it2++)
            {
                cout<<it->first<<" "<<it2->first<<" "<<it2->second<<endl;
            }
        }
    }
    return 0;
}