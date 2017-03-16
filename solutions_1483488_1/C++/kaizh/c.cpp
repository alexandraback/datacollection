#include <iostream>
#include <set>
#include <cstdio>
using namespace std;

int main()
{
	int T;
	//freopen("cb.in","r",stdin);
	//freopen("cb.res","w+",stdout);
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		int A,B;
		cin>>A>>B;
		int cnt=0;
		set<long long> hash;
		for(int i=A;i<=B;i++)
		{
			int arr[20];
			int idx=0,tmp=i;
			while(tmp)
			{
				arr[idx++]=tmp%10;
				tmp/=10;
			}
			int low=0,high=idx-1;
			while(low<high)
			{
				int t=arr[low];
				arr[low]=arr[high];
				arr[high]=t;
				low++;high--;
			}
			long long key=i;
			for(int j=0;j<idx;j++)
			{
				arr[idx+j]=arr[j];
				key*=10;
			}
			for(int j=1;j<idx;j++)
			{
				int num=0;
				for(int t=0;t<idx;t++)
					num=num*10+arr[j+t];
				if(num>i&&num<=B&&num>=A)
				{
					if(hash.count(key+num)==0)
					{
						hash.insert(key+num);
						//cout<<i<<num<<endl;
						cnt++;
					}
				}
			}
		}
		cout<<"Case #"<<tt<<": "<<cnt<<endl;
	}
	return 0;
}
