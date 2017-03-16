#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int H, N, M;

int W; // CURRENT water level

int C[101][101]; // ceiling heights
int F[101][101]; // floor heights

int possible[101][101][10001]; // possible[i][j][t] == it's possible to be at point (i,j) at time t

void init_possible()
{
    int *p = (int*)possible;
    for(int i=0; i<100*100*10000; ++i)
        p[i] = 0;

    possible[0][0][0] = 1;
}

// true if can move from (r0, c0) to (r1, c1), assumes they are adjacent and p0 is valid
bool can_move(int row0, int col0, int row1, int col1)
{
    return ((row1 >= 0) && (row1 < N) &&
            (col1 >= 0) && (col1 < M) &&
            (W <= C[row1][col1] - 50) &&
            (F[row0][col0] <= C[row1][col1] - 50) &&
            (F[row1][col1] <= C[row1][col1] - 50) &&
            (F[row1][col1] <= C[row0][col0] - 50));
}

struct point
{
    int row, col;
    point(int row=0, int col=0): row(row), col(col) {}
};

vector<point> pending_points;
void propagate_initial()
{
    pending_points.push_back(point(0,0));

    while(!pending_points.empty())
    {
        point p = pending_points.back();
        pending_points.pop_back();
        possible[p.row][p.col][0] = 1;
        //cout << "[initial] possible point (" << p.row <<"," << p.col << ")" << endl;
        if (can_move(p.row, p.col, p.row+1, p.col) && !possible[p.row+1][p.col][0]) pending_points.push_back(point(p.row+1, p.col));
        if (can_move(p.row, p.col, p.row-1, p.col) && !possible[p.row-1][p.col][0]) pending_points.push_back(point(p.row-1, p.col));
        if (can_move(p.row, p.col, p.row, p.col+1) && !possible[p.row][p.col+1][0]) pending_points.push_back(point(p.row, p.col+1));
        if (can_move(p.row, p.col, p.row, p.col-1) && !possible[p.row][p.col-1][0]) pending_points.push_back(point(p.row, p.col-1));
    }
}

// cost in tenths of second
int cost_of_moving_from(int row, int col)
{
    if (W-F[row][col] >= 20) return 10;
    else return 100;
}

void propagate(int t)
{
    for (int row=0; row<N; ++row)
        for (int col=0; col<M; ++col)
            if (possible[row][col][t])
                pending_points.push_back(point(row,col));

    while(!pending_points.empty())
    {
        point p = pending_points.back();
        pending_points.pop_back();
        int c = cost_of_moving_from(p.row, p.col);
#ifdef DEBUG
        cout << "[propagate ("<<t<<")] possible point (" << p.row <<"," << p.col << ")["<<t+1 <<"]"<< endl;
#endif
        possible[p.row][p.col][t+1] = 1; // it's possible to stay in the same place
        if (can_move(p.row, p.col, p.row+1, p.col))
        {
#ifdef DEBUG
            cout << "[propagate ("<<t<<")] possible point (" << p.row+1 <<"," << p.col << ")["<<t+c<<"]" << endl;
#endif
            possible[p.row+1][p.col][t+c] = 1;
        }
        if (can_move(p.row, p.col, p.row-1, p.col))
        {
#ifdef DEBUG
            cout << "[propagate ("<<t<<")] possible point (" << p.row-1 <<"," << p.col << ")["<<t+c<<"]" << endl;
#endif
            possible[p.row-1][p.col][t+c] = 1;
        }
        if (can_move(p.row, p.col, p.row, p.col+1))
        {
#ifdef DEBUG
            cout << "[propagate ("<<t<<")] possible point (" << p.row <<"," << p.col+1 << ")["<<t+c<<"]" << endl;
#endif
            possible[p.row][p.col+1][t+c] = 1;
        }
        if (can_move(p.row, p.col, p.row, p.col-1))
        {
#ifdef DEBUG
            cout << "[propagate ("<<t<<")] possible point (" << p.row <<"," << p.col-1 << ")["<<t+c<<"]" << endl;
#endif
            possible[p.row][p.col-1][t+c] = 1;
        }
    }
}


int main()
{

    cin >> T;

    for (int t=0; t<T; ++t)
    {
        cin >> H >> N >> M;

        for (int row=0; row<N; ++row)
            for (int col=0; col<M; ++col)
                cin >> C[row][col];

        for (int row=0; row<N; ++row)
            for (int col=0; col<M; ++col)
                cin >> F[row][col];
        

#ifdef DEBUG
        if (t != 2) continue;

        cout << "H=" << H << endl;
        cout << "N=" << N << endl;
        cout << "M=" << M << endl;
#endif

        int time = 0;
        W = H;
        init_possible();

        propagate_initial();
#ifdef DEBUG
        cout << "time = " << time << endl;
#endif
        while(!possible[N-1][M-1][time])
        {
            propagate(time);
            W = max(W-1, 0);
            time++;
#ifdef DEBUG
            cout << "time = " << time << endl;
            cout << "W = " << W << endl;
#endif
        }

        cout << "Case #" << t+1 << ": " << (time/10.0f)<< endl;

    }

}
