//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

vector<pair<long long,pair<long long,long long> > >vec;
map<pair<long long,long long>, long long > mymap;

int main()
{
    freopen("out.txt","rt",stdin);
    freopen("out1.txt","wt",stdout);
    long long i,j,k,l,n,cas,test,flag,temp,now,ans=0,m,J,P,S,K,tot,ANS;

    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        vec.clear();
        scanf("%lld%lld%lld%lld",&J,&P,&S,&K);

        now=0;

        for(i=1;i<=J;i++)
        {
            for(j=1;j<=P;j++)
            {
                for(k=1;k<=S;k++)
                {
                    vec.push_back(make_pair(i,make_pair(j+J,k+J+P)));
                    now++;
                }
            }
        }

        tot=1LL<<now;
        ans=0;

        for(i=0;i<tot;i++)
        {
            temp=__builtin_popcountll(i);
            if(temp<=ans) continue;
            mymap.clear();
            flag=1;
            for(j=0;j<now;j++)
            {
                if((1LL<<j) & i)
                {
                    mymap[make_pair(vec[j].first,vec[j].second.first)]++;
                    mymap[make_pair(vec[j].first,vec[j].second.second)]++;
                    mymap[make_pair(vec[j].second.first,vec[j].second.second)]++;


                    if(mymap[make_pair(vec[j].first,vec[j].second.first)]>K)
                    {
                        flag=0;
                        break;
                    }
                    if(mymap[make_pair(vec[j].first,vec[j].second.second)]>K)
                    {
                        flag=0;
                        break;
                    }
                    if(mymap[make_pair(vec[j].second.first,vec[j].second.second)]>K)
                    {
                        flag=0;
                        break;
                    }

                }
            }



            if(flag)
            {
                ans=temp;
                ANS=i;
            }

        }

        printf("Case #%lld: %lld\n",cas,ans);
        for(i=0;i<now;i++)
        {
            if((1LL<<i) & ANS)
            {
                printf("%lld %lld %lld\n",vec[i].first,vec[i].second.first-J,vec[i].second.second-J-P);
            }
        }


    }



}
