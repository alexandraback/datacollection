/*
 ***************************************************************************************************************
 
 Author : Tapan Sahni
 
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
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
#define LL long long
#define si(x) scanf("%d",&x)
#define sc(x) scanf("%c",&x)
#define sl(x) scanf("%I64d",&x)
#define prl(x) printf("%I64d",x)
#define pri(x) printf("%d\n",x)
#define prs(x) printf("%s\n",x)
typedef pair<int, int> ii;
typedef pair<LL, LL> iil;
typedef pair<LL, iil> iiil;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;
#define vl vector<ll>
#define vi vector<int>
#define vii vector<ii>
#define vvl vector< vl >
#define vvi vector< vi >
#define vvii vector< vii >
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define mod 1000000007
#define pb push_back

const int  maxn  = 400000;
const int INF  = 10000008;
//const LL INF = 0x0123456789ABCDEFLL;
int K,L,S;

char letter[70];

char str[70];

char temp[70];

int occ(){
    int ret=0;
    for(int i=0;i<S;i++){
        if(i+L<=S){
            int j;
            for(j=i;j<i+L;j++){
                if(str[j-i]!=temp[j])break;
            }
            if(j==i+L)ret++;
        }
    }
    return ret;
}

int a = 0,b = 0  ,crtt  = 1;
double go(){
    a=0; b=0;
    a=0;
    int max_mask=pow(K,S);
    for(int mask=0;mask<max_mask;mask++){
        int mask2=mask;
        for(int i=0;i<S;i++){
            int idx=mask%K;
            mask/=K;
            temp[i]=letter[idx];
        }
        temp[S]='\0';
        int x=occ();
        b=max(b,x);
        a+=x;
        crtt++;
        crtt = mask + crtt;
        mask=mask2;
    }
    double ans=(b*1LL*(max_mask))-a;
    ans/=(max_mask);
    return ans;
}
inline void solve(int turn){
    int x1  = 1;
    x1 ++;
    printf("Case #%d: %.10lf\n",turn,go() );
}

inline void Refresh(void){
    
}

int main()
{
    int t; si(t);
    for(int i=1;i<=t;i++){
        cin >> K >> L >> S;
        cin>>letter;
        cin>>str;
        solve(i);
    }
    return 0;
}