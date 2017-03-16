//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

vector<int>vec;
int ar[100009],pr[100009];

int check(int j)
{
    int i;
    for(i=0;i<j;i++)
    {
        if(ar[pr[i]]==pr[(i-1+j)%j]) continue;
        if(ar[pr[i]]==pr[(i+1)%j]) continue;

        return 0;
    }

    return 1;
}

int main()
{
    freopen("out.txt","rt",stdin);
    freopen("out1.txt","wt",stdout);
    int i,j,k,l,n,cas,test,flag,temp,now,ans=0;

    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        memset(ar,0,sizeof(ar));
        cin>>n;

        for(i=0;i<n;i++)
        {
            pr[i]=i;
            cin>>ar[i];
            ar[i]--;
        }

        ans=0;

        do {

            for(j=0;j<n;j++)
            {
                if(check(j+1)) ans=max(ans,j+1);
            }

        } while ( std::next_permutation(pr,pr+n) );

        printf("Case #%d: %d\n",cas,ans);

    }



}
