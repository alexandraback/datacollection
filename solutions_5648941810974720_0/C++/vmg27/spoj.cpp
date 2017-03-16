#include    <bits/stdc++.h>

#define     M_PI            3.14159265358979323846
#define     mod             1000000007
#define     inf             1000000000000000000
#define     mp              make_pair
#define     pb              push_back
#define     F               first
#define     S               second
#define     ll              long long
#define     pii             pair<int,int>
#define     pli             pair<ll,int>
#define     pil             pair<int,ll>
#define     pll             pair<ll,ll>
#define     si(t)           scanf("%d",&t)
#define     sii(m,n)        scanf("%d %d",&m,&n);
#define     sl(t)           scanf("%lld",&t)
#define     rep(i,n)        for(int i=0;i<n;i++)
#define     REP(i,a,b)      for(int i=a;i<=b;i++)
#define     RREP(i,a,b)     for(int i=a;i>=b;i--)
#define     N               5005

using namespace std;

string ref[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int arr[30],ans[20],n;

void fun(int a){
    string s = ref[a];
    int k = s.length();
    rep(i,k){
        arr[s[i]-'A'] -= ans[a];
    }
}

int main(){
    int t; si(t);
    REP(T,1,t){
        memset(arr,0,sizeof arr);
        string s; cin>>s;
        n = s.length();
        rep(i,n) arr[s[i]-'A']++;
        ans[0] = arr['Z'-'A'];
        fun(0);
        ans[2] = arr['W'-'A'];
        fun(2);
        ans[4] = arr['U'-'A'];
        fun(4);
        ans[6] = arr['X'-'A'];
        fun(6);
        ans[8] = arr['G'-'A'];
        fun(8);
        ans[7] = arr['S'-'A'];
        fun(7);
        ans[5] = arr['V'-'A'];
        fun(5);
        ans[9] = arr['I'-'A'];
        fun(9);
        ans[3] = arr['T'-'A'];
        fun(3);
        ans[1] = arr['O'-'A'];
        fun(1);
        printf("Case #%d: ",T);
        rep(i,10){
            rep(j,ans[i]) printf("%d",i);
        }
        printf("\n");
    }
    return 0;   
}

