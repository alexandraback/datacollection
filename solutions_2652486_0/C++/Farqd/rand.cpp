#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t; cin>>t;
	while(t--)
	{
		cout<<"Case #1:"<<endl;
		
		int R,N,M,K; cin>>R>>N>>M>>K;
		int t[15];
		for(int j=0; j<R; j++)
		{
			for(int i=0; i<K; i++)
			cin>>t[i];
			
			int ilemam = 0;
			vector<int> v;
			
			bool czy = false;
			for(int h=0; h<3; h++)
			{
				for(int i=0; i<K; i++)
				{
					if(t[i] % 3 == 0)
					{
						czy=true;
						t[i]=t[i]/3;
					}
				}
				if(czy)
					{v.push_back(3);
					ilemam++;}
				else
					break;
				czy=false;
			}	
			for(int h=0; h<3; h++)
			{
				for(int i=0; i<K; i++)
				{
					if(t[i] % 5 == 0)
					{
						czy=true;
						t[i]=t[i]/5;
					}
				}
				if(czy)
					{v.push_back(5);
					ilemam++;}
				else
					break;
				czy=false;
			}
			if(ilemam == 0)
			{v.push_back(2);v.push_back(2); v.push_back(4); ilemam+=3;};
			
			if(ilemam == 1)
			{
				bool bo=false;
				for(int i=0; i<K; i++)
					if(t[i]%4==0)
						bo=true;
				if(bo)
				v.push_back(4);
				else
				v.push_back(2);
				
				v.push_back(2);
				ilemam+=2;
			}
			
			if(ilemam==2)
			{
				bool bo=false;
				for(int i=0; i<K; i++)
					if(t[i]%4 == 0)
						bo=true;
				if(bo)
					v.push_back(4);
				else
					v.push_back(2);
			}
			
			for(int i=0; i<v.size(); i++)
			cout<<v[i];
			cout<<endl;
		}
	}
}
