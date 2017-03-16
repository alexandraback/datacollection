#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1005;

#define fo(i , st , en) for (int i = st; i <= en; i++)
#define Me(x , y) memset(x , y , sizeof(x))

int n , t;
double a[N] , b[N];

int main(){
    freopen("4.in" , "r" , stdin);
    freopen("4.out" , "w" , stdout);
    scanf("%d" , &t);
    fo (l , 1 , t){
        scanf("%d" , &n); printf("Case #%d: " , l);
        fo (i , 1 , n) scanf("%lf" , a + i);
        fo (i , 1 , n) scanf("%lf" , b + i);
        sort(a + 1 , a + n + 1);
        sort(b + 1 , b + n + 1);
        int j = 1 , ans1 = 0 , ans2 = 0;
        fo (i , 1 , n){
            while (b[j] < a[i] && j <= n) j++;
            if (j <= n) j++; else ans1++;
        }
        j = 1;
        fo (i , 1 , n){
            while (a[j] < b[i] && j <= n) j++;
            if (j <= n) ans2++ , j++;
        }
        printf("%d %d\n" , ans2 , ans1);
    }
    return 0;
}
