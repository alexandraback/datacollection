#include <iostream>
#include <sstream>
#include <climits>
#include <cstddef>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;


vector< vector<int> > implementation(vector<int> seed,int flag)
{
	vector< vector<int> > res;
	
	vector<int> s;
	s.push_back(1);
	for (int i = 0; i < seed.size(); i++) s.push_back(seed[i]);
	for (int i = seed.size()-1; i >= 0; i--) s.push_back(seed[i]);
	s.push_back(1);
	res.push_back(s);

	s.clear();
	s.push_back(1);
	for (int i = 0; i < seed.size(); i++) s.push_back(seed[i]);
	s.push_back(-1);
	for (int i = seed.size()-1; i >= 0; i--) s.push_back(seed[i]);
	s.push_back(1);

	for (int i = 0; i <= 2; i++)
	{
		s[s.size()/2]=i;
		if (flag>=2 && i==2) continue;
		res.push_back(s);
	}

	return res;
}

int main()
{
	vector< vector<int> > ret;
	
	vector<int> t;
	t.push_back(1);ret.push_back(t);
	t[0]=3;ret.push_back(t);

	for (int i = 1; i <= 52; i++)
	{
		vector<int> seed;
		for (int j = 0; j < i; j++) seed.push_back(0);
		seed[0]=seed[seed.size()-1]=2;
		ret.push_back(seed);

		if (seed.size()!=1 && seed.size()%2==1)
		{
			seed[seed.size()/2]=1;
			ret.push_back(seed);
		}
	}

	for (int i = 0; i <= 25; i++)
	{
		for (int j = 0; j <= min(3,i); j++)
		{
			vector<int> seed;
			for (int k = 0; k < i; k++) seed.push_back(0);

			for (int k = 0; k < j; k++) seed[k]=1;
			sort(seed.begin(),seed.end());

			do
			{
				vector< vector<int> > res=implementation(seed,j);
				for (int k = 0; k < res.size(); k++) ret.push_back(res[k]);
			} while (next_permutation(seed.begin(),seed.end()));
		}
	}


	vector< vector<int> > counter;

	for (int i = 0; i < ret.size(); i++)
	{
		vector<int> multi(150,0);

		for (int j = 0; j < ret[i].size(); j++)
		{
			for (int k = 0; k < ret[i].size(); k++)
			{
				multi[j+k]+=ret[i][j]*ret[i][k];
			}
		}
		reverse(multi.begin(),multi.end());


		bool flag=true;
		for (int j = 0; j < multi.size(); j++)
		{
			if (multi[j]>=10) flag=false;
		}
		if (!flag) continue;
		counter.push_back(multi);
	}

	sort(counter.begin(),counter.end());
	counter.erase(unique(counter.begin(),counter.end()),counter.end());


	int T;
	string a,b;
	
	cin>>T;
	for (int CASE = 1; CASE <= T; CASE++)
	{
		cin>>a>>b;
		vector<int> A(150,0),B(150,0);

		for (int i = 0; i < a.length(); i++) A[A.size()-1-i]=a[a.length()-1-i]-'0';
		for (int i = 0; i < b.length(); i++) B[B.size()-1-i]=b[b.length()-1-i]-'0';


		int ans=upper_bound(counter.begin(),counter.end(),B)-lower_bound(counter.begin(),counter.end(),A);
		cout<<"Case #"<<CASE<<": "<<ans<<endl;
	}

	return 0;
}