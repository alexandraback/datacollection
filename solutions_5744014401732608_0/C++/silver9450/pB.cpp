#include<cstdio>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; ++i)
    {
        int B;
        unsigned long long int M;
        unsigned long long int test = 1;
        bool success = false;
        scanf("%d", &B);
        scanf("%I64d", &M);
        printf("Case #%d: ", i+1);
        if(test >= M)
        {
            success = true;
            printf("POSSIBLE\n");
        }
        for(int j=1; j<=B-2; ++j)
        {
            unsigned long long int tmp = 1;
            if(test >= M)
            {
                success = true;
                printf("POSSIBLE\n");
                break;
            }
            for(int k=B-2; k>B-2-j; --k)
            {
                tmp *= k;
                if(tmp >= M)
                {
                    success = true;
                    printf("POSSIBLE\n");
                    break;
                }
            }
            if(success) break;
            test += tmp;
        }
        if(!success)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(int j=1; j<=B; ++j)
        {
            for(int k=1; k<=B; ++k)
            {
                if(j==B) printf("0");
                else if(j==k) printf("0");
                else printf("1");
            }
            printf("\n");
        }
    }
    return 0;
}
