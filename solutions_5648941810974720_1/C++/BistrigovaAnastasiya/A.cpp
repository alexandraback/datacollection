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

const int MAXN = 2e3 + 5;
const int ALP = 26;

char s[MAXN];
int p[ALP];
int c[10][ALP];
string let[10] = {"ZERO", "ONE", "TWO",
"THREE", "FOUR", "FIVE", "SIX",
"SEVEN", "EIGHT", "NINE" };
int ans[10];

void kill(int cipher, int spec){
    spec -= 'A';
    int num = p[spec];
    ans[cipher] += num;
    for(int i = 0; i < ALP; i++){
        p[i] -= num * c[cipher][i];
    }
}

void solve(){
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < 10; i++){
        ans[i] = 0;
    }
    for(int i = 0; i < ALP; i++){
        p[i] = 0;
    }
    for(int i = 0; i < n; i++){
        p[s[i] - 'A']++;
    }
    kill(0, 'Z');
    kill(2, 'W');
    kill(4, 'U');
    kill(6, 'X');
    kill(1, 'O');
    kill(3, 'R');
    kill(5, 'F');
    kill(7, 'S');
    kill(8, 'H');
    kill(9, 'I');
    for(int i = 0; i < ALP; i++){
        if(p[i]){
            cout << "BAD " << (char)('A' + i) << " " << p[i] << endl;
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < ans[i]; j++){
            printf("%d", i);
        }
    }
}

void precalc(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < (int)let[i].length(); j++){
            c[i][let[i][j] - 'A']++;
        }
    }
}

int main()
{
	#ifdef NASTYA
    assert(freopen("input.txt","r",stdin));
    assert(freopen("output.txt","w",stdout));
    #else
    //assert(freopen(file".in","r",stdin)); assert(freopen(file".out","w",stdout));
    #endif
    precalc();
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
