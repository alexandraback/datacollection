#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i = 1; i<= t; i++)
	{
		int n;
		cin>>n;
		vector<int> arr (2501, 0);
		vector<int> mainArr;
		for(int j =1; j<=((n*2)-1)*n; j++)
		{
			int x;
			cin>>x;
			arr[x]++;
		}
		for(int j = 1; j<=2501; j++)
		{
			if(arr[j]%2 == 1)
				mainArr.push_back(j);
		}
		sort(mainArr.begin(), mainArr.end());
		cout<<"Case #"<<i<<": ";
		for(int j = 0; j<mainArr.size(); j++)
			cout<<mainArr[j]<<" ";
		cout<<endl;
	}
	return 0;
}