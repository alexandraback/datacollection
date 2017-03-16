#include<cstdio>
#include<cstring>
using namespace std;

const int N = 105;

#define fo(i , st , en) for (int i = st; i <= en; i++)
#define mymax(x , y) ((x) > (y) ? (x) : (y))
#define Me(x , y) memset(x , y , sizeof(x))

int T , r , n , m , k;
int a[N];
int t2 , t3 , t4 , t5;

int main(){
    freopen("C.in" , "r" , stdin);
    freopen("C.out" , "w" , stdout);
    scanf("%d" , &T);
    scanf("%d%d%d%d" , &r , &n , &m , &k);
    puts("Case #1:");
    fo (i , 1 , r){
        t2 = t3 = t4 = t5 = 0;
        fo (i , 1 , k){
            scanf("%d" , &a[i]); int tt3 = 0 , x = a[i] , tt5 = 0;
            while (x % 3 == 0){
                tt3++; x /= 3;
            }
            while (x % 5 == 0){
                tt5++; x /= 5;
            }
            t3 = mymax(t3 , tt3); t5 = mymax(t5 , tt5);
        }
        fo (i , 1 , k){
            int x = a[i] , tt2 = 0;
            while (x % 2 == 0){
                tt2++; x /= 2;
            }
            t4 = mymax(t3 + t5 + tt2 - n , t4);
        }
        if (t3 > n) t3 = n;
        if (t5 + t3 > n) t5 = n - t3;
        if (t4 + t3 + t5 > n) t4 = n - t3 - t5;
        fo (i , 1 , t3) putchar('3');
        fo (i , 1 , t5) putchar('5');
        fo (i , 1 , t4) putchar('4');
        fo (i , 1 , n - t3 - t5 - t4) putchar('2');
        puts("");
        
    }
    return 0;
}
