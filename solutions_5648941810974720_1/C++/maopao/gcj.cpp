#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int num[226];
int ans[12];
char str[2005];
int main()
{
//    freopen("A-small-attempt0.in","r",stdin);
//    freopen("A-small-attempt2.out","w",stdout);
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        memset(num,0,sizeof(num));
        memset(ans,0,sizeof(ans));
        scanf("%s",str);
//        printf("%s\n",str);
        for(int i=0;i<strlen(str);i++)
        {
            num[str[i]]++;
        }
        ans[0]=num['Z'];
        num['E']-=num['Z'];
        num['R']-=num['Z'];
        num['O']-=num['Z'];
        num['Z']-=num['Z'];
        ans[6]=num['X'];
        num['S']-=num['X'];
        num['I']-=num['X'];
        num['X']-=num['X'];
        ans[7]=num['S'];
        num['S']-=ans[7];
        num['E']-=ans[7]*2;
        num['V']-=ans[7];
        num['N']-=ans[7];
        ans[8]=num['G'];
        num['E']-=ans[8];
        num['I']-=ans[8];
        num['G']-=ans[8];
        num['H']-=ans[8];
        num['T']-=ans[8];
        ans[4]=num['U'];
        num['F']-=ans[4];
        num['O']-=ans[4];
        num['U']-=ans[4];
        num['R']-=ans[4];
        ans[5]=num['F'];
        num['F']-=ans[5];
        num['I']-=ans[5];
        num['V']-=ans[5];
        num['E']-=ans[5];
        ans[2]=num['W'];
        num['T']-=ans[2];
        num['W']-=ans[2];
        num['O']-=ans[2];
        ans[1]=num['O'];
        num['O']-=ans[1];
        num['N']-=ans[1];
        num['E']-=ans[1];
        ans[3]=num['T'];
        ans[9]=num['I'];
//        for(int i=0;i<)
        printf("Case #%d: ",cas);
        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<ans[i];j++)
                printf("%d",i);
        }
        printf("\n");
    }
    return 0;
}
