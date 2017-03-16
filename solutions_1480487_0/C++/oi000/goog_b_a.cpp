#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<fstream>
using namespace std;
int a[100000];
int flag[10000];
int main()
{
	int ii,i,n,tot,t,k;
	double p,tot1;
	//ofstream ofile;
	//ifstream ifile;
	freopen("A-small-attempt4.in","r",stdin);freopen("A-small-attempt0.txt","w",stdout);
	//ifile.open("A-small-attempt3.in");
	scanf("%d",&t);
	//ifile>>t;
	//ofile.open("4.txt");
	for(ii=1;ii<=t;ii++)
	{
		scanf("%d",&n);
		if (ii==16)
		{
			int gh=1;
		}
		//ifile>>n;
		tot=0;
		printf("Case #%d:",ii);
		//ofile<<"Case #"<<ii<<": ";
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			//ifile>>a[i];
			tot=tot+a[i];
			flag[i]=0;
		}
		p=2.0/(n+0.0);//(tot+0.0)
        k=0;
		tot1=0;
		for(i=1;i<=n;i++)
		{
			if (p<(a[i]+0.0)/(tot+0.0)) 
			{
				//tot1=tot-a[i];
				flag[i]=1;
			}
			else
			{
				tot1=tot1+a[i];
				k++;
			}
		}
		//p=2.0/(k+0.0);
		tot1=(tot1+tot)/(k+0.0);
		for(i=1;i<=n;i++) 
		{
			if (flag[i]) printf(" 0");//ofile<<0<<" ";
			else
				printf("% .6lf",(tot1-a[i]+0.0)/(tot+0.0)*100);
				//ofile<<(int)((tot1-a[i]+0.0)/(tot+0.0)*100)<<'.'<<(int)((((tot1-a[i]+0.0)/(tot+0.0)*100)-(int)((tot1-a[i]+0.0)/(tot+0.0)*100))*10000000)<<' ';
                //ofile<<(int)((p-(a[i]+0.0)/(tot+0.0))*100)<<"."<<(int)((((p-(a[i]+0.0)/(tot+0.0))*100)-(int)((p-(a[i]+0.0)/(tot+0.0))*100))*1000000)<<" ";
			//printf("%.6lf ",(p-(a[ii][i]+0.0)/(tot+0.0))*100);
		}
		printf("\n");
			//if (flag[i]) ofile<<0<<endl;
			//else
				//			ofile<<(int)((tot1-a[i]+0.0)/(tot+0.0)*100)<<'.'<<(int)((((tot1-a[i]+0.0)/(tot+0.0)*100)-(int)((tot1-a[i]+0.0)/(tot+0.0)*100))*10000000)<<endl;
				//ofile<<(int)((tot1-a[i]+0.0)/(tot+0.0))<<'.'<<(int)((((tot1-a[i]+0.0)/(tot+0.0))-(int)((tot1-a[i]+0.0)/(tot+0.0)))*1000000)<<endl;
	//	if (flag[i]) ofile<<0<<" ";
		//	else
              //  ofile<<(int)((p-(a[i]+0.0)/(tot+0.0))*100)<<"."<<(int)((((p-(a[i]+0.0)/(tot+0.0))*100)-(int)((p-(a[i]+0.0)/(tot+0.0))*100))*1000000)<<" ";
			//printf("%.6lf ",(p-(a[ii][i]+0.0)/(tot+0.0))*100);
		//printf("%.6lf ",(p-(a[n]+0.0)/(tot+0.0))*100);
		//ofile<<(int)((p-(a[i]+0.0)/(tot+0.0))*100)<<"."<<(int)((((p-(a[i]+0.0)/(tot+0.0))*100)-(int)((p-(a[i]+0.0)/(tot+0.0))*100))*1000000)<<endl;
			//printf("%.6lf ",(p-(a[ii][i]+0.0)/(tot+0.0))*100);
		//printf("\n");
	}
	//ofile<<endl;
	//ifile.close();
	//ofile.close();
	return 0;

}