#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

using namespace std;

typedef pair<string, string> PSS;
typedef vector<PSS> VPSS;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<string> VS;
typedef set<string> SS;
typedef map<string,int> MSI;

int NUM;
int min_required;
VPII v;

void doit(int pos, int used, VI res)
{
	if (pos == v.size())
	{
		bool done = true;
		for (unsigned i=0; i<res.size(); i++)
			if (res[i] == 0)
			{
				done = false;
				break;
			}
		if (!done)
			return;
		min_required = std::min(min_required, used);
		return;
	}
	doit(pos+1, used, res);
	res[v[pos].first] = 1;
	res[v[pos].second] = 1;
	doit(pos+1, used+1, res);
}

int main()
{
	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		int N;
		cin >> N;
		VPSS vTopic;
		SS sFirst;
		SS sSecond;
		MSI mFirst;
		MSI mSecond;
		v.clear();
		for (int i=0; i<N; i++)
		{
			string first, second;
			cin >> first >> second;
			vTopic.push_back(PSS(first, second));
			sFirst.insert(first);
			sSecond.insert(second);
		}
		NUM = 0;
		for (SS::iterator it=sFirst.begin(); it!=sFirst.end(); ++it)
			mFirst[*it] = NUM++;
		for (SS::iterator it=sSecond.begin(); it!=sSecond.end(); ++it)
			mSecond[*it] = NUM++;
		for (int i=0; i<N; i++)
			v.push_back(PII(mFirst[vTopic[i].first], mSecond[vTopic[i].second]));
		min_required = NUM;
		doit(0, 0, VI(NUM, 0));
		cout << "Case #" << t << ": " << (v.size()- min_required) << endl;
	}
    return 0;
}