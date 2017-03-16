#include<iostream>
using namespace std;

const int Max = 100;
int h[Max][Max];
int main()
{
	int T;
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>h[i][j];
		bool result = true;
		while(n+m > 0 && result)
		{
			int min = 0x7fffffff;
			int idx, idy;
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					if(h[i][j] < min)
						min = h[i][j], idx = i, idy = j;
			// try vertical
			bool temp = true;
			for(int i=0;i<n;i++)
				if(h[i][idy] != min)
					temp = false;
			if(temp)
			{
				for(int i=0;i<n;i++)
					for(int j=idy;j<m;j++)
						h[i][j] = h[i][j+1];
				m--;
				continue;
			}
			temp = true;
			for(int j=0;j<m;j++)
				if(h[idx][j] != min)
					temp = false;
			if(temp)
			{
				for(int i=idx;i<n;i++)
					for(int j=0;j<m;j++)
						h[i][j] = h[i+1][j];
				n--;
				continue;
			}
			result = false;
		}
		cout<<"Case #"<<_<<": "<<(result ? "YES" : "NO")<<endl;
	}
	return 0;
}
