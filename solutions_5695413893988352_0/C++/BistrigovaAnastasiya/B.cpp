#include <bits/stdc++.h>
using namespace std;

#define file "file"
#define mp make_pair
#define pb push_back
#define xx real()
#define yy imag()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef complex<double> point;

#define DEBUG 0
#define dout if(DEBUG) cout

const int INF = 1e9;

string c, j;
int ans;
int ca, ja;
string _ca, _ja;
string cur_c, cur_j;

void rec_sol(int cur, int cn, int jn){
    if(cur == (int)c.length()){
        if(ans > abs(cn - jn) || ans == abs(cn - jn) && cn < ca ||
           ans == abs(cn - jn) && cn == ca && jn < ja){
           ans = abs(cn - jn);
            ca = cn;
            ja = jn;
            _ca = cur_c;
            _ja = cur_j;
        }
        return;
    }
    cn *= 10;
    jn *= 10;
    if(c[cur] == '?'){
        if(j[cur] == '?'){
            for(int i = 0; i < 10; i++){
                for(int i2 = 0; i2 < 10; i2++){
                    cur_c[cur] = (char)('0' + i);
                    cur_j[cur] = (char)('0' + i2);
                    rec_sol(cur + 1, cn + i, jn + i2);
                }
            }
        }
        else{
            for(int i = 0; i < 10; i++){
                cur_c[cur] = (char)('0' + i);
                cur_j[cur] = j[cur];
                rec_sol(cur + 1, cn + i, jn + j[cur] - '0');
            }
        }
    }
    else{
        if(j[cur] == '?'){
            for(int i = 0; i < 10; i++){
                cur_c[cur] = c[cur];
                cur_j[cur] = (char)('0' + i);
                rec_sol(cur + 1, cn + c[cur] - '0', jn + i);
            }
        }
        else{
            cur_c[cur] = c[cur];
            cur_j[cur] = j[cur];
            rec_sol(cur + 1, cn + c[cur] - '0', jn + j[cur] - '0');
        }
    }
}

void solve(){
    cin >> c >> j;
    ans = ca = ja = INF;
    cur_c = c;
    cur_j = j;
    rec_sol(0, 0, 0);
    cout << _ca << " " << _ja;
}

int main()
{
	#ifdef NASTYA
    assert(freopen("input.txt","r",stdin));
    assert(freopen("output.txt","w",stdout));
    #else
    //assert(freopen(file".in","r",stdin)); assert(freopen(file".out","w",stdout));
    #endif
	int t = 1;
	cin >> t;
	int cs = 1;
	while(t--){
        printf("Case #%d: ", cs++);
		solve();
        printf("\n");
	}
	return 0;
}
