/*
 * main.cpp
 *
 *  Created on: 06.04.2013
 *      Author: grand
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool solve()
{
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<int> > a(N);
    for(int i=0; i<N; ++i)
        a[i].resize(M);

    vector<int> max_x(M, 0), max_y(N, 0);

    for(int y=0; y<N; ++y)
    {
        for(int x=0; x<M; ++x)
        {
            scanf("%d", &a[y][x]);
            if(max_x[x]<a[y][x])max_x[x]=a[y][x];
            if(max_y[y]<a[y][x])max_y[y]=a[y][x];
        }
    }

    for(int y=0; y<N; ++y)
    {
        for(int x=0; x<M; ++x)
        {
            if(a[y][x]!=max_x[x] && a[y][x]!=max_y[y])
                return false;
        }
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; ++t)
    {
        printf("Case #%d: %s\n", t, solve()?"YES":"NO");
    }

    return 0;
}
