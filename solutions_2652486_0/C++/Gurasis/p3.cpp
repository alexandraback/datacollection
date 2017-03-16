#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{int m,n,r,k,ar[20],t,m1,n1,i,j,ar1[6],p;
	cin>>t;
	for(m1=0;m1<t;m1++)
		{cin>>r;
		cin>>n;
		cin>>m;
		cin>>k;
		cout<<"Case #"<<m1+1<<":\n";
		for(n1=0;n1<r;n1++)
			{p=0;ar1[0]=0;
			int flag=0;
			for(i=0;i<k;i++)
				{cin>>ar[i];}
			for(j=5;j>1;j--)
				{for(i=0;i<k;i++)
					{if(ar[i]%(j*j)==0)
						{p++;
						
						ar1[p]=j;
						ar[i]=ar[i]/(j*j);						
					p++;ar1[p]=j;
						flag=1; break;
						}
					}
					if(flag==1) break;
				}
						
			flag=0;	
			for(i=0;i<k;i++)
				{for(j=5;j>1;j--)
					{if(ar[i]%j==0&&j!=ar1[p])
						{p++;ar1[p]=j;
												
								}
					if(p==3) {flag=1;break;	}

					}
				if(flag==1) break;}
			if(p==2) {ar1[3]=ar1[2];}
			if(p==0){ar1[1]=2;ar1[2]=2;ar1[3]=2;}
			
		for(i=1;i<4;i++)
				{cout<<ar1[i];}cout<<endl;
			
			}
		
		
		}
}
