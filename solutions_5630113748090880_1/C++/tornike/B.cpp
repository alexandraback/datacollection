#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int con[2510];
void solve()
{
			for(int i = 1 ;  i <= 2500;i++)
	{
		con[i] = 0;
	}
	cin >> N;
	int p;
	for(int i  = 0 ; i < 2*N-1;i++)
	{
		for(int j = 0 ; j < N ; j++)
		{
		
		cin >> p;
		con[p]++;
		}
	}
	vector < int > vc;
	for(int i = 1 ;  i <= 2500;i++)
	{
		if(con[i]%2)
			vc.push_back(i);
	}
//		cout << con[3] << endl;	
	sort(vc.begin(),vc.end());
	for(int i = 0 ; i < N;i++)
	if(i!=0) cout << " " << vc[i];
	else cout << vc[i];
	cout << endl;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 0 ; i < t ; i++)
	{
	printf("Case #%d: ",i+1);
		solve();
	
	}
	
}
