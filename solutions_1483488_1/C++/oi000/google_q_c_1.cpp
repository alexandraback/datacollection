#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
int a[100];
int b[2300000][8];
int main()
{
	ifstream ifile;
	ofstream ofile;
	int k1,k2,k3,k4,k5,k6,k7,i,u,p,len,j,x,y,n,k;
	bool flag;
	for(k1=0;k1<2;k1++)
		for(k2=0;k2<=9;k2++)
			for(k3=0;k3<=9;k3++)
				for(k4=0;k4<=9;k4++)
					for(k5=0;k5<=9;k5++)
						for(k6=0;k6<=9;k6++)
							for(k7=0;k7<=9;k7++)
							{
								a[7]=k1;
								a[6]=k2;
								a[5]=k3;
								a[4]=k4;
								a[3]=k5;
								a[2]=k6;
								a[1]=k7;
								len=7;
								while(a[len]==0)
									len--;
								if (len==0) continue;
								p=0;
								for(i=len;i>=1;i--)
									p=p*10+a[i];
								b[p][0]=0;
								for(i=len-1;i>=1;i--)
								{
									if (a[i]==0) continue;
									u=0;
									
									for(j=i;j>=1;j--)
										u=u*10+a[j];
									for(j=len;j>=i+1;j--)
										u=u*10+a[j];
									if (p==u)continue;
									if (u>2000000) continue;
									flag=false;
									for(k=1;k<=b[p][0];k++)
										if (b[p][k]==u) 
										{
											flag=true;
											break;
											
										}
									if (flag) continue;
									b[p][0]++;
									b[p][b[p][0]]=u;
									
								}
							}
		ifile.open("C-large.in");
		ifile>>n;
		ofile.open("2.txt");
		
		for(i=1;i<=n;i++)
		{
			ifile>>x>>y;
			
			u=0;
			for(j=x;j<=y;j++)
				for(k=1;k<=b[j][0];k++)
					if (b[j][k]>=x&&b[j][k]<=y) u++;
			u=u/2;
			ofile<<"Case #"<<i<<": "<<u<<endl;
		}
		return 0;
}
