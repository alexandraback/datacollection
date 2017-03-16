#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 0 1 2 3  4  5  6  7
// 1,i,j,k,-1,-i,-j,-k
int table[8][8]={
{0,1,2,3,4,5,6,7},
{1,4,3,6,5,0,7,2},
{2,7,4,1,6,3,0,5},
{3,2,5,4,7,6,1,0},
{4,5,6,7,0,1,2,3},
{5,0,7,2,1,4,3,6},
{6,3,0,5,2,7,4,1},
{7,6,1,0,3,2,5,4}
};

int main()
{
	int t;
	cin >> t;
	for(int ta=1;ta<=t;++ta)
	{
		cout << "Case #" << ta << ": ";
		int l; long long int x;
		cin >> l >> x;
		if(x>16) x=16+(x%4);
		vector<int> s(l*x);
		for(int i=0;i<l;++i)
		{
			char c;
			cin >> c;
			s[i]=c-'i'+1;
		}
		for(int i=l;i<l*x;++i)
			s[i]=s[i-l];
		int pos=0;
		int acum=0;
		bool valid=true;
		while(pos<s.size() && acum!=1)
		{
			acum = table[acum][s[pos]];
			pos++;
		}
		//cout << acum << ' ' << pos << endl;
		if(acum!=1)
			valid=false;
		acum=0;
		while(pos<s.size() && acum!=2)
		{
			acum = table[acum][s[pos]];
			pos++;
		}
		//cout << acum << ' ' << pos << endl;
		if(acum!=2)
			valid=false;
		acum=0;
		while(pos<s.size())
		{
			acum = table[acum][s[pos]];
			pos++;
		}
		//cout << acum << ' ' << pos << endl;
		if(acum!=3)
			valid=false;
		cout << (valid?"YES":"NO") << endl;
	}
}
