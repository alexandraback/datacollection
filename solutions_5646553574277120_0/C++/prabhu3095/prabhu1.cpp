#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out1.txt","w",stdout);

    int t,c,d,v;
    cin>>t;
    for(int l=1;l<=t;l++)
    {
        cin>>c>>d>>v;
        int N=d,M;
        int ans=0;
        int nums[N+50],i,j;
        for(i=1;i<=N;i++)
            scanf(" %d",&nums[i]);

        for(M=1; M<=v; M++)
        {

        int ispossible[N+1][M+1];

        for(i=0;i<=N;i++)
            for(j=0;j<=M;j++)
                ispossible[i][j]=0;
        for(i=0;i<=N;i++)
            ispossible[i][0]=1;
        for(i=1;i<=N;i++)
        {
            for(j=0;j<=M;j++)
            {
                if(ispossible[i-1][j]==1)
                    ispossible[i][j]=1;
                if(j-nums[i]>=0 && ispossible[i-1][j-nums[i]]==1)
                    ispossible[i][j]=1;
            }
        }
        if(ispossible[N][M]!=1)
        {
            N++;
            nums[N]=M;
            ans++;
        }
        }
        cout<<"Case #"<<l<<": "<<ans<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
