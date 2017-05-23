#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count,t,c,d,g,i,in,j,l,k,state;
    vector<int>v;
    ifstream input("C-small-attempt0.in");
    ofstream output("output.in");
    input>>t;
    for(i=1;i<=t;i++)
    {
        v.clear();
        count=0;
        input>>c>>d>>g;
        for(j=0;j<d;j++)
        {
            input>>in;
            l=v.size();
            v.push_back(in);
            for(k=0;k<l;k++)
                v.push_back(in+v[k]);
        }
        sort(v.begin(),v.end());
        for(j=1;j<=g;j++)
        {
           state=0;
            for(k=0;k<v.size();k++)
            {
                if(v[k]==j)
                {
                    state=1;
                    break;
                }
            }
            if(state==0)
            {
                l=v.size();
                v.push_back(j);
                for(k=0;k<l;k++)
                    v.push_back(j+v[k]);
                count++;
            }
        }
        output<<"Case #"<<i<<": "<<count<<endl;
    }
    return 0;
}
