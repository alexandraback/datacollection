#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>

using namespace std;
long long modul=(long long)(1e9)+7;
long long num_permutations(int a)
{
	int b=a;
	long long ret=1;
	while(b>1)
	{
		ret*=b;
		ret%=modul;
		b--;
	}
	return ret;
}
int main()
{
	int T;
	cin>>T;
	for(int t=1; t<=T; t++)
	{
		vector<pair<pair<char, char>, string> > A;
		long long count=1;
		int N;
		cin>>N;
		for(int i=0; i<N; i++)
		{
			string b;
			cin>>b;
			A.push_back(make_pair(make_pair(b[0], b[b.length()-1]), b));
		}
		sort(A.begin(), A.end());
		bool tf=true;
		for(int i=0; i<A.size()-1; i++)
		{
			if(A[i+1].first.first<A[i].first.second)
				tf=false;
		}
		if(!tf)
		{
			cout<<"Case #"<<t<<": 0"<<endl;
		}
		else
		{
			int num_blocks=0;
			int blocksize=0;
			for(int i=0; i<N; i++)
			{
				
				if(i==0||A[i].first.first!=A[i-1].first.first)	//New block
				{
					if(i==0||A[i].first.first!=A[i-1].first.second)
						num_blocks++;	//This block isn't forced to be adjacent to the previous block
					//Do work here
					if(i!=0)	//Not the first block
					{
						if(A[i-1].first.first!=A[i-1].first.second)	//This one must be last.
							blocksize--;
						count*=num_permutations(blocksize);
						count%=modul;
					}
					
					//Stop doing work here. Note that the last one will have to be done separately.
					blocksize=1;
				}
				else	//Continue an old block.
				{
					blocksize++;
				}
				//cout<<"Testing: "<<num_blocks<<" blocks so far, "<<blocksize<<" size of most recent block, "<<count<<" permutations total"<<endl;
			}
			if(A[N-1].first.first!=A[N-1].first.second)
				blocksize--;
			count*=num_permutations(blocksize);
			count%=modul;
			count*=num_permutations(num_blocks);
			count%=modul;
			//cout<<"Testing: "<<num_blocks<<" blocks so far, "<<blocksize<<" size of most recent block, "<<count<<" permutations total"<<endl;
			cout<<"Case #"<<t<<": "<<count<<endl;
		}
	}
	return 0;
}