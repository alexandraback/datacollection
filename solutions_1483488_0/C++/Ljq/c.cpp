#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>


using namespace std;

int A, B;

int o[2100000];

int Work()
{
	cin >> A >> B;
	
	int ans = 0, bt = 0, dt = 1, i, z, k;

	for (z = A; z > 0; z /= 10, bt ++);
	for (i = 1; i < bt; i ++)  dt *= 10;

	memset(o, 0, sizeof(o));

	for (k = A; k <= B; k ++)
	{
		for (i = 0, z = dt * (k % 10) + k / 10; i < bt; z = dt * (z % 10) + z / 10, i ++)
			if (z <= B)
			{
				if (o[z] < k)
					ans += (z > k) && (z <= B);
				o[z] = k;
			}
	}

	return ans;
}


int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for (int k = 1; k <= T; k ++)
		cout << "Case #" << k << ": " << Work() << endl;


	return 0;
}