#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T,K,L,S;
    char ch,c[101];
    int a[26],maxb;
    double exp;
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++)
    {
        string b;
        for(int i=0;i<26;i++){a[i]=0;}
        exp=1.0;

        scanf("%d%d%d",&K,&L,&S);
        scanf("%s",c);
        for(int i=0;i<K;i++)
        {
            ch=c[i];
            a[ch-'A']++;
            //printf("%d\n",a[ch-'A']);
        }
        cin>>b;
        for(int i=0;i<L;i++)
        {
            ch=b[i];
            exp*=a[ch-'A'];
            //printf("%d %f\n",a[ch-'A'],exp);
        }
        //b[L]='\0';

        maxb=S/L;
        for(int i=L-1;i>0;i--)
        {
            //cout<<b.substr(0,i)<<" "<<b.substr(L-i,i)<<endl;
            if(b.substr(0,i)==b.substr(L-i,i))
            {
                maxb=(S-L)/(L-i)+1;
                break;
            }
            else if(i==1)
            {
                maxb=S/L;
            }
        }
        if(exp==0) maxb=0;
        exp*=S-L+1;
        exp/=pow(K,L);
        //cout<<maxb<<" "<<exp<<endl;
        printf("Case #%d: %lf\n",tc,maxb-exp);
    }
    return 0;
}
