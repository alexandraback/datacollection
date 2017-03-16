#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<deque>
#include<iterator>
#include<algorithm>
using namespace std;
typedef set<int> sint;
long long int tenbase(int n)
{
	long long int ret=1;
	for(int i=0;i<n;i++)ret*=10;
	return ret;
}
int total(long long int start,long long int stop)
{
	sint processed;
	int nofdig=-1;long long int st=start,ret=0;
	while(st)
	{
		nofdig++;
		st/=10;
	}
	for(long long int i=start;i<=stop;i++)
	{
		long long int temp=i;
		int subret=0;
		while(processed.find(temp)==processed.end())
		{
			if(start<=temp&&stop>=temp)
			{
				processed.insert(temp);subret++;
			}
			int h=temp%10;
			temp/=10;temp+=h*(tenbase(nofdig));
		}
		if(subret>=2)ret+=(subret*(subret-1))/2;
	}
	return ret;
}
int main()
{
	ifstream gin("C-large.in");
	ofstream gout("gypClarge.out");
	int T;long long int A,B;
	gin>>T;
	for(int i=0;i<T;i++)
	{
		gin>>A>>B;
		cout<<i+1<<endl;
		gout<<"Case #"<<i+1<<": "<<total(A,B)<<endl;
	}
	gout.close();
	gin.close();
	return 0;
}
