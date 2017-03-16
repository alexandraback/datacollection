#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

int motesR(long long int ps,long long int fs, long long int& size)
{
	long long int t = ps-1;
	if(t == 0)
		return 1000;
	int count = 0;
	while(t<fs && count < 101)
	{
		t *= 2;
		++count;
	}
	size = t+1;
	return count;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int T;
	fin>>T;
	for(int i=1;i<=T;++i)
	{
		long long int a;
		int n;
		int max = 101;
		int count = 0;
		fin>>a;
		fin>>n;
		vector<long long int> motes;
		motes.resize(n);
		for(int j=0;j<n;++j)
			fin>>motes[j];
		sort(motes.begin(),motes.end());
		for(int j=0;j<motes.size();++j)
		{
			if(a > motes[j])
				a += motes[j];
			else
			{
				int remMotes = motes.size() - j;
				long long int size = 0;
				int reqMotes = motesR(a,motes[j],size);
				if(reqMotes >= remMotes)
				{
					count += remMotes;
					break;
				}
				else
				{
					if(count + remMotes < max)
						max = count + remMotes;
					count += reqMotes;
					if(count >= max)
					{
						count = max;
						break;
					}
					a = size + motes[j];
				}
			}
		}
		fout<<"Case #"<<i<<": "<<count<<endl;
	}

	fin.close();
	fout.close();
}