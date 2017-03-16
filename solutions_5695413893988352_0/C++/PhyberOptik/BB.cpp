
/*  Towhidul Islam
    University Of Dhaka
    Problem Name :
    Algorithm Used :
*/

#include<bits/stdc++.h>

typedef long long ll;

#define SSTR(x)         dynamic_cast< ostringstream & >( \
                        (ostringstream() << dec << x )).str()
#define pb              push_back
#define mem(a, x)       memset(a, x, sizeof a)
#define PI              acos(-1)
#define all(a)          a.begin(), a.end()
#define ff              first
#define ss              second
#define read(in)        freopen("in.txt", "r", stdin)
#define write(out)      freopen("out.txt", "w", stdout)
#define INF             1<<30
#define eps             1e-9
#define FORN(i, n)      for(int i = 0; i < n; i++)
#define FORAB(i, x, n)  for(int i = x; i < n; i++)
#define FORD(i, x, n)   for(int i= n - 1; i >= x; i--)
#define scan(n)         scanf("%d", &n)
#define print(n)        printf("%d\n", n)
#define tor             vector
#define dbg(x)          cout<<#x<<" : "<<x<<endl
#define chkwhere        cout<<"LOL\n"
#define pii             pair<int, int>
#define MOD             1000000007
#define MAX             1000007

int Set(int N, int pos) { return N = N | (1 << pos); }
int reSet(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }

using namespace std;

vector<int>C, J;
string c, j;
int n;
void genC(int pos, int cur){
    //dbg(cur);
    if(pos == n){
        C.pb(cur);
        return;
    }

    if(c[pos] == '?'){
        FORAB(i, 0, 10){
            genC(pos + 1, cur * 10 + i);
        }
    }
    else genC(pos + 1, cur * 10 + c[pos] - '0');
}

void genJ(int pos, int cur){
    if(pos == n){
        J.pb(cur);
        return;
    }

    if(j[pos] == '?'){
        FORAB(i, 0, 10){
            genJ(pos + 1, cur * 10 + i);
        }
    }
    else genJ(pos + 1, cur * 10 + j[pos] - '0');
}

int main(){
    read(in);
    write(out);
    int tc, t = 1;
    cin>>tc;
    while(tc--){
        cin>>c>>j;
        n = c.size();
        genC(0, 0);
        genJ(0, 0);

        int dif = INF, ans1 = INF, ans2 = INF;

        FORAB(i, 0, C.size()){
            FORAB(j, 0, J.size()){
                //dbg(abs(C[i] - J[j]));
                if(abs(C[i] - J[j]) <= dif){
                    if(abs(C[i] - J[j]) == dif){
                        if(ans1 > C[i]){
                            ans1 = C[i];
                            ans2 = J[j];
                        }
                        else if(ans1 == C[i]){
                            ans2 = min(ans2, J[j]);
                        }
                    }

                    else{
                    //dbg(C[i]);
                    dif = abs(C[i] - J[j]);
                    ans1 = C[i];
                    ans2 = J[j];
                }
                }

            }
        }
        //cout<<ans1<<" "<<ans2<<endl;
        printf("Case #%d: ", t++);
        vector<int>d1, d2;
        FORAB(i, 0, n){
            d1.pb(ans1%10);
            ans1 /= 10;
        }
        FORD(i, 0, n) printf("%d", d1[i]);
        printf(" ");
        FORAB(i, 0, n){
            d2.pb(ans2%10);
            ans2 /= 10;
        }
        FORD(i, 0, n) printf("%d", d2[i]);
        puts("");
        C.clear();
        J.clear();
    }
    return 0;
}
