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
#define sc(x) scanf("%d",&x)

int main(void){
    freopen("C:/Users/SONY/Desktop/A-large.in","r",stdin);
    freopen("D:/Code/GCJ/2016/1B/out.txt", "w", stdout);

    int tc, ctr = 1;
    sc(tc);

    while(tc--){
        map<char, int> mapper;
        char arr[2300];
        scanf("%s", arr);
        FOR(i, strlen(arr)){
            mapper[arr[i]]++;
        }
        vector<char> vc;
        FOR(i,10){
            int hasil = 0;
            switch(i){
            case 0:
                hasil = mapper['Z'];
                mapper['Z'] = 0;
                mapper['E']-=hasil;
                mapper['R']-=hasil;
                mapper['O']-=hasil;
                FOR(j, hasil){
                    vc.pb('0');
                }
                break;
            case 1:
                hasil = mapper['W'];
                mapper['W'] = 0;
                mapper['T']-=hasil;
                mapper['O']-=hasil;
                FOR(j,hasil){
                    vc.pb('2');
                }
                break;
            case 2:
                hasil = mapper['X'];
                mapper['X'] = 0;
                mapper['S']-=hasil;
                mapper['I']-=hasil;
                FOR(j,hasil){
                    vc.pb('6');
                }
                break;
            case 3:
                hasil = mapper['U'];
                mapper['U'] = 0;
                mapper['F']-=hasil;
                mapper['O']-=hasil;
                mapper['R']-=hasil;
                FOR(j,hasil){
                    vc.pb('4');
                }
                break;
            case 4:
                hasil = mapper['G'];
                mapper['G'] = 0;
                mapper['E']-=hasil;
                mapper['I']-=hasil;
                mapper['H']-=hasil;
                mapper['T']-=hasil;
                FOR(j,hasil){
                    vc.pb('8');
                }
                break;
            case 5:
                hasil = mapper['R'];
                mapper['R'] = 0;
                mapper['T']-=hasil;
                mapper['H']-=hasil;
                mapper['E']-=2*hasil;
                FOR(j,hasil){
                    vc.pb('3');
                }
                break;

            case 6:
                hasil = mapper['F'];
                mapper['F'] = 0;
                mapper['I']-=hasil;
                mapper['V']-=hasil;
                mapper['E']-=hasil;
                FOR(j,hasil){
                    vc.pb('5');
                }
                break;
            case 7:
                hasil = mapper['V'];
                mapper['V'] = 0;
                mapper['S']-=hasil;
                mapper['E']-=2*hasil;
                mapper['N']-=hasil;
                FOR(j,hasil){
                    vc.pb('7');
                }
                break;
            case 8:
                hasil = mapper['O'];
                mapper['O'] = 0;
                mapper['N']-=hasil;
                mapper['E']-=hasil;
                FOR(j,hasil){
                    vc.pb('1');
                }
                break;
            case 9:
                hasil = mapper['I'];
                FOR(j,hasil){
                    vc.pb('9');
                }
                break;
            }
        }

        sort(vc.begin(), vc.end());

        printf("Case #%d: ", ctr++);
        FOR(i,vc.size())printf("%c",vc[i]);
        printf("\n");
    }





    return 0;
}


