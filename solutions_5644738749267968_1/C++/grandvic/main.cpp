#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
 
using namespace std;

int calcFair(const vector<double> & a, const vector<double> & b)
{
	int i1=0, i2=0, n=(int)a.size();
	while(i2<n)
	{
		if(a[i1]<b[i2])++i1, ++i2;
		else ++i2;
	}
	return n-i1;
}

int calcUnfair(const vector<double> & a, const vector<double> & b)
{
	int n=(int)a.size(), cnt=0;
	for(int i=0, j=0; i<n; ++i)
	{
		if(a[i]>b[j])
			++cnt, ++j;
	}
	return cnt;
}

void solve()
{
	int n; cin>>n;
	vector<double> a(n), b(n);
	for(int i=0; i<n; ++i)cin>>a[i];
	for(int i=0; i<n; ++i)cin>>b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	cout<<calcUnfair(a, b)<<" "<<calcFair(a, b)<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("i:/input.txt", "rt", stdin);
	int T; cin>>T;
	for(int t=1; t<=T; ++t)
	{
		cout<<"Case #"<<t<<": ";
		solve();
	}
 
	return 0;
} 