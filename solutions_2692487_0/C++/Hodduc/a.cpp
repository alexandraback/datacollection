#include<stdio.h>
#include<algorithm>
using namespace std;
int T, N, A;
int d[2][1000002];
int p[1000002];
int m[101];
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    int i, j;
    for(int t = 1; t <= T; t++){
        scanf("%d", &A);
        scanf("%d", &N);
        int bef=0, aft=1;
        for(i=1;i<=N;i++){
            scanf("%d", &m[i]);
        }
        sort(m+1, m+1+N);
        if(A>m[N]){
            printf("Case #%d: 0\n", t);
            continue;
        }
        for(i=1;i<=m[N]+1;i++) d[bef][i]=9999;
        d[bef][A] = 0;

        for(i=1; i<=N;i++){
            for(j=1;j<=m[N]+1;j++) d[aft][j]=d[bef][j]+1;
            for(j=2;j<=m[i];j++)
            {
                int target=j+j-1;
                if(target>m[N]) target=m[N]+1;
                d[bef][target] = d[bef][target] < d[bef][j]+1 ? d[bef][target] : d[bef][j]+1;
            }

            for(j=m[i]+1;j<=m[N]+1;j++)
            {
				int target = j+m[i];
				if(target>m[N]) target=m[N]+1;
                d[aft][target] = d[aft][target] < d[bef][j] ? d[aft][target] : d[bef][j];
            }
			bef ^= 1;
			aft ^= 1;
        }
        int min=9999;
        for(i=1;i<=m[N]+1;i++) min=min<d[bef][i]?min:d[bef][i];
        printf("Case #%d: %d\n", t, min);
    }
    return 0;
}
