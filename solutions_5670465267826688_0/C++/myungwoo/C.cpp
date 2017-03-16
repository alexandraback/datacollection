#include <bits/stdc++.h>
using namespace std;

#define MAXL 10004
typedef long long lld;

int T, L; lld X;
char A[MAXL*4];
string table[128][128];

string multiply(const string &a, const string &b)
{
	bool neg = 0;
	string ret;
	char p, q, r;
	if (a[0] == '-') neg ^= 1, p = a[1];
	else p = a[0];
	if (b[0] == '-') neg ^= 1, q = b[1];
	else q = b[0];
	string &s = table[p][q];
	if (s[0] == '-') neg ^= 1, r = s[1];
	else r = s[0];
	if (neg) ret.push_back('-');
	ret.push_back(r);
	return ret;
}

int main()
{
	table['1']['1'] = "1";
	table['1']['i'] = "i";
	table['1']['j'] = "j";
	table['1']['k'] = "k";
	table['i']['1'] = "i";
	table['i']['i'] = "-1";
	table['i']['j'] = 'k';
	table['i']['k'] = "-j";
	table['j']['1'] = "j";
	table['j']['i'] = "-k";
	table['j']['j'] = "-1";
	table['j']['k'] = "i";
	table['k']['1'] = "k";
	table['k']['i'] = "j";
	table['k']['j'] = "-i";
	table['k']['k'] = "-1";
	int ts = 0;
	for (scanf("%d", &T);T--;){
		printf("Case #%d: ", ++ts);
		scanf("%d%lld%s", &L, &X, A+1);
		for (int i=1;i<=L;i++) A[i+L+L+L] = A[i+L+L] = A[i+L] = A[i]; A[L*4+1] = 0;
		lld left = X*L + 1, right = 0;
		{
			string tmp = "1";
			for (int i=1;i<=L*4;i++){
				tmp = multiply(tmp, string(1, A[i]));
				if (tmp == "i"){ left = i; break; }
			}
		}
		{
			string tmp = "1";
			for (int i=L*4;i>0;i--){
				tmp = multiply(string(1, A[i]), tmp);
				if (tmp == "k"){ right = X*L-(L*4-i); break; }
			}
		}
		left++, right--;
		if (left > right){ puts("NO"); continue; }
		string res = "1";
		lld right_num = (right - 1) / L +1;
		lld left_num = (left - 1) / L + 1;
		int lp = (left - 1) % L + 1;
		int rp = (right - 1) % L + 1;
		if (left_num == right_num){
			for (int i=1;i<=L;i++){
				if (i >= lp && i <= rp) res = multiply(res, string(1, A[i]));
			}
		}else{
			string left_v = "1", right_v = "1";
			for (int i=1;i<=L;i++)
				if (i >= lp) left_v = multiply(left_v, string(1, A[i]));
			for (int i=L;i;i--)
				if (i <= rp) right_v = multiply(string(1, A[i]), right_v);
			int inside_cnt = (right_num-left_num-1)%4;
			res = left_v;
			for (int i=1;i<=inside_cnt*L;i++)
				res = multiply(res, string(1, A[i]));
			res = multiply(res, right_v);
		}
		puts(res == "j" ? "YES" : "NO");
	}
}
