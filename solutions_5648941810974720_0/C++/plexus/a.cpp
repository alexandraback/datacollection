#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 111;

int used[N];
int a[N][N];
int cnt[N];
int f[N];
int p[N];
vector<string> v = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int count(char c, string s)
{
	int ans = 0;
	for (auto e : s)
		ans += (e == c); 
	return ans;
}


bool canAppear(char c, int cnt[N], string s)
{
	if (cnt[c - 'A'] == 0 || count(c, s) == 0)
		return false;
	for (char c = 'A'; c <= 'Z'; c++)
	{
		if (cnt[c - 'A'] < count(c, s))
			return false;
	}
	return true;
}

string solve(string s)
{
	fill(f, f + N, 0);
	fill(p, p + N, 0);
	fill(used, used +  N, 0);
	fill(cnt, cnt + N, 0);

	priority_queue<char> pq;

	for (auto c : s)
		cnt[c - 'A']++;

	for (char c = 'A'; c <= 'Z'; c++)
	{
		int l = 0;
		for (auto e : v)
			if (canAppear(c, cnt, e))
				l++;
		if (l == 1)
			pq.push(c);
	}

	string res;

	while (true)
	{
		char c = 'a';
		for (char i = 'A'; i <= 'Z'; i++)
		{
			int l = 0;
			for (auto e : v)
				if (canAppear(i, cnt, e))
					l++;
			if (l == 1)
				c = i;
		}
		if (c == 'a')
			break;

		//for (int i = 0; i < 26; i++)
			//cout << char(i + 'A') << cnt[i] << " ";
		//cout << endl;

		int cur = -1;
		for (int i = 0; i < 10; i++)
		{
			if (canAppear(c, cnt, v[i]))
				cur = i;
		}

		assert(cur != -1);

		p[cur] = 1;
		int amnt = cnt[c - 'A'] / count(c, v[cur]);
		res += string(amnt, char(cur + '0'));
		//cout << "Cur is " << cur << endl;

		for (char c = 'A'; c <= 'Z'; c++)
			cnt[c - 'A'] -= count(c, v[cur]) * amnt;

	}

	for (int i = 0; i < 26; i++)
		assert(cnt[i] == 0);

	//for (int i = 0; i < 26; i++)
		//cout << char(i + 'A') << cnt[i] << " ";
	//cout << endl;

	sort(res.begin(), res.end());

	return res;
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("out", "w", stdout);

	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		string s;	
		cin >> s;
		cout << "Case #" << i + 1 << ": " << flush; 
		cout << solve(s) << endl;
	}
	
	fflush(stdin);		
	fprintf(stderr, "\n\n Execution time: %.4fs", double(clock()) / CLOCKS_PER_SEC);
	return 0;
}

