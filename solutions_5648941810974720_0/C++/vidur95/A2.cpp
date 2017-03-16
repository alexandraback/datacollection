#include <bits/stdc++.h>
using namespace std;
//@author Vidur Katyal
#define endl '\n'
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef vector <int> vi;
typedef vector < pii > vpii;
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define FAST1 ios_base::sync_with_stdio(0)
#define FAST2 cin.tie(0);cout.tie(0); cerr.tie(0)
const long double PI = acos(-1.0);
const long double EPS = 1e-9;
const LL MOD = 1000000007;
const LL MAXN = 100010;

int main()
{
	FAST1;
	FAST2;
	int T;
	cin>>T;
	map <int, string> MAP = {{0, "ZERO"}, {1, "ONE"}, {2, "TWO"}, {3, "THREE"}, {4, "FOUR"},
							{5, "FIVE"}, {6, "SIX"}, {7, "SEVEN"}, {8, "EIGHT"}, {9, "NINE"}
							};
	for (int t = 1; t <= T; ++t)
	{
		string s;
		string res = "";
		cin>>s;
		int arr[10] = {0};
		for (int i = 0; i < s.length(); ++i)
		{
			if(s[i] == 'Z')
				++arr[0];
			if(s[i] == 'W')
				++arr[2];
			if(s[i] == 'U')
				++arr[4];
			if(s[i] == 'X')
				++arr[6];
			if(s[i] == 'G')
				++arr[8];
		}
		int four = arr[4], four2 = arr[4], eight = arr[8], eight2 = arr[8];
		int zero = arr[0], two = arr[2], six = arr[6], six2 = arr[6];
		for(int i = 0; i < s.length(); ++i)
		{
			if(s[i] == 'F')
			{
				if(four)
					--four;
				else
					++arr[5];
			}
			if(s[i] == 'S')
			{
				if(six)
					--six;
				else
					++arr[7];
			}
			if(s[i] == 'H')
			{
				if(eight)
					--eight;
				else
					++arr[3];
			}
		}
		int five = arr[5], seven = arr[7], three = arr[3];
		for(int i = 0; i < s.length(); ++i)
		{
			if(s[i] == 'I')
			{
				if(five)
					--five;
				else if(six2)
					--six2;
				else if(eight2)
					--eight2;
				else
					++arr[9];
			}
			if(s[i] == 'O')
			{
				if(four2)
					--four2;
				else if(two)
					--two;
				else if(zero)
					--zero;
				else
					++arr[1];
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			while(arr[i]--)
				res += i+48;
		}

		cout<<"Case #"<<t<<": "<<res<<endl;
	}
	return 0;
}