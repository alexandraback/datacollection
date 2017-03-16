#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int MAX = 10*1000*1000+1;

ll p[MAX+10];
int head = 0;

inline bool isP(ll a)
{
	string s;
	while(a)
	{
		s += a%10;
		a /= 10;
	}
	for(int i=0; i<(int)s.size(); i++)
		if( s[i] != s[(int)s.size()-1-i] )
			return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	for(int i=1; i<MAX; i++)
		if( isP(i) && isP((ll)i*i) )
			p[head++] = (ll)i*i;
	int t;
	cin >> t;
	for(int tt=0; tt<t; tt++)
	{
		ll a, b;
		cin >> a >> b;
		cout << "Case #" << tt+1 << ": ";
		cout << upper_bound(p,p+head,b) - lower_bound(p,p+head,a) << endl;
	}
	return 0;
}
