#include <bits/stdc++.h>

using namespace std;
int t;
int n;
int j;
vector<string> tab;

void generateStrings(int size,int j)
{
	int p = (1<<(size+1));
	for(int i=3;i<p;i+=2)
	{
		string s= "";
		int k=i;
		while(k)
		{
			s+= k%2 +'0';
			k/=2;
		}
		reverse(s.begin(),s.end());
		tab.push_back(s);
	}
}

void compute(int n,int j)
{
	generateStrings(n/2,j);
	for(int i=0;i<j;++i)
	{
		string s = tab[i];
		for(int k = 0;k<n-tab[i].length()*2;++k)
			s+='0';
		s+=tab[i];
		cout<<s<<" ";
		for(int k=2;k<=10;++k)
		{
			long long sum = 0;
			long long t = 1;
			for(int p=tab[i].length()-1;p>=0;--p)
			{
				if(tab[i][p]!='0')
					sum = sum + t;
				t = t*k;
			}
			if(k==10)
				cout<<sum;
			else
				cout<<sum<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		cin>>n>>j;
		cout<<"Case #"<<c<<":"<<endl;
		compute(n,j);
	}

	return 0;
}