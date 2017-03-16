#include<bits/stdc++.h>
#define MAX 10000
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define ellapse printf("Time : %0.3lf\n",clock()*1.0/CLOCKS_PER_SEC);
using namespace std;/*//E,SE,S,SW,W,NW,N,NEint dr[8]={0,1,1,1,0,-1,-1,-1};int dc[8]={1,1,0,-1,-1,-1,0,1};*/
typedef long long l64d;
typedef unsigned long int ud;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
l64d m;
int main()
{
    #ifdef Xanxiver
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    #endif
    //std::ios::sync_with_stdio(false);    int t;    int b;    l64d sum[55] = {};    int grid[55][55];    cin>>t;    sum[0] = 1;    for(int i=1;i<50;i++) {        sum[i] = 1LL<<(i-1);    }    for(int T=1;T<=t;T++) {        printf("Case #%d: ",T);        cin>>b>>m;        for(int i=0;i<55;i++) {            for(int j=0;j<55;j++) {                if(i < j) {                    grid[i][j] = 1;                }                else grid[i][j] = 0;            }        }        l64d ans = 0;        if(m > sum[b-1]) {            cout<<"IMPOSSIBLE"<<endl;        }        else {            cout<<"POSSIBLE"<<endl;            for(int i=0;i<b;i++) {                grid[b-1][i] = 0;            }            for(int i=b-2;i>=0;i--) {                if(sum[i] <= m) m -= sum[i];                else grid[i][b-1] = 0;            }            for(int i=0;i<b;i++) {                for(int j=0;j<b;j++) {                    cout<<grid[i][j];                }                cout<<endl;            }        }    }
}
