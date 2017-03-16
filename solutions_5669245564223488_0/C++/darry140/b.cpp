#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	freopen("Bin.in","r",stdin);
	freopen("Bout.txt","w",stdout);
	int T;
	cin>>T;
	string list[20];
	char all[20000];
	bool v[30];
	for(int i=1;i<=T;i++)
	{
		int N;
		cin>>N;
		memset(all,'\0',sizeof(all));
		for(int k=0;k<N;k++)
			cin>>list[k],list[k].push_back(k+'a');
		//for(int k=0;k<N;k++)
		//	cout<<list[k]<<endl;
		//for(int k=0;k<N;k++)
		//	strcat(all,list[k].c_str());
		sort(list,list+N);
		long long ans=0;
		do
		{
			memset(all,'\0',sizeof(all));
			memset(v,false,sizeof(v));
			for(int k=0;k<N;k++)
				strcat(all,list[k].c_str()),all[strlen(all)-1]='\0';
			bool f=true;
			for(int k=0,len=strlen(all);k<len;k++)
			{
				if(!v[all[k]-'a'])
					v[all[k]-'a']=true;
				else if(all[k]!=all[k-1])
				{
					f=false;
					//cout<<all<<endl;
					break;
				}
			}
			if(f)
				ans++;//,cout<<all<<endl;
		}while (next_permutation(list,list+N) );
		printf("Case #%d: ",i);
		cout<<ans<<endl;
	}
	return 0;
}
