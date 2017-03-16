#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<limits>
#include<cassert>
#include<sstream>

using namespace std;
typedef long long ll;

const int max_n=15;

int T,r,n,m,k;
int a[max_n];

int pow(int a, int b)
{
	if(b==0)
		return 1;
	return a;
}

int main()
{
    scanf("%d",&T);
	for(int z=1; z<=T; z++)
	{
		scanf("%d%d%d%d",&r,&n,&m,&k);
		printf("Case #%d: \n",z);
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<k; j++)
				scanf("%d",&a[j]);
		
			int msc=0,rx=2,ry=2,rz=2;
			for(int x=2; x<=5; x++)
				for(int y=2; y<=5; y++)
					for(int z=2; z<=5; z++)
					{
						int sc=0;
						for(int t=0; t<k; t++)
						{
							bool f=0;
							for(int l=0; l<2; l++)
								for(int m=0; m<2; m++)
									for(int p=0; p<2; p++)
										if(!f and pow(x,l)*pow(y,m)*pow(z,p)==a[t])
										{
											sc++;
											f=1;
										}
							if(msc<sc)
							{
								msc=sc;
								rx=x;ry=y;rz=z;
							}
						}
						//cout<<x<<" "<<y<<" "<<z<<" "<<sc<<endl;
					}
			printf("%d%d%d\n",rx,ry,rz);
		}
    }
	
    return 0;
}
