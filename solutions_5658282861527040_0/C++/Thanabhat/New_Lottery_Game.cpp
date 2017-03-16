/*
AUTHOR: THANABHAT KOOMSUBHA
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

int solve(int cc){

    int A,B,K;
    scanf("%d %d %d",&A,&B,&K);
    int sol=0;
    for(int i=0;i<A;i++)
    {
        for(int j=0;j<B;j++)
        {
            if((i&j)<K)
                sol++;
//            printf("%d %d %d %d\n",i,j,i&j,sol);
        }
    }
    printf("Case #%d: %d\n",cc,sol);
    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
        solve(i+1);

	return 0;
}
