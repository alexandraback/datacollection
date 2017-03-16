#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#define intin(a) scanf("%d",&a)
#define intins(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define Sin(s) scanf("%s",s)
#define Lin(a) scanf("%lld",a)
#define LL long long
using namespace std;
LL p,q;

LL gcd(LL n1,LL n2)
{
    return (n2==0?n1:gcd(n2,n1%n2));
}

void separate(string s)
{
    int i,k=s.find("/"), l= s.length();

    //cout<<s.substr(0,i)<<" "<<s.substr(i+1,l-i)<<"\n";

    p=0;q=0;
    for(i=0;i<k;i++)
        {p+=s[i]-'0';p*=10;}
    for(i=k+1;i<l;i++)
        {q+=s[i]-'0';q*=10;}
    p/=10;q/=10;
}

int main()
{
    freopen("A2.in","r",stdin);
    freopen("A2.out", "w", stdout);
    int x=0,cases;
    LL i,j,g,t=1;
    std::string s;
    double f;
    intin(cases);
    while(++x<=cases)
    {
        printf("Case #%d: ",x);

        cin>>s;
        separate(s);
        //reduce
        g=gcd(p,q);
        p/=g;
        q/=g;
        //cout<<p<<" "<<q<<"\n";

        if((q&(q-1))!=0){printf("impossible\n");continue;}

        f=(double) p/q;
        //cout<<f<<"\n";

        for(i=2,j=1;  i<= (t<<40) ; i<<=1,j++)
        {

            //cout<<"help"<<(double) 1/i<<"\n";

            if(f>=(double) 1/i)break;

        }

        printf("%d\n",j);
    }
}
