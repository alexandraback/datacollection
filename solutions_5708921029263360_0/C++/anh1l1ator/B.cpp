#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair < int , int > Point;
typedef pair < Point,int > iii;
vector < iii > Comb;


int main()
{
    freopen("this.in","r+",stdin);
    freopen("that.txt","w+",stdout);
    int T;
    scanf("%d",&T);
    for(int e=1;e<=T;++e)
    {
        cout<<"Case #"<<e<<": ";
        Comb.clear();
        int J , P , S , K , i , k , l ;
        cin>>J>>P>>S>>K;

        for(i=1;i<=J;++i)
            for(k=1;k<=P;++k)
                for(l=1;l<=S;++l)
                    Comb.push_back({{i,k},l});

        int high = 0 , idx = 0;

        for(i=1;i<(1LL<<Comb.size());++i)
        {
            if(__builtin_popcount(i)<=high)
                continue;

            int M1[4][4]={0};
            int M2[4][4]={0};
            int M3[4][4]={0};

            int flag = 0;
            for(int j=0;j<(int)Comb.size();++j)
            {
                if((i>>j)&1)
                {
                    M1[Comb[j].first.first][Comb[j].first.second]++; // 1 2
                    M2[Comb[j].first.first][Comb[j].second]++;       // 1 3
                    M3[Comb[j].first.second][Comb[j].second]++; // 2 3
                    if(M1[Comb[j].first.first][Comb[j].first.second]>K  || M2[Comb[j].first.first][Comb[j].second]>K || M3[Comb[j].first.second][Comb[j].second]>K)
                    {
                        flag =1;
                        break;
                    }
                }
            }
            if(flag)continue;
            high = __builtin_popcount(i);
            idx  = i;
        }


        cout<<high<<'\n';
        i = idx;
        for(int j=0;j<(int)Comb.size();++j)
        {
            if((i>>j)&1)
                cout<<Comb[j].first.first<<" "<<Comb[j].first.second<<" "<<Comb[j].second<<"\n";
        }

    }
    return 0;
}
