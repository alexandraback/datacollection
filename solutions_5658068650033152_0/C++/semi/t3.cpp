#include <cstdio>
#include <iostream>

using namespace std;


void deal(int n, int m, int k)
{
	int ans;
	if ((n==3)&&(m==3))
	{
		ans=k;
		if (k>=5) ans--;
	}
	
	
	if ((n==3)&&(m==4))
	{
		ans=k;
		if (k>=5) ans--;
		if (k>=8) ans--;
	}
	
	
	if ((n==3)&&(m==5))
	{
		ans=k;
		if (k>=5) ans--;
		if (k>=8) ans--;
		if (k>=11) ans--;
	}
	
	
	if ((n==3)&&(m==6))
	{
		ans=k;
		if (k>=5) ans--;
		if (k>=8) ans--;
		if (k>=11) ans--;
		if (k>=14) ans--;
	}
	
	
	if ((n==4)&&(m==4))
	{
		ans=k;
		if (k>=5) ans--;
		if (k>=8) ans--;
		if (k>=10) ans--;
		if (k>=12) ans--;
	}
	
	
	if ((n==4)&&(m==5))
	{
		ans=k;
		if (k>=5) ans--;
		if (k>=8) ans--;
		if (k>=10) ans--;
		if (k>=12) ans--;
		if (k>=14) ans--;
		if (k>=16) ans--;
	}
	cout << ans << endl;
}


int main ()
{
	freopen("C-small-attempt0.in", "r", stdin);
    freopen("t3.out", "w", stdout);
    
	
	int n,m,k;
	int t,tt;
	cin >> tt;
	for (t=1; t<=tt; t++)
	{
		cin >> n >> m >> k;
		printf("Case #%d: ",t);
        int i,j;
        if (n>m)
        {
        	i=n;
        	n=m;
        	m=i;
        }
        if ((n==1)||(n==2)) 
        {
        	cout << k << endl;
        }
        else 
        {
        	deal(n,m,k);
        }
        
	}
	
}
