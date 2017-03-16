#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<deque>
#include<map>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pii (2.0*acos(0.0))
#define inf (1<<30)
#define eps 1e-8
#define ll long long
#define vi vector<int> 
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define N 105
int n , s , p , a[N];
int t[N][N];

int can(int x){
    int maxi = -1;
    for(int i = 0 ; i <= 10 ; i++)
        for(int j = 0 ; j <= 10 ; j++)
            for(int k = 0 ; k <= 10 ; k++)
                if( i+j+k == x ){
                    if( i == j && j == k-1 ) maxi = max( maxi , max(i , max(j,k)) );
                    if( i == j && j == k+1 ) maxi = max( maxi , max(i , max(j,k)) );
                    if( i == j && j == k ) maxi = max( maxi , i );
                }
    return maxi;
}

int g(int x){
    int maxi = -1;
    for(int i = 0 ; i <= 10 ; i++)
        for(int j = 0 ; j <= 10 ; j++)
            for(int k = 0 ; k <= 10 ; k++)
                if( i+j+k == x ){
                    if( i == j && j == k-2 ) maxi = max( maxi , max( i , max(j,k) ) );
                    if( i == j && j == k+2 ) maxi = max( maxi , max( i , max(j,k) ) );
                    if( i == j-1 && j == k-1 ) maxi = max( maxi , max( i , max(j,k) ) );
                }
    return maxi;
}

int f(int x,int S){
    if(x==n){
        if(S==0)return 0;
        return -100;
    }
    int &ret = t[x][S];
    if(ret != -1) return ret;
    //if( a[x] % 3 == 0 ) ret = (a[x]/3>=p) + f( x+1, S );
    int k = can(a[x]);
    //cout << k << " " << x << endl;
    if( k >= 0 ) ret = max(ret , (k>=p) + f(x+1,S) );
    if( S > 0 ){
        int r = g(a[x]);
        if( r >= 0 ) ret = max( ret , (r>=p) + f(x+1,S-1) );
    }
    return ret;
}

void doit(){
    scanf("%d%d%d",&n,&s,&p);
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    me(t,-1);
    printf("%d\n",f(0,s));
}

int main(){
    int tt;
    scanf("%d",&tt);
    for(int i = 1 ; i <= tt ; i++){
        printf("Case #%d: ",i);
        doit();
    }
}
