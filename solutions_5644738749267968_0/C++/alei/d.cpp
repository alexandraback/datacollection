#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<set>
#include<cstring>
typedef long long int uli;
using namespace std;

const int mx = 1e3+10;
double ken[mx];
double naomi[mx];

int main(){
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    int t,n;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf",naomi+i);
        for(int i=0;i<n;i++)
            scanf("%lf",ken+i);
        sort(naomi,naomi+n);
        sort(ken,ken+n);

        int dec = 0;
        int li = 0, ls = n-1;        
        for(int i=0;i<n;i++){
            if(naomi[i]>ken[li])
                dec++,li++;
            else ls--;
        }

        int war = 0;
        li = 0;
        for(int i=0;i<n;i++){
            bool found = false;
            for(;li<n && !found;li++)
                if(ken[li]>naomi[i])
                    found = true;                
            if(!found){
                war = n-i;
                break;
            }
        }
        printf("Case #%d: %d %d\n",tc,dec,war);        
    }
    return 0;
}

