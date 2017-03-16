#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>
#include <algorithm>
#define MAXN 3
#define MAXM 5
#define MAXK 7
#define MAXP 125
using namespace std;

set <int> S;
int p[MAXK+1];
int r,n,m,k;

/*
vector <vector<int> > V[MAXP+1][MAXN+1];
void DFS(int n,int p,int s,vector<int> v)
{
    int i;
    V[p][n].push_back(v);
    if(n==MAXN)
    {
        return;
    }
    for(i=s;i<=MAXM;i++)
    {
        v.push_back(i);
        DFS(n+1,p*i,i,v);
        v.pop_back();
    }
}
*/

void solve()
{
    int i,tk;
    for(i=0;i<k;i++)
    {
        scanf("%d",&p[i]);
    }
    sort(p,p+k);
    tk=unique(p,p+k)-p;
    for(i=0;i<tk;i++)
    {
        if(p[i]== 18){printf("223\n");return;}
        if(p[i]== 24){printf("234\n");return;}
        if(p[i]== 27){printf("333\n");return;}
        if(p[i]== 30){printf("235\n");return;}
        if(p[i]== 32){printf("224\n");return;}
        if(p[i]== 36){printf("334\n");return;}
        if(p[i]== 40){printf("245\n");return;}
        if(p[i]== 45){printf("335\n");return;}
        if(p[i]== 48){printf("344\n");return;}
        if(p[i]== 50){printf("255\n");return;}
        if(p[i]== 60){printf("345\n");return;}
        if(p[i]== 64){printf("444\n");return;}
        if(p[i]== 75){printf("355\n");return;}
        if(p[i]== 80){printf("445\n");return;}
        if(p[i]==100){printf("455\n");return;}
        if(p[i]==125){printf("555\n");return;}
    }
    S.clear();
    for(i=0;i<tk;i++)
    {
        if(p[i]==  2){S.insert(2);}
        if(p[i]==  3){S.insert(3);}
        if(p[i]==  5){S.insert(5);}
        if(p[i]==  6){S.insert(2);S.insert(3);}
        if(p[i]==  9){S.insert(3);S.insert(3);}
        if(p[i]== 10){S.insert(2);S.insert(5);}
        if(p[i]== 15){S.insert(3);S.insert(5);}
        if(p[i]== 25){S.insert(5);S.insert(5);}
        if(p[i]== 12){S.insert(3);}
        if(p[i]== 20){S.insert(5);}
    }
    if(S.size()==n)
    {
        for(set<int>::iterator it=S.begin();it!=S.end();it++)
            printf("%d",*it);
        printf("\n");
        return;
    }
    for(i=0;i<tk;i++)
    {
        if(p[i]==  8)
        {
            if(S.size()==1&&*S.begin()!=2&&*S.begin()!=4){printf("24%d\n",*S.begin());return;}
            else{S.insert(2);S.insert(4);}
        }
        if(p[i]== 12)
        {
            if(S.size()==1&&*S.begin()!=3&&*S.begin()!=4){printf("34%d\n",*S.begin());return;}
            else{S.insert(3);S.insert(4);}
        }
        if(p[i]== 20)
        {
            if(S.size()==1&&*S.begin()!=4&&*S.begin()!=5){printf("45%d\n",*S.begin());return;}
            else{S.insert(4);S.insert(5);}
        }
    }
    for(i=0;i<tk;i++)
    {
        if(p[i]==16)
        {
            if(S.size()==1&&*S.begin()!=4)               {printf("44%d\n",*S.begin());return;}
            else{printf("44");S.insert(8);S.insert(9);}
        }
    }
    for(set<int>::iterator it=S.begin();it!=S.end();it++)
    {
        if(*it<=MAXM)
        {
            printf("%d",*it);
        }
    }
    for(i=S.size();i<n;i++)
    {
        printf("%d",rand()%4+2);
    }
    printf("\n");
}

int main()
{
    freopen("C-small-1-attempt1.in","r",stdin);
    freopen("C-small-1-attempt1.out","w",stdout);
    int c,t,i;
    /*
    DFS(0,1,2,vector<int>());
    for(int i=2;i<=MAXP;i++)
    {
        if(V[i][0].size()+V[i][1].size()+V[i][2].size()+V[i][3].size()==0)continue;
        //if(V[i][0].size()+V[i][1].size()+V[i][2].size()+V[i][3].size()!=1)continue;
        printf("n=%d\n",i);
        for(int n=0;n<=MAXN;n++)
        {
            printf("%d %d %d\n",i,n,V[i][n].size());
            for(int j=0;j<V[i][n].size();j++)
            {
                for(int k=0;k<n;k++)
                {
                    printf("%d ",V[i][n][j][k]);
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    */
    srand((unsigned)time(NULL));
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        printf("Case #%d:\n",c+1);
        scanf("%d %d %d %d",&r,&n,&m,&k);
        for(i=0;i<r;i++)
        {
            solve();
        }
    }
    return 0;
}
