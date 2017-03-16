#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define LL long long
const LL MAX = 110;

LL box[MAX][2], toy[MAX][2], dp[MAX][MAX][4][MAX];
LL b_hash[MAX][MAX][3 * MAX], t_hash[MAX][MAX][3 * MAX];

int T, N, M;

int quer_b_hash(int x, int y, LL v)
{
    for(int i = 1; i <= b_hash[x][y][0]; i++){
        if(v == b_hash[x][y][i]){
            return i;
        }
    }
    return 0;
}
inline
int val_b_hash(int x, int y, LL v)
{
    b_hash[x][y][++b_hash[x][y][0]] = v;
    return b_hash[x][y][0];
}

int quer_t_hash(int x, int y, LL v)
{
    for(int i = 1; i <= t_hash[x][y][0]; i++){
        if(v == t_hash[x][y][i]){
            return i;
        }
    }
    return 0;
}

inline
int val_t_hash(int x, int y, LL v)
{
    t_hash[x][y][++t_hash[x][y][0]] = v;
    return t_hash[x][y][0];
}


LL Dp(LL b, LL t, int x, int y)
{
    if(x >= N || y >= M) return 0;

    int _b = quer_b_hash(x, y, b);
    if(_b == 0){
        _b = val_b_hash(x, y, b);
    }

    int _t = quer_t_hash(x, y, t);
    if(_t == 0){
        _t = val_t_hash(x, y, t);
    }

    LL ans = dp[_b][_t][x][y];

    if(ans != -1) return ans;
    ans = 0;

    if(box[x][1] == toy[y][1]){
        if(b > t){
            ans = t + Dp(b - t, toy[y + 1][0], x, y + 1);
        }else {
            ans = b + Dp(box[x + 1][0], t - b, x + 1, y);
        }
    }else {
        ans = max(ans, max(Dp(box[x + 1][0], t, x + 1, y), Dp(b, toy[y + 1][0], x, y + 1)));
    }
    //cout << _b <<" "<< _t <<" "<< x <<" "<< y <<" "<< ans << endl;
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt.out", "w", stdout);
    int con = 1;
    LL ans;
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i < N; i++)
            cin >> box[i][0] >> box[i][1];
        for(int i = 0; i < M; i++)
            cin >> toy[i][0] >> toy[i][1];
        memset(dp, -1, sizeof(dp));
//        memset(b_hash, 0, sizeof(b_hash));
//        memset(t_hash, 0, sizeof(t_hash));
        for(int i = 0; i <= N; i++)
            for(int j = 0; j <= M; j++){
                b_hash[i][j][0] = t_hash[i][j][0] = 0;
            }


        ans = Dp(box[0][0], toy[0][0], 0, 0);
        cout << "Case #" << con++ << ": " << ans << endl;
    }
    return 0;
}
