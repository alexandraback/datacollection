#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
using namespace std;


vector<int>move[2000005];

int po[10];
int find(int p)
{
    int c=0;
    do
    {
        c++;
        p/=10;
    }while(p!=0);
    return c;
}



void pre()
{
    po[0]=1;
    for(int i=1;i<=9;i++) po[i]=po[i-1]*10;
    for(int i=10;i<=2000000;i++)
    {
        int dg=find(i);
        int mv=i;
        for(int j=1;j<=dg;j++)
        {
            mv=(mv/10)+(mv%10)*po[dg-1];
            //if(i<=40) cout<<i<<" "<<mv<<endl;
            //if(find(mv)<dg) break;
            if(mv>i) move[i].push_back(mv);
        }
        sort(move[i].begin(),move[i].end());
    }

}



int main()
{
    freopen("C1.in","rt",stdin);
    freopen("C.out","wt",stdout);
    pre();
    int tst,cas,a,b;
    scanf("%d",&tst);
    for(cas=1;cas<=tst;cas++)
    {
        scanf("%d%d",&a,&b);
        int cnt=0;
        for(int i=a;i<=b;i++)
        {
            for(int j=0;j<move[i].size();j++)
            {
               // cout<<move[i][j]<<endl;
                if(move[i][j]<=b) {
                    if(j-1>=0&&move[i][j]==move[i][j-1]) continue;
                    cnt++;
                }


                else break;
            }
        }
        printf("Case #%d: %d\n",cas,cnt);
    }

    return 0;
}
