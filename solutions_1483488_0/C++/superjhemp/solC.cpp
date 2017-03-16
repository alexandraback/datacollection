#include <iostream>
//#include <vector>
//#include <string>
#include <set>
using namespace std;

int get_digits(int n)
{
	int d(0);
	while (n)
	{
		d++;
		n/=10;
	}
	return d;
}

int get_power(int d)
{
	int n(1);
	for (int i=1; i<d; i++)
		n*=10;
	return n;
}

/*
bool check(int a, int b)
{
	vector<int> cnta(10,0);
	vector<int> cntb(10,0);
	while(a)
	{
		cnta[a%10]++;
		cntb[b%10]++;
		a/=10;
		b/=10;
	}
	for (int i=0; i<10; i++)
		if (cnta[i]!=cntb[i])
			return false;
	return true;
}

bool check2(int a, int b)
{
	string sa(""), sb("");
	while(a)
	{
		sa += a%10 + '0';
		sb += b%10 + '0';
		a/=10;
		b/=10;
	}
	
	bool yes;	
	for (int o=0; o<sa.size(); o++)
	{
		yes = true;
		for (int i=0; i<sa.size(); i++)
			if (sa[i] != sb[(i+o)%sa.size()])
			{
				yes = false;
				break;
			}
		if (yes) return true;
	}
	return false;
}
*/

int main()
{
	int T, A, B, D, P, cnt, e, ee;
	set<int> tested;
	
	cin>>T;
	for (int t=1; t<=T; t++)
	{
		cin>>A>>B;
		D = get_digits(A);
		P = get_power(D);
		cnt = 0;
		for (int i=A; i<=B; i++)
		{
			e = i;
			tested.clear();
			for (int j=1; j<D; j++)
			{
				ee = (e%10)*P + e/10;
				if (tested.find(ee) == tested.end())
				{
					tested.insert(tested.begin(),ee);
					cnt += (ee != e && ee>i && ee>=A && ee<=B);
				}
				e = ee;
			}
		}
		cout<<"Case #"<<t<<": "<<cnt<<endl;
		/*
		cnt = 0;
		for (int i=A; i<=B; i++)
			for (int j=i+1; j<=B; j++)
				cnt += check2(i,j);
		cout<<cnt<<endl;
		*/
	}
	return 0;
}
