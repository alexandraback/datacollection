/*
Google Code Jam 2016
Qualification Round
AUTHOR: Phawin Prongpaophan
TASK: Coin Jam (Problem C)
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#define LL long long
#include<set>
#include<vector>
using namespace std;

int n = 32;
int j = 500;
set <LL> ac;
vector <LL> prime;
LL digit [44];
LL pow[12][44];
LL cur[44];

LL con[2016][12];
LL ans[2016][44];

void genprime(LL last)
{
    prime.push_back(2);
    for(LL i = 3;i<=last;i++)
    {
        if(i%1000000==0) printf("Checking %lld\n",i);
        bool ok = true;
        for(int j=0;j<prime.size();j++)
        {
            if(i%prime[j]==0) {ok = false; break;}
            if(prime[j]*prime[j]>i) {break;}
        }
        if(!ok) continue;
        prime.push_back(i);
    }
}


LL mymod(LL a[],LL md,LL base)
{
    //Calculation Phase
    LL curmod = 0;
    for(int i=n-1;i>=0;i--)
    {
        curmod+= a[i];
        curmod%=md;
        if(i==0) return curmod;
        curmod*= (base%md);
        curmod%=md;
    }
}


LL getdiv(LL a[],LL base)
{
    for(int i=0;i<prime.size();i++)
    {
        if(mymod(a,prime[i],base)==0) return prime[i];
    }
    return -1;
}

void genpow()
{
    for(int i=2;i<=10;i++)
    {
        pow[i][0] = 1;
        for(int j=1;j<=n;j++) pow[i][j] = pow[i][j-1]*((LL)i);
    }
    return;
}

LL convert(int base)
{
    LL tret = 0;
    for(int i=0;i<n;i++)    tret+= cur[i]*pow[base][i];
    return tret;
}

void each(int tc)
{
    printf("Case #%d: \n",tc);
    srand(2016);
    scanf("%d%d",&n,&j);
    while(ac.size()<j)
    {
        cur[0] = 1;
        cur[n-1] = 1;
        for(int i=1;i<n-1;i++) cur[i] = rand()%2;
        //End Of Random
        LL rep = convert(2);
        //printf("Trying: %lld\n",rep);
        if(ac.find(rep)!=ac.end()) continue;
        //CHECK!
        LL t[22];
        bool foul = false;
        for(int i=2;i<=10;i++)
        {
            LL trnd = getdiv(cur,i);
            if(trnd<0) {foul=true; break;}
            t[i] = trnd;
        }
        if(foul) continue;
        for(int i=2;i<=10;i++) con[ac.size()][i] = t[i];
        for(int i=0;i<n;i++) ans[ac.size()][i] = cur[i];
        ac.insert(rep);
        //printf("Found: %lld\n",rep);

    }
    //Print Answer:
    //printf("ACCEPTED\n");
    for(int i=0;i<j;i++)
    {
        for(int j=n-1;j>=0;j--) printf("%d",ans[i][j]);
        printf(" ");
        for(int j=2;j<=10;j++) printf("%lld ",con[i][j]);
        printf("\n");
    }
    return;
}

int main()
{

    genprime(100000);
    genpow();
    printf("Prime: %d\n",prime.size());
    freopen("InputC.txt","r",stdin);
    freopen("OutputC.txt","w",stdout);
    //for(int i=0;i<prime.size();i++) printf("%lld ",prime[i]);
    int tcc; scanf("%d",&tcc);
    for(int tcnt=1;tcnt<=tcc;tcnt++)    each(tcnt);
    return 0;
}


