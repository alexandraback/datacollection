#include <iostream>
#include <algorithm>
using namespace std;

int a[1000010];

int func(int count,int ar,int s,int n)
{
	if(s>n)
		return count;
	if(ar>a[s])
		return func(count,ar+a[s],s+1,n);
	else
		return min(count+n-s+1,func(count+1,2*ar-1,s,n));
}

int main()
{
	int i,z,t,n,ar;
	cin >> t;
	for(z=1;z<=t;z++)
	{
		cin >> ar >> n;
		for (i=1;i<=n;i++)
			cin >> a[i];
		sort(a+1,a+n+1);
		if(ar==1)
		{
			cout << "Case #" << z << ": " << n << endl;
			continue;
		}
		cout << "Case #" << z << ": " << func(0,ar,1,n) << endl;
	}
	return 0;
}
