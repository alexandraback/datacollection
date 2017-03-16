#include <cstdio>
#include <iostream>

FILE *fin = freopen("A-large.in", "r", stdin);
FILE *fout = freopen("A-small.out", "w", stdout);

using namespace std;

void solve()
{
	
	bool found[10];
	int cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		found[i] = 0;
	}

	long long int n;
	cin >> n;

	if (n == 0) { cout << "INSOMNIA"; return;}
	long long int counter = 0;

	while (cnt < 10)
	{
		long long int k = n;
		counter++;
		k *=counter;
		
		while(k > 0)
		{
			int ost = k%10;
			if(!found[ost])
			{
				cnt++;
				found[ost] = 1;
			}
			k/=10;
		}
	}
	cout << n* counter;

}

// Multiple text cases
void main(){
	int t;
	cin >> t;
	for(int i=1 ; i<=t ; i++){
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
}