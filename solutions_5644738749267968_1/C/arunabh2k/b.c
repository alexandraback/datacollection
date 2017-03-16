#include <stdio.h>
float matn[1001];
float matk[1001];
int visn[1001],visk[1001];
int n;

int canwinall(int ni)
{
    int i;
    for(i=n;i>=ni;i--)
    {
        if(matn[i] < matk[i])
            return 0;
    }
    return 1;
}

int main()
{
	int nc, notc;
	scanf("%d", &notc);
	
	for(nc=1;nc<=notc;nc++)
	{
        //for rigged
        int rg =0;
        int nrg =0;
        int i =0, j=0;
        scanf("%d", &n);
        for(i=1;i<=n;i++)
        {
            float num;
            scanf("%f", &num);
            matn[i] = num;
        }
        for(i=1;i<=n;i++)
        {
            float num;
            scanf("%f", &num);
            matk[i] = num;
        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(matn[j] < matn[i])
                {
                    float tmp = matn[j];
                    matn[j] = matn[i];
                    matn[i] = tmp;
                }
                if(matk[j] < matk[i])
                {
                    float tmp = matk[j];
                    matk[j] = matk[i];
                    matk[i] = tmp;
                }
            }
        }

        
    for(i=0;i<=n;i++)
    {
        visn[i] = 0;
        visk[i] = 0;
    }
    int cnt=0;
    for(i=1;i<=n;i++)
    {
        int mj = 0;
        for(j=1;j<=n;j++)
        {
            if(visk[j])
                continue;
            if(matk[j] < matn[i]) 
            {
                mj = j;
                cnt++;
                break;
            }
            mj = j;
        }
        
        visk[mj] = 1;
    }
    rg = cnt;
    for(i=0;i<=n;i++)
    {
        visn[i] = 0;
        visk[i] = 0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(visk[j])
                continue;
            if(matk[j] > matn[i])
            {
                visk[j] = 1;
                nrg++;
                break;
            }
        }
    }
    nrg = n - nrg;
    printf("Case #%d: %d %d\n", nc, rg, nrg);
    /*
    for(i=1;i<=n;i++)
    {
        printf("%f ", matn[i]);
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("%f ", matk[i]);
    }
    printf("\n");
    */
    }
    return 0;
}
