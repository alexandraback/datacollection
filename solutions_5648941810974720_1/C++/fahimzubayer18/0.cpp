#include <bits/stdc++.h>
#define ll long long
using namespace std;

int cnt[12][29];

string s[12];

int scnt[29];
int ans[29];
int de[29];

void pre()
{
    s[0]="ZERO";
    s[1]="ONE";
    s[2]="TWO";
    s[3]="THREE";
    s[4]="FOUR";
    s[5]="FIVE";
    s[6]="SIX";
    s[7]="SEVEN";
    s[8]="EIGHT";
    s[9]="NINE";

    for(int a=0;a<10;a++)
    {
        for(int b=0;b<s[a].size();b++)
        {
            cnt[a][ s[a][b]-'A' ]++;
        }
    }

    /*for(int a=0;a<10;a++)
    {
        for(int b=0;b<26;b++)
        {
            for(int c=0;c<cnt[a][b];c++) printf("%c",'A'+b);
        }printf("\n");
    }*/
}

void dec(int i,int k)
{
   // cout<<"Decreasing "<<i<<endl;
    while(k)
    {


    for(int a=0;a<26;a++)
    {
        scnt[a]=scnt[a]-cnt[i][a];
        //if(cnt[i][a]) cout<<"Decreased "<<(char)('A'+a)<<" "<<cnt[i][a]<<" times"<<endl;
    }
    k--;
    }
}

int main()
{
    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);

    int a,b,c,d,e,x,y,z,t;

    pre();

    scanf("%d",&t);

    for(int te=1;te<=t;te++)
    {
        printf("Case #%d: ",te);

        string inp;
        cin>>inp;
        //cout<<inp<<endl;

        for(a=0;a<26;a++)
        {
            scnt[a]=0;
            ans[a]=0;
            de[a]=0;
        }

        for(a=0;a<inp.size();a++)
        {
            scnt[ inp[a]-'A' ]++;
        }

        for(a=0;a<26;a++) de[a]=scnt[a];

        ans[0]=ans[0]+scnt['Z'-'A'];
        dec(0,scnt['Z'-'A']);

        ans[2]=ans[2]+scnt['W'-'A'];
        dec(2,scnt['W'-'A']);


        ans[4]=ans[4]+scnt['U'-'A'];
        dec(4,scnt['U'-'A']);




        ans[6]=ans[6]+scnt['X'-'A'];
        dec(6,scnt['X'-'A']);


        ans[8]=ans[8]+scnt['G'-'A'];
        dec(8,scnt['G'-'A']);



        ans[1]=ans[1]+scnt['O'-'A'];
        dec(1,scnt['O'-'A']);

        ans[3]=ans[3]+scnt['T'-'A'];
        dec(3,scnt['T'-'A']);

        ans[5]=ans[5]+scnt['F'-'A'];
        dec(5,scnt['F'-'A']);

        ans[7]=ans[7]+scnt['S'-'A'];
        dec(7,scnt['S'-'A']);

        ans[9]=ans[9]+scnt['I'-'A'];
        dec(9,scnt['I'-'A']);


        for(a=0;a<=9;a++)
        {
            for(b=0;b<ans[a];b++) printf("%d",a);
        }printf("\n");
    }


    return 0;
}
