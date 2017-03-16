#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

#define LL long long
#define LD long double

#define VI vector<int>

#define sd(x) scanf("%d",&x)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define PI pair< int , int >
#define PP pair< PI , PI >

int d[100][100];

int main(){
    freopen("B-large.in","r",stdin);
    freopen("output5.txt","w",stdout);
    int t,n,m,i,j,k,l,p,c=1;
    cin>>t;
    while(t--){
        printf("Case #%d: ",c);
        c++;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                sd(d[i][j]);
            }
        }
        k=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                p=0;
                for(l=0;l<m;l++){
                    if(d[i][l]>d[i][j]){
                        p=1;
                    }
                }
                if(p==1){
                    for(l=0;l<n;l++){
                        if(d[l][j]>d[i][j]){
                            p=0;
                        }
                    }
                    if(p==0){
                        k=1;
                    }
                }
            }
        }
        if(k==1){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}
