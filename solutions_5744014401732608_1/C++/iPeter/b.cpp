#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int B, s[60][60];
long long M,p[60][60],lim;
int main(void){
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d%lld",&B,&M);
        printf("Case #%d: ", tt);

        memset(s,0,sizeof(s));
        for (int i = 0; i < B-1; ++i)
        {
        	for(int j=i+1;j<B-1;++j)
        		s[i][j] = 1;
        }

        lim = 1;
        for (int i = 0; i < B-2; ++i)
        {
        	lim *= 2;
        }

        if (lim < M) {
        	puts("IMPOSSIBLE");
        	continue;
        }
        else if(lim == M){
        	for (int i = 0; i < B-1; ++i)
        	{
        		s[i][B-1] = 1;
        	}
        } else {
        	lim = 1;
        	for (int i = 1; i < B-1; ++i, lim*=2)
        	{
        		if ((M & lim) > 0)
        		{
        			s[i][B-1] = 1;
        		} else {
        			s[i][B-1] = 0;
        		}
        	}
        }

        printf("POSSIBLE\n");

        for (int i = 0; i < B; ++i)
        {
        	for (int j = 0; j < B; ++j)
        		printf("%d",s[i][j]);
        	puts("");
        }
    }
    return 0;
}

