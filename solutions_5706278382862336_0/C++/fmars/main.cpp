#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
using namespace std;
typedef long long ll;
ll gcd (ll n1, ll n2) {
    return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
}
ll find_biggest(ll x){
    int r=1;
    while(r*2<=x)
        r*=2;
    return r;
}
bool valid(ll P,ll Q){
    ll r=gcd(P,Q);
    Q/=r;
    while(Q!=1){
        if(Q%2!=0)
            return false;
        Q/=2;
    }
    return true;
}
int bar(ll P,ll Q){
    if(P==Q)return 0;
    if(P*2>=Q)return 1;
    ll PP,r;
    r=gcd(P,Q);
    P=P/r;
    Q=Q/r;
    PP=find_biggest(P*2);
    return bar(PP,Q)+1;
}
int main()
{
	freopen("in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int  TC, T;
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++){
		printf("Case #%d: ", T);
		char c;
		ll P,Q;
        cin>>P>>c>>Q;

        if(!valid(P,Q)){
            printf("impossible\n");
            continue;
        }
        int res=0;
        res=bar(P,Q);
		printf("%d\n", res);
	}
	return 0;
}
