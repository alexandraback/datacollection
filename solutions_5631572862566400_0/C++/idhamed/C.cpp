#include <bits/stdc++.h>

#define ll long long
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef pair < ll , ll > pie;
int bff[10];
int bb[10];
int ishappy[10];
int ffff;
int fact(int a)
{
	if(a <= 1)
		return 1;
	return a*fact(a-1);
}
int thing()
{
	int jj=fact(ffff);
	int res = 3,tres =0;
	for(int q = 0; q<jj;q++)
	{
		tres = 0;
		for(int ii =3; ii <= ffff;ii++)
		{
			bool happy = true;
			int next,perv;
			if(ii > res)
				for(int i = 0; i < ii; i++)
				{
					next = (i+1)%ii;
					perv = (i+ii-1)%ii;
					if(bff[bb[i]]!=bb[next]&&bff[bb[i]]!=bb[perv])
						happy = false;
				}
			if(ii > res && happy)
				res = ii;
		}
		next_permutation(bb,bb+ffff);
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int k = 1; k <= T; k++)
	{
		int N;
		cin >> N;
		for(int i = 0; i < N; i++)
		{
			cin >> bff[i];
			bff[i]--;
		}
		ffff = N;
		for(int i = 0; i< N ;i++)
			bb[i] = i;
		int tres , res = 0;
		res = thing();
		cout<<"Case #"<<k<<":"<<" "<<res<<endl;
	}
	return 0;
}