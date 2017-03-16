 #include <stdio.h>

int n, x, y, tot, bang, left, right, d;
int i, j, cx, cy;

int main()
 {
   freopen("B-small-attempt1.in", "r", stdin);
//    freopen("A-large.in", "r", stdin);
    freopen("bout.txt", "w", stdout);

     int cas, T;
     scanf("%d", &T);
     for (int cas=1; cas<=T; cas++)
     {
        scanf("%d%d%d", &n, &x, &y);
        tot = 0;
        bang = 0;
        for (i=0; i<(1<<n); i++)
        {
            left = 0;
            right = 0;
            d = 0;
            for (j=0; j<n; j++)
            {
                if (left == right && left == d * 2)
                {
                    cy = d * 2;
                    cx = 0;
                    d++;
                    left = 0;
                    right = 0;

                }
                else if (((i>>j)&1) && left < d * 2 || ((i>>j)&1)==0 && right == d * 2)
                    {
                        cy = left;
                        cx = -(d * 2 - cy);
                        left++;
                    }
                    else
                    {
                        cy = right;
                        cx = d * 2 - cy;
                        right++;
                    }
                  //  printf("%d %d %d\n", i, cx, cy);
                if (cx == x && cy == y) bang++;
            }
            tot++;
        }
        double ans = bang /(double)tot;
        printf("Case #%d: %.9lf\n", cas, ans);
     }
     return 0;
 }
/*
4
3 2 0
*/
