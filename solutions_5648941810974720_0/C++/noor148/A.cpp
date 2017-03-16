#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#define si(a) scanf("%d",&a)

int answer[10],cnt[30];
char str[2005];

void do_it(int pos,char ch,string s)
{
    int chr=ch-'A';
    answer[pos]=cnt[chr];
    int i;
    for(i=0;i<s.size();i++)
        cnt[s[i]-'A']-=answer[pos];
    return ;
}

void solve(int ca)
{
    scanf("%s",str);
    int i;
    memset(answer,0,sizeof(answer));
    memset(cnt,0,sizeof(cnt));
    for(i=0;str[i];i++)
        cnt[str[i]-'A']++;
    do_it(0,'Z',"ZERO");
    do_it(2,'W',"TWO");
    do_it(6,'X',"SIX");
    do_it(4,'U',"FOUR");
    do_it(8,'G',"EIGHT");
    do_it(7,'S',"SEVEN");
    do_it(1,'O',"ONE");
    do_it(5,'V',"FIVE");
    do_it(9,'I',"NINE");
    do_it(3,'H',"THREE");
    printf("Case #%d: ",ca);
    for(i=0;i<10;i++)
        for(int j=0;j<answer[i];j++)
            printf("%d",i);
    printf("\n");
    return ;
}

int main()
{
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("A-small-attempt0.out","w",stdout);
    int t;
    si(t);
    for(int ca=1;ca<=t;ca++)
        solve(ca);
    return 0;
}
