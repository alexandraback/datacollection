#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<cmath>
using namespace std;

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000
LL a[10000];
int main(){
    LL t,i,j,x,n;
    scanf("%Ld",&t);
    while(t--){
        scanf("%Ld %Ld",&x,&n);
        for(i=0;i<n;i++)
            scanf("%Ld",&a[i]);
        sort(a,a+n);
        LL cans,bans = n,csz;
        for(i=n-1;i>=0;i--){
            cans = n-1-i;
            csz = x;
            for(j=0;j<=i;j++){
                LL mv = 200;
                while(csz <= a[j] && mv >= 0){
                    mv --;
                    cans ++;
                    csz += (csz-1);
                }
                csz += a[j];
                if(mv <= 0)
                    break;
            }
            if(j == i+1){
                bans = min(bans,cans);
            }
        }
        static LL ct = 0;
        printf("Case #%Ld: %Ld\n",++ct,bans);
    }
	return 0;
}

