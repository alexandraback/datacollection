#include <vector>
#include <iostream>
#include <algorithm>

typedef long long int ll;
typedef long double ld;

#define pb push_back
#define for0(a,b) for(int a = 0; a < b; a++)


using namespace std;

int main()
{
	int T;
	cin >> T;
	for0(t,T)
	{
		//cerr << t << endl;
		ll N, A;
		cin >> A >> N;
		vector<int> v1;
		for0(n,N)
		{
			int tmp;
			cin >> tmp;
			v1.pb(tmp);
		}
		sort(v1.begin(), v1.end(), greater<int>() );
		ll count=0, best=1<<30;
		//cerr << "***" << endl;
		while(!v1.empty())
		{
			//cerr << A << " " << v1.front() << endl;
			if (A == 1)
			{
				best = count = v1.size();
				break;
			}	
			if (v1.back() < A)
			{
				A += v1.back();
				v1.pop_back();
			}
			else
			{
				best = min(best, (ll) (count + v1.size()));
				count++;
				v1.push_back(A-1);
			}
		}
		cout << "Case #" << t +1 << ": " << min(count,best) << endl;
	}
}
