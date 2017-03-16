/*
user  : triveni
date  : 11/05/2014
time  : 14:32:57
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      mp(a,b)           std::make_pair(a,b)
#define      X                 first
#define      Y                 second

typedef long long ll;
ll MOD = 1000000007;

bool is_valid(string& str){
	// cout << str << endl;
	int l = str.length();
	int tmp[26];
	memset(tmp,false,sizeof(tmp));
	tmp[str[0]-'a'] = true;
	for(int i=1;i<l;++i)
	{
		if(str[i] == str[i-1]) continue;
		if(tmp[str[i]-'a']) return false;
		tmp[str[i]-'a'] = true;
	}
	return true;
}
void solve()
{
	string A[100];
	int N, Ar[100];
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>A[i];
		Ar[i]=i;
	}
	ll ct = 0;
	string st;
	for(int i=0;i<N;++i)
	{
		st = st + A[i];
	}
	if(is_valid(st)) ct++;

	while(next_permutation(Ar,Ar+N))
	{
		string str = "";
		for(int i=0;i<N;++i)
		{
			str = str + A[Ar[i]];
		}
		if(is_valid(str)) ct++;
	}
	cout << ct  << endl;
}

int main()
{
	// while(1)
	// {
	// 	string s;
	// 	cin>>s;
	// 	cout << is_valid(s) << endl;
	// }
	int T;
	cin>>T;
	for(int i=1;i<=T;++i)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}