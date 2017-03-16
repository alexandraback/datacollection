#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <utility>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 2000000000
#define MEMSET_INF 127
#define PI 3.141592653

int main(int argc, char const *argv[])
{
	ll n,t,r;
	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		cin>>r>>t;
		ll count=0;
		while(t>=0)
		{
			t-=((r+1)*(r+1)-r*r);
			r+=2;
			count++;
		}
		count--;
		if(count<0)
			count=0;

		printf("Case #%d: %d\n",i+1,count);

	}

	return 0;
}