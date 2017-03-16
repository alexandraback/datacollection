#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("test.inp","r",stdin); freopen("test.out","w",stdout);
	int T; scanf("%d\n",&T);
	for(int i=1; i<=T; i++)
    {
        int N; scanf("%d",&N);
        int j=0, d=0, res=0;
        char c=getchar();
        while (c<'0'||c>'9') c=getchar();
        while (c>='0'&&c<='9')
        {
            if (c!='0')
            {
                if (d<j)
                {
                    res+=(j-d);
                    d=j;
                }
            }
            d+=(c-'0');
            c=getchar();
            j++;
        }
        printf("Case #%d: %d\n",i,res);
    }
	//fclose(stdin); fclose(stdout);
	return 0;
}
