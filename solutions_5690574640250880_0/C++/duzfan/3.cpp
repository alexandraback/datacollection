#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 55;

#define fo(i , st , en) for (int i = st; i <= en; i++)
#define Me(x , y) memset(x , y , sizeof(x))

int t , r , c , m;
bool ans[N][N];

void Print(bool flag){
    if (flag){
        fo (i , 1 , c){
            fo (j , 1 , r)
                if (i == 1 && j == 1)
                    putchar('c');
                else
                    if (ans[j][i]) putchar('.'); else putchar('*');
            puts("");
        }
    }
    else
        fo (i , 1 , r){
            fo (j , 1 , c)
                if (i == 1 && j == 1)
                    putchar('c');
                else
                    if (ans[i][j]) putchar('.'); else putchar('*');
            puts("");
        }
}

void Work(){
    ans[1][1] = ans[1][2] = ans[2][1] = ans[2][2] = 1; m -= 4;
    if (m){
        ans[3][1] = ans[3][2] = 1; m -= 2;
    }
    if (m){
        ans[1][3] = ans[2][3] = 1; m -= 2;
    }
    fo (i , 4 , r){
        if (m < 2) break;
        ans[i][1] = ans[i][2] = 1; m -= 2;
    }
    fo (i , 4 , c){
        if (m < 2) break;
        ans[1][i] = ans[2][i] = 1; m -= 2;
    }
    fo (i , 3 , r){
        if (!m) break;
        fo (j , 3 , c){
            if (!m) break;
            ans[i][j] = 1; m--;
        }
    }
}

int main(){
    freopen("3.in" , "r" , stdin);
    freopen("3.out" , "w" , stdout);
    scanf("%d" , &t);
    fo (l , 1 , t){
        printf("Case #%d:\n" , l); Me(ans , 0);
        scanf("%d%d%d" , &r , &c , &m); bool flag = 0;
        m = r * c - m;
        if (r > c){
            swap(r , c); flag = 1;
        }
        if (m == 1){
            ans[1][1] = 1; Print(flag); continue;
        }
        if (r == 1)
            fo (i , 1 , m) ans[1][i] = 1;
        else
            if (r == 2)
                if (m & 1 || m < 4){
                    puts("Impossible"); continue;
                }
                else
                    fo (i , 1 , m / 2) ans[1][i] = ans[2][i] = 1;
            else
                if (m & 1)
                    if (m < 9){
                        puts("Impossible"); continue;
                    }
                    else
                        Work();
                else
                    if (m < 4){
                        puts("Impossible"); continue;
                    }
                    else
                        Work();
        Print(flag);
    }
    return 0;
}
