#include <iostream>
#include <algorithm>

using namespace std;

int N;
double A[1005], B[1005];
int main() {
    freopen("D-large.in.txt", "r", stdin);
    freopen("D.out", "w", stdout);
    int T;
    scanf("%d",&T);
    for(int t = 1;t<=T;t++) {
        scanf("%d",&N);
        for(int i = 1;i<=N;i++)
            scanf("%lf",&A[i]);
        for(int i = 1;i<=N;i++)
            scanf("%lf",&B[i]);
        sort(A + 1, A + 1 + N);
        sort(B + 1, B + 1 + N);
        
        int res1 = 0, res2 = 0;
        
        int x = 1, y = 1;
        
        while(x <= N && y <= N) {
            if(A[x] > B[y]) {
                res1++;
                x++;
                y++;
            }
            else {
                x++;
            }
        }

        x = 1, y = 1;
        int kenScore = 0;
        while(x <= N && y <= N) {
            if(A[x] < B[y]) {
                kenScore++;
                x++;
                y++;
            }
            else {
                y++;
            }
        }
        res2 = N - kenScore;
                 
        printf("Case #%d: %d %d\n", t, res1, res2);
    }
    return 0;
}
