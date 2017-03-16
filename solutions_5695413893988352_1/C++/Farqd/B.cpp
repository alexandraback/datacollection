#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long
//*******************
//*******************


int MIN_WYN;
string s_min;
string t_min;

void f(string& s, string& t, int k, int x)
{

	if(k == s.size()){
		// cout<<s<<" "<<t<<endl;

		int X = abs(stol(s) - stol(t));

		if(X < MIN_WYN)
		{
			MIN_WYN = X;
			s_min = s;
			t_min = t;
		} else if(X == MIN_WYN){
			if(s < s_min || (s == s_min && t < t_min))
			{
				s_min = s;
				t_min = t;
			}
		}

		return;
	}
	if(s[k] != '?' && t[k] != '?')
	{
		if(x != 0 || s[k] == t[k])
			return f(s, t, k+1, x);
		if(s[k] < t[k])
			return f(s, t, k+1, -1);
		return f(s, t, k+1, 1);
	}

	if(x == 0){
		if(s[k] == '?' && t[k] == '?')
		{
			s[k] = '0';
			t[k] = '0';
			f(s, t, k+1, 0);

			s[k] = '0';
			t[k] = '1';
			f(s, t, k+1, -1);


			s[k] = '1';
			t[k] = '0';
			f(s, t, k+1, 1);

			s[k] = '?';
			t[k] = '?';
			return;
		}
		if(s[k] == '?')
		{
			s[k] = t[k];
			f(s, t, k+1, 0);

			s[k] = t[k]-1;
			if(t[k] != '0')
				 f(s, t, k+1, -1);


			s[k] = t[k] + 1;
			if(t[k] != '9')
				f(s, t, k+1, 1);


			s[k] = '?';
			return;
		}
		else{
			t[k] = s[k];
			f(s, t, k+1, 0);
			 
			t[k] = s[k]-1;
			if(s[k] != '0')
				 f(s, t, k+1, 1);


			t[k] = s[k] + 1;
			if(s[k] != '9')
				f(s, t, k+1, -1);


			t[k] = '?';
			return;
		}
	}

bool b1 = false,b2 = false;
	if(x < 0) // s < t
	{

		if(s[k] == '?'){
			s[k] = '9'; b1=1;
		}
		if(t[k] == '?'){
			t[k] = '0'; b2=1;
		}
		f(s, t, k+1, x);

		if(b1)
			s[k] = '?';
		if(b2)
			t[k] = '?';
		
		return;
	}
	if(x > 0)
	{
		if(s[k] == '?'){
			s[k] = '0'; b1 = 1;
		}
		if(t[k] == '?'){
			t[k] = '9'; b2 = 1;
		}
		f(s, t, k+1, x);

		if(b1)
			s[k] = '?';
		if(b2)
			t[k] = '?';

		return;
	}
}

void read() {

MIN_WYN = 1000000000000000000;

	string s; cin>>s;
	string t; cin>>t;

	f(s, t, 0, 0);
	cout<<s_min<< " "<<t_min<<endl;


}

void solve() {

}

void clean() {
}

main() {
	ios::sync_with_stdio(false);
	int z;
	cin >> z;
	for(int zz=1; zz<=z; zz++)
	{

	cout<<"Case #"<<zz<<": ";
		read();
		solve();
		clean();
	}
  return 0;
}