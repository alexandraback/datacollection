#include <algorithm>
#include <cstdio>

using std::max;

int T;
int R, C;
int A[100][100];
int maxR[100];
int maxC[100];

int main(int argc, char** argv)
{
    scanf("%d", &T);
    
    for(int t = 1; t <= T; ++t)
    {
        printf("Case #%d: ", t);
        
        scanf("%d %d", &R, &C);
        
        for(int i = 0; i < R; ++i)
            maxR[i] = 0;
        for(int i = 0; i < C; ++i)
            maxC[i] = 0;
        
        for(int i = 0; i < R; ++i)
            for(int j = 0; j < C; ++j)
                scanf("%d", A[i] + j);
        
        for(int i = 0; i < R; ++i)
            for(int j = 0; j < C; ++j)
            {
                maxR[i] = max(maxR[i], A[i][j]);
                maxC[j] = max(maxC[j], A[i][j]);
            }
            
        bool CanDo = true;
        for(int i = 0; i < R; ++i)
            for(int j = 0; j < C; ++j)
                CanDo &= ((A[i][j] == maxR[i]) || (A[i][j] == maxC[j]));
        
        if(CanDo)
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}