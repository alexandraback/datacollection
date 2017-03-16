#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>


using namespace std;

typedef long long lint;

set<int> get(int i, int j, int k)
{
	set<int> a;
	vector<int> ii;
	ii.push_back(1);
	vector<int> jj(ii);
	vector<int> kk(ii);
	ii.push_back(i);
	jj.push_back(j);
	kk.push_back(k);

	for (int iii = 0; iii < ii.size(); ++iii)
	{
		for (int jjj = 0; jjj < jj.size(); ++jjj)
		{
			for (int kkk = 0; kkk < kk.size(); ++kkk)
			{
				a.insert(ii[iii]*jj[jjj]*kk[kkk]);
			}
		}
	}
	return a;
}

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;

	for (int tt = 0; tt < T; ++tt)
	{
		
		int R, N, M, K;
		cin>>R>>N>>M>>K;

		vector< vector<int> > number;
		vector< set<int> > prod;


		
		for (int i = 2; i < M+1; ++i)
		{
			for (int j = 2; j < M+1; ++j)
			{
				for (int k = 2; k < M+1; ++k)
				{
					vector<int> n;
					n.push_back(i);
					n.push_back(j);
					n.push_back(k);
					number.push_back(n);
					prod.push_back(get(i,j,k));
				}
			}
		}

		cout<<"Case #"<<tt+1<<":"<<endl;
		for (int i = 0; i < R; ++i)
		{
			vector<int> p;
			for (int k = 0; k < K; ++k)
			{
				int t;
				cin>>t;
				p.push_back(t);
			}

			bool find = false;
			int index = 0;
			for (int prodset = 0; prodset < prod.size(); ++prodset)
			{
				set<int> s = prod[prodset];
				bool in = true;
				for (int k = 0; k < K; ++k)
				{
					if (s.find(p[k]) == s.end())
					{
						in = false;
						break;
					}
				}
				if(in) {
					find = true;
					index = prodset;
					break;
				}
			}

			for (int n = 0; n < N; ++n)
			{
				cout<<number[index][n];
			}
			cout<<endl;
		}
	}
	return 0;
}