#include <cstdio>
#include <vector>
using namespace std;
int k,c,s;
long long power[105];
int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("small.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cases=1; cases<=T; cases++)
    {
        scanf("%d%d%d",&k,&c,&s);
        if(c>k) c=k;
        power[0]=1;
        for(int i=1; i<c; i++)
            power[i]=power[i-1]*k;
        vector<long long> v;
        int p=0,cnt=0;
        long long bac=0;
        while(s)
        {
            long long tmp=0;
            for(int i=0; i<c; i++,p++)
            {
                tmp+=p*power[c-i-1];
                cnt++;
            }
            v.push_back(tmp+1);
            //printf("%d\n",tmp+1);
            bac=tmp+1;
            s--;
            if(p>=k) break;
            if(cnt+c>k) break;
        }
        //printf("s %d %d %d\n",s,v.size(),cnt);
        if(cnt<k)
        {
            while(s)
            {
                v.push_back(++bac);
                cnt++;
                s--;
                if(cnt>=k) break;
            }
        }
        printf("Case #%d:",cases);
        if(cnt>=k)
        {
            for(int i=0; i<(int)v.size(); i++)
                printf(" %I64d",v[i]);
        }
        else
            printf(" IMPOSSIBLE");
        puts("");
    }
    return 0;
}
