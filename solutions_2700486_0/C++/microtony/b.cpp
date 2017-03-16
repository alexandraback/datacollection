#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int ncr[3000][3000];
int ncr2[3000][3000];

int main() {
    int t;
    scanf("%d",&t);
    ncr[1][0] = 1;
    ncr[1][1] = 1;
    ncr2[1][0] = 1;
    ncr2[1][1] = 2;
    for (int i=2; i<3000; i++) {
        ncr[i][0] = ncr[i][i] = 1;
        ncr2[i][0] = 1;
        for (int j=1; j<i; j++) {
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
            ncr2[i][j] = ncr2[i][j-1] + ncr[i][j];
        }
        ncr2[i][i] = ncr2[i][i-1] + 1;
    }
    /*
    for (int i=1; i<=5; i++) {
        for (int j=0; j<=i; j++) {
            printf("%d ",ncr[i][j]);
        }
        printf("\n");
    }
    for (int i=1; i<=5; i++) {
        for (int j=0; j<=i; j++) {
            printf("%d ",ncr2[i][j]);
        }
        printf("\n");
    }*/
    for (int i=0; i<t; i++) {
        int n,x,y;
        long long triangle;
        scanf("%d %d %d", &n, &x, &y);
        if (x<0) x = -x;
        int sum = x+y;
        if ((sum+1)*(sum+2)<=n*2) {
            printf("Case #%d: 1.0\n",i+1);
        } else if ((sum-1)*(sum)<n*2) {
            //calculate prob
            int already = (sum-1)*(sum)/2;
            int left = n-already;
            if (left > sum) {
                if (left-sum > y) {
                    printf("Case #%d: 1.0\n",i+1);
                } else {
                    if (x==0) {
                        printf("Case #%d: 0.0\n",i+1);              
                    } else {
                        printf("Case #%d: %f\n",i+1 , ncr2[2*sum-left][sum-y-1] / (double)(1 << 2*sum-left));
                    }
                }
            } else {
                if (y >= left) {
                    printf("Case #%d: 0.0\n", i+1);            
                } else {
                    printf("Case #%d: %f\n",i+1,  ncr2[left][left-y-1] / (double)(1 << left));
                }
            }
        } else {
            printf("Case #%d: 0.0\n",i+1);            
        }
    }
    return 0;
}
