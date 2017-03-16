#include<bits/stdc++.h>
using namespace std;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
#define bitcount    __builtin_popcountll
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d %d",&x,&y);
#define slld(x) scanf("%lld",&x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define ss(x) scanf("%s",x)
#define ll long long
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define pb(x) push_back(x)
#define MOD 1000000007


int ans[50],f[50];
string a;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);freopen("output.txt","w",stdout);

    int t;
    sd(t);
    for(int q=0;q<t;q++)
    {
        for(int i=0;i<30;i++)
        {
            f[i]=0;
            ans[i]=0;
        }
        cin>>a;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            f[a[i]-'A']++;
        }
        int temp=0;

        //0
        temp=f[25];
        for(int i=0;i<temp;i++)
        {
            ans[0]++;
            f[25]--;
            f[4]--;
            f[17]--;
            f[14]--;
        }
        //8
        temp=f[6];
        for(int i=0;i<temp;i++)
        {
            ans[8]++;
            f[4]--;
            f[8]--;
            f[6]--;
            f[7]--;
            f[19]--;
        }
        //6
        temp=f[23];
        for(int i=0;i<temp;i++)
        {
            ans[6]++;
            f[18]--;
            f[8]--;
            f[23]--;
        }
        //7
        temp=f[18];
        for(int i=0;i<temp;i++)
        {
            ans[7]++;
            f[18]--;
            f[4]--;
            f[21]--;
            f[4]--;
            f[13]--;
        }


        //5
        temp=f[21];
        for(int i=0;i<temp;i++)
        {
            ans[5]++;
            f[5]--;
            f[8]--;
            f[21]--;
            f[4]--;
        }

        //2
        temp=f[22];
        for(int i=0;i<temp;i++)
        {
            ans[2]++;
            f[19]--;
            f[22]--;
            f[14]--;
        }

        //4
        temp=f[5];
        for(int i=0;i<temp;i++)
        {
            ans[4]++;
            f[5]--;
            f[14]--;
            f[20]--;
            f[17]--;
        }

        //3
        temp=f[19];
        for(int i=0;i<temp;i++)
        {
            ans[3]++;
            f[19]--;
            f[7]--;
            f[17]--;
            f[4]-=2;
        }

        //1

        temp=f[14];
        for(int i=0;i<temp;i++)
        {
            ans[1]++;
            f[14]--;
            f[13]--;
            f[4]--;
        }

        ans[9]+=f[8];

        printf("Case #%d: ",q+1);

        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<ans[i];j++)
                printf("%d",i);
        }
        printf("\n");












    }





}



