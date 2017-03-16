#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

_int64 a[101];
_int64 b[101];
vector<int> sa;
vector<int> sb;

_int64 solve()
{
	if (sa.size()==0 || sb.size()==0)
	{
		return 0;
	}

	int ta=sa[0];
	int tb=sb[0];
	_int64 va=a[0];
	_int64 vb=b[0]; 
	_int64 value1;
	_int64 value2;
	_int64 value;

	if (sa[0]==sb[0])
	{
		if (a[0]==b[0])
		{
			for (int i=0;i<(int)sa.size()-1;i++)
			{
				sa[i]=sa[i+1];
				a[i]=a[i+1];
			}
			sa.pop_back();
			for (int i=0;i<(int)sb.size()-1;i++)
			{
				sb[i]=sb[i+1];
				b[i]=b[i+1];
			}
			sb.pop_back();
			value=solve();
			sb.push_back(0);
			for (int i=(int)sb.size()-1;i>=1;i--)
			{
				sb[i]=sb[i-1];
				b[i]=b[i-1];
			}
			sb[0]=tb;
			b[0]=vb;
			sa.push_back(0);
			for (int i=(int)sa.size()-1;i>=1;i--)
			{
				sa[i]=sa[i-1];
				a[i]=a[i-1];
			}
			sa[0]=ta;
			a[0]=va;
			return value+a[0];
		}
		else
		{
			if (a[0]>b[0])
			{
				a[0]=a[0]-b[0];
				for (int i=0;i<(int)sb.size()-1;i++)
				{
					sb[i]=sb[i+1];
					b[i]=b[i+1];
				}
				sb.pop_back();
				value=solve();
				sb.push_back(0);
				for (int i=(int)sb.size()-1;i>=1;i--)
				{
					sb[i]=sb[i-1];
					b[i]=b[i-1];
				}
				sb[0]=tb;
				b[0]=vb;
				a[0]=a[0]+b[0];
				return value+b[0];
			}
			else
			{
				if (b[0]>a[0])
				{
					b[0]=b[0]-a[0];
					for (int i=0;i<(int)sa.size()-1;i++)
					{
						sa[i]=sa[i+1];
						a[i]=a[i+1];
					}
					sa.pop_back();
					value=solve();
					sa.push_back(0);
					for (int i=(int)sa.size()-1;i>=1;i--)
					{
						sa[i]=sa[i-1];
						a[i]=a[i-1];
					}
					sa[0]=ta;
					a[0]=va;
					b[0]=b[0]+a[0];
					return value+a[0];
				}
			}
		}
	}
	else
	{
		for (int i=0;i<(int)sb.size()-1;i++)
		{
			sb[i]=sb[i+1];
			b[i]=b[i+1];
		}
		sb.pop_back();
		value1=solve();
		sb.push_back(0);
		for (int i=(int)sb.size()-1;i>=1;i--)
		{
			sb[i]=sb[i-1];
			b[i]=b[i-1];
		}
		sb[0]=tb;
		b[0]=vb;
		for (int i=0;i<(int)sa.size()-1;i++)
		{
			sa[i]=sa[i+1];
			a[i]=a[i+1];
		}
		sa.pop_back();
		value2=solve();
		sa.push_back(0);
		for (int i=sa.size()-1;i>=1;i--)
		{
			sa[i]=sa[i-1];
			a[i]=a[i-1];
		}
		sa[0]=ta;
		a[0]=va;
		if (value1>value2)
		{
			return value1;
		}
		else
		{
			return value2;
		}
	}
}

int main()
{
	ifstream fin;
	fin.open("C-small.in");
	ofstream fout;
	fout.open("Cans.txt");
	int T;
	int N;
	int M;
	_int64 repeat;
	int type;
	fin>>T;
	for (int i=1;i<=T;i++)
	{
		fin>>N;
		fin>>M;
		for (int j=0;j<=100;j++)
		{
			a[j]=0;
			b[j]=0;
		}
		sa.clear();
		sb.clear();

		for (int j=0;j<N;j++)
		{
			fin>>repeat;
			fin>>type;
			a[j]=repeat;
			sa.push_back(type);
		}

		for (int j=0;j<M;j++)
		{
			fin>>repeat;
			fin>>type;
			b[j]=repeat;
			sb.push_back(type);
		}
		fout<<"Case #"<<i<<": "<<solve()<<endl;
	}
	fin.close();
	fout.close();;
	return 0;
}