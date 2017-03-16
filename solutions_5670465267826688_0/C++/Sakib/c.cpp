#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#define inf 2000000000
#define ll long long
#define pci pair<char,int>
#define Max

using namespace std;

void conv(char p,char q,char& r,int& d){

    d=1;

    if(p=='1'){r=q;return;}

    if(q=='1'){r=p;return;}

    if(p==q){r='1';d=-1;return;}

    if(p=='i'){

        if(q=='j'){
                r='k';
                return;
        }

        else{
            r='j';
            d=-1;
            return;
        }
    }

    else if(p=='j'){

        if(q=='i'){
                r='k';
                d=-1;
                return;
        }

        else{
            r='i';
            return;
        }
    }

    else{

        if(q=='i'){
                r='j';
                return;
        }

        else{
            r='i';
            d=-1;
            return;
        }

    }
}

pci mul(pci a,pci b)
{

    char c;
    int sign;

    conv(a.first,b.first,c,sign);

    return make_pair(c,sign*a.second*b.second);

}

pci target[3];
string str;

void pr(pci x)
{
    printf("%c %d\n",x.first,x.second);
}


int main()
{
    int i,j,k,T,cas,ret=0,l,x;

    freopen("/Users/sakibshafayat/Documents/Codes/CodesRunning/Codejam15/Quali/C-small-attempt0.in","r",stdin);
    freopen("/Users/sakibshafayat/Documents/Codes/CodesRunning/Codejam15/Quali/C-small.txt","w",stdout);

    target[0] = make_pair('i',1);
    target[1] = mul( target[0] , make_pair('j',1) );
    target[2] = mul( target[1] , make_pair('k',1) );


    scanf("%d",&T);

    for(cas=1;cas<=T;cas++)
    {
        scanf("%d %d",&l,&x);

        string base;

        cin>>base;

        str="";

        while(x--) str+=base;

        int current=0;

        pci now = make_pair('1',1);

        for(i=0;str[i];i++)
        {

            now=mul(now,make_pair(str[i],1));

            //pr(now);

            if(current<2 && now == target[current]) current++;

        }

        ret=0;

        if( current == 2 && now == target[current]) ret=1;

        printf("Case #%d: %s\n",cas,ret ? "YES" : "NO");
    }

    return 0;
}
