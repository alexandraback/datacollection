#include <iostream>
#include <cstdio>

using namespace std;

int n,m,w,tot,T;
	
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin >> T;
	for(int Case=1;Case<=T;Case++)
	{
		cin >> n >> m >> w;
		tot = (n - 1) * (m / w) + m / w;
		m %= w;
		if(!m)	tot += w-1;
		else	tot += w;
		cout << "Case #" << Case << ": " << tot << endl; 
	}
}
