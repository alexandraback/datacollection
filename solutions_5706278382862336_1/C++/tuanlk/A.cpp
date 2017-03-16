#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#include<vector>

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DFOR(i,a,b) for(int i=a;i>=b;i--)
#define mp(x,y) make_pair((int)x,(int)y)
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; FOR(i,a,b) cout << x[i] << ' '; cout << endl;}
#define ll long long
#define DEBUG 1
#define nmax 100
int nTest;
char s[nmax];
ll P,Q;
ll gcd(ll a, ll b){
    if (b==0LL) return a;
    return gcd(b,a%b);
}
bool checkPow2(ll num){
    ll value=1LL;
    while (value<num) value*=2LL;
    return value==num;
}
bool bigger(ll D,ll P, ll Q){
    return P>=(Q/D);
}
int main(){
    if (DEBUG==1){
        freopen("A-large.in","r",stdin);
        freopen("output.txt","w",stdout);
    }
    scanf("%d\n",&nTest);
    FOR(test,1,nTest){
        scanf("%s",s);
        P=0LL;
        int cs=0;
        while (s[cs]!='/'){
            int num= s[cs]-'0';
            P=P*10LL+(ll)num;
            cs++;
        }
        cs++;
        Q=0LL;
        while (cs<strlen(s)){
            int num= s[cs]-'0';
            Q=Q*10LL+(ll)num;
            cs++;
        }
        ll D= gcd(P,Q);
        P/=D;
        Q/=D;
        int ans=0;
        if (checkPow2(Q)){
            D=1LL;
            FOR(cs,1,40){
                D*=2;
                if (bigger(D,P,Q)){
                    ans=cs;
                    break;
                }
            }
        }
        printf("Case #%d: ",test);
        if (ans==0) cout<<"impossible"<<endl; else cout<<ans<<endl;
    }
    return 0;
}
