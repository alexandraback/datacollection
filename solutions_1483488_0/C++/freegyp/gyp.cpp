#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<deque>
#include<iterator>
#include<algorithm>
using namespace std;
typedef set<int> sint;
int tenbase(int n)
{
	int ret=1;
	for(int i=0;i<n;i++)ret*=10;
	return ret;
}
int total(int start,int stop)
{
	sint processed;
	int ret=0,nofdig=-1,st=start;
	while(st)
	{
		nofdig++;
		st/=10;
	}
	for(int i=start;i<=stop;i++)
	{
		int temp=i;
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
	ifstream gin("C-small-attempt2.in");
	ofstream gout("gypCsmall.out");
	int T,A,B;
	gin>>T;
	for(int i=0;i<T;i++)
	{
		gin>>A>>B;
		gout<<"Case #"<<i+1<<": "<<total(A,B)<<endl;
	}
	gout.close();
	gin.close();
	return 0;
}
