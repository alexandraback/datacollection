#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int check[10], cnt, l;

int len(int val)
{
    int le = 0;
    while(val){
        le++;
        val /= 10;
    }
    return le;
}
inline void mitoa(char *s, int val)
{
    int i = 0, t = val;
    while(t){
        s[l - i - 1] = t % 10 + '0';
        i++;
        t /= 10;
    }
    s[l] = '\0';
}

inline int matoi(char *s)
{
    int val = 0;
    while(*s){
        val = val * 10 + *s - '0';
        s++;
    }
    return val;
}
inline bool Ishave(int val)
{
    for(int i = 0; i < cnt; i++){
        if(val == check[i])
            return true;
    }
    return false;
}
int main()
{
    int N, A, B;
    int ans, m, n;
    char a[10];
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &A, &B);
        ans= 0;
        l = len(A);
        for(int j = A; j <= B; j++){
            mitoa(a, j);
            n = j;
            cnt = 0;
            for(int k = 1; k < l; k++){
                char c = a[0];
                for(int loop = 0; loop < l - 1; loop++)
                    a[loop] = a[loop + 1];
                a[l - 1] = c;
                m = matoi(a);
                if(m > n && m <= B && !Ishave(m)){
                    //printf("%d %d\n", n, m);
                    check[cnt++] = m;
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n", i + 1, ans);
    }
    return 0;
}
