#include <cstdio>
#include <cstdlib>


using namespace std;

int main()
{
    int T;
    int cnt=1;
    scanf("%d", &T);
    while (cnt <= T)
    {
        int N,tmp;
        int height[3000]={0};
        int out[100] = {0};
        scanf("%d", &N);
        for(int i=0; i<2*N-1; i++)
        {
            for(int j=0; j<N; j++)
            {
                scanf("%d", &tmp);
                height[tmp]++;
            }
        }
        for(int i=0, j=0; i<=2500; i++)
        {
            if(height[i]%2!=0)
            {
                out[j] = i;
                j++;
            }
        }
        printf("Case #%d: ", cnt);
        for(int i=0; i<N; i++)
        {
            printf("%d", out[i]);
            if(i!=N-1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }

        cnt++;
    }
    return 0;
}
