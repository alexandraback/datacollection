#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<assert.h>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>

using namespace std;

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define EPS 1e-9
#define asdf exit(0);
typedef long long LL;

int ab(int a)
{
    if(a<0) return -a;
    else return a;
}


int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);



    int i,j,k,m,cs,T;



    scanf("%d",&T);
    LL ans=0;
    int LAST;

    int X,Y;

    for(cs=1;cs<=T;cs++)
    {
        printf("Case #%d: ",cs);

        scanf("%d %d",&X,&Y);



        string s[4];


        if(Y>=0)
        {
            s[0]="N";
            s[1]="S";
        }
        else
        {
            s[0]="S";
            s[1]="N";
        }


        if(X>=0)
        {
            s[2]="E";
            s[3]="W";
        }
        else
        {
            s[2]="W";
            s[3]="E";
        }


        string st="";

        for(i=0;i<ab(Y);i++)
        {
            st+=s[1];
            st+=s[0];
        }
        for(i=0;i<ab(X);i++)
        {
            st+=s[3];
            st+=s[2];
        }



        cout<<st<<endl;




    }
    return 0;
}

