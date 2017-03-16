/**
Coded by:-   Rogue
**/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <sstream>

#define LL long long int
#define SF second.first
#define SS second.second
#define mp(a,b) make_pair((a),(b))

using namespace std;

int main()
{
	LL cases, t, cnt, s, n, no, sol, i;
	bool flag=false;
	vector<int> v;
	cin>>cases;
	for(t=1; t<=cases; t++)
	{
		v.clear();
		cnt=0;
		cin>>s>>n;
		for(i=0; i<n; i++)
		{
			cin>>no;
			v.push_back(no);
		}
		sort(v.begin(), v.end());
		sol=n;
		for(i=0; i<n; i++)
		{
			if(v[i]<s)
			{
				s+=v[i];
			}
			else
			{
				if(s!=1)
				{
					while(s<=v[i])
					{
						cnt++;
						s+=s-1;
						flag=true;
					}
				}
			}
			sol=min(cnt+n-i-1, sol);
			if(flag)
				i--;
			flag=false;
		}
		if(s==1)
			cout<<"Case #"<<t<<": "<<n<<endl;
		else
			cout<<"Case #"<<t<<": "<<sol<<endl;
	}
	return 0;
}

