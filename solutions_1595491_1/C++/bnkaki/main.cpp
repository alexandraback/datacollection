#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <functional>
#include <set>
#include <map>
#include <sstream>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int T,N,S,p,points;

int normal[200],surprising[200];
bool used[200];

int main()
{
	cin>>T;
	for (int t = 1; t <= T; t++)
	{
		cin>>N>>S>>p;

		for (int i = 0; i < N; i++)
		{
			cin>>points;

			if (points==0 || points==1)
			{
				normal[i]=points;
				surprising[i]=-1;
			}
			else
			{
				if (points%3==0)
				{
					normal[i]=points/3;
					surprising[i]=(points/3)+1;
				}
				else if (points%3==1)
				{
					normal[i]=(points/3)+1;
					surprising[i]=(points/3)+1;
				}
				else
				{
					normal[i]=(points/3)+1;
					surprising[i]=(points/3)+2;
				}
			}
		}

		int ans=0;
		memset(used,0,sizeof(used));

		for (int i = 0; i < N; i++)
		{
			if (normal[i]>=p) {ans++;used[i]=true;}
		}
		for (int i = 0; i < N; i++)
		{
			if (!used[i] && surprising[i]>=p && S>0) {ans++;S--;}
		}

		cout<<"Case #"<<t<<": "<<ans<<endl;
	}

	return 0;
}