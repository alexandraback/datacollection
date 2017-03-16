#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

class place{
    public:
        int x, y;
        double time;
        
        place(int xx, int yy, double tt) {
            x = xx; y = yy; time = tt;
        }
        
        bool operator < (const place & A) const {
            return time > A.time;
        }
};
const int max_S = 109;
double ceiling[max_S][max_S];
double floor[max_S][max_S];
double time[max_S][max_S];

// ---> M 
// |
// N
double canGoTo(int x, int y, int dx, int dy, double h) {
    double result_h = h;
    result_h = min(ceiling[x][y]-50, result_h);
    result_h = min(ceiling[x+dx][y+dy]-50, result_h);
    if(min(ceiling[x][y], ceiling[x+dx][y+dy]) - max(floor[x][y], floor[x+dx][y+dy])<50)
        result_h = -100;
 //   printf("h %lf rh %lf\n", h, result_h);
    return result_h;    
}
double timeToGo(int x, int y, int h) {
    if(floor[x][y] + 20 <= h)
        return 1;
    return 10;
}


int main() {
    int tc;
    scanf("%d", &tc);
    for(int ttc=1; ttc<=tc; ttc++) {
        printf("Case #%d: ", ttc);
        int H, N, M;
        scanf("%d%d%d", &H, &N, &M);
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                scanf("%lf", &ceiling[i][j]);
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                scanf("%lf", &floor[i][j]);
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                time[i][j] = -1;
        queue<place> Q;
        priority_queue<place> P;
        Q.push(place(0, 0, 0));
        while(!Q.empty()) {
            place top = Q.front();
            Q.pop();
            P.push(top);
            if(time[top.x][top.y] == -1) {
                time[top.x][top.y] = top.time;
                for(int dx = -1; dx <= 1; dx++)
                    for(int dy = -1; dy <= +1; dy++) {
                        if(dx != 0 && dy != 0)
                            continue;
                        if(dx == 0 && dy == 0)
                            continue;
                        if(top.x+dx < 0 || top.y+dy < 0 || top.x+dx >= N || top.y+dy >= M)
                            continue;
                        if(canGoTo(top.x, top.y, dx, dy, H) == H)
                            Q.push(place(top.x+dx, top.y+dy, 0)); 
                    }
            }   
        }
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                time[i][j] = -1;
 
        while(!P.empty()) {
            place top = P.top();
            P.pop();
            if(time[top.x][top.y] == -1) {
                time[top.x][top.y] = top.time;
                for(int dx = -1; dx <= 1; dx++)
                    for(int dy = -1; dy <= +1; dy++) {
                        double height = max((double)0, H - top.time*10);
                
                        if(dx != 0 && dy != 0)
                            continue;
                        if(dx == 0 && dy == 0)
                            continue;
                        if(top.x+dx < 0 || top.y+dy < 0 || top.x+dx >= N || top.y+dy >= M)
                            continue;
                        if(time[top.x+dx][top.y+dy] != -1)
                            continue;
                   //     printf("%d %d -> %d %d \n", top.x, top.y, top.x+dx, top.y+dy);
                        double neededH = canGoTo(top.x, top.y, dx, dy, height);
                        double myTime = top.time;
               //         printf("needed H %lf myTime %lf\n", neededH, myTime);
                        if(neededH == -100)
                            continue;
                        if(neededH < height) {
                            myTime += (height-neededH) / 10;
                            height = neededH;
                        }
                        myTime += timeToGo(top.x, top.y, height);
                 //       printf("addind (%d %d) time %lf\n", top.x+dx, top.y+dy, myTime);
                        P.push(place(top.x+dx, top.y+dy, myTime));
                    }                       
            }
        }
 /*       printf("\n");
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                printf("%lf ", time[i][j]);
            }
            printf("\n");
        }
   */     
        printf("%lf\n", time[N-1][M-1]);
                
    }

}
