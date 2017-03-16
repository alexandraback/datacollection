#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

set<int> s;
int A,B;
struct Bit
{
    int v[100];
    int l;
};
int toNum(Bit &bit)
{
    int num=0;
    for(int i=0;i<bit.l;i++) num=num*10+bit.v[i];
    return num;
}
Bit toBit(int num)
{
    Bit bit;
    bit.l=0;
    while(num)
    {
        bit.v[bit.l++]=num%10;
        num/=10;
    }
    for(int i=0;i<bit.l/2;i++) swap(bit.v[i],bit.v[bit.l-1-i]);
    return bit;
}
int solve(int n)
{
    Bit bit=toBit(n);
    Bit bit2;
    int ret=0;
    s.clear();

    for(int i=bit.l-1;i>=0;i--)
    {
        bit2.l=0;
        int j;
        for(j=i;j<bit.l;j++) bit2.v[bit2.l++]=bit.v[j];
        j=0;
        while(bit2.l<bit.l) bit2.v[bit2.l++]=bit.v[j++];

        int tmp=toNum(bit2);


        Bit b1,b2;
        b1=toBit(n);
        Bit a=toBit(A);

        b2=toBit(tmp);



        if(A<=n && n<tmp && tmp<=B && b1.l==b2.l && b1.l==a.l &&
           s.count(tmp)==0 )
           {
               s.insert(tmp);
               ret++;
           }
    }
    return ret;
}
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int t;
    scanf("%d",&t);
    int cot=1;
    while(t--)
    {
        scanf("%d%d",&A,&B);
        int ans=0;
        for(int i=A;i<=B;i++)
        {
            ans+=solve(i);
        }
        printf("Case #%d: %d\n",cot++,ans);
    }
    return 0;
}






