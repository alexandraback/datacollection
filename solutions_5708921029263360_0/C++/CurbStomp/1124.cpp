#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test;
    cin>>test;
    for(int x=1;x<=test;x++)
    {
        map<pair<pair<int,int>,int>,int >th;
        vector<pair<pair<int,int>,int> >memo;
        int days=0;
        map<pair<int,int>,int >otw;
        map<pair<int,int>,int >oth;
        map<pair<int,int>,int >tt;
        int j,p,s,k;
        cin>>j>>p>>s>>k;
        cout<<"Case #"<<x<<": ";
        for(int i1=1;i1<=j;i1++)
        {
            for(int i2=1;i2<=p;i2++)
            {
                for(int i3=1;i3<=s;i3++)
                {
                    if(th[make_pair(make_pair(i1,i2),i3)]==1)
                        continue;
                    else
                    {
                        if(otw[make_pair(i1,i2)]>=k||oth[make_pair(i1,i3)]>=k||tt[make_pair(i2,i3)]>=k)
                            continue;
                        th[make_pair(make_pair(i1,i2),i3)]=1;
                        otw[make_pair(i1,i2)]++;
                        oth[make_pair(i1,i3)]++;
                        tt[make_pair(i2,i3)]++;
                        days++;
                        memo.push_back(make_pair(make_pair(i1,i2),i3));
                    }
                }
            }
        }
        cout<<days<<endl;
        for(int i=0;i<days;i++)
            cout<<memo[i].first.first<<" "<<memo[i].first.second<<" "<<memo[i].second<<endl;
    }
    fclose(stdout);
}
