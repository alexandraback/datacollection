#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <string>
#define Nmax 521196
using namespace std;
string s[601010],sir;
long long A,N,v[501010],aux;
int cost[55][55];
long long ind=0,ret=101010,T;


inline int check(int i,int j,int gr)
{//printf("%d %d\n",i,j);
    int ret=0;
    if(sir.size()-i < s[j].size())
        return -1;
    int last = gr-1;
    if(last == -1)
        last = -12345;
    for(int k=i;k<s[j].size()+i;++k)
    {
     //   printf("%c %c %d\n",s[j][k-i],sir[i],abs(s[j][k-i]-sir[i]));
        if(sir[k]!=s[j][k-i])
        {
            ++ret;
            if(k-last<5)
                return -1;
        last = k;
        }

    }
  //  printf("!@$");
    return ret;
}
inline int check1(int i,int j,int gr)
{//printf("%d %d\n",i,j);
    int ret=0;
    if(sir.size()-i < s[j].size())
        return -1;
    int last = gr-1;
    if(last == -1)
        last = -12345;
    for(int k=i;k<s[j].size()+i;++k)
    {

        if(sir[k]!=s[j][k-i])
        {
            ++ret;
            if(k-last<5)
                return -1;
        last = k;
        }

    }
  //  printf("!@$");
    if(last<0)
        return 0;
    else return last+1;
}
int main()
{
    freopen("dic.txt","r",stdin);
    for(int i=1;i<=521196;++i)
        cin>>s[i];
    freopen("b.in","r",stdin);
    freopen("b1.out","w",stdout);
    scanf("%lld\n",&T);
    int ind=0;

    while(T--)
    {   ++ind;
        cin>>sir;

        for(int i=0;i<sir.size()+5;++i)
        {
            for(int k=0;k<=51;++k)
            cost[i][k]=123456;
        }
        cost[0][0]=0;
        for(int i=0;i<sir.size();++i)
        {
            for(int k=0;k<=51;++k)
            if(cost[i][k]!=123456) // daca se poate
            {
                for(int j=0;j<=Nmax;++j)
                    if(check(i,j,k)!=-1)
                    {//cout<<i<<" "<<k<<"\n";
                        int p = check1(i,j,k);

                        cost[i+s[j].size()][p] = min(cost[i+s[j].size()][p],cost[i][k] + check(i,j,k));
                    }
            }
        }
        int rez=1234567;
        for(int k=0;k<=51;++k)
        {
            rez=min(rez,cost[sir.size()][k]);
     //       printf("%d\n",cost[sir.size()][k]);
        }
        printf("Case #%d: %d\n",ind,rez);
    }
    return 0;
}
