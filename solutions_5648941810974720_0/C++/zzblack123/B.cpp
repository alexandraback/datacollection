/***************************************
      zzblack                         **
      2016-04-30                      **
      Orz                             **
****************************************/
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define ls id<<1,l,mid
#define rs id<<1|1,mid+1,r
#define OFF(x) memset(x,-1,sizeof x)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(x) memset(x,0x3f,sizeof x)
typedef long long ll ;
typedef pair<int,int> pii ;
const int maxn = 1e5 + 50 ;
const int maxm = 1e6 + 50;
const double eps = 1e-10;
const int max_index = 62;
const int inf = 0x3f3f3f3f ;
const int MOD = 1e9+7 ;

inline int read(){
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    int x = 0;
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

string s;
string t[10] = {"ZERO", "ONE", "TWO", "THERE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int num[10];
int Hash[300];

int main () {
#ifdef LOCAL
	freopen("C:\\Users\\zzblack\\Desktop\\case.in","r",stdin);
      freopen("C:\\Users\\zzblack\\Desktop\\case.out","w",stdout);
#endif

    int T = read(), cas = 1;
    while (T--) {
        cin >> s;
        memset(num, 0, sizeof num);
        memset(Hash, 0, sizeof Hash);
//        cout << s << "\n";
        for (int i = 0; s[i]; i++) Hash[s[i]]++;
//        for (int i = 'A'; i <= 'Z'; i++) printf("%d\n", Hash[i]);
//        for (int i = 0; i < 10; i++) {
//            int tmp = 100000;
//            for (int j = 0; t[i][j]; j++) {
//                int x = Hash[t[i][j]];
//                if ((i == 3 || i == 7) && t[i][j] == 'E') x /= 2;
//                if (i == 9 && t[i][j] == 'N') x /= 2;
//                tmp = min(tmp, x);
//            }
//            num[i] = tmp;
//            for (int j = 0; t[i][j]; j++) {
//                if ((i == 3 || i == 7) && t[i][j] == 'E') Hash[t[i][j]] -= tmp;;
//                if (i == 9 && t[i][j] == 'N') Hash[t[i][j]] -= tmp;
//                Hash[t[i][j]] -= tmp;
//            }
//        }

         num[0] = Hash['Z'];
        for (int i = 0; i < 4; i++) Hash[t[0][i]] -= num[0];
         num[2] = Hash['W'];
        for (int i = 0; i < 3; i++) Hash[t[2][i]] -= num[2];
         num[8] = Hash['G'];
        for (int i = 0; i < 5; i++) Hash[t[8][i]] -= num[8];
         num[3] = Hash['H'];
        for (int i = 0; i < 5; i++) Hash[t[3][i]] -= num[3];
         num[4] = Hash['R'];
        for (int i = 0; i < 4; i++) Hash[t[4][i]] -= num[4];
         num[5] = Hash['F'];
        for (int i = 0; i < 4; i++) Hash[t[5][i]] -= num[5];
         num[6] = Hash['X'];
        for (int i = 0; i < 3; i++) Hash[t[6][i]] -= num[6];
         num[1] = Hash['O'];
        for (int i = 0; i < 3; i++) Hash[t[1][i]] -= num[1];
         num[7] = Hash['V'];
        for (int i = 0; i < 5; i++) Hash[t[7][i]] -= num[7];
         num[9] = Hash['E'];
        for (int i = 0; i < 4; i++) Hash[t[9][i]] -= num[9];


        printf("Case #%d: ", cas++);
        for (int i = 0; i < 10; i++)
            while (num[i]--) printf("%d", i);
        puts("");

    }

	return 0;
}
