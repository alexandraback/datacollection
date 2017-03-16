#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	int total = tc;
	while(tc--)
	{
		int low,high;
		cin>>low>>high;
		int cnt = 0;
		for(int i=low;i<=high;i++)
		{
			int num = i;
			int dn = (int)log10((double)num);
			int mul = (int)pow((double)10,dn);
			num = (num%10)*mul+num/10;
			while(num != i)
			{
				if(num >= low && num <= high)
				{
					cnt++;
				}
				num = (num%10)*mul+num/10;
			}
		}
		cout<<"Case #"<<total-tc<<": "<<cnt/2<<"\n";
	}
	return 0;
}
