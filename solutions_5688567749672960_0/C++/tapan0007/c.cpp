//  main.cpp
//  Practice

//  Copyright (c) 2014 Tapan. All rights reserved.
//

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
#define max_long_value 9223372036854775807
#define pb push_back

const int  maxn  = 2005;

const int INF  = 1000000008;

LL rev(LL n){
    LL s = 0;
    while(n!=0){
        s = s*10 + n%10;
        n/=10;
    }
    return s;
}
map<LL , LL> visit , val;
inline void solve(void){
    int t;
    cin >>t;
    int Tnum = 1;
    while(t--){
        LL n;
        cin >> n;
        visit.clear();
        val.clear();
        queue<LL> v;
        v.push(1);
        visit[1] = 1;
        val[1] = 1;
        while(!v.empty()){
            LL f = v.front();
            v.pop();
            if(f==n){
                break;
            }
            if(visit[f+1] == 0){
                v.push(f+1);visit[f+1] = 1;
                val[f+1] =val[f] + 1;
            }
            if(visit[rev(f)]== 0){
                v.push(rev(f));
                visit[rev(f)] = 1;
                val[rev(f)] =val[f] + 1;
            }
        
        }
        cout << "Case #"<<Tnum<<":  "<<val[n]<<endl;
        Tnum++;
    }
}
void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main(int argc, const char * argv[]){
    init();
    solve();
    return 0;
}