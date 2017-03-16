#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>
using namespace std;

#define MaxN 110

struct Heap {
    int r,c;
    double time;

    Heap() {}
    Heap( int _r, int _c, double _time ) {
        r = _r;
        c = _c;
        time = _time;
    }

    bool operator < ( const Heap &other ) const {
        return time > other.time;
    }
};

double Time[MaxN][MaxN];
int ceil[MaxN][MaxN];
int f[MaxN][MaxN];
int h,n,m;
int T;

double t[MaxN][MaxN];

priority_queue< Heap > heap;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void Dijkstra( int r, int c )
{
    while ( !heap.empty() ) heap.pop();

    heap.push( Heap( r, c, 0.0 ) );
    while ( !heap.empty() ) {

        Heap tmp = heap.top();
        heap.pop();

        int r = tmp.r;
        int c = tmp.c;
        double time = tmp.time;

        if ( Time[r][c] > -1 ) continue;
        Time[r][c] = time;

        //printf("%d %d %lf\n",r,c,time);

        for (int i = 0; i < 4; ++i) {
            int newR = r + dr[i];
            int newC = c + dc[i];

            if ( newR < 0 || newR >= n || newC < 0 || newC >= m ) continue;
            if ( ceil[newR][newC] - max( h, max( f[r][c], f[newR][newC] ) ) < 50 ) continue;
            if ( ceil[r][c] - f[newR][newC] < 50 ) continue;

            if ( Time[newR][newC] > -1 ) continue;

            heap.push( Heap( newR, newC, 0.0 ) );
        }

    }
}

void PopuniHeap()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ( Time[i][j] < -1 ) continue;

            int r = i;
            int c = j;

            for (int i = 0; i < 4; ++i) {
                int newR = r + dr[i];
                int newC = c + dc[i];

                if ( newR < 0 || newR >= n || newC < 0 || newC >= m ) continue;
                if ( Time[newR][newC] > -1 ) continue;

                if ( ceil[newR][newC] - max( f[r][c], f[newR][newC] ) < 50 ) continue;
                if ( ceil[r][c] - f[newR][newC] < 50 ) continue;

                double newTime = 0.0;
                if ( ceil[newR][newC] - h < 50 ) {
                    newTime = ( 50 - ( ceil[newR][newC] - h ) ) / 10.0;

                    int tmp = ceil[newR][newC] - 50;
                    if ( tmp - f[r][c] < 20 ) newTime += 10.0;
                    else                      newTime += 1.0;
                }

                //printf("@%d %d %lf\n",newR,newC,newTime);
                if ( t[newR][newC] > -1 )
                    t[newR][newC] = min( t[newR][newC], newTime );
                else t[newR][newC] = newTime;
            }
        }
    }


    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if ( t[i][j] > -1 ) {
                heap.push( Heap( i, j, t[i][j] ) );
            }
}

void Idi( int r, int c, double time )
{
    double newH = h - 10*time;
    for (int i = 0; i < 4; ++i) {
        int newR = r + dr[i];
        int newC = c + dc[i];

        if ( newR < 0 || newR >= n || newC < 0 || newC >= m ) continue;
        if ( Time[newR][newC] > -1 ) continue;

        if ( ceil[newR][newC] - max( f[r][c], f[newR][newC] ) < 50 ) continue;
        if ( ceil[r][c] - f[newR][newC] < 50 ) continue;

        double newTime = time;
        if ( ceil[newR][newC] - newH < 50 ) {
            newTime += ( 50 - ( ceil[newR][newC] - newH ) ) / 10.0;

            int tmp = ceil[newR][newC] - 50;
            if ( tmp - f[r][c] < 20 ) newTime += 10.0;
            else                      newTime += 1.0;
        }
        else {
            if ( newH - f[r][c] < 20 ) newTime += 10.0;
            else                       newTime += 1.0;
        }



        //printf("Idi %d %d %lf %lf\n",newR,newC,newTime,time);
        if ( t[newR][newC] < -1 ) {
            t[newR][newC] = newTime;
            heap.push( Heap( newR, newC, newTime ) );
        }
        else if ( t[newR][newC] > newTime+(1e-5) ) {
            t[newR][newC] = newTime;
            heap.push( Heap( newR, newC, newTime ) );
        }
    }
}

int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);

    scanf("%d",&T);
    for (int t1 = 1; t1 <= T; ++t1) {
        scanf("%d%d%d",&h,&n,&m);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf("%d",&ceil[i][j]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf("%d",&f[i][j]);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                Time[i][j] = -2.0;
        Dijkstra( 0, 0 );

        //printf("*********************\n");
        //for (int i = 0; i < n; ++i) {
        //    for (int j = 0; j < m; ++j)
        //        printf("%.3lf ",Time[i][j]);
        //    printf("\n");
        //}


        if ( Time[n-1][m-1] > -1.0 ) {
            printf("Case #%d: 0.0\n",t1);
        }
        else {
            while (!heap.empty()) heap.pop();

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    t[i][j] = -2.0;
            PopuniHeap();

            //printf("SADA\n");
            while ( !heap.empty() ) {
                Heap p = heap.top();
                heap.pop();

                int r = p.r;
                int c = p.c;
                double time = p.time;

                if ( t[r][c] > -1 && t[r][c] < time ) continue;
                //printf("%d %d %lf %lf\n",r,c,t[r][c],time);

                Idi( r, c, time );

                //system("pause");
            }

            printf("Case #%d: %lf\n",t1,t[n-1][m-1]);
        }

        //printf("\n\n");

    }

    return 0;
}
