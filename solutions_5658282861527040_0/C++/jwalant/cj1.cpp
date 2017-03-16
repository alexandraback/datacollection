#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define li long int
#define lli long long int
#define fri(n) for(li i=0;i<n;i++)
#define frj(n) for(li j=0;j<n;j++)
using namespace std;

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.in", "w", stdout);
	li t;
	cin >> t;
	for (li ti = 1; ti <= t; ti++) {
		lli a,b,c;
		cin>>a>>b>>c;
		lli finans=0;
		fri(a)
		{
			frj(b)
				if((i&j)<c)
				{

					finans++;
				}
		}

		cout << "Case #" << ti << ": ";
		cout<<finans<<"\n";
	}
	return 0;

}
