/*
Google Code Jam 2016
Round 1C
AUTHOR: Phawin Prongpaophan
*/

#include<stdio.h>
#include<algorithm>
#include<math.h>
#define LL long long
using namespace std;


int b;
LL m;
int lft;

LL bi[70];

int ans[55][55];
LL powtwo[70];

void each(int tc)
{
    scanf("%d",&b);
    scanf("%lld",&m);
    if(m>powtwo[b-2]) {printf("Case #%d: IMPOSSIBLE\n",tc); return;}
    for(int i=0;i<=b;i++) for(int j=0;j<=b;j++) ans[i][j] = 0;
    lft = b-2;
    LL rival = 1;
    int extra = 0;
    while(rival<m)
    {
        rival*=2; extra++;
    }

    //Answer Exist
    LL penalty = rival-m;
    //printf("Penalty: %lld\n",penalty);
    //Make It happen
    for(int i=1;i<=1+extra;i++)
    {
        for(int j=i+1;j<=1+extra;j++) ans[i][j] = 1;
        ans[i][b] = 1;
    }
    //Make Binary
    LL lft = penalty;
    //printf("Penalty: %lld\n",lft);
    for(int i=0;i<70;i++)
    {
        bi[i] = lft%2; lft/=2;
    }
    //Subtract
    for(int i=0;i<65;i++)
    {
        if(bi[i]==0) continue;
        ans[1][extra+1-i] = 0;
    }
    /*/Check
    LL way[100];
    for(int i=1;i<=b;i++) way[i] = 0;
    way[b] = 1;
    for(int i=b-1;i>0;i--)
    {
        for(int j=i+1;j<=b;j++) way[i]+=(ans[i][j]*way[j]);
    }
    if(way[1]!=m) printf("\aBUG\a\n");*/
    //Print
    printf("Case #%d: POSSIBLE\n",tc);
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=b;j++) printf("%d",ans[i][j]); printf("\n");
    }
    return;
}

int main()
{
    powtwo[0] = 1;
    for(int i=1;i<=63;i++) powtwo[i] = 2*powtwo[i-1];

    freopen("Bin.in","r",stdin);
    freopen("Bout.txt","w",stdout);

    int tcc; scanf("%d",&tcc);
    for(int tcnt=1;tcnt<=tcc;tcnt++)    each(tcnt);
    return 0;
}

