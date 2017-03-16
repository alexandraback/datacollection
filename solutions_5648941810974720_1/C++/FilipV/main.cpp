#include <bits/stdc++.h>

using namespace std;

int cnt[30];
int tmp[30];
int rem(string digits)
{
    int minn=9999;
    for(int i=0; i<30; i++)tmp[i]=0;
    for(int i=0; i<digits.size(); i++)
        tmp[digits[i]-'A']++;
    for(int i=0; i<digits.size(); i++)
        minn=min(minn,cnt[digits[i]-'A']/tmp[digits[i]-'A']);
    for(int i=0; i<digits.size(); i++)
        cnt[digits[i]-'A']-=minn;
    return minn;
}
int sol[11];
int main()
{
    int t,testno=1;
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        string s;
        cin>>s;
        for(int i=0; i<26; i++)cnt[i]=0;
        for(int i=0; i<s.length(); i++)
            cnt[s[i]-'A']++;
        sol[0]=rem("ZERO");
        sol[2]=rem("TWO");
        sol[6]=rem("SIX");
        sol[8]=rem("EIGHT");
        sol[7]=rem("SEVEN");
        sol[3]=rem("THREE");
        sol[5]=rem("FIVE");
        sol[4]=rem("FOUR");
        sol[1]=rem("ONE");
        sol[9]=rem("NINE");
        printf("Case #%d: ",testno++);
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<sol[i]; j++)
                printf("%d",i);
        }
        printf("\n");
    }
    return 0;
}
