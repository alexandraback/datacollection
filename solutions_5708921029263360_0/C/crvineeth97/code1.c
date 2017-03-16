#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
        int t, cn;
        scanf("%d", &t);
        for(cn=1; cn<=t; cn++)
        {
                int j, p, s, k, a, b, c, grid[1005][3]={0}, count=0, x[11][11]={}, y[11][11]={}, z[11][11]={};
                scanf("%d %d %d %d", &j, &p, &s, &k);
                for(a=1; a<=j; a++)
                {
                        for(b=1; b<=p; b++)
                        {
                                for(c=1; c<=s; c++)
                                {
                                        if(x[a][b]==k || y[a][c]==k || z[b][c]==k)
                                                continue;
                                        if(b==2 && z[2][3]!=k)
                                                c=3;
                                        grid[count][0]=a;
                                        grid[count][1]=b;
                                        grid[count][2]=c;
                                        count++;
                                        y[a][c]++;
                                        z[b][c]++;
                                        x[a][b]++;
                                }
                        }
                }
                printf("Case #%d: %d\n", cn, count);
                for(a=0; a<count; a++)
                        printf("%d %d %d\n", grid[a][0], grid[a][1], grid[a][2]);
        }
        return 0;
}
