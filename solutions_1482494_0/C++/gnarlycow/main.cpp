#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int nc;
    cin>>nc;
    for(int cc=1;cc<=nc;++cc) {
        int n;
        cin>>n;
        vector < pair<int,int> > d;
        for(int i=0;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            d.push_back(make_pair(b,a));
        }
        sort(d.begin(),d.end());
        int p=0,i=0,ans=0;
        while(i<d.size())
        {
            if(d[i].first<=p)
            {
                while(i<d.size()&&d[i].first<=p)
                {
                    if(d[i].second==-1) ++p;
                    else p+=2;
                    ++i;
                    ++ans;
                }
            }
            else
            {
                int id=-1,maxfirst=-1;
                for(int j=i;j<d.size();++j)
                    if(d[j].second<=p&&maxfirst<d[j].first)
                    {
                        id=j;
                        maxfirst=d[j].first;
                    }
                if(id==-1) break;
                d[id].second=-1;
                ++p;
                ++ans;
            }
        }
        printf("Case #%d: ",cc);
        if(i<d.size()) puts("Too Bad");
        else printf("%d\n",ans);
    }
    return 0;
}
