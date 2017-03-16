/*	Problem C	*/
/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i;
    	scanf("%d",&t);
    	int initial=0,count=0;
    	int n,m,k;
    	int sqr;
    	int ans=0;
    	while(t--)
    	{
    		initial++;
        	ans=0;
        	cin>>n;
        	cin>>m;
        	cin>>k;
        	sqr=sqrt(k);
        	if((sqr*sqr>k/2) && (sqr<=n)&& (sqr<=m))
        	{
        	    	ans=k-(sqr*sqr-(sqr*2+2*(sqr-2)));
        		ans=ans-(k-(sqr*sqr));
        	}
        	else
        	{
			int l,b;
        		l=sqr;
        		b=sqr;
        		bool con=true;
        		do
        		{
            			if(con)
            			{
					l++;
            				con=false;
            			}
            			else
				{
            				b++;
            				con=true;
            			}
        		}
			while(l*b<=k);
        		if(con)
        			b--;
        		else
        			l--;
        		ans=k-(l*b-(b*2+2*(l-2)));
        		ans=ans-(k-(l*b));
        	}
        	printf("Case #%d: %d\n",initial,ans);
    	}
	return 0;
}
