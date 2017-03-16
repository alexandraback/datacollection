#include <iostream>
#include <cstdio>
#include <set>
#include <assert.h>
using namespace std;
char s[10*10010];
int h[200];
int lef[10*10010];
int righ[10*10010];
int l;
long long x;
int mat[10][10]
=
{
    {
        1,2,3,4
    },
    {
        2,-1,4,-3
    },
    {
        3,-4,-1,2
    },
    {
        4,3,-2,-1
    }
};

int map(int x,int y)
{
    if(x>0&&y>0)return mat[x-1][y-1];
    else if(x<0&&y>0)return -mat[-x-1][y-1];
    else if(x>0&&y<0)return -mat[x-1][-y-1];
    else return mat[-x-1][-y-1];
}
int main()
{
    #ifdef CODEBLOCKS
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CODEBLOCKS
    int t;
    scanf("%d",&t);
    h['i']=2;
    h['j']=3;
    h['k']=4;
    for(int ti=1;ti<=t;ti++)
    {

        scanf("%d%lld",&l,&x);
        scanf("%s",s);
        lef[0]=h[s[0]];
        int copystr=x%4;
        if(x>=4)copystr+=4;
//        cout<<lef[0]<<' ';
        for(int j=1;j<l;j++)
        {
            lef[j]=map(lef[j-1],h[s[j]]);
//            cout<<lef[j]<<' ';
        }
//        cout<<endl;
        for(int i=1;i<copystr;i++)
        {
            for(int j=0;j<l;j++)
            {
                lef[i*l+j]=map(lef[i*l+j-1],h[s[j]]);
//                cout<<lef[i*l+j]<<' ';
            }
//            cout<<endl;
        }

        bool flag=(lef[copystr*l-1]==-1);
//        cout<<lef[copystr*l-1]<<endl;
        int i;
        for(i=0;i<copystr*l&&lef[i]!=2&&flag;i++);
        int j;
        for(j=copystr*l-1;j>=0&&lef[j]!=4&&flag;j--);


        if(flag&&i<j)
        {
            cout<<"Case #"<<ti<<": YES"<<endl;
        }
        else
        {
            cout<<"Case #"<<ti<<": NO"<<endl;
        }
    }
    return 0;
}
