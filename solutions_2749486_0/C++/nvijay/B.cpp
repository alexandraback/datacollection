#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define LIM 201
#define MAX 100
#define MAXLEN 510

struct Point{
    int x;
    int y;
};
typedef struct Point Point;

map< Point, vector<Point> > graph;
Point prev[LIM][LIM];
bool vis[LIM][LIM];

void Init(){
    int x = 0, y = 0;
    int i, j;
    int level = 0;
    queue< pair<int,Point> > q;
    Point pt;
    
    for (i=0; i<LIM; i++)
        for (j=0; j<LIM; j++)
            vis[i][j] = false;
    
    q.push( make_pair(0, (Point){0,0} ) );
    prev[0+MAX][0+MAX] = (Point){0,0};
    vis[0+MAX][0+MAX] = true;
    while (not q.empty()){
        pt = q.front().second;
        level = q.front().first;
        q.pop();
        //printf("popped (%d,%d) at level=%d\n", pt.x, pt.y, level);
        x = pt.x, y = pt.y;
        int dx[] = {level+1, -level-1, 0, 0};
        int dy[] = {0, 0, level+1, -level-1};
        for (int k=0; k<4; k++){
            if (-1*MAX<=x+dx[k] and x+dx[k]<=MAX and -1*MAX<=y+dy[k] and y+dy[k]<=MAX and not vis[x+dx[k]+MAX][y+dy[k]+MAX]){
                vis[x+dx[k]+MAX][y+dy[k]+MAX] = true;
                q.push( make_pair(level+1, (Point){x+dx[k],y+dy[k]} ) );
                //printf("pushing (%d,%d) at level=%d\n", x+dx[k], y+dy[k], level+1);
                prev[x+dx[k]+MAX][y+dy[k]+MAX] = (Point){x,y};
            }
        }
    }
    
    /*
    for (x=0; x<6; x++){
        for (y=0; y<6; y++)
            printf("prev for (%d,%d) = (%d,%d)\n", x, y, prev[x+MAX][y+MAX].x, prev[x+MAX][y+MAX].y);
    }
    */
}

char* Solve(int X, int Y){
    char* str = new char[MAXLEN];
    int i = 0;
    Point pt1 = (Point){X,Y}, pt2;
    while (pt1.x!=0 or pt1.y!=0){
        pt2 = prev[pt1.x+MAX][pt1.y+MAX];
        if (pt2.x<pt1.x and pt2.y==pt1.y) str[i++]='E';
        else if (pt2.x>pt1.x and pt2.y==pt1.y) str[i++]='W';
        else if (pt2.x==pt1.x and pt2.y<pt1.y) str[i++]='N';
        else if (pt2.x==pt1.x and pt2.y>pt1.y) str[i++]='S';
        pt1.x = pt2.x;
        pt1.y = pt2.y;
    }
    str[i] = '\0';
    int len = strlen(str);
    char c;
    for (i=0; i<len/2; i++){
        c = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = c;
    }
    return str;
}

int main(){
    int T, X, Y;
    scanf("%d", &T);
    Init();
    for (int t=1; t<=T; t++){
        scanf("%d %d", &X, &Y);
        printf("Case #%d: %s\n", t, Solve(X,Y));
    }
    return 0;
}

