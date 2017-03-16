#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
#include<map>
#include<queue>
#include<bitset>
#include<string>
#include<stdlib.h>
#include<sstream>
#define pb push_back
using namespace std;
int cs;
const double pi=acos(-1);
bool go(long long n,long long st,long long can){
    long long ed=st+(n-1)*4;
    return (st+ed)<=2*can/n;
}
int main(){
    int T,i,j,k,n;
    scanf("%d",&T);
    long long r,t,an;
    while(T--){
        an=0;
        scanf("%lld%lld",&r,&t);
        long long can=t;
        if(2*r+1>can)an=0;
        else{
            long long ll=1;
            for(i=0;;i++)
                if(!go((long long)1<<i,2*r+1,can))break;
            for(i--;i>=0;i--){
                if(go(an+((long long)1<<i),2*r+1,can))an+=(long long)1<<i;
            }
        }
        printf("Case #%d: %lld\n",++cs,an);
    }
    return 0;
}

