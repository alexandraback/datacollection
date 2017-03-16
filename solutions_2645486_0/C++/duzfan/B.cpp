#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N = 10005;

#define fo(i , st , en) for (int i = st; i <= en; i++)
#define mymax(x , y) ((x) > (y) ? (x) : (y))
#define mymin(x , y) ((x) < (y) ? (x) : (y))
#define Me(x , y) memset(x , y , sizeof(x))
#define lowbite(x) ((x) & -(x))

struct _two{
    int a , b;
    inline void Input(int A , int B){
        a = A; b = B;
    }
}a[N];

bool operator < (const _two &x , const _two &y){
    return x.a < y.a;
}

int h1[N] , h2[N];
int T , E , n , r;
ll ans;

void Ins(int *h , int x , int y){
    for (; x <= n; x += lowbite(x)) h[x] = mymax(h[x] , y);
}

int Find(int *h , int x){
    int sum = 0;
    for (; x; x -= lowbite(x)) sum = mymax(sum , h[x]);
    return sum;
}

void Init(){
    scanf("%d%d%d" , &E , &r , &n);
    fo (i , 1 , n){
        scanf("%d" , &a[i].a); a[i].b = i;
    }
    sort(a + 1 , a + n + 1); reverse(a + 1 , a + n + 1);
}

void Work(){
    Me(h1 , 0); Me(h2 , 0); ans = 0;
    fo (i , 1 , n){
        int pred = Find(h1 , a[i].b) , succ = Find(h2 , n - a[i].b + 1);
        ll cur = ((ll)a[i].b - pred) * r;
        if (!pred) cur += E - r;
        if (cur > E) cur = E;
        if (succ){
            cur += ((ll)n - succ + 1 - a[i].b) * r - E;
        }
        if (cur > E) cur = E;
        if (cur > 0)
            ans += cur * a[i].a;
        Ins(h1 , a[i].b , a[i].b); Ins(h2 , n - a[i].b + 1 , n - a[i].b + 1);
    }
    printf("%I64d\n" , ans);
}

int main(){
    freopen("B.in" , "r" , stdin);
    freopen("B.out" , "w" , stdout);
    scanf("%d" , &T);
    fo (p , 1 , T){
        printf("Case #%d: " , p);
        Init();
        Work();
    }
    return 0;
}
