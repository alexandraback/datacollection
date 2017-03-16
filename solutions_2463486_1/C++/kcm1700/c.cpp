#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

string current;
vector<string> all;

int digits[128];
void checkraw(string raw)
{
	memset(digits,0,sizeof(digits));
	int len = raw.size();
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len; j++){
			digits[i+j] += (raw[i]-'0') * (raw[j]-'0');
		}
	}
	for(int i = 0; i < len*2-1; i++) {
		if (digits[i] >= 10) return;
		if (digits[i] != digits[len*2-2-i]) return;
	}
	string final;
	for(int i = 0; i < len*2-1; i++) {
		final.push_back('0' + digits[i]);
	}
	all.push_back(final);
}
void rec(int pos, int l2cnt, int l1cnt)
{
	{
		string rev(current.size(),'0');
		reverse_copy(current.begin(), current.end(), rev.begin());
		if (pos != 0) checkraw(current + rev);
		if (pos != 0) checkraw(current + "0" + rev);
		checkraw(current + "1" + rev);
		if (l2cnt >= 1) checkraw(current + "2" + rev);
		if (pos == 0) checkraw(current + "3" + rev);
	}
	// do something
	if (pos >= 25) return;
	if (l2cnt >= 1) {
		current.push_back('2');
		rec(pos + 1, l2cnt - 1, l1cnt);
		current.pop_back();
	}
	if (l1cnt >= 1) {
		current.push_back('1');
		rec(pos + 1, l2cnt, l1cnt-1);
		current.pop_back();
	}
	if (pos != 0)
	{
		current.push_back('0');
		rec(pos + 1, l2cnt, l1cnt);
		current.pop_back();
	}
}

void precalc()
{
	rec(0, 1, 4);
}

bool sf(const string &a, const string &b) {
	if (a.length() != b.length()) return a.length() < b.length();
	return a < b;
}

int main()
{
	precalc();
	fprintf(stderr, "Precalc finished total %d\n", (int)all.size());
	sort(all.begin(),all.end(),sf);
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		char start[128];
		char end[128];
		scanf("%s%s",start,end);
		int lpos = lower_bound(all.begin(),all.end(),start,sf) - all.begin();
		int upos = upper_bound(all.begin(),all.end(),end,sf) - all.begin();
		printf("Case #%d: %d\n", testcase, upos - lpos);
	}
	return 0;
}
