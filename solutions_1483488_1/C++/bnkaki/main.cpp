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

int T,a,b;
const int powTen[]={1,10,100,1000,10000,100000,1000000,10000000,100000000};

int main()
{
	cin>>T;
	for (int t = 1; t <= T; t++)
	{
		cin>>a>>b;

		int ans=0;
		for (int i = a; i <= b; i++)
		{
			int temp=i;

			int digit=-1;
			while (temp>0) {digit++;temp/=10;}

			temp=i;
			do
			{
				temp=(temp/10)+powTen[digit]*(temp%10);
				if (temp>i && temp<=b) ans++;
			} while (temp!=i);
		}

		cout<<"Case #"<<t<<": "<<ans<<endl;
	}

	return 0;
}