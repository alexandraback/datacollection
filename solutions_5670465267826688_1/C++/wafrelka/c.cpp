#include <cstdio>
#include <vector>
using namespace std;

typedef long long int int64;

char calc(char l, char r)
{
	const int table[] =
		{
			1, 2, 3, 4,
			2, -1, 4, -3,
			3, -4, -1, 2,
			4, 3, -2, -1
		};

	const int lsig = 1 - (l < 0) * 2;
	const int rsig = 1 - (r < 0) * 2;
	const int sig = lsig * rsig;
	const int val = table[(l * lsig - 1) * 4 + (r * rsig - 1)] * sig;
	return val;
}

int main()
{
	int test_case;

	scanf("%d", &test_case);

	for(int case_num = 1; case_num <= test_case; ++case_num) {

		const int max_l = 10200;
		int l;
		int64 x;
		char s_temp[max_l];
		vector<char> s;

		scanf("%d%lld%s", &l, &x, s_temp);
		s.resize(l);
		for(int i = 0; i < l; ++i) {
			char c = s_temp[i];
			s[i] = 10000;
			if(c == 'i') s[i] = 2;
			if(c == 'j') s[i] = 3;
			if(c == 'k') s[i] = 4;
		}

		if(x >= 12)
			x = 8 + (x % 4);

		bool ok = false;

		vector<char> red, revred;

		red.resize(l * x);
		revred.resize(l * x);

		red[0] = s[0];
		for(int i = 1; i < l * x; ++i)
			red[i] = calc(red[i - 1], s[i % l]);
		revred[l * x - 1] = s[l - 1];
		for(int i = l * x - 2; i >= 0; --i)
			revred[i] = calc(s[i % l], revred[i + 1]);


		if(red[l * x - 1] == calc(2, calc(3, 4))) {

			int iit = 0, kit = l * x - 1;
			while(red[iit] != 2 && iit < l * x)
				iit += 1;
			while(revred[kit] != 4 && kit >= 0)
				kit -= 1;

			if(iit < kit)
				ok = true;
		}

		printf("Case #%d: %s\n", case_num, ok ? "YES" : "NO");
	}

	return 0;
}
