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

const int MAXN=2020;
int n;
string s;
string words[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char trick[]={'Z', 'X', 'G', 'W', 'T', 'R', 'F', 'O', 'S', 'I'};
int num[]={0, 6, 8, 2, 3, 4, 5, 1, 7, 9};

int let[10][26];

int knt[26];
int knt2[26];
int res[10];
int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    ios::sync_with_stdio(0);
    forn(i, 10) forall(it, words[i]) let[i][(int)(*it-'A')]++;
    int TC; cin >> TC;
    for(int tc=1; tc<=TC; tc++){
        zero(knt);
        zero(res);
        cin >> s;
        forn(i, sz(s)) knt[s[i]-'A']++;
        forn(i, sz(s)) knt2[s[i]-'A']++;
        forn(i, 10){
            int k=knt[trick[i]-'A'];
            res[num[i]]=k;
            forall(it, words[num[i]]) knt[*it-'A']-=k;
        }
        forn(i, 26) assert(knt[i]==0);
        cout << "Case #" << tc << ": ";
        forn(i, 10) forn(j, res[i]) cout << i;
        cout << endl;
    }
    return 0;
}
