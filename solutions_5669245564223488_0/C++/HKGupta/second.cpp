#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		vector<string> train;
		int N;
		cin>>N;
		string s;
		for(int i=0;i<N;i++)
		{
			cin>>s;
			train.push_back(s);
		}
		long long count=1;
		sort(train.begin(),train.end());
		for(int i=0;i<train.size()-1;i++)
		{
			if(train[i][train[i].length()-1]>train[i+1][0])
			{
				count=0;
				break;
			}
		}
		if(count!=0)
		{
		vector<string> tr;
		tr.push_back(train[0]);	
		
		for(int i=0;i<train.size()-1;i++)
		{
			string t=train[i];
			string t1=train[i+1];
			if((t[t.length()-1]==t1[0])&&(t[t.length()-1]==t[0])&&(t1[0]==t1[t1.length()-1]))
			{
				count*=2;
				tr[tr.size()-1].append(t1);
			}
			else if(t[t.length()-1]==train[i+1][0])
			{
				tr[tr.size()-1].append(t1);
				
			}
			else 
				tr.push_back(t1);	
		}
		//cout<<count<<tr.size();
		for(int i=1;i<=tr.size();i++)
			count*=i;
		}
		cout<<"Case #"<<t+1<<": "<<count%1000000007<<endl;
	}
	return 0;
}	
