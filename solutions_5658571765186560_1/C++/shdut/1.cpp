#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ll long long
#define ull long long
#define inf 1000000007
#define mod 1000000007
#define DBG(x) cerr<<#x<<"="<<x<<"\n";
#define FOREACH(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define N 10005

int main()
{
    freopen("input.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,i,j,k,m=8,ca=0,n;
    
    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",++ca);
        int r,c,x;
        scanf("%d%d%d",&x,&r,&c);
        if(r*c%x||x>max(r,c)){
            puts("RICHARD");
        }
        else if(x==2||x==1)puts("GABRIEL");
        else {
            int ok=1;
            if(x==3){
                if(r*c==3)ok=0;
            }
            else{
                m=r*c;
                if(m<=2*x)ok=0;
            }
            if(ok)puts("GABRIEL");
            else puts("RICHARD");
        }
    }
    return 0;
}