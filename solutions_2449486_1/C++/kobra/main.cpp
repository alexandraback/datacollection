#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <string>
#include <cstring>
#include <regex>

using namespace std;

int Map[100][100];
int N,M;
bool rows[100];
bool cols[100];

struct cell{
    int w;
    int x;
    int y;
    bool operator <(const cell &other) const{
        return this->w > other.w;
    }
};

vector<cell> Cells;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int z = 0; z < T; z++){
        Cells.clear();
        printf("Case #%d: ",z+1);

        scanf("%d%d",&N,&M);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
            {
                scanf("%d",&Map[i][j]);
                cell temp;
                temp.w = Map[i][j];
                temp.x = i;
                temp.y = j;
                Cells.push_back(temp);
            }

        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));

        sort(Cells.begin(), Cells.end());
        int k = 0;
        bool flag = true;
        while(k != Cells.size()){
            bool rowsCopy[100];
            bool colsCopy[100];
            for(int i = 0; i < 100; i++)
            {
                rowsCopy[i] = rows[i];
                colsCopy[i] = cols[i];
            }
            do{
                rowsCopy[Cells[k].x] = true;
                colsCopy[Cells[k].y] = true;
                if(rows[Cells[k].x] && cols[Cells[k].y])
                {
                    flag = false;
                }
                k++;
            }
            while(Cells[k].w == Cells[k-1].w && k < Cells.size());
            for(int i = 0; i < 100; i++)
            {
                rows[i] = rowsCopy[i];
                cols[i] = colsCopy[i];
            }
        }
        if(flag)
            printf("YES");
        else
            printf("NO");
        printf("\n");

    }
    return 0;
}

