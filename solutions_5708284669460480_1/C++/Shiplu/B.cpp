#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<numeric>
#include<fstream>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps (1e-9)
#define inf (1<<29)
#define i64 long long
#define u64 unsigned i64

int K, L, S, pi[102], prb[26];
void computePrefix(string s)
{
    int m = s.length();
    int k,q;
    pi[1] = k = 0;
    for(q = 2; q<=m;q++){
        while (k > 0 && s[k] != s[q-1])
            k = pi[k];
        if (s[k] == s[q-1])
            k = k + 1;
        pi[q] = k;
    }
}
string target;
double dp[101][101][101];
bool vis[101][101][101];
double solve(int pos,int l, int cnt){
    if(pos == S){
        return cnt*1.0;
    }
    double &ret = dp[pos][l][cnt];
    if(vis[pos][l][cnt]) return ret;
    vis[pos][l][cnt] = 1;
    ret = 0;
    int i;
    for(i = 0;i<26;i++){
        if(prb[i] == 0) continue;
        int len = l, c = cnt;
        while(len && target[len]!= i+'A') len = pi[len];
        if(target[len] == i+'A'){
            len++;
        }
        if(len == L){
            c = cnt + 1;
            len = pi[len];
        }
        ret += solve(pos+1,len,c) * prb[i] / (K*1.0);
    }
    return ret;
}
int main(){
    string  key;
    int t,cs = 1, i;
    cin>>t;
    while(t--){
        cin>>K>>L>>S;
        cin>>key>>target;
        CLR(prb);
        for(i = 0;i<K;i++){
            prb[key[i] -'A'] ++;
        }
        for(i = 0;i<L;i++){
            if(prb[target[i]-'A'] == 0) break;
        }
        if(i<L ){
            printf("Case #%d: %lf\n",cs++,0.0);
            continue;
        }
        CLR(vis);

        computePrefix(target);
        int m = 1, cnt = 0;
        int tmp = S;
        tmp -= L;
        m+= tmp / (L - pi[L]);
        for(i = 0;i<26;i++){
            if(prb[i]) cnt++;
        }
        double ans = m - solve(0,0,0);//pow(cnt,S);
        printf("Case #%d: %lf\n",cs++,ans);
    }
	return 0;
}
