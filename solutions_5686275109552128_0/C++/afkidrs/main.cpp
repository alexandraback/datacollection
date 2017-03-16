#include <iostream>
#include <vector>
#define INF 0x1f1f1f1f


using namespace std;
vector<int> d;
int n;

inline int MAX(int a,int b)
{
	return (a<b)?b:a;
}

int CalculateMax()
{
	int index=0;
	int maximum=0;
	for(unsigned int i=0;i<d.size();++i)
	{
		if(d[i]>maximum)
		{
			maximum=d[i];
			index=i;
		}
	}
	return index;
}

int CalculateNbIntegers(int x)
{
	int count=0;
	for(unsigned int i=0;i<d.size();++i)
	{
		if(d[i]>x)
			count++;
	}
	return count;
}


int main()
{
	int t,a;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>n;
		for(int j=0;j<n;++j)
		{
			cin>>a;
			d.push_back(a);
		}
		int index=CalculateMax();
		int passed=0;
		while(d[index]!=0)
		{
			int maximum = d[index];
			for(int i=maximum-1;i>(maximum+1)/2;--i)
			{
				int count=CalculateNbIntegers(i);
				if(maximum-i>=count && maximum!=1)
				{
					int length=d.size();
					for(int j=0;j<length;++j)
					{
						if(d[j]>i)
						{
							d.push_back((d[j]+1)/2);
							d[j]-=(d[j]+1)/2;
							passed++;
						}
					}
				}
			}
			vector<int>::iterator it=d.begin();
			while(it!=d.end())
			{
				(*it)--;
				if((*it)==0)
				{
					it=d.erase(it);
				}
				else it++;
			}
			passed++;
			index=CalculateMax();
		}
		d.clear();
		cout<<"Case #"<<i<<": "<<passed<<endl;
	}
	return 0;
}