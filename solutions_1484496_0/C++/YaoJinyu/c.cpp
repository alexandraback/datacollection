#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
 
const int MAXN = 510;
const int MAXX = 2000000;
int a[MAXN], n;
bool mod1[MAXX], mod[MAXX];
bool mark1[MAXN], mark2[MAXN];
bool get;

void init()
{
     scanf("%d", &n);
     for (int i = 0; i < n; ++i) scanf("%d", &a[i]);     
     sort(a, a+n);
}
     
void search1(int i, int now, int tot)
{
     if (now == tot){
        get = true;
        for (int j = 0; j < n; ++j)
            if (mark1[j]) printf("%d ", a[j]);
        printf("\n");
        for (int j = 0; j < n; ++j)
            if (mark2[j]) printf("%d ", a[j]);
        printf("\n");
        return;     
     }     
     
     if (i == n) return;
     if (now + a[i] > tot) return;
     if (!mod[(tot-now)%MAXX]) return;
     
     if (!mark1[i]) {
        mark2[i] = true;
        search1(i+1, now+a[i], tot);
        if (get) return;
     }
     
     mark2[i] = false;
     search1(i+1, now, tot);
     
}
     
void search(int i, int now, int tot)
{
     if (now == tot){
        search1(0, 0, tot);
        return;        
     }
     if (i == n) return;
     if (now + a[i] > tot) return;
     if (!mod[(tot-now)%MAXX]) return;
     
     mark1[i] = true;
     search(i+1, now+a[i], tot);
     if (get) return;
     
     mark1[i] = false;
     search(i+1, now, tot);
     
}
      
void work()
{
     for (int i = 0; i < MAXX; ++i)
         mod[i] = false;
     mod[0] = true;
     for (int i = n-1; i >= 0; --i) {
         for (int j = 0; j < MAXX; ++j)
             mod1[j] = false;
         for (int j = 0; j < MAXX; ++j)
             if (mod[j]) {
                mod1[j] = true;
                mod1[(j+a[i])%MAXX] = true;
             }
         for (int j = 0; j < MAXX; ++j)
             mod[j] = mod1[j]; 
     }

     int s = 0;
     for (int i = 0; i < n; ++i)
         s += a[i];
     for (int i = 2; i <= s/2; ++i)
         if (mod[i%MAXX] && mod[i*2%MAXX]){
            memset(mark1, 0, sizeof(mark1));
            memset(mark2, 0, sizeof(mark2));
            get = false;
            search(0, 0, i);
            if (get) return;
         }
     printf("Impossible\n");
}
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int cases, i;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; ++i){
        printf("Case #%d:\n", i);
        init();
        work();
    }
    
    return 0;
}
