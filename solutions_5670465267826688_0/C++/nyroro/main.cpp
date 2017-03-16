#include <iostream>
#include <cstdio>
#include <set>
#include <assert.h>
using namespace std;
char s[10*10010];
int h[200];
int lef[10*10010];
int righ[10*10010];
long long l,x;
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

        scanf("%lld%lld",&l,&x);
        scanf("%s",s);
        lef[0]=h[s[0]];
        for(int j=1;j<l;j++)
        {
            lef[j]=map(lef[j-1],h[s[j]]);
        }
        for(int i=1;i<x;i++)
        {
            for(int j=0;j<l;j++)
            {
                s[i*l+j]=s[j];
                lef[i*l+j]=map(lef[i*l+j-1],h[s[j]]);
            }
        }

        righ[(x-1)*l+l-1]=h[s[(x-1)*l+l-1]];

        for(int j=(x-1)*l+l-2;j>=0;j--)
        {
            righ[j]=map(h[s[j]],righ[j+1]);
        }

        bool flag=false;
        for(int i=0;i<x*l&&!flag;i++)
        {
            if(lef[i]==2)
            {
                for(int j=i+1;j<x*l&&!flag;j++)
                {
                    if(righ[j]==4)
                    {
                        if(lef[j-1]==4)
                        {
                            flag=true;
                        }
                    }
                }
            }
        }

        if(flag)
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
