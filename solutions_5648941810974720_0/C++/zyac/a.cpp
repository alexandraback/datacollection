#include<bits/stdc++.h>
using namespace std;
char str[2010];
int vis[10],xx[30];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int n,m;
    int T,Case=1;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof vis);
        memset(xx,0,sizeof xx);
        printf("Case #%d: ",Case++);
        scanf("%s",str);
        int len=strlen(str);
        for(int i=0;i<len;i++)
        {
            xx[str[i]-'A']++;
        }
        vis[0]=xx[25];
        xx['R'-'A']-=xx['Z'-'A'];
        xx['E'-'A']-=xx['Z'-'A'];
        xx['O'-'A']-=xx['Z'-'A'];
        vis[2]=xx['W'-'A'];
        xx['T'-'A']-=xx['W'-'A'];
        xx['O'-'A']-=xx['W'-'A'];
        vis[4]=xx['U'-'A'];
        xx['F'-'A']-=xx['U'-'A'];
        xx['O'-'A']-=xx['U'-'A'];
        xx['R'-'A']-=xx['U'-'A'];
        vis[3]=xx['R'-'A'];
        xx['T'-'A']-=xx['R'-'A'];
        xx['H'-'A']-=xx['R'-'A'];
        xx['E'-'A']-=2*xx['R'-'A'];
        vis[1]=xx['O'-'A'];
        xx['N'-'A']-=xx['O'-'A'];
        xx['E'-'A']-=xx['O'-'A'];
        vis[5]=xx['F'-'A'];
        xx['I'-'A']-=xx['F'-'A'];
        xx['V'-'A']-=xx['F'-'A'];
        xx['E'-'A']-=xx['F'-'A'];
        vis[6]=xx['X'-'A'];
        xx['I'-'A']-=xx['X'-'A'];
        xx['S'-'A']-=xx['X'-'A'];
        vis[7]=xx['S'-'A'];
        xx['E'-'A']-=2*xx['S'-'A'];
        xx['V'-'A']-=xx['S'-'A'];
        xx['N'-'A']-=xx['S'-'A'];
        vis[8]=xx['G'-'A'];
        xx['E'-'A']-=xx['G'-'A'];
        xx['I'-'A']-=xx['G'-'A'];
        xx['H'-'A']-=xx['G'-'A'];
        xx['T'-'A']-=xx['G'-'A'];
        vis[9]=xx['I'-'A'];
        for(int i=0;i<10;i++)
        {
            if(vis[i])
            {
                //cout<<vis[i]<<endl;
                for(int j=0;j<vis[i];j++)
                    printf("%c",'0'+i);
            }
        }
        cout<<endl;
    }
    return 0;
}


