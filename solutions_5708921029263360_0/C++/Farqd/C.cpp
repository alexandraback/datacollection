#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef long long LL;

//*******************
//*******************
struct str{int a, b, c;};
int J,P, S; 
int K;
vector<str> f1()
{
vector<str> v;
	map< pair<int, int>, int> M1, M2, M3;
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++)
			{
				M1[{i, j}] = 0;
				M2[{i, j}] = 0;
				M3[{i, j}] = 0;
			}
	for(int i=1; i<=J; i++)
		if(i!=2){
		for(int j=1; j<=P; j++)
			for(int k=1; k<= S; k++)
			{
				if(M1[{i, j}] < K && M2[{i,  k}] < K && M3[{j, k}] < K)
				{
					v.push_back({i, j, k});
					// cout<<i<<" "<<j<<" "<<k;
					M1[{i, j}] ++;
					M2[{i, k}] ++;
					M3[{j, k}] ++;
				}

			}
		}
		else
		{
		for(int j=P; j>=1; j--)
			for(int k=1; k<= S; k++)
			{
				if(M1[{i, j}] < K && M2[{i,  k}] < K && M3[{j, k}] < K)
				{
					v.push_back({i, j, k});
					// cout<<i<<" "<<j<<" "<<k;
					M1[{i, j}] ++;
					M2[{i, k}] ++;
					M3[{j, k}] ++;
				}

			}
		}
		return v;
}

vector<str> f2()
{
	vector<str> v;
	map< pair<int, int>, int> M1, M2, M3;
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++)
			{
				M1[{i, j}] = 0;
				M2[{i, j}] = 0;
				M3[{i, j}] = 0;
			}
	for(int i=1; i<=J; i++)
		if(i!=2){
		for(int j=1; j<=P; j++)
			for(int k=1; k<= S; k++)
			{
				if(M1[{i, j}] < K && M2[{i,  k}] < K && M3[{j, k}] < K)
				{
					v.push_back({i, j, k});
					// cout<<i<<" "<<j<<" "<<k;
					M1[{i, j}] ++;
					M2[{i, k}] ++;
					M3[{j, k}] ++;
				}

			}
		}
		else
		{
		for(int j=P; j>=1; j--)
			for(int k=S; k>=1; k--)
			{
				if(M1[{i, j}] < K && M2[{i,  k}] < K && M3[{j, k}] < K)
				{
					v.push_back({i, j, k});
					// cout<<i<<" "<<j<<" "<<k;
					M1[{i, j}] ++;
					M2[{i, k}] ++;
					M3[{j, k}] ++;
				}

			}
		}
		return v;
}

void read() {
	cin>>J>>P>>S; cin>>K;
	 auto  v = f1();
	auto  x = f2();
	
	if(v.size() < x.size())
		swap(v, x);

	cout<<v.size()<<endl;
	for(auto & x : v)
		cout<<x.a<<" "<<x.b<<" "<<x.c<<endl;

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
		// cout<<endl;
	}
  return 0;
}