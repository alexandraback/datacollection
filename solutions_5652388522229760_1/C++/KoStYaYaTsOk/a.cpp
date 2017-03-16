#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include<string>
#include<algorithm>

using namespace std;

#define mp make_pair
#define pb push_back 
#define fi(n) for(int i = 0; i < n; i++)
#define fj(n) for(int j = 0; j < n; j++)
#define ll long long
#define itt ::iterator it = 

ifstream in;
ofstream out;

int main()
{
	int n;

	in.open("input.in");
	out.open("output.txt");
	in >> n;
	for (int g = 1; g <= n; g++)
	{
		ll x;
		in >> x;
		set <ll> st;
		set<int> dig;
		fi(1000000000000000000)
		{
			ll now = x * i;
			ll answ = now;
			

			while (now > 0)
			{
				dig.insert(now % 10);
				now /= 10;
			}
			if (dig.size() == 10)
			{
				out << "Case #" << g << ": " << answ << endl;
				break;
			}
			else if (st.find(answ) != st.end())
			{
				out << "Case #" << g << ": INSOMNIA" << endl;
				break;
			}
			st.insert(now);
		}
		

	}
	out.close();
	in.close();
	return 0;
}
