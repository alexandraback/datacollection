#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <algorithm> 
#include <cassert> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
#include <vector> 
#include <map> 
#include <set> 
#include <stack> 
#include <iomanip> 
#include <queue> 

#define pb push_back 
#define mp make_pair 
#define ll long long 
#define abracadabra next 
#define pii pair<int, int> 

using namespace std; 

char s[16];

bool is_01(long long n)
{
	
	sprintf(s, "%lld", n);
	for(int i = (strlen(s)) / 2; s[i + 1]; i++)
	{
		if (s[i] != '0')
			return false;
	}
	return s[strlen(s) - 1] == '1';
}

bool is_101(long long n)
{
	sprintf(s, "%lld", n);
	for(int i = 1; s[i] && s[i + 1]; i++)
	{
		if (s[i] != '0')
			return false;
	}
	return s[0] == '1' &&  s[strlen(s) - 1] == '1';
}

void reverse(long long & n)
{
		sprintf(s, "%lld", n);
		reverse(s, s + strlen(s));
		n = atoi(s);
}

int main(){ 
	ios_base::sync_with_stdio(false); 
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++)
	{
	long long n;
	int ans = 1;
	cin >> n;
	while (n > 1)
	{
		if (is_01(n) && !is_101(n))
		{
			reverse(n);
			ans++;
		} else {
			n--;
			ans++;
		}
	}
	cout << "Case #" << test << ": " << ans << endl;
	}
	
	
	return 0; 
} 
