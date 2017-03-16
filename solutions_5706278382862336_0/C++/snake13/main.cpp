#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>
#include <math.h>
#include <map>
#include <string>
#include <deque>
#define LL long long int
#define double long double
using namespace std;

LL gcd (LL a, LL b)
{
	while (b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}

void solve (int t)
{
	LL a=0,b=0,del=1,i;
	string s;
	cin>>s;
	for (i=0; i<s.size(); i++)
		if (s[i]=='/')
			break;
	int pos = i;
	for (i=pos-1; i>=0; i--)
	{
		a+=1ll*(s[i]-'0')*del;
		del=1ll*del*10;
	}
	del = 1;
	for (i=s.size()-1; i>=pos+1; i--)
	{
		b+=1ll*(s[i]-'0')*del;
		del=1ll*del*10;
	}
	
	cout<<"Case #"<<t<<": ";
	vector <LL> st(41);
	st[0] = 1;
	for (i=1; i<=40; i++) st[i] = 1ll*st[i-1]*2;
	//for (i=1; i<40; i++) cout<<st[i]<<" "; cout<<endl;
	int kol = 0;
	while (1ll*2*a<b)
	{
		a = 1ll*2*a;
		kol++;
	}
	LL g = gcd(a,b);
	a/=g; b/=g;
	for (i=1; i<40; i++)
	{
		if (st[i]%b == 0)
		{
			if (((st[i]/b)*a)%2)
			{
				cout<<kol+1<<endl;
				return;
			}
		}
	}
	cout<<"impossible"<<endl;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin); freopen("output.txt", "w", stdout);
    int i,t;
	cin>>t;
	for (i=1; i<=t; i++)
		solve(i);
    return 0;
}