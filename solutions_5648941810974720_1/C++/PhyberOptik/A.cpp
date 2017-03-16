
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

int F[1000], cnt[11];

string clc(int pos){
    if(pos == 0) return "ZERO";
    if(pos == 1) return "ONE";
    if(pos == 2) return "TWO";
    if(pos == 3) return "THREE";
    if(pos == 4) return "FOUR";
    if(pos == 5) return "FIVE";
    if(pos == 6) return "SIX";
    if(pos == 7) return "SEVEN";
    if(pos == 8) return "EIGHT";
    if(pos == 9) return "NINE";
}

int main(){
    read(in);
    write(out);
    int tc, t = 1;
    string s;
    cin>>tc;
    while(tc--){
        cin>>s;
        mem(F, 0);
        mem(cnt, 0);
        FORAB(i, 0, s.size()){
            F[s[i]]++;
        }

        if(F['Z']){
            string str = clc(0);
            int c = F['Z'];
            FORAB(i, 0, str.size()){
                F[str[i]] -= c;
            }
            cnt[0] += c;
        }

        if(F['W']){
            string str = clc(2);
            int c = F['W'];
            FORAB(i, 0, str.size()){
                F[str[i]] -= c;
            }
            cnt[2] += c;
        }

        if(F['U']){
            string str = clc(4);
            int c = F['U'];
            FORAB(i, 0, str.size()){
                F[str[i]] -= c;
            }
            cnt[4] += c;
        }

        if(F['X']){
            string str = clc(6);
            int c = F['X'];
            FORAB(i, 0, str.size()){
                F[str[i]] -= c;
            }
            cnt[6] += c;
        }

        if(F['G']){
            string str = clc(8);
            int c = F['G'];
            FORAB(i, 0, str.size()){
                F[str[i]] -= c;
            }
            cnt[8] += c;
        }

        if(F['O']){
            string str = clc(1);
            int c = F['O'];
            FORAB(i, 0, str.size()){
                F[str[i]] -= c;
            }
            cnt[1] += c;
        }

        if(F['T']){
            string str = clc(3);
            int c = F['T'];
            FORAB(i, 0, str.size()){
                F[str[i]] -= c;
            }
            cnt[3] += c;
        }

        if(F['F']){
            string str = clc(5);
            int c = F['F'];
            FORAB(i, 0, str.size()){
                F[str[i]] -= c;
            }
            cnt[5] += c;
        }

        if(F['V']){
            string str = clc(7);
            int c = F['V'];
            FORAB(i, 0, str.size()){
                F[str[i]] -= c;
            }
            cnt[7] += c;
        }
        if(F['I']){
            string str = clc(9);
            int c = F['I'];
            cnt[9] += c;
        }


        printf("Case #%d: ", t++);
        FORAB(i, 0, 10){
            FORAB(j, 0, cnt[i]){
                printf("%d", i);
            }
        }
        puts("");
    }
    return 0;
}
