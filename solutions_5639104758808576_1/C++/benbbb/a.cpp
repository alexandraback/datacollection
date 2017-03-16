#include<iostream>
#include<cstdio>

using namespace std;

int main()

{
     freopen("A-large.in","r",stdin);
     freopen("A-large.out","w",stdout);

    int lv,T,ca,i,ans,sum;
    char p[1010];
    cin>>T;
    for (ca=1;ca<=T;ca++)
    {
     ans=0;
     scanf("%d %s",&lv,p);
     sum=p[0]-'0';
     for (i=1;i<=lv;i++)
     {
         if (i>sum) {if (i-sum>ans) ans=i-sum;}
         sum+=p[i]-'0';
     }
    printf("Case #%d: %d\n",ca,ans);

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
