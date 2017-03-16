#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(I,N) for(int (I) = 0; (I) < (N); (I)++)

typedef pair<int,int> pii;
typedef long long ll;

char tab[107];
string k, l;
int s, kl, llen;
int count(string x){
    int res = 0;
    for(int i = 0; i + l.length() <= x.length(); i++){
        if (x.substr(i, l.length()) == l)
            res++;
    }
    return res;
}
int biggest;
ll sum;
string possible;
ll power(ll a, ll b){
    if (!b) return 1ll;
    return a * power(a, b-1ll);
}
ll howMany(){
    return power((ll)(kl), (ll)(s));
}
void gen(){
    if (possible.length() == s){
        int curr = count(possible);
        biggest = max(biggest, curr);
        sum += curr;
        return;
    }
    for(int i = 0; i < k.length(); i++){
        possible.pb(k[i]);
        gen();
        possible.erase(possible.begin() + (possible.length() - 1));
    }
}
int main(){
    int t;
    scanf("%d",&t);
    rep(testId,t){
        printf("Case #%d: ", testId+1);
        scanf("%d%d%d",&kl, &llen, &s);
        scanf("%s", tab);
        k = (string)(tab);
        scanf("%s",tab); l = (string)(tab);
        sum = 0ll; biggest = 0;
        possible = "";
        gen();
        printf("%.7Lf\n", (long double)biggest - (long double)(sum)/(howMany()));
    }
}
