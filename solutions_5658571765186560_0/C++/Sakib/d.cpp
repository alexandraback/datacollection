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
#define Max

using namespace std;

int cas;

void win(int p){

     printf("Case #%d: %s\n",cas,p==2 ? "GABRIEL" : "RICHARD");

}

int main()
{
    int i,j,k,T,ret=0,x,r,c;

    freopen("/Users/sakibshafayat/Documents/Codes/CodesRunning/Codejam15/Quali/D-small-attempt0.in","r",stdin);
    freopen("/Users/sakibshafayat/Documents/Codes/CodesRunning/Codejam15/Quali/D-small.txt","w",stdout);
    //freopen("/Users/sakibshafayat/Documents/Codes/CodesRunning/Codejam15/Quali/B-large.txt","w",stdout);

    scanf("%d",&T);

    for(cas=1;cas<=T;cas++)
    {
        scanf("%d %d %d",&x,&r,&c);

        if(r<c) swap(r,c);

        if((r*c)%x){
            win(1);
            continue;
        }

        if(x<=2){
            win(2);
            continue;
        }

        if(x==3){

            if(r*c == 3 ){
                win(1);
                continue;
            }

            win(2);
            continue;
        }

        if(r*c > 9) win(2);

        else win(1);
    }

    return 0;
}
