#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	int T;
	cin >> T;

	for(int i = 0; i < T ; ++i)
	{
		int N,S,p;
		cin>>N>>S>>p;
		vector<int> t(N);
		for(int j=0;j<N;j++)
			scanf("%d", &t[j]);
		sort(t.begin(), t.end());
		reverse(t.begin(), t.end());
		int ans = 0;
		int x = p+2*max(0, p-1);
		int k = 0;
		for(;k<N && t[k]>=x;k++) ans++;
		int y = p+2*max(0, p-2);
		for(;k<N && t[k]>=y && S>0;k++) ans++, S--;

		cout << "Case #" << i + 1 << ": " << ans << endl;

	}

	return 0;
}