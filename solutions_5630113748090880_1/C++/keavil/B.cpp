#include<bits/stdc++.h>
using namespace std;
int T,N,lis[110][110];
int now[110],ans[110];
int main()
{
    cin>>T;
    for(int data=1;data<=T;data++)
    {
        cin>>N;
        for(int i=1;i<=2*N-1;i++)
            for(int j=1;j<=N;j++)
                cin>>lis[i][j];
        cout<<"Case #"<<data<<": ";
        memset(now,0,sizeof(now));
        for(int i=1;i<=N;i++)
        {
            int ind=0;
            for(int j=1;j<=2*N-1;j++)
                now[++ind]=lis[j][i];
            sort(now+1,now+ind+1);
            if(now[2*i-1]==now[2*i])continue;
            int tar=0;
            for(int j=1;j<=2*N-1;j++)
                if(lis[j][i]==now[2*i-1])
                    tar=j;
            int tlen=0,tnow=1;
            for(int j=1;j<=2*N-1;j++)
                if(tnow>N || now[j]!=lis[tar][tnow])
                    ans[++tlen]=now[j];
                else ++tnow;
            ans[++tlen]=now[2*i-1];
            sort(ans+1,ans+tlen+1);
            for(int i=1;i<tlen;i++)
                printf("%d ",ans[i]);
            printf("%d\n",ans[tlen]);
            break;
        }
    }
}
