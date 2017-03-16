#include<iostream>

using namespace std;

const int MAXN = 10005, MAXC = 300;
int pro[MAXC][MAXC], sign[MAXC][MAXC];

int main()
{
	pro['i']['i'] = '1', sign['i']['i'] = -1;
	pro['j']['j'] = '1', sign['j']['j'] = -1;
	pro['k']['k'] = '1', sign['k']['k'] = -1;
	pro['i']['j'] = 'k', sign['i']['j'] = 1;
	pro['i']['k'] = 'j', sign['i']['k'] = -1;
	pro['j']['k'] = 'i', sign['j']['k'] = 1;
	pro['j']['i'] = 'k', sign['j']['i'] = -1;
	pro['k']['i'] = 'j', sign['k']['i'] = 1;
	pro['k']['j'] = 'i', sign['k']['j'] = -1;
	pro['1']['1'] = '1', sign['1']['1'] = 1;
	pro['1']['i'] = 'i', sign['1']['i'] = 1;
	pro['1']['j'] = 'j', sign['1']['j'] = 1;
	pro['1']['k'] = 'k', sign['1']['k'] = 1;
	pro['i']['1'] = 'i', sign['i']['1'] = 1;
	pro['j']['1'] = 'j', sign['j']['1'] = 1;
	pro['k']['1'] = 'k', sign['k']['1'] = 1;
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++)
	{
		int l, x;
		cin >> l >> x;
		string s, inp;
		cin >> inp;
		for(int i = 0; i < x; i++)
			s += inp;
		int n = l * x;
		cout << "Case #" << tt << ": ";
		char a = '1';
		int b = 1;
		for(int i = 0; i < n; i++)
		{
			b = sign[a][s[i]] * b;
			a = pro[a][s[i]];
		}
		if(a != '1' || b != -1)
		{
			cout << "NO" << endl;
			continue;
		}
		int in = -1;
		a = '1', b = 1;
		for(int i = 0; i < n; i++)
		{
			b = sign[a][s[i]] * b;
			a = pro[a][s[i]];
			if(a == 'i' && b == 1)
			{
				in = i;
				break;
			}
		}
		if(in == -1)
		{
			cout << "NO" << endl;
			continue;
		}
		bool flag = false;
		a = '1', b = 1;
		for(int i = 0; i < n; i++)
		{
		   	b = sign[a][s[i]] * b;
			a = pro[a][s[i]];
			if(a == 'k' && b == 1 && i > in)
			{
				cout << "YES" << endl;
				flag = true;
				break;
			}
		}
		if(!flag)
			cout << "NO" << endl;
	}
	return 0;
}
