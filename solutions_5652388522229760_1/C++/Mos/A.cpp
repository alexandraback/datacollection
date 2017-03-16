#include<iostream>
#include<cstdio>
#include<set>
#include<cstdlib>

using namespace std;

#define FOR(x,N) for(int x = 0 ; x < (N) ; x++ )

int main()
{
	long long T, N;
	char buf[1000000];
	freopen("in2.in", "rt", stdin);
	freopen("out", "wt", stdout);
		
	cin >> T;
	string s;
	set<int> num;
	FOR(i,T)
	{
		cin >> N;
		if (N == 0){
			cout << "Case #" << i + 1 << ": " << "INSOMNIA" << endl;
			continue;
		}
		int k=0;
		num.clear();
		while (1)
		{
			k++;
			long long temp = N*k;
			if (temp < 0)
			{
				cout <<"Case #"<<i+1<<": "<<"INSOMNIA" << endl;
				break;
			}
			itoa(temp, buf, 10);
			s = buf;
			FOR(j, s.length())
			{
				num.insert(buf[j]);
			}
			if (num.size() == 10)
			{
				cout << "Case #" << i + 1 << ": " << temp << endl;
				break;
			}
		}
	}
}