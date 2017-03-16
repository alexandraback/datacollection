#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stdio.h>

bool digits[10];

using namespace std;

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	int k;
	bool ch;
	cin>>T;
	int n;
	vector<int> frequencies;
	vector<int> result;
	for(int t=1; t<=T; t++)
	{
		cin>>n;
		int tmp;
		result.resize(n);
		frequencies.resize(2501);
		for(int i=0; i<2501; i++) frequencies[i]=0;
		for(int i=0; i<2*n-1; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin>>tmp;
				frequencies[tmp]++;
			}
		}
		k=0;
		for( int i=0; i<2501; i++)
		{
			if(frequencies[i]%2!=0)
			{
				result[k]=i;
				k++;
			}
		}
		sort(result.begin(), result.end());
		cout<<"Case #"<<t<<": ";
		for(int i=0; i<n; i++) cout<<result[i]<<" ";
		cout<<endl;
	}
	return 0;
}
