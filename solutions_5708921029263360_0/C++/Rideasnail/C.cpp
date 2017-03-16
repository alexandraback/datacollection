#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#ifdef DEBUG
    #define cek(x) cout<<x
#else
    #define cek(x) if(false){}
#endif // DEBUG

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define PI acos(-1.0)
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define sci(x) scanf("%d",&x)
#define scs(x) scanf("%s",&x)

int main(void){
    freopen("D:/Code/C-small-attempt1.in","r",stdin);
    freopen("D:/Code/out.txt","w",stdout);

    int tc;
    sci(tc);

    FOR(i,tc)
    {
        int aa,bb,cc,dd;

        cin >> aa;
        cin >> bb;
        cin >> cc;
        cin >> dd;

        cout << "Case #" << i+1 << ": ";

        if(aa==1 && bb==1 && cc==1) {
            cout << 1 << endl;
            cout << "1 1 1" << endl;
        }

        if(aa==1 && bb==1 && cc==2) {
            if(dd==1){
                cout << 1 << endl;
                cout << "1 1 1" << endl;
            } else {
                cout << 2 << endl;
                cout << "1 1 1" << endl;
                cout << "1 1 2" << endl;
            }
        }

        if(aa==1 && bb==1 && cc==3) {
            if(dd==1){
                cout << 1 << endl;
                cout << "1 1 1" << endl;
            } else if(dd==2){
                cout << 2 << endl;
                cout << "1 1 1" << endl;
                cout << "1 1 2" << endl;
            } else {
                cout << 3 << endl;
                cout << "1 1 1" << endl;
                cout << "1 1 2" << endl;
                cout << "1 1 3" << endl;
            }
        }

        if(aa==1 && bb==2 && cc==2) {
            if(dd==1){
                cout << 2 << endl;
                cout << "1 1 1" << endl;
                cout << "1 2 2" << endl;
            } else if(dd==2){
                cout << 4 << endl;
                cout << "1 1 1" << endl;
                cout << "1 1 2" << endl;
                cout << "1 2 1" << endl;
                cout << "1 2 2" << endl;
            } else {
                cout << 4 << endl;
                FOR(a,aa)
                    FOR(b,bb)
                        FOR(c,cc){
                            cout << a+1 << " " << b+1 << " " << c+1 << endl;
                        }
            }
        }

        if(aa==1 && bb==2 && cc==3) {
            if(dd==1){
                cout << 2 << endl;
                cout << "1 1 1" << endl;
                cout << "1 2 2" << endl;
            } else if(dd==2){
                cout << 4 << endl;
                cout << "1 1 1" << endl;
                cout << "1 1 2" << endl;
                cout << "1 2 1" << endl;
                cout << "1 2 2" << endl;
            } else {
                cout << 6 << endl;
                FOR(a,aa)
                    FOR(b,bb)
                        FOR(c,cc){
                            cout << a+1 << " " << b+1 << " " << c+1 << endl;
                        }
            }
        }

        if(aa==1 && bb==3 && cc==3) {
            if(dd==1){
                cout << 3 << endl;
                cout << "1 1 1" << endl;
                cout << "1 2 2" << endl;
                cout << "1 3 3" << endl;
            } else if(dd==2){
                cout << 6 << endl;
                cout << "1 1 1" << endl;
                cout << "1 1 2" << endl;
                cout << "1 2 2" << endl;
                cout << "1 2 3" << endl;
                cout << "1 3 1" << endl;
                cout << "1 3 3" << endl;
            } else {
                cout << 9 << endl;
                FOR(a,aa)
                    FOR(b,bb)
                        FOR(c,cc){
                            cout << a+1 << " " << b+1 << " " << c+1 << endl;
                        }
            }
        }

        if(aa==2 && bb==2 && cc==2) {
            if(dd==1){
                cout << 4 << endl;
                cout << "1 1 1" << endl;
                cout << "1 2 2" << endl;
                cout << "2 1 2" << endl;
                cout << "2 2 1" << endl;
            } else {
                cout << 8 << endl;
                FOR(a,aa)
                    FOR(b,bb)
                        FOR(c,cc){
                            cout << a+1 << " " << b+1 << " " << c+1 << endl;
                        }
            }
        }

        if(aa==2 && bb==2 && cc==3) {
            if(dd==1){
                cout << 4 << endl;
                cout << "1 1 1" << endl;
                cout << "1 2 2" << endl;
                cout << "2 1 2" << endl;
                cout << "2 2 1" << endl;
            } else if(dd==2){
                cout << 8 << endl;
                cout << "1 1 1" << endl;
                cout << "1 1 2" << endl;
                cout << "1 2 1" << endl;
                cout << "1 2 2" << endl;
                cout << "2 1 1" << endl;
                cout << "2 1 2" << endl;
                cout << "2 2 1" << endl;
                cout << "2 2 2" << endl;

            } else {
                cout << 12 << endl;
                FOR(a,aa)
                    FOR(b,bb)
                        FOR(c,cc){
                            cout << a+1 << " " << b+1 << " " << c+1 << endl;
                        }
            }
        }

        if(aa==2 && bb==3 && cc==3) {
            if(dd==1){
                cout << 6 << endl;
                cout << "1 1 1" << endl;
                cout << "1 2 2" << endl;
                cout << "1 3 3" << endl;
                cout << "2 1 2" << endl;
                cout << "2 2 3" << endl;
                cout << "2 3 1" << endl;
            } else if(dd==2){
                cout << 12 << endl;
                cout << "1 1 1" << endl;
                cout << "1 1 2" << endl;
                cout << "1 2 2" << endl;
                cout << "1 2 3" << endl;
                cout << "1 3 1" << endl;
                cout << "1 3 3" << endl;
                cout << "2 1 1" << endl;
                cout << "2 1 2" << endl;
                cout << "2 2 2" << endl;
                cout << "2 2 3" << endl;
                cout << "2 3 1" << endl;
                cout << "2 3 3" << endl;
            } else {
                cout << 18 << endl;
                FOR(a,aa)
                    FOR(b,bb)
                        FOR(c,cc){
                            cout << a+1 << " " << b+1 << " " << c+1 << endl;
                        }
            }
        }

        if(aa==3 && bb==3 && cc==3) {
            if(dd==1){
                cout << 9 << endl;
                cout << "1 1 1" << endl;
                cout << "2 2 2" << endl;
                cout << "3 3 3" << endl;
                cout << "1 2 3" << endl;
                cout << "2 3 1" << endl;
                cout << "3 1 2" << endl;
                cout << "3 2 1" << endl;
                cout << "1 3 2" << endl;
                cout << "2 1 3" << endl;
            } else if(dd==2){
                cout << 18 << endl;
                cout << "1 1 1" << endl;
                cout << "1 1 2" << endl;

                cout << "1 2 2" << endl;
                cout << "1 2 3" << endl;

                cout << "1 3 1" << endl;
                cout << "1 3 3" << endl;

                cout << "2 1 2" << endl;
                cout << "2 1 3" << endl;

                cout << "2 2 1" << endl;
                cout << "2 2 3" << endl;

                cout << "2 3 1" << endl;
                cout << "2 3 2" << endl;

                cout << "3 1 1" << endl;
                cout << "3 1 3" << endl;

                cout << "3 2 1" << endl;
                cout << "3 2 2" << endl;

                cout << "3 3 2" << endl;
                cout << "3 3 3" << endl;

            } else {
                cout << 27 << endl;
                FOR(a,aa)
                    FOR(b,bb)
                        FOR(c,cc){
                            cout << a+1 << " " << b+1 << " " << c+1 << endl;
                        }
            }
        }


    }


    return 0;
}
