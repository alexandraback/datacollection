#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;

typedef struct Node {
    int x,y,h;
    double time;
    Node(int _x, int _y, int _h, double _t):x(_x),y(_y),h(_h),time(_t){}
    bool operator < ( const Node &b) const {
        if (x == b.x) {
            if (y == b.y) {
                return h < b.h;
            }
            return y < b.y;
        }
        return x < b.x;
    }
}Node;

const int MAXN = 101;
int F[MAXN][MAXN];
int C[MAXN][MAXN];
int H, N, M;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

deque<Node> Q;
set<Node> S;

bool Reach(int x, int y, int d, int h) {
    int nx = x + dir[d][0];
    int ny = y + dir[d][1];
    if (nx >= N || nx < 0 || ny >= M || ny < 0) return 0;
    return h <= C[nx][ny]-50 && F[x][y] <= C[nx][ny]-50 && F[nx][ny] <= C[nx][ny]-50 && F[nx][ny] <= C[x][y] -50;
}
inline void Add(Node nd) {
    if (S.find(nd) == S.end()) {
        Q.push_back(nd);
        S.insert(nd);
    }
}
int main() {
    int cas;
    scanf("%d", &cas);
    for (int ic = 1;ic <= cas;ic++) {
        scanf("%d%d%d", &H, &N, &M);
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < M;j++) {
                scanf("%d", &C[i][j]);
            }
        }
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < M;j++) {
                scanf("%d", &F[i][j]);
            }
        }
        Q.clear();
        S.clear();
        Node first = Node(0,0,H,0.);
        Q.push_back(first);
        double ans = 1e12;
        while (Q.size() > 0) {
            Node front = Q.front();
            if (front.x == N-1 && front.y == M-1 && ans > front.time) {
                ans = front.time;
            }
            Q.pop_front();
            for (int d = 0;d < 4;d++) {
                if (Reach(front.x, front.y, d, front.h)) {
                    if (front.h == H) {
                        Add(Node(front.x + dir[d][0], front.y+dir[d][1], H, 0.));
                    }else if(front.h - F[front.x][front.y] < 20) {
                        Add(Node(front.x+dir[d][0], front.y+dir[d][1], 0,front.time+10.));
                    }else{
                        Add(Node(front.x+dir[d][0], front.y+dir[d][1], front.h-10, front.time+1.));
                    }
                }else{
                    int nh = 0;
                    for (nh = front.h-1;nh-F[front.x][front.y] >= 20;nh--) {
                        if (Reach(front.x, front.y, d, nh)) {
                            Add(Node(front.x+dir[d][0], front.y+dir[d][1], nh-10, front.time+1.+(front.h-nh)/10.));
                        }
                    }
                    for (;nh - F[front.x][front.y] >= 0;nh--) {
                        if (Reach(front.x, front.y, d, nh)) {
                            Add(Node(front.x+dir[d][0], front.y+dir[d][1], 0, front.time+10.+(front.h-nh)/10.));
                        }
                    }
                }
            }
        }
        printf("Case #%d: %lf\n", ic, ans);
    }
    return 0;
}
