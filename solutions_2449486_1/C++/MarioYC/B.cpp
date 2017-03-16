#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int T,R,C;
    int M[100][100],maxr[100],maxc[100];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d",&R,&C);
        
        for(int i = 0;i < R;++i)
            for(int j = 0;j < C;++j)
                scanf("%d",&M[i][j]);
        
        memset(maxr,0,sizeof maxr);
        memset(maxc,0,sizeof maxc);
        
        for(int i = 0;i < R;++i)
            for(int j = 0;j < C;++j)
                maxr[i] = max(maxr[i],M[i][j]);
        
        for(int i = 0;i < C;++i)
            for(int j = 0;j < R;++j)
                maxc[i] = max(maxc[i],M[j][i]);
        
        bool ok = true;
        
        for(int i = 0;i < R;++i)
            for(int j = 0;j < C;++j)
                if(M[i][j] != min(maxr[i],maxc[j]))
                    ok = false;
        
        printf("Case #%d: %s\n",tc,ok? "YES" : "NO");
    }
    
    return 0;
}
