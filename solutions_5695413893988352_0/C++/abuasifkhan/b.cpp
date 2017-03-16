

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pii pair <string, string>
#define pb push_back
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf (1ll<<28)
#define ll unsigned long long
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
#define mx 100010

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while((~c&&c<'0')||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
//int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
//int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
int X[]= {-1, 0, 1, 0};   //x 4 direction
int Y[]= { 0, 1, 0, -1};  //y 4 direction

string a, b;
ll minVal;

ll stringToInt(string a){
    stringstream ss;
    ss<<a;
    ll tmp;
    ss>>tmp;
    return tmp;
}
ll ABS(ll a1, ll b1){
    if(a1>=b1)return (a1-b1);
    return b1-a1;
}

bool comp(pii a, pii b){
    if(stringToInt(a.first)==stringToInt(b.first)){
        return stringToInt(a.second)<stringToInt(b.second);
    }
    return a.first<b.first;
}

pii ans;

void rec(string aa, string bb, int aidx){
    if(aidx>aa.length())return;
    
    ll ab = ABS(stringToInt(aa), stringToInt(bb));
    if(aa.length()==aidx ){
        if(minVal>ab){
            ans = pii(aa,bb);
            minVal=ab;
        }
        else if(minVal==ab){
            if(comp(ans, pii(aa,bb))==0)ans=pii(aa,bb);
        }
        return;
    }
    if(aa[aidx]!='?' and bb[aidx]!='?'){
        rec(aa,bb,aidx+1);
    }
    else if(aa[aidx]=='?' and bb[aidx]=='?'){
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                string t1 = aa, t2=bb;
                t1[aidx] = char(i+'0');
                t2[aidx] = char(j+'0');
                rec(t1,t2,aidx+1);
            }
        }
    }
    else if(aa[aidx]=='?'){
        for(int i=0;i<=9;i++){
            string t1 = aa;
            aa[aidx] = char(i+'0');
            rec(aa,bb,aidx+1);
        }
    }
    else if(bb[aidx]=='?'){
        for(int i=0;i<=9;i++){
            string t1 = bb;
            bb[aidx]=char(i+'0');
            rec(aa,bb,aidx+1);
        }
    }
}

int main() {
    freopen("/Users/abuasifkhan/Desktop/Problem Solving/Problem Solving/a.in", "r", stdin);
    freopen("/Users/abuasifkhan/Desktop/Problem Solving/Problem Solving/b.out", "w", stdout);
    
    int test;
    read(test);
    for(int C=1; C<=test; C++) {
        printf("Case #%d: ", C);
        minVal=(1ll<<19);
        cin>>a>>b;
        rec(a,b,0);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
    
    return 0;
}


