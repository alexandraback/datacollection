#include <stdio.h>
#include <stdlib.h>

const int MAXN = 110;
const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const double ZERO = 1e-8;

struct Tnode{
       int x, y;
       double time;
} list[MAXN*MAXN*10000];

int h, n, m;
double c[MAXN][MAXN], f[MAXN][MAXN];
double min[MAXN][MAXN];

void init()
{
     scanf("%d%d%d", &h, &n, &m);
     for (int i = 0; i < n; ++i)
         for (int j = 0; j < m; ++j)
             scanf("%lf", &c[i][j]);
     for (int i = 0; i < n; ++i)
         for (int j = 0; j < m; ++j)
             scanf("%lf", &f[i][j]); 
}

double calc(int x, int y, int x1, int y1, double t)
{
       double curH = h - t * 10;
       if (curH < 0) curH = 0;
       if (f[x][y] <= c[x1][y1] - 50 + ZERO
       &&  f[x1][y1] <= c[x1][y1] - 50 + ZERO
       &&  f[x1][y1] <= c[x][y] - 50 + ZERO) {
           double wait = 0;
           if (curH > c[x1][y1] - 50 - ZERO){
              wait = (curH - (c[x1][y1] - 50)) / 10.0;
              curH = c[x1][y1] - 50;
           }
           double move = 0;
           if (curH >= f[x][y] + 20 - ZERO)
              move = 1;
           else
              move = 10;
           if (t <= ZERO && wait <= ZERO)
              return 0;
           else
              return wait + move;
       }
       else
           return -1000.0;
}
       
void work()
{
     int h, w, x, y, x1, y1;
     double tt;
     for (int i = 0; i < n; ++i)
         for (int j = 0; j < m; ++j)
             min[i][j] = -1;
     min[0][0] = 0;
     list[1].x = list[1].y = 0;
     list[1].time = 0;
     h = 0; w = 1;
     while (h < w){
           ++h;
           x = list[h].x; y = list[h].y;
           tt = list[h].time;
           for (int i = 0; i < 4; ++i){
               x1 = x+d[i][0];
               y1 = y+d[i][1];
               if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m){
                  double delta = calc(x, y, x1, y1, tt);
                  if (delta < 0) ; else {
                     if (min[x1][y1] < 0 || min[x1][y1] > tt + delta){
                //        printf("%d %d %.6lf\n", x1, y1, delta);
                        min[x1][y1] = tt + delta;
                        ++w;
                        list[w].x = x1;
                        list[w].y = y1;
                        list[w].time = tt + delta;                
                     }          
                  }       
               }  
           }   
     }          
    // printf("%d %d\n", n*m, w);
     printf("%.8lf\n", min[n-1][m-1]);
}
          
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int cases, i;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; ++i){
        printf("Case #%d: ", i);
        init();
        work();
    }
         
    return 0;
}
