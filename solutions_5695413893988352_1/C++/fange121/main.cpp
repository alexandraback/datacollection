#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
typedef __int64 ll;
#define N 20
char s1[N];
char s2[N];
ll a[N],b[N];
char ans[2][2][3][N];   //第一个为滚动，第二个为那个字符串，第三个为最大值，最小值和最相近的值//
ll vis[3]; //0为使得c-f尽可能的大,1为使得其尽可能相等,2为使得f-c尽可能的大//
ll vis1[3];
ll len;
int main()
{
    ll T,len,i,i1=1;
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%I64d",&T);
    while(T--)
    {
        scanf("%s%s",s1,s2);
        len=strlen(s1);
        for(i=0;i<len;i++)
        {
            if(s1[i]=='?')
                a[i]=-1;
            else
                a[i]=s1[i]-'0';
            if(s2[i]=='?')
                b[i]=-1;
            else
                b[i]=s2[i]-'0';
        }
        for(i=0;i<len;i++)
        {
            ans[1][0][0][i]='a';ans[1][1][0][i]='a';
            ans[1][0][1][i]='a';ans[1][1][1][i]='a';
            ans[1][0][2][i]='a';ans[1][1][2][i]='a';
            ans[0][0][0][i]='a';ans[0][1][0][i]='a';
            ans[0][0][1][i]='a';ans[0][1][1][i]='a';
            ans[0][0][2][i]='a';ans[0][1][2][i]='a';
        }
        ans[1][0][0][len]='\0';ans[1][1][0][len]='\0';
        ans[1][0][1][len]='\0';ans[1][1][1][len]='\0';
        ans[1][0][2][len]='\0';ans[1][1][2][len]='\0';
        i=len-1;
        if(a[i]==b[i]&&a[i]==-1)
        {
            vis[0]=9;ans[1][0][0][len-1]='9';ans[1][1][0][len-1]='0';
            vis[1]=0;ans[1][0][1][len-1]='0';ans[1][1][1][len-1]='0';
            vis[2]=-9;ans[1][0][2][len-1]='0';ans[1][1][2][len-1]='9';
        }
        else if(a[i]!=-1&&b[i]!=-1)
        {
            vis[0]=a[i]-b[i];ans[1][0][0][len-1]=a[i]+'0';ans[1][1][0][len-1]=b[i]+'0';
            vis[1]=a[i]-b[i];ans[1][0][1][len-1]=a[i]+'0';ans[1][1][1][len-1]=b[i]+'0';
            vis[2]=a[i]-b[i];ans[1][0][2][len-1]=a[i]+'0';ans[1][1][2][len-1]=b[i]+'0';
        }
        else if(a[i]==-1)
        {
            vis[0]=9-b[i];ans[1][0][0][len-1]=9+'0';ans[1][1][0][len-1]=b[i]+'0';
            vis[1]=0;ans[1][0][1][len-1]=b[i]+'0';ans[1][1][1][len-1]=b[i]+'0';
            vis[2]=0-b[i];ans[1][0][2][len-1]=0+'0';ans[1][1][2][len-1]=b[i]+'0';
        }
        else if(b[i]==-1)
        {
            vis[0]=a[i]-0;ans[1][0][0][len-1]=a[i]+'0';ans[1][1][0][len-1]=0+'0';
            vis[1]=0;ans[1][0][1][len-1]=a[i]+'0';ans[1][1][1][len-1]=a[i]+'0';
            vis[2]=a[i]-9;ans[1][0][2][len-1]=a[i]+'0';ans[1][1][2][len-1]=9+'0';
        }
        ll tmp=1;
        ll j,k;
        int flag[3];
        for(i=len-2;i>=0;i--)
        {
            tmp*=10;
            memset(flag,0,sizeof(flag));
            for(j=0;j<=9;j++)
                for(k=0;k<=9;k++)
            {
                if((j==a[i]||a[i]==-1)&&(b[i]==-1||b[i]==k))
                {
                    if(flag[0]==0||vis1[0]<vis[i]+(j-k)*tmp)
                    {
                        flag[0]=1;
                        vis1[0]=vis[0]+(j-k)*tmp;
                        strcpy(ans[0][0][0],ans[1][0][0]);
                        strcpy(ans[0][1][0],ans[1][1][0]);
                        ans[0][0][0][i]=j+'0';
                        ans[0][1][0][i]=k+'0';
                    }
                    if(flag[2]==0||vis1[2]>vis[2]+(j-k)*tmp)
                    {
                        flag[2]=1;
                        vis1[2]=vis[2]+(j-k)*tmp;
                        strcpy(ans[0][0][2],ans[1][0][2]);
                        strcpy(ans[0][1][2],ans[1][1][2]);
                        ans[0][0][2][i]=j+'0';
                        ans[0][1][2][i]=k+'0';
                    }
                    if(flag[1]==0||abs(vis1[1])>=abs(vis[1]+(j-k)*tmp))
                    {
                        flag[1]=1;
                        if(abs(vis1[1])>abs(vis[1]+(j-k)*tmp))
                        {
                            vis1[1]=vis[1]+(j-k)*tmp;
                            strcpy(ans[0][0][1],ans[1][0][1]);
                            strcpy(ans[0][1][1],ans[1][1][1]);
                            ans[0][0][1][i]=j+'0';
                            ans[0][1][1][i]=k+'0';
                        }
                        else
                        {
                            ll z,c1=ans[0][0][1][i]-'0',c2=j,d1=ans[0][1][1][i]-'0',d2=k;
                            for(z=i+1;z<len;z++)
                            {
                                c1*=10;c2*=10;d1*=10;d2*=10;
                                c1+=ans[0][0][1][z]-'0';
                                d1+=ans[0][1][1][z]-'0';
                                c2+=ans[1][0][1][z]-'0';
                                d2+=ans[1][1][1][z]-'0';
                            }
                            if((c2<c1)||(c1==c2&&d2<d1))
                            {
                                vis1[1]=vis[1]+(j-k)*tmp;
                                strcpy(ans[0][0][1],ans[1][0][1]);
                                strcpy(ans[0][1][1],ans[1][1][1]);
                                ans[0][0][1][i]=j+'0';
                                ans[0][1][1][i]=k+'0';
                            }
                        }
                    }
                    if(flag[1]==0||abs(vis1[1])>=abs(vis[0]+(j-k)*tmp))
                    {
                        flag[1]=1;
                        if(abs(vis1[1])>abs(vis[0]+(j-k)*tmp))
                        {
                            vis1[1]=vis[0]+(j-k)*tmp;
                            strcpy(ans[0][0][1],ans[1][0][0]);
                            strcpy(ans[0][1][1],ans[1][1][0]);
                            ans[0][0][1][i]=j+'0';
                            ans[0][1][1][i]=k+'0';
                        }
                        else
                        {
                            ll z,c1=ans[0][0][1][i]-'0',c2=j,d1=ans[0][1][1][i]-'0',d2=k;
                            for(z=i+1;z<len;z++)
                            {
                                c1*=10;c2*=10;d1*=10;d2*=10;
                                c1+=ans[0][0][1][z]-'0';
                                d1+=ans[0][1][1][z]-'0';
                                c2+=ans[1][0][0][z]-'0';
                                d2+=ans[1][1][0][z]-'0';
                            }
                            if((c2<c1)||(c1==c2&&d2<d1))
                            {
                                vis1[1]=vis[0]+(j-k)*tmp;
                                strcpy(ans[0][0][1],ans[1][0][0]);
                                strcpy(ans[0][1][1],ans[1][1][0]);
                                ans[0][0][1][i]=j+'0';
                                ans[0][1][1][i]=k+'0';
                            }
                        }
                    }
                    if(flag[1]==0||abs(vis1[1])>=abs(vis[2]+(j-k)*tmp))
                    {
                        flag[1]=1;
                        if(abs(vis1[1])>abs(vis[2]+(j-k)*tmp))
                        {
                            vis1[1]=vis[2]+(j-k)*tmp;
                            strcpy(ans[0][0][1],ans[1][0][2]);
                            strcpy(ans[0][1][1],ans[1][1][2]);
                            ans[0][0][1][i]=j+'0';
                            ans[0][1][1][i]=k+'0';
                        }
                        else
                        {
                            ll z,c1=ans[0][0][1][i]-'0',c2=j,d1=ans[0][1][1][i]-'0',d2=k;
                            for(z=i+1;z<len;z++)
                            {
                                c1*=10;c2*=10;d1*=10;d2*=10;
                                c1+=ans[0][0][1][z]-'0';
                                d1+=ans[0][1][1][z]-'0';
                                c2+=ans[1][0][2][z]-'0';
                                d2+=ans[1][1][2][z]-'0';
                            }
                            if((c2<c1)||(c1==c2&&d2<d1))
                            {
                                vis1[1]=vis[2]+(j-k)*tmp;
                                strcpy(ans[0][0][1],ans[1][0][2]);
                                strcpy(ans[0][1][1],ans[1][1][2]);
                                ans[0][0][1][i]=j+'0';
                                ans[0][1][1][i]=k+'0';
                            }
                        }
                    }
                }
            }
            for(j=0;j<2;j++)
                for(k=0;k<3;k++)
                    strcpy(ans[1][j][k],ans[0][j][k]);
            for(j=0;j<3;j++)
                vis[j]=vis1[j];
        }
        printf("Case #%I64d: ",i1++);
        printf("%s %s\n",ans[1][0][1],ans[1][1][1]);
    }
    return 0;
}
