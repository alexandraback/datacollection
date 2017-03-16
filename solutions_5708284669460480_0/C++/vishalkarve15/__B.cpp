#include<bits/stdc++.h>

using namespace std;

char key[10];
char tar[10];
char act[10];

int numgive[10];
int numkeep[10];

int main()
{
    int t;
    scanf("%d",&t);

    for(int tt=1;tt<=t;tt++)
    {
        memset(numgive,0,sizeof numgive);
        int k,l,s;
        scanf("%d%d%d",&k,&l,&s);

        // k^s

        int com=1;
        for(int i=0;i<s;i++)
            com*=k;
        scanf("%s%s",key,tar);
        for(int i=0;i<com;i++)
        {
            int num=i;
            for(int j=0;j<s;j++)
            {
                act[j]=key[num%k];
                num/=k;
            }
            int matches=0;
            for(int j=0;j+l-1<s;j++)
            {
                bool mat=1;
                for(int m=0;m<l;m++)
                    if(act[j+m]!=tar[m])
                    {
                        mat=0;
                        break;
                    }
                if(mat)
                    matches++;
            }
            numgive[matches]++;
        }
        int maxgive=-1;
        for(int i=0;i<10;i++)
            if(numgive[i])
                maxgive=i;
        for(int i=0;i<=maxgive;i++)
            numkeep[maxgive-i]=numgive[i];
        int sum=0;
        for(int i=0;i<=maxgive;i++)
            sum+=numgive[i];
        double ans=0.0;
        for(int i=0;i<=maxgive;i++)
        {
            ans+=(double)numkeep[i]*(double)i/(double)sum;
        }
        printf("Case #%d: %.9lf\n",tt,ans);
    }
    return 0;
}
