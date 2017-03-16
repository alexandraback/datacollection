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

int main()
{
    #ifdef Xanxiver
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small-attempt2.out","w",stdout);
    #endif
    //std::ios::sync_with_stdio(false);    int t;    vector<string> ans;    int j,p,s,k,day=0;    int jp[15][15];    int ps[15][15];    int js[15][15];    scanf("%d",&t);    for(int i=1;i<=t;i++) {        day = 0;        ans.clear();        memset(jp, 0, sizeof jp);        memset(ps, 0, sizeof ps);        memset(js, 0, sizeof js);        scanf("%d %d %d %d",&j,&p,&s,&k);        for(int n=1;n<=j;n++) {            for(int l=1;l<=p;l++) {                for(int m=1;m<=s;m++) {                    if(jp[n][l] < k && ps[l][m] < k && js[n][m] < k) {                        jp[n][l]++;                        ps[l][m]++;                        js[n][m]++;                        day++;                        string s = "";                        s += '0' + n;                        s += ' ';                        s += '0' + l;                        s += ' ';                        s += '0' + m;                        s += '\n';                        ans.pb(s);                    }                }            }        }        printf("Case #%d: %d\n",i, day);        for(int z=0;z<ans.size();z++) {            cout<<ans[z];        }    }
}
