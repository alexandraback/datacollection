#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct st
{
    string i;
    string j;
};

st ar[20];
int N;

vector<st>ori,rep;

bool check()
{
    map<string,bool>F,S;

    F.clear();
    S.clear();
    int a,b,c,d,e,x,y,z;

    for(a=0;a<ori.size();a++)
    {
        F[ ori[a].i ]=true;
        S[ ori[a].j ]=true;
    }

    for(a=0;a<rep.size();a++)
    {
        if(!F[ rep[a].i ]) return false;
        if(!S[ rep[a].j ]) return false;
    }
    return true;
}

int main()
{
    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);

    int a,b,c,d,e,x,y,z,t;



    scanf("%d",&t);

    for(int te=1;te<=t;te++)
    {
        printf("Case #%d: ",te);

        scanf("%d",&N);

        for(a=0;a<N;a++)
        {
            cin>>ar[a].i>>ar[a].j;
        }

        int ans=0;

        for(a=1;a<(1<<N);a++)
        {
            ori.clear();
            rep.clear();

            for(b=0;b<N;b++)
            {
                if((a&(1<<b))) ori.push_back(ar[b]);
                else rep.push_back(ar[b]);
            }

            b=rep.size();

            if(check()) ans=max(ans,b);
        }
        cout<<ans<<endl;
    }


    return 0;
}
