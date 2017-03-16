#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int T, t, d, D, i, eat, min, div, p;
	vector< int > items;

	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> D;
		items.clear();
		for ( i = 0 ; i < D ; i++ ) {
			cin >> d;
			items.push_back(d);
		}
		sort(items.begin(), items.end(), greater<int>());
		min = items[0];
        for (eat = 1; eat < items[0]; eat++)
        {
            div = 0;
			for ( i = 0 ; i < D ; i++ ) {
				p = items[i];

                if (p <= eat) break;
                if (p%eat == 0) div += p/eat-1;
                else div += p/eat;
            }
            if (div + eat < min) min = div + eat;
        }
		cout << "Case #"<< t+1 << ": " << min << endl;
	}

	return 0;
}