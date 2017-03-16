#include<bits/stdc++.h>

using namespace std;

int N;
int A[1003], f[1003][1003];

void prep()
{
    for(int i=1; i<=1000; i++)
        for(int j=1; j<=1000; j++)
        {
            if (j<=i)
                f[i][j]=0;
            else f[i][j]=j/i+(int)(j%i!=0)-1;
        }
}

int main()
{
	//freopen("test.inp","r",stdin); freopen("test.out","w",stdout);
	int T; scanf("%d",&T);
	prep();
	//cout<<f[3][9]<<endl;
	for(int t=1; t<=T; t++)
    {
        scanf("%d",&N);
        for(int i=1; i<=N; i++) scanf("%d",&A[i]);
        int res = 2e9;
        for(int i=1; i<=1000; i++)
        {
            int t = i;
            for(int j=1; j<=N; j++)
                t+=f[i][A[j]];
            res=min(res,t);
        }
        printf("Case #%d: %d\n",t,res);
    }
	fclose(stdin); fclose(stdout);
	return 0;
}
