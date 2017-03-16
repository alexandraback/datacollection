#include <bits/stdc++.h>
using namespace std;

#define LL long long
 
 
struct hiker
{
	LL d,m;
	char pick=0;
	
	hiker()
	{
		d=m=0;
	}
	
	hiker(LL _d, LL _m)
	{
		d=_d;
		m=_m;
		pick=0;
	}
};

bool operator < (hiker h1, hiker h2)
{
	return (h1.d<h2.d); 
}


vector<hiker> H;
 


int main()
{ 
	int n,t,i,j,k;
	LL d,m,h;
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	 
	

	
	cin>>t;
	 
	for(i=1;i<=t;i++)
	{
		H.clear();
		cin>>n;
		for(j=0;j<n;j++)
		{
			cin>>d>>h>>m;
			for(k=0;k<h;k++) H.push_back(hiker(d,m+k));
		}
		
		LL ans=0;
		
		LL t2 = (720 - H[1].d)*H[1].m;
		LL t1 = (360 - H[0].d)*H[0].m;
		
		if(t2<=t1)ans=1;
		
		
		  t2 = (720 - H[0].d)*H[0].m;
		  t1 = (360 - H[1].d)*H[1].m;
		
		if(t2<=t1)ans=1;
		
		sort(H.begin(), H.end());
		
		/*int nn = (int)H.size();
		
		
		for(j=0;j<nn;j++)
		{
			char gut=1;
			for(k=0;k<nn;k++) if(H[k].pick==0 && k!=j)
			{
				LL t1,t2;
				
				t1 = (360 - H[j].d)*H[j].m;
				t2 = (720-H[k].d)*H[k].m;
				if(t2<=t1)gut=0;
			}
			
			if(gut==0)
			{
				H[j].pick=1;
				ans++;
			}else break;
			
		}*/
		 
		
		printf("Case #%d: %lld\n",i,ans);
	}

	return 0;

}
