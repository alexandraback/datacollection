#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <vector>
#include <map>
#include <ctime>
#include <functional>
#include <utility>

#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double

using namespace std;

int t,tt,INF,n,i,kol,j,mn,a[1010];

int main()
{
	//ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>t;
	INF=(int)2e9;
	for (tt=1; tt<=t; tt++)
	{
		cin>>n;
		for (i=1; i<=n; i++)
			cin>>a[i];
		mn=INF;
			
		for (j=1; j<=1000; j++)
		{
			kol=0;
			for (i=1; i<=n; i++)
			{
				kol+=(a[i]-1)/j;
			}	
			mn=min(mn,kol+j);
		}
		cout<<"Case #"<<tt<<": "<<mn<<endl;
	}

	return 0;
}


    