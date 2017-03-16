#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>


using namespace std;

string s1, s2;


int din[200][200];

void func()
{
	if(s1.size() < s2.size())
		swap(s2, s1);

}


string clean(const string & s)
{
	string r;
	if(s.size())
		r.push_back(s[0]);
	for(int i = 1; i < s.size(); i++)
		if(r.back() != s[i])
			r.push_back(s[i]);
	return r;
}


vector<int> get_num(const string & s)
{


	string r;
	if(s.size())
		r.push_back(s[0]);

	vector<int> ret;
	if(s.size())
	ret.push_back(1);


	for(int i = 1; i < s.size(); i++)
	{
		if(r.back() != s[i])
		{
			ret.push_back(1);
			r.push_back(s[i]);
		}
		else
		{
			ret.back()++;
		}
	}

	return ret;
}



int main()
{

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int tt;
	cin >> tt;
	for(int t = 1; t <= tt; t++)
	{
		int n;
		cin >> n;
	

		vector<string> vs(n);
		for(int i = 0; i < n; i++)
		{
			cin >> vs[i];
		}

		bool bOk = true;
		string s1 = clean(vs[0]);
		for(int i  =0; i< n; i++)
		{
			if(s1 != clean(vs[i]))
			{
				bOk = false;
				break;
			}
		}
		if(!bOk)
		{
			printf("Case #%d: Fegla Won\n", t);
			continue;
		}


		vector<vector<int> > tr(n);
		for(int i = 0; i < n; i++)
		{
			tr[i] = get_num(vs[i]);
		}


		long long res = 0;

		for(int  i = 0; i < tr[0].size(); i++)
		{

			int m = 1000 * 1000 * 1000;
			for(int k = 0; k <= 100; k++)
			{
				int tm = 0;
				for(int j = 0; j < n; j++)
				{
					tm += abs(k - tr[j][i]);
				}
				m = min(tm, m);
			}
			res += m;
		}

		printf("Case #%d: %d\n", t, res);
	}

	return 0;
}