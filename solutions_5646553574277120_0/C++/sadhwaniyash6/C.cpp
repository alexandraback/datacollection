/*
***************************************************************************************************************

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


#define rep(i,a,b) for(int i=(a);i<(b);i++)

bool p[50];
bool check(int v , int a[]){
    vector<int> c;
    for(int i=1;i<=v;i++){
        if(a[i] > 0){
            c.pb(i);
        }
    }
    rep(i,0,45)p[i] = false;
    int mask = pow(2 , c.size());
    for(int i=0;i<mask;i++){
        int s  = 0;
        for(int j=0;j<c.size();j++){
            if(i & (1<<j)){
                s+=c[j];
            }
        }
        p[s] = 1;
    }
    for(int i=1;i<=v;i++) if(!p[i]){
        return  false;
    }
    return  true;
}
inline void solve(void){
    int t;
    cin >> t;
    int t1 = 1;
    while(t--){
        int c , d , v;
        cin >> c >> d >> v;
        int den[40];
        int cc[40]={0};
        for(int i=0;i < d;i++){
            cin >> den[i];
            cc[den[i]]++;
        }
        int ans = 5;
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                for(int k=1;k<=v;k++){
                    for(int m=1;m<=v;m++){
                        int cnt[50]={0};
                        cnt[i]++;cnt[j]++;
                        cnt[k]++;cnt[m]++;
                        rep(mm,0,d)cnt[den[mm]]++;
                        if(check(v, cnt)){
                            int c = 0;
                            for(int jj=1;jj<=v;jj++){
                                if(cnt[jj] > 0 && cc[jj] == 0){
                                    c++;
                                }
                            }
                            ans  = min(ans  , c);
                        }
                    }
                }
            }
            
        }
        cout<<"Case #"<<t1 <<": "<< ans <<endl;
        t1++;
    }
}
int main(){
    solve();
    return 0;
}