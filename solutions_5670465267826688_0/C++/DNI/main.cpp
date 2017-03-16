#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>


using namespace std;


enum qutquat
{
	qutquat_l = 0,
	qutquat_i,
	qutquat_j,
	qutquat_k

};

enum sign
{
	sign_plus,
	sign_minus
};

struct qutquat_s
{
	qutquat q;
	sign	s;	
};

qutquat_s matr_appl[4][4] = 
{
	{ {qutquat_l, sign_plus},	{qutquat_i, sign_plus},		{qutquat_j, sign_plus},		{qutquat_k, sign_plus}	},
	{ {qutquat_i, sign_plus},	{qutquat_l, sign_minus},	{qutquat_k, sign_plus},		{qutquat_j, sign_minus} },
	{ {qutquat_j, sign_plus},	{qutquat_k, sign_minus},	{qutquat_l, sign_minus},	{qutquat_i, sign_plus}	},
	{ {qutquat_k, sign_plus},	{qutquat_j, sign_plus},		{qutquat_i, sign_minus},	{qutquat_l, sign_minus} }
};


sign GetDiffSign(sign s)
{
	if(s == sign_plus)
		return sign_minus;
	return sign_plus;
}

qutquat_s Apply(qutquat_s A, qutquat_s B)
{
	qutquat_s res = matr_appl[A.q][B.q];
	if(A.s != B.s)
	{
		res.s = GetDiffSign(res.s);
	}
	return res;
}

int main()
{

	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int t;
	cin >> t;
	for(int tt = 0; tt < t; tt++)
	{

		int l, x;
		cin >> l >> x;
		string s;
		cin >> s;
		string t = s;

		for(int i = 1; i < x; i++)
		{
			s += t;
		}
		
		vector<qutquat_s> vq(s.size());
		qutquat_s temp = {qutquat_l, sign_plus};
		for(int i = 0; i < s.size(); i++)
		{
			switch (s[i])
			{
				case('i'): temp.q = qutquat_i; break;
				case('j'): temp.q = qutquat_j; break;
				case('k'): temp.q = qutquat_k; break;
			}
			vq.push_back(temp);
		}

		int nextfunded = qutquat_i;
		qutquat_s cur = {qutquat_l, sign_plus};
		for(int i = 0; ; i++)
		{
			if(cur.q == nextfunded)
			{
				cur.q = qutquat_l;
				nextfunded++;
			}

			if(i >= vq.size())
			{
				break;
			}

			cur = Apply(cur, vq[i]);
		}

		string sRes = "NO";
		if(nextfunded == (qutquat_k + 1) && cur.q == qutquat_l && cur.s == sign_plus)
		{
			sRes = "YES";
		}
		printf("Case #%d: %s\n", tt+1, sRes.c_str());
		
	}


	return 0;
}