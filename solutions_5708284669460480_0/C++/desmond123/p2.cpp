#include<bits/stdc++.h>

using namespace std;

#define LL long long int
#define ULL unsigned long long
#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define vi vector<int> 
#define pii pair<int,int> 
#define F first
#define S second
#define D double
#define LD long double

int total = 0;
int countMaxBanana(string key, string word, int s)
{
	if(s < word.size())
		return 0;
	for(int i=0; i < word.size(); i++)
	{
		bool flag = false;
		for(int j = 0; j < key.size(); j++)
		{
			if(word[i] == key[j])
			{
				flag = true;
				break;
			}
		}
		if(!flag)
			return 0;
	}

	int e = word.size();
	for(int j = 1; j < word.size(); j++)
	{
		int sz = word.size() - j;
		if(word.substr(0, sz) == word.substr(j, sz))
		{
			e = j;
			break;
		}
	}
	s -= word.size();
	int c = 1 + s/e;
	return c;
}

void typeCharacters(string key, string word, int s, string curr)
{
	// cout << s <<endl;
	if(s == 0)
	{
		for(int i = 0; i < curr.size() - word.size() + 1; i++)
			if(word == curr.substr(i, word.size()))
				total++;
		// cout << curr <<" "<<total<< endl;
		return;
	}
	for(int i = 0; i < key.size(); i++)
	{
		curr.push_back(key[i]);
		typeCharacters(key, word, s-1, curr);
		curr.pop_back();
	}
}
inline void solve()
{
	int k,l,s;
	cin >> k >> l >> s;
	// cout << k << l << s << endl;
	total = 0;
	string key, word;
	cin >> key >> word;
	// cout << key <<" "<< word<<endl;
	int c = countMaxBanana(key, word, s);
	// cout << c << endl;
	if(c == 0)
	{
		printf("%.6f\n", 0.0);
		return;
	}
	typeCharacters(key, word, s, "");
	double p = total;
	for(int i = 0; i < s; i++)
		p /= key.size();
	// cout << total << " " << p << endl;
	printf("%.6lf\n",c - p);

}

int main()
{
	int t, i;
	sd(t);
	for(i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		solve();
	}
    return 0;
}