#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long int LL;
typedef vector<int> VI;

#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 2000000000
#define MOD 1000000007
#define D double
#define LD long double

#define N 1123456
#define S 18

int cnt[N], par[N];
bool vis[N] = {false};
queue<int> Q;
LL dp[S];

inline LL getCnt(LL n){
    if(n < 10){
        return n;
    }
    LL a[S + 5], s = 0, p = 1, ret = 0;
    while(n > 0){
        a[s] = n % 10;
        n /= 10;
        s++;
    }
    int i, j = (s + 1) / 2;
    for(i = s - 1; i >= (s + 1) / 2; i--){
        ret += a[i] * p;
        p *= 10;
    }
    if(ret > 1){
        ret++;
    }
    p = 1;
    for(i = 0; i < (s + 1) / 2; i++){
        ret += p * a[i];
        p *= 10;
    }
    return ret + dp[s - 1];
}

inline void pre(){
    LL p = 0;
    dp[0] = 0;
    for(int s = 1; s < S; s++){
        p *= 10;
        p += 9;
        dp[s] = getCnt(p);
        //cout<<s<<" "<<dp[s]<<endl;
    }
}

int rev(int x){
    int y = 0;
    while(x > 0){
        y *= 10;
        y += x % 10;
        x /= 10;
    }
    return y;
}

int main(){
    freopen("in.in", "r", stdin);
    freopen("op.txt", "w", stdout);
    LL u, x;
    pre();
    cnt[1] = 1;
    par[1] = 0;
	vis[1] = true;
	Q.push(1);
	while(!Q.empty()){
        u = Q.front();
        //if(u % 1000 == 0)
        //cout<<u<<" "<<cnt[u]<<endl,system("pause");
        Q.pop();
        x = u + 1;
        if(x < N && vis[x] == false){
            Q.push(x);
            cnt[x] = cnt[u] + 1;
            par[x] = u;
            vis[x] = true;
        }
        x = rev(u);
        if(x < N && vis[x] == false){
            Q.push(x);
            cnt[x] = cnt[u] + 1;
            par[x] = u;
            vis[x] = true;
        }
	}
	int t, c = 1;
	sd(t);
	while(t--){
        cin>>x;
        printf("Case #%d: %d\n", c, cnt[x]);
        c++;
        //cout<<x<<" "<<cnt[x]<<" "<<getCnt(x)<<endl;
	}
	return 0;
}
