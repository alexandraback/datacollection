#include <cstdio>
#include <cstring>

using namespace std;

double pos[100000], ans[100001];

int main(void){
    
    freopen("AS.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, c=0, a, b;
    
    scanf("%d", &cas);
    while(cas--){
        scanf("%d %d", &a, &b);
        for(int i=1; i<=a; ++i)
            scanf("%lf", &pos[i]);
        
        double tp = 1.0;
        for(int i=1; i<=a; ++i){
            tp *= pos[i];
            ans[i] = tp*((a-i)+(b-i)+1) + (1.0-tp)*((a-i)+(b-i+1)+(b+1));
            //printf("-> %d %lf %lf\n", i, tp*((a-i)+(b-i)+1), (1.0-tp)*((a-i)+(b-i+1)+(b+1)));
        }
        
        ans[0] = b+2;
        
        tp = 10000000.0;
        for(int i=0; i<=a; ++i){
        if( ans[i] < tp )   tp = ans[i];
        }
        printf("Case #%d: %lf\n", ++c, tp);
    }
    
    return 0;
}
