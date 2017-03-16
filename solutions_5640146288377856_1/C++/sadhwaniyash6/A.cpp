/****************************************************************************************************************

                            Author : Yash Sadhwani

**************************************************************************************************************
*/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<stack>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<functional>
using namespace std;
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define mod 1000000007
#define mem(x,y) memset(x,y,sizeof(x))
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define max_int_value 2147483647
#define max_long_value 9223372036854775807


//qsort(ww,cc,sizeof(tp),compare);
/*int compare(const void *a,const void *b){
    ll y=((((tp*)a)->w)-(((tp*)b)->w));
    if(y>0)return 1;
    else if(y==0)return 0;
    else return -1;
}*/

inline void solve(void){
    int t;
    cin >> t;
    int t1 = 1;
    while(t--){
        int r ,c ,w ;
        cin >> r >> c >> w;
        c = r*c;
        int lim;
        
        if(c%w==0) lim = c/w-1;
        else lim = c/w;
        cout <<"Case #"<<t1<<": "<<lim+w<<endl;
        t1++;
        }
    
   
}
int main(void){
    solve();
    return 0;
}