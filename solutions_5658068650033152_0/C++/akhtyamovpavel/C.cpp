#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <complex>
#include <iomanip>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<vector<int> > graph;
const int INF = 1000000000;
const ll MOD = 1000000009;
#define FILEIN "C.in"
#define FILEOUT "C.out"

vector<vector<char> > st;

bool used[100][100];
int N, M;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
bool bfs(int x, int y){
    //cout << x << " " << y << endl;
    if (st[x][y])
        return true;
    if (x == 0 || y == 0 || x == N - 1 || y == M - 1)
        return false;
    //cout<<"ok"<<endl;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            used[i][j] = false;



    queue<pair<int, int> > q;

    q.push(make_pair(x, y));
    used[x][y] = true;

    while (!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        int curx = cur.first;
        int cury = cur.second;
        //cout << "cur" << curx << " " << cury << endl;
        if (curx == 0 || cury == 0 || curx == N - 1 || cury == M - 1){
            return false;
        }
        for (int i = 0; i < 4; ++i){
            if (curx + dx[i] >= 0 && curx < N && cury + dy[i] >= 0 && cury + dy[i] < M){
                if (!st[curx + dx[i]][cury + dy[i]] && !used[curx + dx[i]][cury + dy[i]]){
                    used[curx + dx[i]][cury + dy[i]] = true;
                    q.push(mp(curx + dx[i], cury + dy[i]));
                }
            }
        }
    }
    return true;
}

int mask[100];
int main(){
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);
    int tests;
    cin >> tests;
    for (int _ = 1; _ <= tests; ++_){
        int K;
        cin >> N >> M >> K;
        st.clear();
        st.resize(N);
        for (int i = 0; i < N; ++i)
            st[i].resize(M);

        int smres = 100;

        for (int mm = 0; mm < 1 << (N*M); ++mm){
            
            int cur = mm;
            
            int sum = 0;
            for (int j = 0; j < N*M; ++j){
                mask[j] = cur % 2;
                cur >>= 1;
                sum += mask[j];
            }
            
            if(sum >= smres)
                continue;
            for (int i = 0; i <N*M; ++i){
                if (mask[i] == 1){
                    st[i%N][i / N] = true;
                }
                else
                    st[i%N][i / N] = false;
            }
            
            
            
            int cnt = 0;
            
            for (int i = 0; i < N; ++i){
                for (int j = 0; j < M; ++j){

                    if (bfs(i, j)){
                        //cout<<"ok"<<endl;
                        ++cnt;
                    }
                    if(cnt > K)
                        goto endi;
                               
                }
            }
             
           
            
            if(cnt == K){
                smres = sum;
            }
        endi:;
        }


        cout << "Case #" << _ << ": ";

        cout << smres << endl;
    }
    return 0;
}