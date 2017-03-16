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

int t,cases,n,i,added,cur;
string s;

int main()
{
	//ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>t;
	for (cases=1; cases<=t; cases++)
	{
		cin>>n>>s;
		cur=0;
		added=0;
		for (i=0; i<n+1; i++)
		{
			if (cur+added<i)
				added+=i-added-cur;
			cur+=s[i]-'0';
		}
		cout<<"Case #"<<cases<<": "<<added<<endl;
	}

	return 0;
}


    