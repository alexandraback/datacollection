#include<bits/stdc++.h>

using namespace std;
#include <fstream>
#include <sstream>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF INT_MAX/3
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)

#define VS vector<string>
#define VI vector<int>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PI acos(-1.0)

#define INFILE() freopen("A-small-attempt2.in","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define FASTIO ios_base::sync_with_stdio(0);cin.tie();

#define LL long long
#define ULL unsigned long long
#define EPS 1e-9
#define MOD 1000000007
#define xx first
#define yy second
#define PII pair<LL,LL>
template<typename T>inline string toString(T a){
    ostringstream os(""); os<<a; return os.str();
}
template<typename T>inline LL toLong(T a){
    LL res; istringstream os(a); os>>res; return res;
}
//MATHEMATICS
template<typename T>inline T  SQ(T a){ return a*a; }

template<typename T>inline ULL bigmod(T a, T b, T m) {
    if (b == 0)return 1;
    else if (b % 2 == 0)return SQ(bigmod(a, b / 2, m)) % m;
    else return (a % m*bigmod(a, b - 1, m)) % m;
}
template<typename T>inline VS parse(T str){
    VS res; string s; istringstream os(str); while(os>>s)res.PB(s); return res;
}
template<typename T>inline ULL  dist(T A,T B) {
    ULL res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y); return res;
}
template<typename T>inline double cosAngle(T a,T b,T c) {
    double res=a*a+b*b-c*c; res=res/(2*a*b); res=acos(res); return res;
}
int n,e,src;
int dp[1000004];
LL rev(LL x){
    int ar[17];
    int i=0;
    while(x){
        ar[i]=x%10;
        x/=10;
        i++;
    }
    LL ret=0;
    int j=0;
    while(j<i){
        ret=(ret*10LL + ar[j] );
        j++;
    }
    return ret;

}

//LL cal(LL x){
//    priority_queue<PII>Q;
//    Q.push(MP(1,1));
//    LL ret=0;
//    while(!Q.empty()){
//        PII a = Q.top();
//        if(a.first==x)return ret=a.second;
//        Q.pop();
//
//        LL b = rev(a.first);
//        if(b<=x)
//        Q.push(MP(b,a.second+1) );
//        a.first++;a.second++;
//        Q.push(a);
//    }
//    return ret;
//}

int main(){

    int x,y;
    int ks,cas;
    INFILE();
    OUTFILE();

    dp[0]=0;
    dp[1]=1;
    int Li;
    Li = 1000000;
//    Li = 20;
    for(int i=2;i<=Li;i++){
        dp[i]=dp[i-1]+1;

        int x = rev(i);//cout<<i<<" "<<x<<endl;
        if(rev(x)==i &&  x<i)dp[i]=MIN(dp[i], dp[x]+1);
    }

    cin>>ks;
    for(cas=1;cas<=ks;cas++){
        cin>>n;
//        LL res=cal(n);
        LL res=dp[n];
        cout<<"Case #"<<cas<<": "<<res<<endl;

    }

}
