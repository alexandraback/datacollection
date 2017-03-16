
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin>>T;
	long long A;
	int n;
	vector<long long>	 aa;

	for (int t=1;t<=T;t++)
	{
		aa.clear();
		cin>>A>>n;
		int res=n;
		long long tmp;
		for (int i=0;i<n;i++)
		{
			cin>>tmp;
			aa.push_back(tmp);
		}
		sort(aa.begin(),aa.end());
		if (A==1)
		{
			cout<<"Case #"<<t<<": "<<res<<endl;
			continue;
		}
		for (int i=0;i<n;i++)
		{
			int temp_res=i;
			long long nowA=A;
			int index=0;
			while(1)
			{
				while (nowA<=aa[index])
				{
					nowA=nowA+nowA-1;
					temp_res++;
				}
				while(index<(n-i)&&nowA>aa[index])
				{
					nowA=nowA+aa[index];
					index++;
				}
				if (index>=(n-i))
					break;
			}
			if (temp_res<res)
				res=temp_res;
		}
		cout<<"Case #"<<t<<": "<<res<<endl;
	}
	return 0;
}
