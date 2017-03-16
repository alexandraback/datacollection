#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

void solve()
{
	int n;
	string a, b;
	std::multimap<string,string> ma;
	std::multimap<string,string> mb;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		ma.insert(std::pair<string,string>(a,b));
		mb.insert(std::pair<string,string>(b,a));
	}
	int copy = 0;
	for (std::multimap<string,string>::iterator it=ma.begin(); it!=ma.end(); ++it){
		if(ma.count((*it).first) > 1 && mb.count((*it).second) > 1)
			copy++;
	}
	cout << copy;
}

int main(void)
{
	int T;
	cin >> T;
	for(int tt = 1; tt <= T; tt++)
	{
		printf("Case #%d: ", tt);
		solve();
		printf("\n");
	}
}