#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<time.h>
#include<cmath>
#include<vector>
#include <iomanip>
#define PB(u)  push_back(u);
#define AA   first
#define BB   second
#define inf 0x3f3f3f3f
using namespace std ;
#define MAX 2005
#define sz size()
typedef long long ll ;
typedef pair<int,int> PII ;
const double eps=1e-8;
const double pi=acos(-1.0);

char s[MAX];
int num[MAX];
int ans[MAX];

char str[10][10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"} ;

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int T;
    cin>>T;
    int cas=1;
    while(T--)
    {
        memset(num,0,sizeof(num));
        scanf(" %s",s);
        int len=strlen(s);
       // cout<<len<<endl ;
        for(int i=0;i<len;i++)
        {
            num[s[i]]++;
        }
        ans[0]=num['Z'];
        for(int i=0;i<strlen(str[0]);i++)
        {
            num[str[0][i]]-=ans[0];
        }
        ans[2]=num['W'];
        for(int i=0;i<strlen(str[2]);i++)
        {
            num[str[2][i]]-=ans[2];
        }
        ans[6]=num['X'];
        for(int i=0;i<strlen(str[6]);i++)
        {
            num[str[6][i]]-=ans[6];
        }
        ans[4]=num['U'];
        for(int i=0;i<strlen(str[4]);i++)
        {
            num[str[4][i]]-=ans[4];
        }
        ans[3]=num['R'];
        for(int i=0;i<strlen(str[3]);i++)
        {
            num[str[3][i]]-=ans[3];
        }
        ans[5]=num['F'];
        for(int i=0;i<strlen(str[5]);i++)
        {
            num[str[5][i]]-=ans[5];
        }
        ans[7]=num['V'];
        for(int i=0;i<strlen(str[7]);i++)
        {
            num[str[7][i]]-=ans[7];
        }
        ans[1]=num['O'];
        for(int i=0;i<strlen(str[1]);i++)
        {
            num[str[1][i]]-=ans[1];
        }
        ans[8]=num['H'];
        for(int i=0;i<strlen(str[8]);i++)
        {
            num[str[8][i]]-=ans[8];
        }
        ans[9]=num['E'];
        for(int i=0;i<strlen(str[9]);i++)
        {
            num[str[9][i]]-=ans[9];
        }
        printf("Case #%d: ",cas++);
        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<ans[i];j++)
                printf("%d",i);
        }
        printf("\n");
        for(int i=0;i<MAX;i++)
        {
            if(num[i]!=0)
            {
                printf("%c wrong\n",char(i));
            }
        }
    }
    return 0 ;
}
