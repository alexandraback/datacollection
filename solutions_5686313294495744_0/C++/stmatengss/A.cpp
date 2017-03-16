#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>

using namespace std;

int t;
int n;
string s1[18],s2[18];
string ss;
map<string,int> mp1,mp2;

bool status;
int res;
int counter;

int main()
{
	int i,j,k;
	int tcase=1;

	freopen("A.in","r",stdin);
	freopen("A","w",stdout);

	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		for(j=0;j<n;j++)
		{
			cin>>s1[j]>>s2[j];
		}
		res=0;
		for(j=0;j<(1<<n);j++)
		{
//			cout<<j<<endl;
			mp1.clear();
			mp2.clear();
			status=true;
			counter=0;
			for(k=0;k<n;k++)
			{
				if(((1<<k)&j))
				{
//					cout<<"+";
					mp1[s1[k]]=1;
					mp2[s2[k]]=1;
				}
			}
			for(k=0;k<n;k++)
			{
				if(!((1<<k)&j))
				{
//					cout<<"-";
					counter++;
					if(mp1[s1[k]]==1&&mp2[s2[k]]==1)
					{
//						cout<<"T";
					}
					else
					{
//						cout<<"F";
						status=false;
						break;
					} 
				}
			}
//			cout<<endl;
			if(status)res=max(res,counter);
		}
		cout<<"Case #"<<tcase++<<": "<<res<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
