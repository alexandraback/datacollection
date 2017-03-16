#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	
	for (int i = 1; i <=t ; i++)
	{
		int n;
		cin>>n;
		long double nao[n], ken[n];
		for(int j=0; j<n ;j++)
		{
			cin>>nao[j];
		} 
		
		for(int j=0; j<n ;j++)
		{
			cin>>ken[j];
		} 
		
		sort(nao, nao+n);
		sort(ken, ken+n);
		
		int nao_val=0, ken_val=0;
		int pos_start=0, pos_end=n-1;		// for ken
		for(int j=0; j<n; j++)		// for nao
		{
			if(nao[j] > ken[pos_start])
			{
				nao_val++;
				pos_start++;
			}
			else 
			{
				ken_val++;
				pos_end--;
			}
		}
		
		int nao_val2=0;
		pos_start=0, pos_end=n-1;
		for(int j=n-1; j>=0; j--)
		{
			if(nao[j]>ken[pos_end])
			{
				nao_val2++;
			}
			else pos_end--;
		}
		
		cout<<"Case #"<<i<<": "<<nao_val<<" "<<nao_val2<<endl;
	}
}
