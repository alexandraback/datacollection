#include<iostream>
#include<list>
#include<stack>
#include<vector>
using namespace std;

typedef struct classdet
{
	int n;
	list<int> parent;
}classdetails;
int main()
{
	int test,i,j,temp,n,k,l;
	cin >> test;
	for(i=0;i<test;i++)
	{
			cin>>n;
			classdetails cd[n];
			int flag[n];
			for(k=0;k<n;k++)
			{	
				flag[k]=0;
				cin>>cd[k].n;
				if(cd[k].n>1)
					flag[k]=1;
				for(j=0;j<cd[k].n;j++)
					{ cin>>temp;
					  cd[k].parent.push_back(temp);
					}
			}
		
	
		int mainflag=0;
		for(k=0;k<n&&mainflag==0;k++)
		{
			if(flag[k]==1)
			{

				stack<int> trav;
				vector<int> values;
				trav.push(k+1);
				bool first=true;
				
				do
				{

					l=trav.top();									
					if(!first)
					{
						int ii;
						for(ii=0;ii<values.size();ii++)
						{
							if(values[ii]==l)
								{	mainflag=1;
									break;
								}
						} 
						values.push_back(l);
					}

					trav.pop();
					list<int>::iterator it;
					for(it=cd[l-1].parent.begin(); it != cd[l-1].parent.end(); ++it)
					{
						trav.push(*it);
					}
					first=false;
				}while(!trav.empty()&&mainflag==0);	
			}
		}
		if(mainflag==0)
			cout<<"Case #"<<i+1<<": No"<<"\n";
		else
			cout<<"Case #"<<i+1<<": Yes"<<"\n";
	}
	
	return 0;
}
