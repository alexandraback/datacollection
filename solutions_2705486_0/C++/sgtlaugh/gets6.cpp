#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <cassert>
#include <istream>
#include <ostream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <complex>
#include <limits>
#include <bitset>
#include <iterator>
#include <utility>
#include <functional>
#include <tr1/random>
#include <tr1/unordered_map>

#define eps (1e-9)
#define vinf (1 << 28)
#define nvinf (-(1 << 28))
#define inf ((~0U) >> (1))
#define pi (2.0 * acos(0.0))
#define d_zero(x) (abs(x) < eps)
#define lowbit(x) ((x) & (-(x)))
#define sine(x) (sin(radians(x)))
#define cosine(x) (cos(radians(x)))
#define setbit(x, i) (x |= (1 << i))
#define tangent(x) (tan(radians(x)))
#define arcsine(x) (degrees((asin(x))))
#define resetbit(x, i) (x &= (~(1 << i)))
#define arccosine(x) (degrees((acos(x))))
#define arctangent(x) (degrees((atan(x))))
#define d_equals(a, b) (d_zero((a) - (b)))
#define getbit(x, i) (x & (1 << i) ? 1 : 0)
#define clr(ar) (memset(ar, 0, sizeof(ar)))
#define radians(x) (((1.0 * x * pi) / 180.0))
#define degrees(x) (((x * 180.0) / (1.0 * pi)))
#define read() (freopen("lol.txt", "r+", stdin))
#define write() (freopen("output.txt", "w+", stdout))
#define d_lesser(a, b) (!d_equals(a, b) && (a) < (b))
#define d_greater(a, b) (!d_equals(a, b) && (a) > (b))
#define dbg(x) (std::cout << #x << " = " << x << endl)
#define flipbit(x, i) (getbit(x, i) ? (resetbit(x, i)) : (setbit(x, i)))
#define twopow(x) ((((x & (x - 1)) == 0) && (x != 0)) ? (true) : (false))
#define mod(n, m) ((n >= 0) ? (n % m) : ((abs(n) % m) == 0) ? 0 : (m - (abs(n) % m)))

using namespace std;

char word[15], str[52];
bool visited[52][12];
int n, dp[52], P[52][12];
std::tr1::unordered_map <string, bool> mp;

inline int Possible(int i, int j){
    if (visited[i][j]) return P[i][j];

    int k, l, d, c;
    char lol[15];
    int res = -1;
    for (k = 0; k <= j; k++) lol[k] = str[i + k];
    lol[j + 1] = 0;

    if (mp[lol]) res = 0;
    else{
        for (k = 0; k <= j; k++){
            for (l = 0; l < 26; l++){
                int x = lol[k] - 97;
                if (l != x){
                    lol[k] = l + 97;
                    if (mp[lol]){
                        res = 1;
                        lol[k] = x + 97;
                        goto Skip;
                    }
                }
                lol[k] = x + 97;
            }
        }

        Skip:
        if (!res){
            for (k = 0; k <= j; k++){
                for (d = k + 5; d <= j; d++){
                    for (l = 0; l < 26; l++){
                        int x = lol[k] - 97;
                        if (l != x){
                            for (c = 0; c < 26; c++){
                                int y = lol[d] - 97;
                                if (y != c){
                                    lol[d] = c + 97;
                                    if (mp[lol]){
                                        res = 2;
                                        lol[k] = x + 97;
                                        lol[d] = y + 97;
                                        goto Skip2;
                                    }
                                }
                                lol[d] = y + 97;
                            }

                        }
                        lol[k] = x + 97;
                    }
                }
            }
        }
    }

    Skip2:
    visited[i][j] = true;
    return (P[i][j] = res);
}

inline int F(int i){
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];

    int j, k, res = 10010;
    for (j = 0; j < 10; j++){
        k = (i + j);
        if (k == n) break;

        if (Possible(i, j) != -1){
            int x = F(i + j + 1) + Possible(i, j);
            if (x < res) res = x;
        }
    }

    return (dp[i] = res);
}

int main(){
    int t, line, i, j, k;
    //write();
    //freopen("garbled_email_dictionary.txt", "r", stdin);

    for (i = 0; i < 521196; i++){
        scanf("%s", word);
        mp[word] = true;
    }

    scanf("%d", &t);
    for (line = 1; line <= t; line++){
        scanf("%s", str);
        n = strlen(str);

        clr(visited);
        memset(dp, -1, sizeof(dp));
        int res = F(0);
        printf("Case #%d: %d\n", line, res);
    }
    return 0;
}
