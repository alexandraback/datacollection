/*Author : Md. Al- Amin
           20th batch
           Dept. of CSE, SUST*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define pi (2*acos(0))
#define SF scanf
#define SFd1(a) scanf("%d",&a)
#define SFd2(a,b) scanf("%d%d",&a,&b)
#define SFd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define PF printf
#define inf 99999999
#define eps 0.00000001
#define ll long long
#define ull long long unsigned
#define int_max 2147483647
#define int_min -2147483648
#define long_max 9223372036854775807
#define long_min -9223372036854775808
#define fr(i,n) for(i=0;i<n;i++)
#define ms(dp,a) memset(dp,a,sizeof(dp))
#define dist(x1,y1,x2,y2) sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) )
#define PB push_back
#define mem(arr,val) memset(arr,val,sizeof(arr))

using namespace std;
//int rr[]={1,2,-1,-2,1,2,-1,-2};
//int cc[]={2,1,2,1,-2,-1,-2,-1};
//int rr[]={0,0,1,-1};
//int cc[]={-1,1,0,0};

int t,p,flag,l,res[12],mpp[210],i;
char arr[2010];

int main()
{
    freopen("A-small-attempt0a.in","r",stdin);
    freopen("gettingthedigitsout.txt","w",stdout);
    scanf(" %d",&t);

    for(p=1;p<=t;p++)
    {
        scanf(" %s",arr);
        memset(mpp,0,sizeof(mpp));
        l=strlen(arr);
        for(i=0;i<l;i++)
        {
            mpp[arr[i]-'A']++;
        }
        res[0]=mpp['Z'-'A'];
        mpp['Z'-'A']=0;
        mpp['E'-'A']-=res[0];
        mpp['R'-'A']-=res[0];
        mpp['O'-'A']-=res[0];

        res[2]=mpp['W'-'A'];
        mpp['W'-'A']=0;
        mpp['T'-'A']-=res[2];
        mpp['O'-'A']-=res[2];

        res[8]=mpp['G'-'A'];
        mpp['G'-'A']=0;
        mpp['E'-'A']-=res[8];
        mpp['I'-'A']-=res[8];
        mpp['H'-'A']-=res[8];
        mpp['T'-'A']-=res[8];

        res[6]=mpp['X'-'A'];
        mpp['X'-'A']=0;
        mpp['S'-'A']-=res[6];
        mpp['I'-'A']-=res[6];

        res[7]=mpp['S'-'A'];
        mpp['S'-'A']=0;
        mpp['E'-'A']-=res[7];
        mpp['V'-'A']-=res[7];
        mpp['E'-'A']-=res[7];
        mpp['N'-'A']-=res[7];

        res[5]=mpp['V'-'A'];
        mpp['V'-'A']=0;
        mpp['F'-'A']-=res[5];
        mpp['I'-'A']-=res[5];
        mpp['E'-'A']-=res[5];

        res[4]=mpp['F'-'A'];
        mpp['F'-'A']=0;
        mpp['O'-'A']-=res[4];
        mpp['U'-'A']-=res[4];
        mpp['R'-'A']-=res[4];

        res[3]=mpp['T'-'A'];
        mpp['T'-'A']=0;
        mpp['H'-'A']-=res[3];
        mpp['R'-'A']-=res[3];
        mpp['E'-'A']-=res[3];
        mpp['E'-'A']-=res[3];

        res[1]=mpp['O'-'A'];
        mpp['O'-'A']=0;
        mpp['N'-'A']-=res[1];
        mpp['E'-'A']-=res[1];

        res[9]=mpp['I'-'A'];
        mpp['I'-'A']=0;
        mpp['N'-'A']-=res[9];
        mpp['N'-'A']-=res[9];
        mpp['E'-'A']-=res[9];

        flag=0;

        for(i=0;i<26;i++)
        {
            if(mpp[i]!=0)
                flag=1;
        }
        printf("Case #%d: ",p);
        if(flag==0)
        {
            for(i=0;i<10;i++)
            {
                while(res[i]>0)
                {
                    printf("%d",i);
                    res[i]--;
                }
            }
        }
        printf("\n");
    }
    return 0;
}

