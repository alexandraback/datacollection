#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

//*******************
//*******************

int t[500];

void read() {
	string s; cin>>s;
	for(int i=0; i<100; i++)
		t[i]=0;

	for(int i=0; i<s.size(); i++)
		t[s[i]-'A']++;

	vector<int> v;

	//ZERO -> Z
	int k;

	k=t['Z'-'A'];
	if(k>0)
	{
		for(int i=0; i<k; i++)
			v.push_back(0);
		t['Z'-'A'] -= k;
		t['E'-'A'] -= k;
		t['R'-'A'] -= k;
		t['O'-'A'] -= k;
			
	}

	k = t['X'-'A'];
	if(k>0)
	{
		for(int i=0; i<k; i++)
			v.push_back(6);
		t['S'-'A'] -= k;
		t['I'-'A'] -= k;
		t['X'-'A'] -= k;
		
	}

	k = t['S'-'A'];
	if(k>0)
	{
		for(int i=0; i<k; i++)
			v.push_back(7);
		t['S'-'A'] -= k;
		t['E'-'A'] -= k;
		t['V'-'A'] -= k;
		t['E'-'A'] -= k;
		t['N'-'A'] -= k;

	}

	k = t['V'-'A'];
	if(k>0)
	{
		for(int i=0; i<k; i++)
			v.push_back(5);
		t['F'-'A'] -= k;
		t['I'-'A'] -= k;
		t['V'-'A'] -= k;
		t['E'-'A'] -= k;
	}

	k = t['F'-'A'];
	if(k>0)
	{
		for(int i=0; i<k; i++)
			v.push_back(4);
		t['F'-'A'] -= k;
		t['O'-'A'] -= k;
		t['U'-'A'] -= k;
		t['R'-'A'] -= k;
	}

	k = t['G'-'A'];
	if(k>0)
	{
		for(int i=0; i<k; i++)
			v.push_back(8);
		t['E'-'A'] -= k;
		t['I'-'A'] -= k;
		t['G'-'A'] -= k;
		t['H'-'A'] -= k;
		t['T'-'A'] -= k;
	}


	k = t['I'-'A'];
	if(k>0)
	{
		for(int i=0; i<k; i++)
			v.push_back(9);
		t['N'-'A'] -= k;
		t['I'-'A'] -= k;
		t['N'-'A'] -= k;
		t['E'-'A'] -= k;

	}

	k = t['H'-'A'];
	if(k>0)
	{
		for(int i=0; i<k; i++)
			v.push_back(3);
		t['T'-'A'] -= k;
		t['H'-'A'] -= k;
		t['R'-'A'] -= k;
		t['E'-'A'] -= k;
		t['E'-'A'] -= k;

	}


	k = t['T'-'A'];
	if(k>0)
	{
		for(int i=0; i<k; i++)
			v.push_back(2);
		t['T'-'A'] -= k;
		t['W'-'A'] -= k;
		t['O'-'A'] -= k;
	}


	k = t['N'-'A'];
	if(k>0)
	{
		for(int i=0; i<k; i++)
			v.push_back(1);
	}


	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++)
		cout<<v[i];
	cout<<endl;

}

void solve() {

}

void clean() {
}

int main() {
	ios::sync_with_stdio(false);
	int z;
	cin >> z;
	for(int zz=1; zz<=z; zz++)
	{

	cout<<"Case #"<<zz<<": ";
		read();
		solve();
		clean();
	}
  return 0;
}