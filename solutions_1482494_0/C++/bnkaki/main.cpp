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


int T;
int n;
P d[2000];
bool used[2000][2];

int main()
{
	const int INF=100000000;

	cin>>T;
	for (int tt = 1; tt <= T; tt++)
	{
		cin>>n;
		for (int i=0;i<n;i++) {cin>>d[i].second>>d[i].first;}

		sort(d,d+n);

		bool flag=false;
		memset(used,0,sizeof(used));

		int current=0,ans=0,conq=0;
		while (conq!=n)
		{
			int bigNum=INF,pickUpBig;
			int smallGain=INF,pickUpSmall;
			for (int i=0;i<n;i++)
			{
				if (!used[i][1] && !used[i][0] && bigNum>d[i].first && current>=d[i].first) {bigNum=d[i].first;pickUpBig=i;}
				else if (!used[i][1] && used[i][0] && smallGain>d[i].first && current>=d[i].first) {smallGain=d[i].first;pickUpSmall=i;}
			}

			if (bigNum!=INF)
			{
				conq++;

				current+=2;
				used[pickUpBig][1]=true;
				ans++;

				continue;
			}
			else if (smallGain!=INF)
			{
				conq++;

				current++;
				used[pickUpSmall][1]=true;
				ans++;

				continue;
			}


			int smallNum=INF,pickUp;

			for (int i = n-1; i >= 0; i--)
			{
				if (!used[i][0] && !used[i][1] && smallNum>d[i].second && current>=d[i].second) {smallNum=d[i].second;pickUp=i;}
			}

			if (smallNum!=INF)
			{
				current++;
				used[pickUp][0]=true;
				ans++;

				continue;
			}
			else
			{
				flag=true;
				break;
			}
		}

		if (flag) cout<<"Case #"<<tt<<": "<<"Too Bad"<<endl;
		else cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
}