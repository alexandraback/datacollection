#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t,X,len,mark[26],cnt[10];
string S;

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&t);

    while(t--)
    {
        X++;
        printf("Case #%d: ",X);

        cin>>S;
        for(int i=0;i<26;++i)
            mark[i]=0;

		for(int i=0;i<10;++i)
            cnt[i]=0;

        int i=0;

        while(S[i])
        {
            ++mark[S[i]-'A'];
            ++i;
        }

        cnt[6]=mark['X'-'A'];
        mark['S'-'A']-=mark['X'-'A'];
        mark['I'-'A']-=mark['X'-'A'];
        mark['X'-'A']-=mark['X'-'A'];

        cnt[0]=mark['Z'-'A'];
        mark['E'-'A']-=mark['Z'-'A'];
        mark['R'-'A']-=mark['Z'-'A'];
        mark['O'-'A']-=mark['Z'-'A'];
        mark['Z'-'A']-=mark['Z'-'A'];

        cnt[2]=mark['W'-'A'];
        mark['T'-'A']-=mark['W'-'A'];
        mark['O'-'A']-=mark['W'-'A'];
        mark['W'-'A']-=mark['W'-'A'];

        cnt[8]=mark['G'-'A'];
        mark['E'-'A']-=mark['G'-'A'];
        mark['I'-'A']-=mark['G'-'A'];
        mark['H'-'A']-=mark['G'-'A'];
        mark['T'-'A']-=mark['G'-'A'];
        mark['G'-'A']-=mark['G'-'A'];

        cnt[4]=mark['U'-'A'];
        mark['F'-'A']-=mark['U'-'A'];
        mark['O'-'A']-=mark['U'-'A'];
        mark['R'-'A']-=mark['U'-'A'];
        mark['U'-'A']-=mark['U'-'A'];

        cnt[5]=mark['F'-'A'];
        mark['I'-'A']-=mark['F'-'A'];
        mark['V'-'A']-=mark['F'-'A'];
        mark['E'-'A']-=mark['T'-'A'];
        mark['F'-'A']-=mark['F'-'A'];

        cnt[7]=mark['S'-'A'];
        mark['E'-'A']-=mark['S'-'A'];
        mark['V'-'A']-=mark['S'-'A'];
        mark['E'-'A']-=mark['S'-'A'];
        mark['N'-'A']-=mark['S'-'A'];
        mark['S'-'A']-=mark['S'-'A'];

        cnt[1]=mark['O'-'A'];
        mark['N'-'A']-=mark['O'-'A'];
        mark['E'-'A']-=mark['O'-'A'];
        mark['O'-'A']-=mark['O'-'A'];

        cnt[3]=mark['T'-'A'];
        mark['H'-'A']-=mark['T'-'A'];
        mark['R'-'A']-=mark['T'-'A'];
        mark['E'-'A']-=mark['T'-'A'];
        mark['E'-'A']-=mark['T'-'A'];
        mark['T'-'A']-=mark['T'-'A'];

        cnt[9]=mark['N'-'A']/2;
        mark['I'-'A']-=(mark['N'-'A']/2);
        mark['E'-'A']-=(mark['N'-'A']/2);
        mark['N'-'A']-=mark['N'-'A'];

        for(int i=0;i<10;++i)
        {
            while(cnt[i]--)
            {
                printf("%c",'0'+i);
            }
        }
        printf("\n");
}
return 0;
}
