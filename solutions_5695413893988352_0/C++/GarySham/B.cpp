#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<list>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define FIT(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); ++it)
#define CLR(i) memset(i,0,sizeof(i))
#define eps (1e-8)
#define feq(x,y) (fabs((x)-(y))<=eps)
#define fgt(x,y) (((x)-(y)) > eps)
#define flt(x,y) (((y)-(x)) > eps)
#define fgeq(x,y) (fgt(x,y) || feq(x,y))
#define fleq(x,y) (flt(x,y) || feq(x,y))
#define ll long long

int T;
char s1[20],s2[20];
int len;
bool found;
ll ans1,ans2,diff;

void update(ll left, ll right){
    ll dd = left - right;
    if (dd < 0ll) dd = -dd;
//    printf("%lld %lld %lld\n",left, right, dd);
//    printf("%lld %lld %lld\n",ans1, ans2, diff);
    if (found){
        if (dd < diff){
            ans1 = left; ans2 = right; diff = dd;
        }
        else if (dd == diff){
            if (left < ans1){
                ans1 = left; ans2 = right; diff = dd;
            }
            else if (left == ans1){
                if (right < ans2){
                    ans1 = left; ans2 = right; diff = dd;
                }
            }
        }
    }
    else{
        found = 1;
        ans1 = left; ans2 = right; diff = dd;
    }
}

void gen(int n, int pos, ll left, ll right){
    if (pos >= n){
        update(left, right);
        return;
    }

    if (left > right){
        FOR(i,pos,n){
            if (s1[i] == '?') left = left*10ll + 0ll;
            else left = left*10ll + (ll)(s1[i]-'0');

            if (s2[i] == '?') right = right*10ll + 9ll;
            else right = right*10ll + (ll)(s2[i]-'0');
        }
        update(left,right);
        return;
    }
    else if (right > left){
        FOR(i,pos,n){
            if (s1[i] == '?') left = left*10ll + 9ll;
            else left = left*10ll + (ll)(s1[i]-'0');

            if (s2[i] == '?') right = right*10ll + 0ll;
            else right = right*10ll + (ll)(s2[i]-'0');
        }
        update(left,right);
        return;
    }

    if (s1[pos] == '?' && s2[pos] == '?'){
        // 00
        gen(n,pos+1,left*10ll + 0ll, right*10ll + 0ll);
        // 01
        gen(n,pos+1,left*10ll + 0ll, right*10ll + 1ll);
        // 10
        gen(n,pos+1,left*10ll + 1ll, right*10ll + 0ll);
    }
    else if (s1[pos] == '?'){
        // up 1
        if (s2[pos] != '9'){
            gen(n,pos+1,left*10ll + (ll)(s2[pos]-'0') + 1ll, right*10ll + (ll)(s2[pos]-'0'));
        }
        // down 1
        if (s2[pos] != '0'){
            gen(n,pos+1,left*10ll + (ll)(s2[pos]-'0') - 1ll, right*10ll + (ll)(s2[pos]-'0'));
        }
        // eq
        gen(n,pos+1,left*10ll + (ll)(s2[pos]-'0'), right*10ll + (ll)(s2[pos]-'0'));
    }
    else if (s2[pos] == '?'){
        // up 1
        if (s1[pos] != '9'){
            gen(n,pos+1,left*10ll + (ll)(s1[pos]-'0'), right*10ll + (ll)(s1[pos]-'0') + 1ll);
        }
        // down 1
        if (s1[pos] != '0'){
            gen(n,pos+1,left*10ll + (ll)(s1[pos]-'0'), right*10ll + (ll)(s1[pos]-'0') - 1ll);
        }
        // eq
        gen(n,pos+1,left*10ll + (ll)(s1[pos]-'0'), right*10ll + (ll)(s1[pos]-'0'));
    }
    else{
        gen(n,pos+1,left*10ll + (ll)(s1[pos]-'0'), right*10ll + (ll)(s2[pos]-'0'));
    }
}

int main(){
    scanf("%d",&T); gets(s1);
    FOE(t,1,T){
        found = 0;
        scanf("%s%s",s1,s2);
        len = strlen(s1);
        gen(len,0,0ll,0ll);

        int d1,d2;
        ll a1,a2;
        a1 = ans1; a2 = ans2;
        d1=d2=0;
        while (a1 > 0ll){
            ++d1;
            a1 /= 10ll;
        }
        while (a2 > 0ll){
            ++d2;
            a2 /= 10ll;
        }
        if (ans1 == 0ll) ++d1;
        if (ans2 == 0ll) ++d2;

        printf("Case #%d: ", t);
        FOR(i,0,len-d1) printf("0");
        printf("%lld ", ans1);
        FOR(i,0,len-d2) printf("0");
        printf("%lld", ans2);
        puts("");
    }
    return 0;
}
