#include<bits/stdc++.h>

using namespace std;

#define R "RICHARD"
#define G "GABRIEL"

string solve(int x, int m, int n)
{
    if (x==1)
    {
        return G;
    }
    if (x==2)
    {
        if ((m*n)%2==1)
            return R;
        return G;
    }
    if (x==3)
    {
        if ((m*n)%3!=0)
            return R;
        if (m*n<=3)
            return R;
        return G;
    }
    if (x==4)
    {
        if ((m*n)%4!=0)
            return R;
        if (m*n<=4)
            return R;
        if (m==2&&n==4) return R;
        return G;
    }
    if (x==5)
    {
        if ((m*n)%5!=0)
            return R;
        if (m<=2)
            return R;
        if (m==3&&n<=5)
            return R;
        return G;
    }
    if (x==6)
    {
        if ((m*n)%6!=0)
            return R;
        if (m<=3)
            return R;
        return G;
    }
    return R;
}

int main()
{
	//freopen("test.inp","r",stdin); freopen("test.out","w",stdout);
	int T; scanf("%d",&T);
	for(int t=1; t<=T; t++)
    {
        int X, M, N;
        scanf("%d%d%d",&X,&M,&N);
        string res = solve(X,min(M,N),max(M,N));
        printf("Case #%d: %s\n",t,res.c_str());
    }
	fclose(stdin); fclose(stdout);
	return 0;
}
