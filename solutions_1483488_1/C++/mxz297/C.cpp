#include<cstdio>
#include<cstring>

int list[2000001][10];
int total[2000001];
int power[10];
int T, A, B;

int length(int a){
    int len = 1;
    a /= 10;
    while (a){
          ++len;
          a /= 10;
    }
    return len;
}

int next(int a, int len){
    return a / 10 + (a % 10) * power[len - 1];
}

void init()
{
     power[0] = 1;
     for (int i = 1; i <= 8; ++i) power[i] = power[i - 1] * 10;
     for (int i = 1; i <= 2000000; ++i){
         int a = i; 
         int len = length(a);
         a = next(a, len);
         while (a != i){
               list[i][total[i]++] = a;
               a = next(a, len);
         }
     }
}
 

int main(){
    freopen("input.txt" , "r", stdin);
    freopen("output.txt", "w", stdout);
    init();
    scanf("%d", &T);
    for (int cases = 1; cases <= T; ++cases){
        scanf("%d %d", &A, &B);
        int ans = 0;
        for (int i = A; i <= B; ++i)
            for (int j = 0; j < total[i]; ++j)
                if (i < list[i][j] && list[i][j] <= B) ++ans;
        printf("Case #%d: %d\n", cases, ans);        
    }
}
