#include<bits/stdc++.h> 
using namespace std;

#define MAX 1000006 
queue<int> Q;
int dp[MAX];
int func(int x)
{
	int r = 0;
	while (x > 0) {
		r = r * 10 + (x % 10);
		x /= 10;
	}
	return r;
}
 
int main()
{
	int t,n,i,x;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    dp[1] = 1;
    Q.push(1);
    while(Q.size()) {
        x = Q.front();
        Q.pop();
        if (x + 1 < MAX and dp[x + 1] == 0) {
            dp[x + 1] = dp[x] + 1;
            Q.push(x + 1);
        }
        if (func(x) < MAX and dp[func(x)] == 0) {
            dp[func(x)] = dp[x] + 1;
            Q.push(func(x));
        }
    }
    cin>>t;
    for(i = 1; i <= t; i++) {
        cin>>n;
        printf("Case #%d: %d\n",i, dp[n]);
    }
    return 0;
}
