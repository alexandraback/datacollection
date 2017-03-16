#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std ;

#define MAXN 100

class ELEMENT
{
    public:
        long long cnt;
        int type;
}boxes[MAXN+5],toys[MAXN+5];
int n,m;

long long solve(int i1,int i2)
{
    if (i1==n || i2==m)return 0;
    long long ret=0;
    long long alpha=0;
    if (boxes[i1].type == toys[i2].type)
        alpha = min(boxes[i1].cnt,toys[i2].cnt);
    ret = max(ret,solve(i1+1,i2));
    boxes[i1].cnt-=alpha;
    toys[i2].cnt-=alpha;
    if (!boxes[i1].cnt)
        ret = max(ret,alpha + solve(i1+1,i2));
    else ret = max(ret,alpha + solve(i1,i2+1));
    boxes[i1].cnt+=alpha;
    toys[i2].cnt+=alpha;
    return ret;
}

int main()
{
//    FILE *in=fopen("box.in","r");
    freopen("box.in","r",stdin);
    freopen("box4.out","w",stdout);
    int c,c2;
    int tests;
//    fscanf(in,"%d",&tests);
    cin>>tests;
    for (int test=1;test<=tests;test++)
    {
//        fscanf(in,"%d%d",&n,&m);
        cin>>n>>m;
        long long teet;
        for (c=0;c<n;c++){
//            fscanf(in,"%lld%d",&teet,&boxes[c].type);
            cin>>boxes[c].cnt>>boxes[c].type;
//            boxes[c].cnt=teet;
        }
        for (c=0;c<m;c++){
//            fscanf(in,"%lld%d",&teet,&toys[c].type);
            cin>>toys[c].cnt>>toys[c].type;
//            toys[c].cnt=teet;
        }
        printf("Case #%d: ",test);
        long long ret=0;
        int c3,c4;
        ret=solve(0,0);
        cout<<ret<<endl;
    }
    
    
//    system("pause");
    return 0;
}
