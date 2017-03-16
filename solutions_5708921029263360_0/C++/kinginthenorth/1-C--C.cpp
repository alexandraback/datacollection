#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int cno=1;cno<=t;cno++)
	{
		int j,p,s,k;
		cin>>j>>p>>s>>k;
		int outfit[100][3],jc,pc,sc,line=0,i,flag,count;
			for(jc=1;jc<=j;jc++)
			{
				for(pc=1;pc<=p;pc++)
				{
					for(sc=1;sc<=s;sc++)
					{
						flag=0;
						count=0;
						for(i=0;i<line;i++)
						{
							if(outfit[i][0]==jc&&outfit[i][1]==pc)
							{
								count++;
							}
						}
						if(count>=k)
							flag=1;
						if(flag==0)
						{
							count=0;
							for(i=0;i<line;i++)
							{
								if(outfit[i][1]==pc&&outfit[i][2]==sc)
								{
									count++;
								}
							}
							if(count>=k)
							{
								flag=1;
							}
						}
						if(flag==0)
						{
							count=0;
							for(i=0;i<line;i++)
							{
								if(outfit[i][0]==jc&&outfit[i][2]==sc)
								{
									count++;
								}
							}
							if(count>=k)
								flag=1;
						}
						if(flag==0)
						{
							outfit[line][0]=jc;
							outfit[line][1]=pc;
							outfit[line][2]=sc;
							line++;
						}
					}
				}
			}
		cout<<"Case #"<<cno<<": "<<line<<endl;
		for(i=0;i<line;i++)
		{
			cout<<outfit[i][0]<<" "<<outfit[i][1]<<" "<<outfit[i][2]<<endl;
		}
	}
	return 0;
}
