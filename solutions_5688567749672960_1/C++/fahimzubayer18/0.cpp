#include <bits/stdc++.h>
using namespace std;

int mx[20];
int my[20];

int grid[20][20];

void clr(int r,int c)
{
    int a,b;
    for(a=0;a<r;a++)
    {
        for(b=0;b<c;b++) grid[a][b]=0;
    }
}

int cal_ans(int r,int c)
{
    int a,b,k,z;
    z=0;
    for(a=0;a<r;a++)
    {
        for(b=0;b<c;b++)
        {
            if(a+1<r)
            {
                if(grid[a][b] && grid[a+1][b]) z++;
            }
            if(b+1<c)
            {
                if(grid[a][b] && grid[a][b+1]) z++;
            }
        }
    }
    return z;
}

int main()
{

    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);

    /*
    cout << fixed << setprecision(4);
    std::ios::sync_with_stdio(false);

	*/

	int iter,tn;

	int a,b,c,d,e,x,y,z,n,k,r;

	scanf("%d",&tn);

	for(iter=1;iter<=tn;iter++)
	{
	    printf("Case #%d: ",iter);

	    cin>>r>>c>>k;

	    n=r*c;

	    clr(r,c);

	    e=0;
	    for(a=0;a<r;a++)
	    {
	        for(b=0;b<c;b++)
	        {
	            mx[e]=a;
	            my[e]=b;
	            e++;
	        }
	    }

	    z=r*r*c*c;

	    for(a=0;a<(1<<n);a++)
	    {
	        e=0;
	        for(b=0;b<n;b++)
	        {
	            if((a&(1<<b))) e++;
	        }
	        if(e==k)
	        {
	            clr(r,c);
	            for(b=0;b<n;b++)
                {
                    if((a&(1<<b)))
                    {
                        x=mx[b];
                        y=my[b];
                        grid[x][y]=1;
                    }
                }
                z=min(z,cal_ans(r,c));
	        }
	    }
	    cout<<z<<endl;

	}

    return 0;
}
