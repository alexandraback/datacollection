#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <numeric>

using namespace std;

typedef long long	LL;

#define	rep(i, n)	for(int i = 0 ; i < (n) ; ++i)

inline bool vowel(const char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

LL C(int n)
{
	if(n < 2)
		return 0;
	return ((LL)n) * (n - 1) / 2;
}

LL solve()
{
	string	str;
	int		n;

	cin >> str >> n;

	vector<int>		count;
	int		index = 0;
	while(index < str.size()) {
		int		num = 0;
		while(index < str.size() && vowel(str[index])) {
			++index;
			++num;
		}
		count.push_back(num);
		num = 0;
		while(index < str.size() && !vowel(str[index])) {
			++index;
			++num;
		}
		count.push_back(num);
	}
	deque<int>		account;
	account.push_front(0);
	rep(i, count.size()) {
		int		a = account.front();
		account.push_front(a + count[count.size() - i - 1]);
	}

	vector<LL>		ans;
	int		start = 0;
	LL		head = 0;
	while(start < count.size()) {
		int		send = start + 1;
		head += count[start];
		while(send < count.size() && count[send] < n) {
			head += count[send] + count[send+1];
			send += 2;
		}
		if(send >= count.size())
			break;
		ans.push_back((head + 1) * (count[send] - n + account[send+1] + 1) + ((LL)(count[send] - n)) * (account[send+1] + 1) + C(count[send] - n));
		start = send + 1;
		head = n - 1;
	}

	return accumulate(ans.begin(), ans.end(), (LL)0);
}

int main()
{
	int		T;
	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}

