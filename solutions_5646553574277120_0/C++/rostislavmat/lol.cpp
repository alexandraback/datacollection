#include <algorithm>
#include <bitset>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;



int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
    int qq;
	cin>>qq;
	for (int q=0;q<qq;q++)
	{
		cout<<"Case #"<<q+1<<": ";
		int c,n,v;
		cin>>c>>n>>v;
		vector <int> a(n);
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		vector <int> can(v+1,0);
		can[0]=1;
		for (int i=0;i<n;i++)
		{
			for (int j=v;j>=0;j--)
			{
				if ((can[j]==1)&&(j+a[i]<=v))
				{
					can[j+a[i]]=1;
				}
			}
		}
		int ans=0;
		for (int i=1;i<=v;i++)
		{
			if (can[i]==0)
			{
				ans++;
				for (int j=v;j>=0;j--)
				{
					if ((can[j]==1)&&(j+i<=v))
					{
						can[j+i]=1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}