#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN=100100;
int n;
string C,J;

int best=99999999;
int bestc;
int bestc2;
void bruto(){
    best=99999999;
    if(n==3){
        forn(i,10) forn(j, 10) forn(k, 10)
        forn(i2,10) forn(j2, 10) forn(k2, 10){
            if(C[0]=='?' || C[0]==i+'0')
            if(C[1]=='?' || C[1]==j+'0')
            if(C[2]=='?' || C[2]==k+'0')
            if(J[0]=='?' || J[0]==i2+'0')
            if(J[1]=='?' || J[1]==j2+'0')
            if(J[2]=='?' || J[2]==k2+'0'){
                int c=i*100+j*10+k;
                int c2=i2*100+j2*10+k2;
                if(abs(c-c2)<best || (abs(c-c2)==best && bestc>c) || (abs(c-c2)==best && bestc==c && bestc2>c2)){
                    best=abs(c-c2);
                    bestc=c;
                    bestc2=c2;
                }
            }
        }
    }
    else if(n==2){
        forn(i,10) forn(j, 10) 
        forn(i2,10) forn(j2, 10) {
            if(C[0]=='?' || C[0]==i+'0')
            if(C[1]=='?' || C[1]==j+'0')
            if(J[0]=='?' || J[0]==i2+'0')
            if(J[1]=='?' || J[1]==j2+'0'){
                int c=i*10+j;
                int c2=i2*10+j2;
                if(abs(c-c2)<best || (abs(c-c2)==best && bestc>c) || (abs(c-c2)==best && bestc==c && bestc2>c2)){
                    best=abs(c-c2);
                    bestc=c;
                    bestc2=c2;
                }
            }
        }
    }
    else{
        forn(i,10) 
        forn(i2,10) {
            if(C[0]=='?' || C[0]==i+'0')
            if(J[0]=='?' || J[0]==i2+'0'){
                int c=i;
                int c2=i2;
                if(abs(c-c2)<best || (abs(c-c2)==best && bestc>c) || (abs(c-c2)==best && bestc==c && bestc2>c2)){
                    best=abs(c-c2);
                    bestc=c;
                    bestc2=c2;
                }
            }
        }
    }
}

int main() {
    //~ freopen("input.in", "r", stdin);
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("B-small-attempt2.out", "w", stdout);
    ios::sync_with_stdio(0);
    int TC; cin >> TC;
    for(int tc=1; tc<=TC; tc++){
        cin >> C >> J;
        n=sz(C);
        bruto();
        cout << "Case #" << tc << ": ";
        //~ cout << C << ' ' << J << endl;
        dforn(i, n){
            C[i]=bestc%10+'0';
            bestc/=10;
        } 
        dforn(i, n){
            J[i]=bestc2%10+'0';
            bestc2/=10;
        }
        cout << C << ' ' << J;
        cout << endl;
    }
    return 0;
}
